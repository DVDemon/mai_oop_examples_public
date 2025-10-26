#include <iostream>
#include <memory_resource>
#include <vector>

/**
 * Пользовательский memory_resource для демонстрации полиморфных аллокаторов
 * Использует стандартные операторы new и delete для выделения памяти
 * 
 * Показывает, как создать собственный memory_resource для использования
 * с полиморфными аллокаторами C++17
 */
class CustomMemoryResource : public std::pmr::memory_resource {
public:
    /**
     * Выделение памяти с заданным выравниванием
     * 
     * @param bytes - размер выделяемой памяти в байтах
     * @param alignment - требуемое выравнивание
     * @return указатель на выделенную память
     */
    void* do_allocate(size_t bytes, size_t alignment) override {
        std::cout << "   Выделение " << bytes << " байт с выравниванием " << alignment << std::endl;
        return ::operator new(bytes);
    }

    /**
     * Освобождение памяти
     * 
     * @param ptr - указатель на освобождаемую память
     * @param bytes - размер освобождаемой памяти
     * @param alignment - выравнивание освобождаемой памяти
     */
    void do_deallocate(void* ptr, size_t bytes, size_t alignment) override {
        std::cout << "   Освобождение " << bytes << " байт по адресу " << ptr << std::endl;
        ::operator delete(ptr);
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
 * Основная функция - демонстрация полиморфных аллокаторов
 * Показывает создание пользовательского memory_resource и его использование
 * с полиморфными аллокаторами C++17
 */
int main() {
    std::cout << "=== ДЕМОНСТРАЦИЯ ПОЛИМОРФНЫХ АЛЛОКАТОРОВ ===" << std::endl;

    // ========================================================================
    // ДЕМОНСТРАЦИЯ 1: СОЗДАНИЕ ПОЛЬЗОВАТЕЛЬСКОГО MEMORY_RESOURCE
    // ========================================================================
    std::cout << "\n1. Создание пользовательского memory_resource:" << std::endl;
    CustomMemoryResource custom_memory_resource;
    std::cout << "   Пользовательский memory_resource создан" << std::endl;

    // ========================================================================
    // ДЕМОНСТРАЦИЯ 2: СОЗДАНИЕ ПОЛИМОРФНОГО АЛЛОКАТОРА
    // ========================================================================
    std::cout << "\n2. Создание полиморфного аллокатора:" << std::endl;
    std::pmr::polymorphic_allocator<int> polymorphic_allocator(&custom_memory_resource);
    std::cout << "   Полиморфный аллокатор создан" << std::endl;

    // ========================================================================
    // ДЕМОНСТРАЦИЯ 3: ИСПОЛЬЗОВАНИЕ С PMR::VECTOR
    // ========================================================================
    std::cout << "\n3. Использование с std::pmr::vector:" << std::endl;
    std::pmr::vector<int> integer_vector(polymorphic_allocator);
    std::cout << "   Вектор с полиморфным аллокатором создан" << std::endl;

    // ========================================================================
    // ДЕМОНСТРАЦИЯ 4: ДОБАВЛЕНИЕ ЭЛЕМЕНТОВ
    // ========================================================================
    std::cout << "\n4. Добавление элементов в вектор:" << std::endl;
    for (int element_value = 0; element_value < 10; ++element_value) {
        integer_vector.push_back(element_value);
        std::cout << "   Добавлен элемент: " << element_value << std::endl;
    }

    // ========================================================================
    // ДЕМОНСТРАЦИЯ 5: ВЫВОД ЭЛЕМЕНТОВ
    // ========================================================================
    std::cout << "\n5. Содержимое вектора:" << std::endl;
    std::cout << "   ";
    for (int element_value : integer_vector) {
        std::cout << element_value << " ";
    }
    std::cout << std::endl;

    std::cout << "\n=== ДЕМОНСТРАЦИЯ ЗАВЕРШЕНА ===" << std::endl;
    return 0;
}