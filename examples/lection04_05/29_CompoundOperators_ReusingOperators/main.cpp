#include <iostream>
#include "point.h"

int main() {
    // ДЕМОНСТРАЦИЯ СОСТАВНЫХ ОПЕРАТОРОВ И ПЕРЕИСПОЛЬЗОВАНИЯ ОПЕРАТОРОВ
    
    std::cout << "=== Демонстрация составных операторов и переиспользования ===" << std::endl;
    
    // Создание объектов Point для демонстрации
    Point first_point(10, 10);
    Point second_point(20, 20);
    Point third_point(5, 5);
    
    std::cout << "--- Исходные точки ---" << std::endl;
    std::cout << "First point: " << first_point << std::endl;   // Point(10, 10)
    std::cout << "Second point: " << second_point << std::endl; // Point(20, 20)
    std::cout << "Third point: " << third_point << std::endl;   // Point(5, 5)
    
    std::cout << "\n--- Демонстрация арифметических операторов (переиспользуют составные) ---" << std::endl;
    
    // ДЕМОНСТРАЦИЯ 1: Арифметические операторы создают новые объекты
    // ВАЖНО: арифметические операторы (+, -) реализованы через составные операторы (+=, -=)
    std::cout << "first_point + second_point: " << (first_point + second_point) << std::endl; // Point(30, 30)
    std::cout << "second_point - third_point: " << (second_point - third_point) << std::endl; // Point(15, 15)
    
    std::cout << "\n--- Проверка, что исходные объекты не изменились ---" << std::endl;
    std::cout << "First point (не изменился): " << first_point << std::endl;   // Point(10, 10)
    std::cout << "Second point (не изменился): " << second_point << std::endl; // Point(20, 20)
    std::cout << "Third point (не изменился): " << third_point << std::endl;   // Point(5, 5)
    
    std::cout << "\n--- Демонстрация составных операторов (изменяют объекты) ---" << std::endl;
    
    // ДЕМОНСТРАЦИЯ 2: Составные операторы изменяют левый операнд
    // ВАЖНО: составные операторы (+=, -=) изменяют исходный объект
    std::cout << "До first_point += second_point:" << std::endl;
    std::cout << "First point: " << first_point << std::endl;   // Point(10, 10)
    
    first_point += second_point;  // Изменяем first_point
    
    std::cout << "После first_point += second_point:" << std::endl;
    std::cout << "First point (изменился): " << first_point << std::endl; // Point(30, 30)
    std::cout << "Second point (не изменился): " << second_point << std::endl; // Point(20, 20)
    
    std::cout << "\n--- Демонстрация второго составного оператора ---" << std::endl;
    std::cout << "До second_point -= third_point:" << std::endl;
    std::cout << "Second point: " << second_point << std::endl; // Point(20, 20)
    
    second_point -= third_point;  // Изменяем second_point
    
    std::cout << "После second_point -= third_point:" << std::endl;
    std::cout << "Second point (изменился): " << second_point << std::endl; // Point(15, 15)
    std::cout << "Third point (не изменился): " << third_point << std::endl; // Point(5, 5)
    
    std::cout << "\n--- Дополнительные примеры использования ---" << std::endl;
    
    // ДЕМОНСТРАЦИЯ 3: Цепочка составных операторов
    Point chain_point(100, 100);
    std::cout << "Исходная chain_point: " << chain_point << std::endl; // Point(100, 100)
    
    chain_point += (Point(10, 20) -= Point(5, 5));  // Цепочка составных операторов
    std::cout << "После цепочки: " << chain_point << std::endl; // Point(105, 115)
    
    // ДЕМОНСТРАЦИЯ 4: Сравнение арифметических и составных операторов
    Point arithmetic_result = first_point + second_point;  // Новый объект
    std::cout << "Результат арифметического сложения: " << arithmetic_result << std::endl; // Point(45, 45)
    std::cout << "first_point остался: " << first_point << std::endl; // Point(30, 30)
    
    Point compound_result = first_point;
    compound_result += second_point;  // Изменяем compound_result
    std::cout << "Результат составного сложения: " << compound_result << std::endl; // Point(45, 45)
    std::cout << "first_point остался: " << first_point << std::endl; // Point(30, 30)
    
    std::cout << "\n=== Важные выводы ===" << std::endl;
    std::cout << "1. Составные операторы (+=, -=) изменяют левый операнд" << std::endl;
    std::cout << "2. Арифметические операторы (+, -) создают новые объекты" << std::endl;
    std::cout << "3. Арифметические операторы переиспользуют составные операторы" << std::endl;
    std::cout << "4. Составные операторы возвращают ссылку на измененный объект" << std::endl;
    std::cout << "5. Арифметические операторы возвращают новый объект" << std::endl;
    
    std::cout << "\n=== Паттерн переиспользования операторов ===" << std::endl;
    std::cout << "1. Сначала реализуем составные операторы (+=, -=)" << std::endl;
    std::cout << "2. Затем реализуем арифметические операторы через составные" << std::endl;
    std::cout << "3. Это обеспечивает единообразие и избегает дублирования кода" << std::endl;
    std::cout << "4. Изменения в логике нужно делать только в составных операторах" << std::endl;
    
    std::cout << "\n=== Синтаксис операторов ===" << std::endl;
    std::cout << "Составные операторы: ClassType& operator+=(ClassType& left, const ClassType& right)" << std::endl;
    std::cout << "Арифметические операторы: ClassType operator+(const ClassType& left, const ClassType& right)" << std::endl;
    
    std::cout << "\n=== Преимущества переиспользования ===" << std::endl;
    std::cout << "1. Единообразие логики - изменения в одном месте" << std::endl;
    std::cout << "2. Меньше дублирования кода" << std::endl;
    std::cout << "3. Легче поддерживать и отлаживать" << std::endl;
    std::cout << "4. Соответствие принципу DRY (Don't Repeat Yourself)" << std::endl;
    
    std::cout << "\n=== Программа завершается ===" << std::endl;
    
    return 0;
}