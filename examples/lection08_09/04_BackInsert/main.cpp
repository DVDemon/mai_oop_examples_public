#include <iostream>     // std::cout
#include <iterator>     // std::back_insert_iterator
#include <vector>       // std::vector
// #include <algorithm>    // std::copy (альтернатива стандартной функции)

/**
 * Пользовательская реализация алгоритма копирования
 * Демонстрирует работу с итераторами ввода и вывода
 * 
 * @tparam InputIterator - тип итератора ввода
 * @tparam OutputIterator - тип итератора вывода
 * @param first - начало диапазона для копирования
 * @param last - конец диапазона для копирования
 * @param result - итератор вывода для записи элементов
 * @return итератор, указывающий за последний скопированный элемент
 */
template<class InputIterator, class OutputIterator>
OutputIterator my_copy(InputIterator first, InputIterator last, 
                      OutputIterator result) {
    while (first != last) {
        *result = *first;  // Копируем элемент
        ++result;          // Переходим к следующей позиции вывода
        ++first;           // Переходим к следующему элементу ввода
    }
    return result;
}

/**
 * Основная функция - демонстрация back_insert_iterator
 * Показывает безопасное копирование элементов в контейнер с автоматическим расширением
 */
int main() {
    std::cout << "=== ДЕМОНСТРАЦИЯ BACK_INSERT_ITERATOR ===" << std::endl;

    // ========================================================================
    // СОЗДАНИЕ И ИНИЦИАЛИЗАЦИЯ КОНТЕЙНЕРОВ
    // ========================================================================
    std::vector<int> destination_vector;  // Пустой вектор-получатель
    std::vector<int> source_vector;      // Вектор-источник данных

    // Заполнение исходного вектора значениями
    for (int element_index = 1; element_index <= 5; ++element_index) {
        source_vector.push_back(element_index * 10);
    }

    // ========================================================================
    // ДЕМОНСТРАЦИЯ: ИСПОЛЬЗОВАНИЕ BACK_INSERT_ITERATOR
    // ========================================================================
    std::cout << "1. Создание back_insert_iterator для безопасного копирования:" << std::endl;
    std::back_insert_iterator<std::vector<int>> back_insert_iterator(destination_vector);
    
    std::cout << "2. Копирование элементов с помощью пользовательской функции my_copy:" << std::endl;
    my_copy(source_vector.begin(), source_vector.end(), back_insert_iterator);

    // ========================================================================
    // АЛЬТЕРНАТИВНЫЕ СПОСОБЫ (ЗАКОММЕНТИРОВАНЫ)
    // ========================================================================
    // Способ 1: Предварительное изменение размера (может быть неэффективным)
    // destination_vector.resize(10);
    
    // Способ 2: Использование стандартной функции std::copy (может быть небезопасным)
    // std::copy(source_vector.begin(), source_vector.end(), destination_vector.begin()); // ОПАСНО!
    
    // Способ 3: Использование std::back_inserter (рекомендуется)
    // std::copy(source_vector.begin(), source_vector.end(), std::back_inserter(destination_vector));

    // ========================================================================
    // ВЫВОД РЕЗУЛЬТАТОВ
    // ========================================================================
    std::cout << "3. Результат копирования:" << std::endl;
    std::cout << "destination_vector:";
    for (auto element : destination_vector) {
        std::cout << ' ' << element;
    }
    std::cout << std::endl;

    std::cout << "\n=== ДЕМОНСТРАЦИЯ ЗАВЕРШЕНА ===" << std::endl;
    return 0;
}