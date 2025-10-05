#include <iostream>
#include "point.h"

int main() {
    // ДЕМОНСТРАЦИЯ ПЕРЕГРУЗКИ ОПЕРАТОРА + КАК МЕТОДА КЛАССА
    
    std::cout << "=== Демонстрация перегрузки оператора + как метода класса ===" << std::endl;
    
    // Создание объектов Point
    Point first_point(10, 10);
    Point second_point(20, 20);
    
    std::cout << "--- Создание точек ---" << std::endl;
    std::cout << "First point: ";
    first_point.print_info();
    std::cout << "Second point: ";
    second_point.print_info();
    
    std::cout << "\n--- Сложение точек с помощью перегруженного оператора + ---" << std::endl;
    
    // ДЕМОНСТРАЦИЯ 1: Сложение двух существующих объектов
    // Синтаксис: point1 + point2
    // Эквивалентно: point1.operator+(point2)
    Point result_point{first_point + second_point};
    
    std::cout << "Результат сложения first_point + second_point:" << std::endl;
    result_point.print_info();
    
    // ДЕМОНСТРАЦИЯ 2: Сложение с временным объектом
    // Создается временный объект Point(5, 5) и складывается с second_point
    Point another_result{second_point + Point(5, 5)};
    
    std::cout << "Результат сложения second_point + Point(5, 5):" << std::endl;
    another_result.print_info();
    
    // ДЕМОНСТРАЦИЯ 3: Сложение временных объектов
    // Создаются два временных объекта и складываются
    std::cout << "Результат сложения временных объектов Point(20,20) + Point(10,10):" << std::endl;
    (Point(20, 20) + Point(10, 10)).print_info();
    
    std::cout << "\n=== Важные выводы ===" << std::endl;
    std::cout << "1. Оператор + перегружается как метод класса" << std::endl;
    std::cout << "2. Синтаксис: point1 + point2 эквивалентен point1.operator+(point2)" << std::endl;
    std::cout << "3. Метод вызывается для левого операнда (this)" << std::endl;
    std::cout << "4. Правый операнд передается как параметр" << std::endl;
    std::cout << "5. Возвращается новый объект (не изменяются исходные объекты)" << std::endl;
    
    return 0;
}