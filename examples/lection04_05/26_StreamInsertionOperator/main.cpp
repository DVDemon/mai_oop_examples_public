#include <iostream>
#include "point.h"

int main() {
    // ДЕМОНСТРАЦИЯ ПЕРЕГРУЗКИ ОПЕРАТОРА ПОТОКОВОГО ВЫВОДА (operator<<)
    
    std::cout << "=== Демонстрация перегрузки оператора << ===" << std::endl;
    
    // Создание объектов Point
    Point first_point(10, 20);
    Point second_point(3, 4);
    
    std::cout << "--- Создание точек ---" << std::endl;
    std::cout << "First point: ";
    first_point.print_info();
    
    std::cout << "Second point: ";
    second_point.print_info();
    
    std::cout << "\n--- Демонстрация оператора << ---" << std::endl;
    
    // ДЕМОНСТРАЦИЯ 1: Использование оператора << для вывода точки
    std::cout << "Using operator<< to output first point:" << std::endl;
    std::cout << first_point << std::endl;
    
    // ДЕМОНСТРАЦИЯ 2: Вывод нескольких точек в одной строке
    std::cout << "Outputting both points:" << std::endl;
    ((std::cout << "Point 1: ") << first_point) << ", Point 2: " << second_point << std::endl;
    
    // ДЕМОНСТРАЦИЯ 3: Цепочка операторов << (chaining)
    // ВАЖНО: оператор возвращает ссылку на поток, что позволяет цепочку
    std::cout << "\n--- Демонстрация цепочки операторов << ---" << std::endl;
    std::cout << "Chaining operators: ";
    ((std::cout << first_point) << " and ") << second_point << std::endl;
    
    // ДЕМОНСТРАЦИЯ 4: Использование в условных выражениях
    std::cout << "\n--- Использование в выражениях ---" << std::endl;
    std::cout << "Points comparison: " << first_point << " vs " << second_point << std::endl;
    
    // ДЕМОНСТРАЦИЯ 5: Вывод с дополнительным форматированием
    std::cout << "\n--- Форматированный вывод ---" << std::endl;
    std::cout << "Coordinates: X=" << first_point << " (first), Y=" << second_point << " (second)" << std::endl;
    
    // ПРИМЕР ЗАКОММЕНТИРОВАННОГО КОДА - неправильный синтаксис:
    // first_point << std::cout << second_point;  // ОШИБКА! Неестественный порядок
    
    std::cout << "\n=== Важные выводы ===" << std::endl;
    std::cout << "1. Оператор << перегружается как friend функция" << std::endl;
    std::cout << "2. Синтаксис: std::ostream& operator<<(std::ostream& os, const ClassType& obj)" << std::endl;
    std::cout << "3. Friend функция имеет доступ к приватным членам класса" << std::endl;
    std::cout << "4. Возврат ссылки на поток позволяет цепочку операторов" << std::endl;
    std::cout << "5. Естественный синтаксис: cout << object (а не object << cout)" << std::endl;
    
    std::cout << "\n=== Преимущества friend функции для operator<< ===" << std::endl;
    std::cout << "1. Естественный синтаксис - cout << object" << std::endl;
    std::cout << "2. Возможность цепочки операторов" << std::endl;
    std::cout << "3. Доступ к приватным членам без геттеров" << std::endl;
    std::cout << "4. Совместимость с STL и стандартными потоками" << std::endl;
    std::cout << "5. Возможность вывода в любые потоки (cout, файлы, строки)" << std::endl;
    
    std::cout << "\n=== Программа завершается ===" << std::endl;
    
    return 0;
}