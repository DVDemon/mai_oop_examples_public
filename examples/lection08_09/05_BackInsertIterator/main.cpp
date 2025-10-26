#include <iostream>
#include <iterator>
#include <vector>

/**
 * Пользовательская реализация back_insert_iterator
 * Демонстрирует создание итератора вывода для безопасного добавления элементов в контейнер
 * 
 * @tparam Container - тип контейнера, в который будут добавляться элементы
 */
template <class Container>
class back_insert_iterator {
protected:
    Container* container_pointer;  // Указатель на контейнер

public:
    typedef Container container_type;  // Тип контейнера для совместимости
    
    /**
     * Конструктор итератора
     * @param container - ссылка на контейнер, в который будут добавляться элементы
     */
    explicit back_insert_iterator(Container& container) : container_pointer(&container) {}
    
    /**
     * Оператор присваивания для копирования значения
     * Добавляет элемент в конец контейнера через push_back()
     * 
     * @param value - значение для добавления в контейнер
     * @return ссылка на итератор для цепочки операций
     */
    back_insert_iterator<Container>& 
    operator=(const typename Container::value_type& value) {
        container_pointer->push_back(value);
        return *this;
    }
    
    /**
     * Оператор присваивания для перемещения значения
     * Эффективно перемещает элемент в конец контейнера
     * 
     * @param value - rvalue для перемещения в контейнер
     * @return ссылка на итератор для цепочки операций
     */
    back_insert_iterator<Container>& 
    operator=(typename Container::value_type&& value) {
        container_pointer->push_back(std::move(value));
        return *this;
    }
    
    /**
     * Оператор разыменования
     * Возвращает сам итератор для поддержки синтаксиса *it = value
     * 
     * @return ссылка на итератор
     */
    back_insert_iterator<Container>& operator*() {
        return *this;
    }
    
    /**
     * Префиксный оператор инкремента
     * Для back_insert_iterator не изменяет позицию, возвращает сам итератор
     * 
     * @return ссылка на итератор
     */
    back_insert_iterator<Container>& operator++() {
        return *this;
    }
    
    /**
     * Постфиксный оператор инкремента
     * Для back_insert_iterator не изменяет позицию, возвращает копию итератора
     * 
     * @return копия итератора
     */
    back_insert_iterator<Container> operator++(int) {
        return *this;
    }
};

/**
 * Основная функция - демонстрация пользовательского back_insert_iterator
 * Показывает создание и использование итератора вывода для безопасного добавления элементов
 */
int main(int argc, char** argv) {
    std::cout << "=== ДЕМОНСТРАЦИЯ ПОЛЬЗОВАТЕЛЬСКОГО BACK_INSERT_ITERATOR ===" << std::endl;

    // ========================================================================
    // СОЗДАНИЕ И ИНИЦИАЛИЗАЦИЯ ДАННЫХ
    // ========================================================================
    std::vector<int> destination_container;  // Пустой контейнер-получатель
    int source_array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};  // Массив-источник данных
    
    std::cout << "1. Исходные данные:" << std::endl;
    std::cout << "   Массив-источник: ";
    for (int element : source_array) {
        std::cout << element << " ";
    }
    std::cout << std::endl;
    std::cout << "   Контейнер-получатель (пустой): размер = " << destination_container.size() << std::endl;

    // ========================================================================
    // ДЕМОНСТРАЦИЯ: СОЗДАНИЕ И ИСПОЛЬЗОВАНИЕ BACK_INSERT_ITERATOR
    // ========================================================================
    std::cout << "2. Создание back_insert_iterator:" << std::endl;
    back_insert_iterator<std::vector<int>> back_insert_iterator(destination_container);
    
    std::cout << "3. Копирование элементов с помощью пользовательского итератора:" << std::endl;
    for (int source_element : source_array) {
        back_insert_iterator = source_element;  // Используем оператор присваивания
    }

    // ========================================================================
    // ВЫВОД РЕЗУЛЬТАТОВ
    // ========================================================================
    std::cout << "4. Результат копирования:" << std::endl;
    std::cout << "   Контейнер-получатель: размер = " << destination_container.size() << std::endl;
    std::cout << "   Элементы: ";
    for (int destination_element : destination_container) {
        std::cout << destination_element << " ";
    }
    std::cout << std::endl;

    std::cout << "\n=== ДЕМОНСТРАЦИЯ ЗАВЕРШЕНА ===" << std::endl;
    return 0;
}

