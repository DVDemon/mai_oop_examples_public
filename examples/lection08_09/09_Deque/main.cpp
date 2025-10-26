#include <deque>
#include <iostream>

/**
 * Демонстрация внутренней структуры std::deque
 * Показывает, как deque использует сегментированную структуру данных
 * и как это влияет на адреса элементов при добавлении
 */
void testMemoryStructure() {
    std::cout << "\n=== ТЕСТ ВНУТРЕННЕЙ СТРУКТУРЫ STD::DEQUE ===" << std::endl;

    int stack_variable = 0;
    std::deque<int> deque_data = {0, 1, 2, 3, 4, 5};

    std::cout << "Адрес переменной на стеке: " << &stack_variable << std::endl;
    std::cout << "Адрес объекта deque:      " << &deque_data << std::endl;
    std::cout << "Адрес первого элемента:   " << &deque_data[0] << std::endl;

    // Отслеживание изменений адресов при добавлении элементов
    auto previous_element_pointer = &deque_data[0];
    for (int element_index = 1; element_index < 1000; ++element_index) {
        deque_data.push_back(element_index);

        auto current_element_pointer = &deque_data.back();

        // Проверка на изменение сегмента (bucket)
        if (element_index > 0) {
            if (((current_element_pointer - previous_element_pointer) > 1) || 
                ((current_element_pointer - previous_element_pointer) < -1)) {
                std::cout << "Обнаружен новый сегмент (bucket)!" << std::endl;
                std::cout << "Индекс элемента: " << element_index << std::endl;
                std::cout << "Предыдущий адрес: " << previous_element_pointer << std::endl;
                std::cout << "Текущий адрес:    " << current_element_pointer << std::endl;
                std::cout << "Разность адресов: " << (current_element_pointer - previous_element_pointer) << std::endl;
            }
        }
        previous_element_pointer = current_element_pointer;
    }
}

/**
 * Демонстрация работы с итераторами std::deque
 * Показывает операции с итераторами и их инвалидацию при модификации контейнера
 */
void testIteratorOperations() {
    std::cout << "\n=== ТЕСТ ОПЕРАЦИЙ С ИТЕРАТОРАМИ STD::DEQUE ===" << std::endl;

    std::deque<int> deque_data = {0, 1, 2, 3, 4, 5, 6, 7, 8};

    // Создание итератора на 4-й элемент (индекс 3)
    auto current_iterator = std::next(deque_data.cbegin(), 3);
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

    // Вычисление позиции итератора
    auto iterator_position = std::distance(deque_data.cbegin(), current_iterator);
    std::cout << "Позиция итератора: " << iterator_position << std::endl;

    // Сохранение указателя на элемент
    auto element_pointer = &*current_iterator;
    std::cout << "Добавляем элемент в конец..." << std::endl;
    deque_data.push_back(42);    

    std::cout << "Адрес первого элемента: " << &deque_data[0] << std::endl;
    std::cout << "Адрес элемента на позиции " << iterator_position << ": " << &deque_data[iterator_position] << std::endl;

    // ========================================================================
    // ВАЖНО: ИТЕРАТОРЫ МОГУТ СТАТЬ НЕВАЛИДНЫМИ ПРИ МОДИФИКАЦИИ
    // ========================================================================
    std::cout << "ВНИМАНИЕ: Итератор может стать невалидным после модификации!" << std::endl;
    // std::cout << *current_iterator << std::endl;  // ОПАСНО!
    
    // Но указатель на элемент может остаться валидным
    std::cout << "Значение через указатель: " << *element_pointer << std::endl;

    // Создание нового итератора
    auto new_iterator = std::next(deque_data.cbegin(), 3);
    std::cout << "Новый итератор на позиции 3: " << *new_iterator << std::endl;
    
    // Вставка элемента в середину
    std::cout << "Вставляем элемент в середину..." << std::endl;
    deque_data.insert(new_iterator, 42);
    
    // ========================================================================
    // ВАЖНО: ИТЕРАТОРЫ И УКАЗАТЕЛИ МОГУТ СТАТЬ НЕВАЛИДНЫМИ
    // ========================================================================
    std::cout << "ВНИМАНИЕ: После insert() итераторы и указатели могут стать невалидными!" << std::endl;
    std::cout << "Попытка использовать итератор: " << *new_iterator << std::endl;
    std::cout << "Попытка использовать указатель: " << *element_pointer << std::endl;

    // Вывод всех элементов
    std::cout << "Все элементы deque: ";
    for (auto& element : deque_data) {
        std::cout << element << ' ';
    }
    std::cout << std::endl;
}

/**
 * Основная функция - демонстрация std::deque
 * Показывает внутреннюю структуру deque и работу с итераторами
 */
int main() {
    std::cout << "=== ДЕМОНСТРАЦИЯ STD::DEQUE ===" << std::endl;

    // Тест 1: Внутренняя структура deque
    testMemoryStructure();
    
    // Тест 2: Операции с итераторами (закомментирован для демонстрации)
    // testIteratorOperations();

    std::cout << "\n=== ДЕМОНСТРАЦИЯ ЗАВЕРШЕНА ===" << std::endl;
    return 0;
}