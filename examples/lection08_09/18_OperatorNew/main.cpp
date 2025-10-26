#include <cstdlib>
#include <iostream>
#include <exception>

/**
 * Глобальный буфер для демонстрации кастомного аллокатора
 * Используется для показа перегрузки операторов new/delete
 */
const size_t BUFFER_SIZE = 80;
unsigned char memory_buffer[BUFFER_SIZE];
unsigned char* current_buffer_pointer = memory_buffer;

/**
 * Демонстрационный класс для перегрузки операторов new/delete
 * Показывает различные способы выделения памяти и управления жизненным циклом объектов
 */
class CustomAllocatorDemo {
private:
    int stored_value;

public:
    /**
     * Конструктор с параметром
     * @param value - значение для хранения
     */
    CustomAllocatorDemo(int value) : stored_value(value) {
        std::cout << "   Конструктор вызван для значения: " << stored_value << std::endl;
    }

    /**
     * Перегрузка оператора new для кастомного аллокатора
     * @param size - размер выделяемой памяти
     * @return указатель на выделенную память
     */
    void* operator new(size_t size);

    /**
     * Перегрузка оператора new с дополнительным параметром
     * @param size - размер выделяемой памяти
     * @param message - сообщение для вывода
     * @return указатель на выделенную память
     */
    void* operator new(size_t size, const char* message);
    
    /**
     * Перегрузка оператора delete
     * @param pointer - указатель на освобождаемую память
     */
    void operator delete(void* pointer);

    /**
     * Деструктор
     */
    ~CustomAllocatorDemo() {
        std::cout << "   Деструктор вызван для значения: " << stored_value << std::endl;
    }
};


/**
 * Реализация оператора new с дополнительным параметром
 * Демонстрирует перегрузку с пользовательскими параметрами
 */
void* CustomAllocatorDemo::operator new(size_t size, const char* message) {
    std::cout << "   Сообщение: " << message << std::endl;
    std::cout << "   Выделение памяти через malloc: " << size << " байт" << std::endl;
    return std::malloc(size);
}

/**
 * Реализация кастомного оператора new
 * Использует глобальный буфер для демонстрации аллокатора
 */
void* CustomAllocatorDemo::operator new(size_t size) {
    // Проверка доступности места в буфере
    if ((current_buffer_pointer + size) > (memory_buffer + BUFFER_SIZE)) {
        throw std::logic_error("Недостаточно места в буфере");
    }
    
    void* allocated_memory = current_buffer_pointer;
    current_buffer_pointer += size;
    std::cout << "   Выделено: " << size << " байт из буфера" << std::endl;
    return allocated_memory;
}

/**
 * Реализация кастомного оператора delete
 * Демонстрирует управление освобождением памяти
 */
void CustomAllocatorDemo::operator delete(void* pointer) {
    std::cout << "   Память освобождена (кастомный delete)" << std::endl;
    // В данном случае не вызываем free(), так как используем буфер
}

/**
 * Основная функция - демонстрация перегрузки операторов new/delete
 * Показывает различные способы выделения памяти и управления объектами
 */
int main() {
    std::cout << "=== ДЕМОНСТРАЦИЯ ПЕРЕГРУЗКИ ОПЕРАТОРОВ NEW/DELETE ===" << std::endl;

    // ========================================================================
    // ДЕМОНСТРАЦИЯ 1: СТЕКОВОЕ ВЫДЕЛЕНИЕ ПАМЯТИ
    // ========================================================================
    std::cout << "\n1. Стековое выделение памяти (НЕ вызывает operator new):" << std::endl;
    {
        CustomAllocatorDemo stack_object(1);
        std::cout << "   Внутренний блок - объект на стеке" << std::endl;
    }
    std::cout << "   Объект автоматически уничтожен при выходе из блока" << std::endl;

    // ========================================================================
    // ДЕМОНСТРАЦИЯ 2: PLACEMENT NEW
    // ========================================================================
    std::cout << "\n2. Placement new (размещение в предварительно выделенной памяти):" << std::endl;
    char* pre_allocated_memory = new char[sizeof(CustomAllocatorDemo)];
    CustomAllocatorDemo* placement_object = ::new (pre_allocated_memory) CustomAllocatorDemo(2018);
    
    // Явный вызов деструктора для placement new
    placement_object->~CustomAllocatorDemo();
    delete[] pre_allocated_memory;

    // ========================================================================
    // ДЕМОНСТРАЦИЯ 3: КАСТОМНЫЙ NEW С ПАРАМЕТРАМИ
    // ========================================================================
    std::cout << "\n3. Кастомный new с параметрами:" << std::endl;
    CustomAllocatorDemo* parameterized_object = new ("Привет, мир!") CustomAllocatorDemo(2019);
    delete parameterized_object;
    
    // ========================================================================
    // ДЕМОНСТРАЦИЯ 4: ДИНАМИЧЕСКОЕ ВЫДЕЛЕНИЕ ПАМЯТИ ИЗ БУФЕРА
    // ========================================================================
    std::cout << "\n4. Динамическое выделение памяти из буфера:" << std::endl;
    std::cout << "   Размер буфера: " << BUFFER_SIZE << " байт" << std::endl;
    
    for (int iteration = 0; iteration < BUFFER_SIZE; ++iteration) {
        try {
            CustomAllocatorDemo* buffer_object = new CustomAllocatorDemo(iteration);
            delete buffer_object;
            std::cout << "   Итерация " << iteration << " завершена" << std::endl;
        } catch (const std::logic_error& error) {
            std::cout << "   ОШИБКА на итерации " << iteration << ": " << error.what() << std::endl;
            break;
        }
    }

    std::cout << "\n=== ДЕМОНСТРАЦИЯ ЗАВЕРШЕНА ===" << std::endl;
    return 0;
}
