
#include <iostream>     // std::cin, std::cout
#include <iterator>     // std::istream_iterator, std::ostream_iterator
#include <vector>       // std::vector

/**
 * Основная функция - демонстрация потоковых итераторов
 * Показывает использование istream_iterator для ввода и ostream_iterator для вывода
 */
int main() {
    std::cout << "=== ДЕМОНСТРАЦИЯ ПОТОКОВЫХ ИТЕРАТОРОВ ===" << std::endl;

    // ========================================================================
    // ДЕМОНСТРАЦИЯ 1: ВВОД ДВУХ ЗНАЧЕНИЙ С ПОМОЩЬЮ ISTREAM_ITERATOR
    // ========================================================================
    double first_value, second_value;
    std::cout << "1. Введите два значения: ";

    // Создание итераторов для чтения из потока ввода
    std::istream_iterator<double> end_of_stream_iterator;  // Итератор конца потока
    std::istream_iterator<double> input_stream_iterator(std::cin);  // Итератор для чтения из stdin

    // Чтение первого значения
    if (input_stream_iterator != end_of_stream_iterator) {
        first_value = *input_stream_iterator;
    }

    // Переход к следующему значению
    ++input_stream_iterator;
    if (input_stream_iterator != end_of_stream_iterator) {
        second_value = *input_stream_iterator;
    }

    // Вывод результата умножения
    std::cout << "   Результат: " << first_value << " * " << second_value 
              << " = " << (first_value * second_value) << std::endl;

    
    // ========================================================================
    // ДЕМОНСТРАЦИЯ 2: ВВОД МНОЖЕСТВА ЗНАЧЕНИЙ И КОНСТРУКТОР ВЕКТОРА
    // ========================================================================
    std::cout << "2. Введите множество значений (завершите ввод Ctrl+D или Ctrl+Z): ";
    
    // Переход к следующему значению в потоке (если есть)
    ++input_stream_iterator;
    
    // ========================================================================
    // АЛЬТЕРНАТИВНЫЕ СПОСОБЫ ВВОДА (ЗАКОММЕНТИРОВАНЫ)
    // ========================================================================
    // Способ 1: Использование insert_iterator
    // std::vector<double> numbers_vector;
    // std::insert_iterator<std::vector<double>> insert_iterator(numbers_vector, numbers_vector.begin());
    // std::copy(input_stream_iterator, end_of_stream_iterator, insert_iterator);
    
    // Способ 2: Ручной ввод в цикле
    // std::vector<double> numbers_vector;
    // while (input_stream_iterator != end_of_stream_iterator) {
    //     numbers_vector.push_back(*input_stream_iterator);
    //     ++input_stream_iterator;
    // }
    
    // Способ 3: Конструктор вектора с итераторами (используется)
    std::vector<double> numbers_vector(input_stream_iterator, 
                                        end_of_stream_iterator);

    // ========================================================================
    // ДЕМОНСТРАЦИЯ 3: ВЫВОД С ПОМОЩЬЮ OSTREAM_ITERATOR
    // ========================================================================
    std::cout << "3. Вывод значений с помощью ostream_iterator:" << std::endl;
    std::cout << "   Введенные значения: ";
    
    // Создание итератора для вывода в поток
    std::ostream_iterator<double> output_stream_iterator(std::cout, " ");
    
    // Копирование элементов вектора в поток вывода
    std::copy(numbers_vector.begin(), 
    numbers_vector.end(), 
    output_stream_iterator);
    
    std::cout << std::endl;
    
    // ========================================================================
    // АЛЬТЕРНАТИВНЫЙ СПОСОБ ВЫВОДА (ЗАКОММЕНТИРОВАН)
    // ========================================================================
    // Ручной вывод с помощью range-based for loop
    // std::cout << "   Альтернативный вывод: ";
    // for (auto value : numbers_vector) {
    //     std::cout << " " << value;
    // }
    // std::cout << std::endl;

    std::cout << "\n=== ДЕМОНСТРАЦИЯ ЗАВЕРШЕНА ===" << std::endl;
    return 0;
}