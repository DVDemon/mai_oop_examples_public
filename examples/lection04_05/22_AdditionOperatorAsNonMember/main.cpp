#include <iostream>
#include "point.h"

int main() {
    // ДЕМОНСТРАЦИЯ ПЕРЕГРУЗКИ ОПЕРАТОРА + КАК НЕ-ЧЛЕНА КЛАССА (friend функция)
    
    std::cout << "=== Демонстрация перегрузки оператора + как friend функции ===" << std::endl;
    
    // Создание объектов Point
    Point first_point(10, 10);
    Point second_point(20, 20);
    
    std::cout << "--- Создание точек ---" << std::endl;
    std::cout << "First point: ";
    first_point.print_info();
    std::cout << "Second point: ";
    second_point.print_info();
    
    std::cout << "\n--- Сложение точек с помощью перегруженного оператора + ---" << std::endl;
    
    // ДЕМОНСТРАЦИЯ 1: Явный вызов friend функции
    // Синтаксис: operator+(point1, point2)
    Point result_point{operator+(first_point, second_point)};
    
    std::cout << "Результат сложения operator+(first_point, second_point):" << std::endl;
    result_point.print_info();
    
    // ДЕМОНСТРАЦИЯ 2: Инфиксная запись (естественная)
    // Синтаксис: point1 + point2 (эквивалентно operator+(point1, point2))
    // ПРИМЕР ЗАКОММЕНТИРОВАННОГО КОДА - инфиксная запись:
    // Point result_point{first_point + second_point};  // operator+(first_point, second_point)
    
    // ДЕМОНСТРАЦИЯ 3: Сложение с временным объектом
    Point another_result{second_point + Point(5, 5)};
    
    std::cout << "Результат сложения second_point + Point(5, 5):" << std::endl;
    another_result.print_info();
    
    // ДЕМОНСТРАЦИЯ 4: Сложение временных объектов
    std::cout << "Результат сложения временных объектов Point(20,20) + Point(10,10):" << std::endl;
    (Point(20, 20) + Point(10, 10)).print_info();
    
    std::cout << "\n=== Важные выводы ===" << std::endl;
    std::cout << "1. Оператор + перегружается как friend функция (не-член класса)" << std::endl;
    std::cout << "2. Friend функция имеет доступ к приватным членам класса" << std::endl;
    std::cout << "3. Синтаксис: point1 + point2 эквивалентен operator+(point1, point2)" << std::endl;
    std::cout << "4. Оба операнда передаются как параметры функции" << std::endl;
    std::cout << "5. Возвращается новый объект (не изменяются исходные объекты)" << std::endl;
    
    std::cout << "\n=== Преимущества friend функций ===" << std::endl;
    std::cout << "1. Симметричность - оба операнда обрабатываются одинаково" << std::endl;
    std::cout << "2. Доступ к приватным членам без геттеров" << std::endl;
    std::cout << "3. Возможность перегрузки для смешанных типов" << std::endl;
    std::cout << "4. Естественный синтаксис вызова" << std::endl;
    
    return 0;
}