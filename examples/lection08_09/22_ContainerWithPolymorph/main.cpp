#include <iostream>
#include <memory_resource>
#include <vector>
#include <concepts>
#include <memory>
#include <exception>
#include <algorithm>

/**
 * Пользовательский memory_resource с буферной памятью
 * Демонстрирует создание memory_resource с предварительно выделенным буфером
 * и отслеживанием занятых блоков памяти
 */
class CustomMemoryResource : public std::pmr::memory_resource {
    /**
     * Структура для отслеживания занятых блоков памяти
     */
    struct MemoryBlock {
        size_t offset{0};  // Смещение от начала буфера
        size_t size{0};    // Размер блока
    };

    static constexpr size_t BUFFER_SIZE{600};  // Размер буфера в байтах
    char memory_buffer[BUFFER_SIZE];           // Буфер для хранения данных
    std::vector<MemoryBlock> used_blocks;      // Список занятых блоков

public:
    /**
     * Выделение памяти из буфера
     * Ищет свободное место в буфере и выделяет блок нужного размера
     * 
     * @param bytes - размер выделяемой памяти в байтах
     * @param alignment - требуемое выравнивание
     * @return указатель на выделенную память
     */
    void* do_allocate(size_t bytes, size_t alignment) override {
        // Поиск свободного блока в буфере
        size_t allocation_offset = 0;
        
        for (const MemoryBlock& block : used_blocks) {
            // Проверяем, помещается ли блок перед текущим занятым блоком
            if ((allocation_offset + bytes <= block.offset) || 
                (allocation_offset >= block.offset + block.size)) {
                // Место найдено
            } else {
                // Перемещаемся за текущий блок
                allocation_offset = block.offset + block.size + 1;
            }
        }
        
        // Проверяем, помещается ли блок в буфер
        if (allocation_offset + bytes >= BUFFER_SIZE) {
            throw std::bad_alloc();
        }

        // Добавляем новый блок в список занятых
        used_blocks.emplace_back(allocation_offset, bytes);
        
        // Сортируем блоки по смещению для оптимизации поиска
        std::sort(used_blocks.begin(), used_blocks.end(),
                  [](const MemoryBlock& left, const MemoryBlock& right) { 
                      return left.offset <= right.offset; 
                  });
        
        std::cout << "   Выделение: смещение " << allocation_offset << ", размер " << bytes << " байт" << std::endl;
        return memory_buffer + allocation_offset;
    }

    /**
     * Освобождение памяти в буфере
     * Находит блок по указателю и удаляет его из списка занятых
     * 
     * @param ptr - указатель на освобождаемую память
     * @param bytes - размер освобождаемой памяти
     * @param alignment - выравнивание освобождаемой памяти
     */
    void do_deallocate(void* ptr, size_t bytes, size_t alignment) override {
        std::cout << "   Освобождение: адрес " << ptr << ", размер " << bytes << " байт" << std::endl;
        
        // Поиск блока по указателю
        for (size_t block_index = 0; block_index < used_blocks.size(); ++block_index) {
            if (ptr == memory_buffer + used_blocks[block_index].offset) {
                used_blocks.erase(used_blocks.begin() + block_index);
                return;
            }
        }
        throw std::logic_error("Попытка освобождения не выделенного блока");
    }

    /**
     * Сравнение с другим memory_resource
     * 
     * @param other - другой memory_resource для сравнения
     * @return true, если это тот же объект
     */
    bool do_is_equal(const std::pmr::memory_resource& other) const noexcept override {
        return this == &other;
    }
};

/**
 * Пользовательский контейнер Array с поддержкой полиморфных аллокаторов
 * Демонстрирует создание контейнера, совместимого с PMR аллокаторами
 * 
 * @tparam T - тип элементов контейнера
 * @tparam allocator_type - тип аллокатора (должен быть полиморфным)
 */
template <class T, class allocator_type>
    requires std::is_default_constructible_v<T> && 
             std::is_same_v<allocator_type, std::pmr::polymorphic_allocator<T>>
class Array {
private:
    /**
     * Пользовательский deleter для unique_ptr
     * Не выполняет реального удаления, так как память управляется аллокатором
     */
    struct PolymorphicDeleter {
        void operator()(T* ptr) const {
            // Память освобождается через аллокатор в деструкторе
        }
    };

    using LimitedUniquePtr = std::unique_ptr<T, PolymorphicDeleter>;

    allocator_type polymorphic_allocator;  // Полиморфный аллокатор
    LimitedUniquePtr data_pointer;         // Указатель на данные
    std::size_t array_size;                // Размер массива

public:
    /**
     * Конструктор массива
     * 
     * @param size - размер массива
     * @param alloc - полиморфный аллокатор
     */
    Array(std::size_t size, allocator_type alloc = {}) 
        : polymorphic_allocator(alloc), array_size(size) {
        
        // Выделение памяти через полиморфный аллокатор
        T* raw_pointer = polymorphic_allocator.allocate(size);
        
        // Конструирование объектов в выделенной памяти
        for (size_t element_index = 0; element_index < size; ++element_index) {
            polymorphic_allocator.construct(raw_pointer + element_index);
        }
        
        // Создание unique_ptr с пользовательским deleter
        data_pointer = std::unique_ptr<T, PolymorphicDeleter>(raw_pointer, PolymorphicDeleter{});
    }
    /**
     * Оператор доступа к элементам массива
     * 
     * @param index - индекс элемента
     * @return ссылка на элемент
     */
    T& operator[](std::size_t index) {
        if (index < array_size) {
            return data_pointer.get()[index];
        } else {
            throw std::out_of_range("Выход за границы массива");
        }
    }

    /**
     * Константный оператор доступа к элементам массива
     * 
     * @param index - индекс элемента
     * @return константная ссылка на элемент
     */
    const T& operator[](std::size_t index) const {
        if (index < array_size) {
            return data_pointer.get()[index];
        } else {
            throw std::out_of_range("Выход за границы массива");
        }
    }

    /**
     * Итератор начала массива
     * 
     * @return указатель на первый элемент
     */
    T* begin() {
        return data_pointer.get();
    }

    /**
     * Итератор конца массива
     * 
     * @return указатель за последним элементом
     */
    T* end() {
        return data_pointer.get() + array_size;
    }

    /**
     * Получение размера массива
     * 
     * @return размер массива
     */
    std::size_t size() const {
        return array_size;
    }

    /**
     * Деструктор массива
     * Разрушает объекты и освобождает память через аллокатор
     */
    ~Array() {
        if constexpr (std::is_destructible_v<T>) {
            for (size_t element_index = 0; element_index < array_size; ++element_index) {
                std::allocator_traits<allocator_type>::destroy(polymorphic_allocator, 
                                                              data_pointer.get() + element_index);
            }
        }
        polymorphic_allocator.deallocate(data_pointer.get(), array_size);
    }
};

/**
 * Основная функция - демонстрация пользовательского контейнера с полиморфными аллокаторами
 * Показывает создание и использование Array с кастомным memory_resource
 */
int main() {
    std::cout << "=== ДЕМОНСТРАЦИЯ КОНТЕЙНЕРА С ПОЛИМОРФНЫМИ АЛЛОКАТОРАМИ ===" << std::endl;

    // ========================================================================
    // ДЕМОНСТРАЦИЯ 1: СОЗДАНИЕ MEMORY_RESOURCE И АЛЛОКАТОРА
    // ========================================================================
    std::cout << "\n1. Создание пользовательского memory_resource:" << std::endl;
    CustomMemoryResource custom_memory_resource;
    std::pmr::polymorphic_allocator<int> polymorphic_allocator(&custom_memory_resource);
    std::cout << "   Полиморфный аллокатор создан" << std::endl;

    // ========================================================================
    // ДЕМОНСТРАЦИЯ 2: СОЗДАНИЕ МАССИВА С ПОЛЬЗОВАТЕЛЬСКОЙ СТРУКТУРОЙ
    // ========================================================================
    std::cout << "\n2. Создание массива с пользовательской структурой:" << std::endl;
    struct TestStructure {
        int first_value;
        int second_value;
    };

    Array<TestStructure, std::pmr::polymorphic_allocator<TestStructure>> 
        structure_array(10, std::pmr::polymorphic_allocator<TestStructure>(&custom_memory_resource));
    std::cout << "   Массив структур создан" << std::endl;

    // ========================================================================
    // ДЕМОНСТРАЦИЯ 3: СОЗДАНИЕ МНОЖЕСТВЕННЫХ МАССИВОВ
    // ========================================================================
    std::cout << "\n3. Создание множественных массивов:" << std::endl;
    Array<int, std::pmr::polymorphic_allocator<int>>* array1, *array2, *array3, *array4;

    array1 = new Array<int, std::pmr::polymorphic_allocator<int>>(10, polymorphic_allocator);
    array2 = new Array<int, std::pmr::polymorphic_allocator<int>>(10, polymorphic_allocator);
    array3 = new Array<int, std::pmr::polymorphic_allocator<int>>(10, polymorphic_allocator);
    array4 = new Array<int, std::pmr::polymorphic_allocator<int>>(10, polymorphic_allocator);
    std::cout << "   Четыре массива созданы" << std::endl;

    // ========================================================================
    // ДЕМОНСТРАЦИЯ 4: ОСВОБОЖДЕНИЕ ЧАСТИ МАССИВОВ
    // ========================================================================
    std::cout << "\n4. Освобождение части массивов:" << std::endl;
    delete array2;
    delete array3;
    std::cout << "   Два массива освобождены" << std::endl;

    // ========================================================================
    // ДЕМОНСТРАЦИЯ 5: ЦИКЛИЧЕСКОЕ СОЗДАНИЕ И ИСПОЛЬЗОВАНИЕ МАССИВОВ
    // ========================================================================
    std::cout << "\n5. Циклическое создание и использование массивов:" << std::endl;
    for (int iteration = 0; iteration < 10; ++iteration) {
        std::cout << "   Итерация " << iteration << ":" << std::endl;
        
        Array<int, std::pmr::polymorphic_allocator<int>> temp_array(10, polymorphic_allocator);
        Array<int, std::pmr::polymorphic_allocator<int>> large_array(40, polymorphic_allocator);
        
        // Заполнение массива значениями
        for (int element_index = 0; element_index < 10; ++element_index) {
            temp_array[element_index] = element_index;
        }
        
        // Вывод содержимого массива
        std::cout << "     Содержимое: ";
        for (int element_value : temp_array) {
            std::cout << element_value << " ";
        }
        std::cout << std::endl;
    }

    // ========================================================================
    // ДЕМОНСТРАЦИЯ 6: ОСВОБОЖДЕНИЕ ОСТАВШИХСЯ МАССИВОВ
    // ========================================================================
    std::cout << "\n6. Освобождение оставшихся массивов:" << std::endl;
    delete array1;
    delete array4;
    std::cout << "   Все массивы освобождены" << std::endl;

    std::cout << "\n=== ДЕМОНСТРАЦИЯ ЗАВЕРШЕНА ===" << std::endl;
    return 0;
}