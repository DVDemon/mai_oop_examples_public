#include <iostream>
#include "point.h"

int main() {
    // ДЕМОНСТРАЦИЯ ПЕРЕГРУЗКИ ОПЕРАТОРА [] ДЛЯ ЧТЕНИЯ И ЗАПИСИ
    
    std::cout << "=== Демонстрация перегрузки оператора [] для чтения и записи ===" << std::endl;
    
    // Создание объекта Point
    Point point_object(10, 20);
    
    std::cout << "--- Исходное состояние точки ---" << std::endl;
    std::cout << "Initial point: ";
    point_object.print_info();
    
    std::cout << "\n--- Демонстрация чтения через оператор [] ---" << std::endl;
    
    // ДЕМОНСТРАЦИЯ 1: Чтение значений через оператор []
    double x_coordinate = point_object[0];
    double y_coordinate = point_object[1];
    
    std::cout << "Reading X coordinate: point_object[0] = " << x_coordinate << std::endl;
    std::cout << "Reading Y coordinate: point_object[1] = " << y_coordinate << std::endl;
    
    std::cout << "\n--- Демонстрация записи через оператор [] ---" << std::endl;
    
    // ДЕМОНСТРАЦИЯ 2: Изменение данных через оператор []
    // ВАЖНО: оператор возвращает ссылку, что позволяет изменять значения
    std::cout << "Changing X coordinate: point_object[0] = 35.6" << std::endl;
    point_object[0] = 35.6;
    
    std::cout << "Changing Y coordinate: point_object[1] = 23.9" << std::endl;
    point_object[1] = 23.9;
    
    std::cout << "\n--- Состояние точки после изменения ---" << std::endl;
    std::cout << "Modified point: ";
    point_object.print_info();
    
    std::cout << "\n--- Дополнительные примеры использования ---" << std::endl;
    
    // ДЕМОНСТРАЦИЯ 3: Использование в выражениях
    double sum_before = point_object[0] + point_object[1];
    std::cout << "Sum of coordinates before modification: " << sum_before << std::endl;
    
    // ДЕМОНСТРАЦИЯ 4: Инкремент через оператор []
    std::cout << "Incrementing X coordinate by 1..." << std::endl;
    point_object[0] += 1.0;
    
    std::cout << "Incrementing Y coordinate by 2..." << std::endl;
    point_object[1] += 2.0;
    
    std::cout << "Point after increment: ";
    point_object.print_info();
    
    // ДЕМОНСТРАЦИЯ 5: Использование в условных выражениях
    if (point_object[0] > point_object[1]) {
        std::cout << "X coordinate is greater than Y coordinate" << std::endl;
    } else {
        std::cout << "Y coordinate is greater than or equal to X coordinate" << std::endl;
    }
    
    std::cout << "\n=== Важные выводы ===" << std::endl;
    std::cout << "1. Оператор [] возвращает ССЫЛКУ для чтения и записи" << std::endl;
    std::cout << "2. НЕ const метод - МОЖЕТ изменять объект" << std::endl;
    std::cout << "3. Синтаксис: object[index] = value (запись)" << std::endl;
    std::cout << "4. Синтаксис: value = object[index] (чтение)" << std::endl;
    std::cout << "5. Assert проверяет корректность индекса" << std::endl;
    
    std::cout << "\n=== Преимущества оператора [] для записи ===" << std::endl;
    std::cout << "1. Естественный синтаксис изменения элементов" << std::endl;
    std::cout << "2. Возможность использования в выражениях" << std::endl;
    std::cout << "3. Поддержка операторов присваивания (+=, -=, *=, /=)" << std::endl;
    std::cout << "4. Интеграция с алгоритмами STL" << std::endl;
    
    std::cout << "\n=== Программа завершается ===" << std::endl;
    
    return 0;
}