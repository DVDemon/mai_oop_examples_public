#include <forward_list>
#include <iostream>

/**
 * Демонстрация размещения элементов std::forward_list в памяти
 * Показывает, что элементы могут быть разбросаны по памяти
 * и отслеживает разности адресов между соседними элементами
 */
void testMemoryPlacement() {
    std::cout << "\n=== ТЕСТ РАЗМЕЩЕНИЯ STD::FORWARD_LIST В ПАМЯТИ ===" << std::endl;

    int stack_variable = 0;
    std::forward_list<int> forward_list_data;
    
    // ========================================================================
    // ДОБАВЛЕНИЕ ЭЛЕМЕНТОВ В НАЧАЛО СПИСКА
    // ========================================================================
    std::cout << "1. Добавление 100 элементов в начало списка:" << std::endl;
    for (int element_index = 0; element_index < 100; ++element_index) {
        forward_list_data.push_front(element_index);
    }

    std::cout << "2. Анализ размещения элементов в памяти:" << std::endl;
    std::cout << "   Адрес переменной на стеке: " << &stack_variable << std::endl;
    std::cout << "   Адрес объекта forward_list: " << &forward_list_data << std::endl;
    
    // ========================================================================
    // ОТСЛЕЖИВАНИЕ РАЗНОСТЕЙ АДРЕСОВ МЕЖДУ ЭЛЕМЕНТАМИ
    // ========================================================================
    int* previous_element_pointer = nullptr;
    size_t element_index{0};
    
    for (auto& current_element : forward_list_data) {
        ++element_index;
        if (previous_element_pointer) {
            // Вычисление разности адресов между соседними элементами
            long address_difference = reinterpret_cast<unsigned long>(previous_element_pointer) - 
                                     reinterpret_cast<unsigned long>(&current_element);
            std::cout << "   Разность адресов: " << address_difference 
                      << " (элемент " << element_index << ")" << std::endl;
        }
        previous_element_pointer = &current_element;        
    }
}

/**
 * Демонстрация работы с итераторами std::forward_list
 * Показывает особенности однонаправленных итераторов и операции вставки
 */
void testIteratorOperations() {
    std::cout << "\n=== ТЕСТ ОПЕРАЦИЙ С ИТЕРАТОРАМИ STD::FORWARD_LIST ===" << std::endl;

    std::forward_list<int> forward_list_data = {0, 1, 2, 3, 4, 5, 6, 7, 8};

    // ========================================================================
    // ОСНОВНЫЕ ОПЕРАЦИИ С ИТЕРАТОРАМИ
    // ========================================================================
    std::cout << "1. Базовые операции с итераторами:" << std::endl;
    auto current_iterator = std::next(forward_list_data.cbegin(), 3);
    std::cout << "   Элемент на позиции 3: " << *current_iterator << std::endl;

    // Перемещение вперед
    ++current_iterator;
    std::cout << "   Следующий элемент: " << *current_iterator << std::endl;

    // ========================================================================
    // ОГРАНИЧЕНИЯ ОДНОНАПРАВЛЕННЫХ ИТЕРАТОРОВ
    // ========================================================================
    std::cout << "2. Ограничения однонаправленных итераторов:" << std::endl;
    std::cout << "   - НЕТ оператора -- (движение назад)" << std::endl;
    std::cout << "   - НЕТ оператора += (прямое перемещение)" << std::endl;
    std::cout << "   - ТОЛЬКО оператор ++ (движение вперед)" << std::endl;
    
    // Закомментированные операции, которые НЕ РАБОТАЮТ:
    // --current_iterator;  // ОШИБКА КОМПИЛЯЦИИ!
    // current_iterator += 3;  // ОШИБКА КОМПИЛЯЦИИ!
    
    // Альтернатива для перемещения на несколько позиций
    std::advance(current_iterator, 3);
    std::cout << "   Элемент через 3 позиции (std::advance): " << *current_iterator << std::endl;

    // ========================================================================
    // РАБОТА С ПОЗИЦИЯМИ ИТЕРАТОРОВ
    // ========================================================================
    auto iterator_position = std::distance(forward_list_data.cbegin(), current_iterator);
    std::cout << "   Позиция итератора: " << iterator_position << std::endl;

    // ========================================================================
    // ОПЕРАЦИИ ВСТАВКИ И ИХ ВЛИЯНИЕ НА ИТЕРАТОРЫ
    // ========================================================================
    std::cout << "3. Операции вставки и влияние на итераторы:" << std::endl;
    
    // ВАЖНО: forward_list НЕ ИМЕЕТ push_back!
    // values.push_back(42);  // ОШИБКА КОМПИЛЯЦИИ!
    forward_list_data.push_front(42);
    std::cout << "   Добавлен элемент в начало списка" << std::endl;

    std::cout << "   Адрес первого элемента: " << &*forward_list_data.cbegin() << std::endl;
    std::cout << "   Адрес элемента на позиции " << iterator_position << ": " 
              << &*(std::next(forward_list_data.cbegin(), iterator_position)) << std::endl;
    
    // Итератор остается валидным после push_front
    std::cout << "   Адрес элемента через итератор: " << &*current_iterator << std::endl;

    // ========================================================================
    // ВСТАВКА ПОСЛЕ ЭЛЕМЕНТА
    // ========================================================================
    auto new_iterator = std::next(forward_list_data.cbegin(), 3);
    std::cout << "   Элемент на позиции 3: " << *new_iterator << std::endl;
    
    std::cout << "   Вставка элемента после позиции 3..." << std::endl;
    forward_list_data.insert_after(forward_list_data.cbegin(), 42);
    std::cout << "   Элемент на позиции 3 после вставки: " << *new_iterator << std::endl;

    // ========================================================================
    // ВСТАВКА В НАЧАЛО СПИСКА
    // ========================================================================
    forward_list_data.insert_after(forward_list_data.before_begin(), 9999);
    std::cout << "   Первый элемент после вставки в начало: " << *forward_list_data.cbegin() << std::endl;

    // ========================================================================
    // ВЫВОД ВСЕХ ЭЛЕМЕНТОВ
    // ========================================================================
    std::cout << "4. Все элементы списка:" << std::endl;
    for (auto& element : forward_list_data) {
        std::cout << "   " << element << std::endl;
    }
}

/**
 * Основная функция - демонстрация std::forward_list
 * Показывает особенности односвязного списка и однонаправленных итераторов
 */
int main() {
    std::cout << "=== ДЕМОНСТРАЦИЯ STD::FORWARD_LIST ===" << std::endl;

    // Тест 1: Размещение элементов в памяти
    testMemoryPlacement();

    // Тест 2: Операции с итераторами
    testIteratorOperations();

    std::cout << "\n=== ДЕМОНСТРАЦИЯ ЗАВЕРШЕНА ===" << std::endl;
    return 0;
}