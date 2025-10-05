#include <iostream>
#include "point.h"

int main() {
    // ДЕМОНСТРАЦИЯ ПЕРЕГРУЗКИ ОПЕРАТОРА [] ДЛЯ ЧТЕНИЯ
    
    std::cout << "=== Демонстрация перегрузки оператора [] для чтения ===" << std::endl;
    
    // Создание объекта Point
    Point point_object(10, 20);
    
    std::cout << "--- Создание точки ---" << std::endl;
    std::cout << "Point object: ";
    point_object.print_info();
    
    std::cout << "\n--- Доступ к координатам через оператор [] ---" << std::endl;
    
    // ДЕМОНСТРАЦИЯ 1: Инфиксная запись (естественная)
    // Синтаксис: object[index]
    // ПРИМЕР ЗАКОММЕНТИРОВАННОГО КОДА - инфиксная запись:
    // std::cout << "p1.x: " << p1[0] << std::endl;  // x coordinate: 10
    
    // ДЕМОНСТРАЦИЯ 2: Явный вызов оператора
    // Синтаксис: object.operator[](index)
    std::cout << "point_object[0] (X coordinate): " << point_object.operator[](0) << std::endl;
    
    // ДЕМОНСТРАЦИЯ 3: Инфиксная запись для Y координаты
    std::cout << "point_object[1] (Y coordinate): " << point_object[1] << std::endl;
    
    std::cout << "\n--- Дополнительные примеры использования ---" << std::endl;
    
    // ДЕМОНСТРАЦИЯ 4: Использование в выражениях
    double x_coordinate = point_object[0];
    double y_coordinate = point_object[1];
    std::cout << "X coordinate extracted: " << x_coordinate << std::endl;
    std::cout << "Y coordinate extracted: " << y_coordinate << std::endl;
    
    // ДЕМОНСТРАЦИЯ 5: Использование в вычислениях
    double sum_of_coordinates = point_object[0] + point_object[1];
    std::cout << "Sum of coordinates: " << sum_of_coordinates << std::endl;
    
    std::cout << "\n=== Важные выводы ===" << std::endl;
    std::cout << "1. Оператор [] перегружается как const метод для чтения" << std::endl;
    std::cout << "2. Синтаксис: object[index] эквивалентен object.operator[](index)" << std::endl;
    std::cout << "3. Const метод НЕ МОЖЕТ изменять объект, только читать" << std::endl;
    std::cout << "4. Assert проверяет корректность индекса" << std::endl;
    std::cout << "5. Индекс 0 = X координата, индекс 1 = Y координата" << std::endl;
    
    std::cout << "\n=== Преимущества оператора [] ===" << std::endl;
    std::cout << "1. Естественный синтаксис доступа к элементам" << std::endl;
    std::cout << "2. Возможность использования в циклах и алгоритмах" << std::endl;
    std::cout << "3. Унифицированный интерфейс для контейнеров" << std::endl;
    std::cout << "4. Проверка корректности индекса через assert" << std::endl;
    
    std::cout << "\n=== Программа завершается ===" << std::endl;
    
    return 0;
}