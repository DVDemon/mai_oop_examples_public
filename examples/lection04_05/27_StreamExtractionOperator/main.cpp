#include <iostream>
#include "point.h"

int main() {
    // ДЕМОНСТРАЦИЯ ПЕРЕГРУЗКИ ОПЕРАТОРА ПОТОКОВОГО ВВОДА (operator>>)
    
    std::cout << "=== Демонстрация перегрузки оператора >> ===" << std::endl;
    
    // Создание объекта Point с координатами по умолчанию (0, 0)
    Point input_point;
    
    std::cout << "--- Исходное состояние точки ---" << std::endl;
    std::cout << "Initial point: " << input_point << std::endl;
    
    std::cout << "\n--- Ввод координат через оператор >> ---" << std::endl;
    
    // ДЕМОНСТРАЦИЯ 1: Использование оператора >> для ввода координат
    // ВАЖНО: оператор >> изменяет объект, поэтому параметр НЕ const
    std::cin >> input_point;
    
    std::cout << "\n--- Состояние точки после ввода ---" << std::endl;
    std::cout << "Point after input: " << input_point << std::endl;
    
    std::cout << "\n--- Дополнительные примеры использования ---" << std::endl;
    
    // ДЕМОНСТРАЦИЯ 2: Создание нескольких точек с вводом
    std::cout << "Creating another point..." << std::endl;
    Point second_point;
    std::cin >> second_point;
    
    std::cout << "Second point: " << second_point << std::endl;
    
    // ДЕМОНСТРАЦИЯ 3: Сравнение введенных точек
    std::cout << "\n--- Сравнение точек ---" << std::endl;
    std::cout << "First point: " << input_point << std::endl;
    std::cout << "Second point: " << second_point << std::endl;
    
    // ДЕМОНСТРАЦИЯ 4: Использование в циклах
    std::cout << "\n--- Ввод массива точек ---" << std::endl;
    const int NUM_POINTS = 3;
    Point points_array[NUM_POINTS];
    
    std::cout << "Enter " << NUM_POINTS << " points:" << std::endl;
    for (int i = 0; i < NUM_POINTS; ++i) {
        std::cout << "Point " << (i + 1) << ": ";
        std::cin >> points_array[i];
    }
    
    std::cout << "\nEntered points:" << std::endl;
    for (int i = 0; i < NUM_POINTS; ++i) {
        std::cout << "Point " << (i + 1) << ": " << points_array[i] << std::endl;
    }
    
    std::cout << "\n=== Важные выводы ===" << std::endl;
    std::cout << "1. Оператор >> перегружается как friend функция" << std::endl;
    std::cout << "2. Синтаксис: std::istream& operator>>(std::istream& is, ClassType& obj)" << std::endl;
    std::cout << "3. Параметр объекта НЕ const, так как мы изменяем объект" << std::endl;
    std::cout << "4. Friend функция имеет доступ к приватным членам класса" << std::endl;
    std::cout << "5. Возврат ссылки на поток позволяет цепочку операторов" << std::endl;
    
    std::cout << "\n=== Преимущества friend функции для operator>> ===" << std::endl;
    std::cout << "1. Естественный синтаксис - cin >> object" << std::endl;
    std::cout << "2. Возможность цепочки операторов" << std::endl;
    std::cout << "3. Доступ к приватным членам без сеттеров" << std::endl;
    std::cout << "4. Совместимость с STL и стандартными потоками" << std::endl;
    std::cout << "5. Возможность ввода из любых потоков (cin, файлы, строки)" << std::endl;
    
    std::cout << "\n=== Особенности оператора >> ===" << std::endl;
    std::cout << "1. Автоматически пропускает пробелы и разделители" << std::endl;
    std::cout << "2. Может обрабатывать ошибки ввода" << std::endl;
    std::cout << "3. Поддерживает различные форматы данных" << std::endl;
    std::cout << "4. Интегрируется с другими потоковыми операциями" << std::endl;
    
    std::cout << "\n=== Программа завершается ===" << std::endl;
    
    return 0;
}