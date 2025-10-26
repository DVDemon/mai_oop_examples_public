#include <array>
#include <iostream>
#include <memory>

/**
 * Тестовая структура для демонстрации размещения std::array в памяти
 * Содержит массив фиксированного размера
 */
struct TestStructure {
    /**
     * Конструктор по умолчанию
     */
    TestStructure() = default;

    std::array<int, 5> values;  // Массив из 5 целых чисел
};

/**
 * Демонстрация размещения std::array в памяти
 * Показывает, что std::array размещается на стеке, как обычные переменные
 */
void testMemoryPlacement() {
    std::cout << "\n=== ТЕСТ РАЗМЕЩЕНИЯ STD::ARRAY В ПАМЯТИ ===" << std::endl;

    int stack_variable = 0;
    std::array<int, 10> array_data = {0, 1, 2, 3};

    std::cout << "Адрес переменной на стеке: " << &stack_variable << std::endl;
    std::cout << "Адрес объекта array:      " << &array_data << std::endl;
    std::cout << "Адрес данных array:       " << array_data.data() << std::endl;
    std::cout << "Размер array в байтах:    " << sizeof(array_data) << std::endl; 

    // Демонстрация итерации по массиву
    std::cout << "Элементы массива: ";
    for (auto& element : array_data) {
        std::cout << element << ' ';
    }
    std::cout << std::endl;

    // Демонстрация размещения array в структуре
    std::unique_ptr<TestStructure> structure_pointer{new TestStructure{}};
    std::cout << "Адрес структуры:           " << structure_pointer.get() << std::endl;
    std::cout << "Адрес array в структуре:   " << structure_pointer->values.data() << std::endl;
}

/**
 * Демонстрация работы с итераторами std::array
 * Показывает различные операции с итераторами для статического массива
 */
void testIteratorOperations() {
    std::cout << "\n=== ТЕСТ ОПЕРАЦИЙ С ИТЕРАТОРАМИ STD::ARRAY ===" << std::endl;

    std::array<int, 10> array_data = {0, 1, 2, 3, 4, 5, 6, 7, 8};

    // Создание итератора на 4-й элемент (индекс 3)
    auto current_iterator = std::next(array_data.cbegin(), 3);
    std::cout << "Элемент на позиции 3: " << *current_iterator << std::endl;

    // Перемещение итератора вперед
    ++current_iterator;
    std::cout << "Следующий элемент: " << *current_iterator << std::endl;

    // Перемещение итератора назад
    --current_iterator;
    --current_iterator;
    std::cout << "Предыдущий элемент: " << *current_iterator << std::endl;

    // Перемещение итератора на 3 позиции вперед
    current_iterator += 3;
    std::cout << "Элемент через 3 позиции: " << *current_iterator << std::endl;
}

/**
 * Основная функция - демонстрация std::array
 * Показывает особенности статического массива и его размещение в памяти
 */
int main() {
    std::cout << "=== ДЕМОНСТРАЦИЯ STD::ARRAY ===" << std::endl;

    // Тест 1: Размещение в памяти
    testMemoryPlacement();
    
    // Тест 2: Операции с итераторами
    testIteratorOperations();

    std::cout << "\n=== ДЕМОНСТРАЦИЯ ЗАВЕРШЕНА ===" << std::endl;
    return 0;
}