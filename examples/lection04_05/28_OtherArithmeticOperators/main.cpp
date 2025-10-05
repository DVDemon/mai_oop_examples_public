#include <iostream>
#include "point.h"

int main() {
    // ДЕМОНСТРАЦИЯ ПЕРЕГРУЗКИ АРИФМЕТИЧЕСКИХ ОПЕРАТОРОВ (+ и -)
    
    std::cout << "=== Демонстрация арифметических операторов для точек ===" << std::endl;
    
    // ДЕМОНСТРАЦИЯ 1: Арифметические операции с временными объектами
    std::cout << "--- Операции с временными объектами ---" << std::endl;
    
    // ВЫЧИТАНИЕ: Point(20,20) - Point(10,10) = Point(10,10)
    std::cout << "Point(20,20) - Point(10,10) = " << (Point(20,20) - Point(10,10)) << std::endl;
    
    // СЛОЖЕНИЕ: Point(20,20) + Point(10,10) = Point(30,30)
    std::cout << "Point(20,20) + Point(10,10) = " << (Point(20,20) + Point(10,10)) << std::endl;
    
    std::cout << "\n--- Работа с именованными объектами ---" << std::endl;
    
    // ДЕМОНСТРАЦИЯ 2: Создание именованных объектов
    Point first_point(10, 10);
    Point second_point(20, 20);
    
    // ДЕМОНСТРАЦИЯ 3: Использование арифметических операторов с именованными объектами
    // СЛОЖЕНИЕ: first_point + second_point = Point(30, 30)
    Point sum_result{first_point + second_point};
    
    // ВЫЧИТАНИЕ: second_point - Point(5,5) = Point(15, 15)
    Point difference_result{second_point - Point(5, 5)};
    
    std::cout << "First point: " << first_point << std::endl;      // Point(10, 10)
    std::cout << "Second point: " << second_point << std::endl;    // Point(20, 20)
    std::cout << "Sum result: " << sum_result << std::endl;        // Point(30, 30)
    std::cout << "Difference result: " << difference_result << std::endl; // Point(15, 15)
    
    std::cout << "\n--- Дополнительные примеры арифметических операций ---" << std::endl;
    
    // ДЕМОНСТРАЦИЯ 4: Цепочка операций
    Point complex_result = Point(100, 50) - Point(25, 10) + Point(5, 5);
    std::cout << "Complex operation: Point(100,50) - Point(25,10) + Point(5,5) = " 
              << complex_result << std::endl; // Point(80, 45)
    
    // ДЕМОНСТРАЦИЯ 5: Использование в выражениях
    Point origin(0, 0);
    Point vector_from_origin = Point(15, 20) - origin;
    std::cout << "Vector from origin: Point(15,20) - Point(0,0) = " 
              << vector_from_origin << std::endl; // Point(15, 20)
    
    // ДЕМОНСТРАЦИЯ 6: Работа с массивом точек
    std::cout << "\n--- Работа с массивом точек ---" << std::endl;
    const int NUM_POINTS = 3;
    Point points_array[NUM_POINTS] = {
        Point(1, 1),
        Point(2, 2), 
        Point(3, 3)
    };
    
    Point array_sum(0, 0);
    for (int i = 0; i < NUM_POINTS; ++i) {
        std::cout << "Point " << (i + 1) << ": " << points_array[i] << std::endl;
        array_sum = array_sum + points_array[i];  // Накопительное сложение
    }
    std::cout << "Sum of all points: " << array_sum << std::endl; // Point(6, 6)
    
    std::cout << "\n=== Важные выводы ===" << std::endl;
    std::cout << "1. Арифметические операторы перегружаются как friend функции" << std::endl;
    std::cout << "2. Синтаксис: ReturnType operator+(const ClassType& left, const ClassType& right)" << std::endl;
    std::cout << "3. Оба операнда const - операторы НЕ изменяют исходные объекты" << std::endl;
    std::cout << "4. Возвращается НОВЫЙ объект - арифметические операции создают новые значения" << std::endl;
    std::cout << "5. Friend функция имеет доступ к приватным членам класса" << std::endl;
    
    std::cout << "\n=== Преимущества friend функций для арифметических операторов ===" << std::endl;
    std::cout << "1. Симметрия операций - оба операнда равноправны" << std::endl;
    std::cout << "2. Возможность неявных преобразований для первого операнда" << std::endl;
    std::cout << "3. Естественный синтаксис - obj1 + obj2" << std::endl;
    std::cout << "4. Совместимость с математическими ожиданиями" << std::endl;
    std::cout << "5. Возможность цепочки операций" << std::endl;
    
    std::cout << "\n=== Особенности арифметических операторов ===" << std::endl;
    std::cout << "1. НЕ изменяют исходные объекты (в отличие от +=, -=)" << std::endl;
    std::cout << "2. Возвращают новый объект с результатом операции" << std::endl;
    std::cout << "3. Могут использоваться в выражениях и присваиваниях" << std::endl;
    std::cout << "4. Поддерживают цепочку операций" << std::endl;
    std::cout << "5. Оба операнда передаются по const ссылке для эффективности" << std::endl;
    
    std::cout << "\n=== Математическая интерпретация ===" << std::endl;
    std::cout << "1. Сложение точек: (x1,y1) + (x2,y2) = (x1+x2, y1+y2)" << std::endl;
    std::cout << "2. Вычитание точек: (x1,y1) - (x2,y2) = (x1-x2, y1-y2)" << std::endl;
    std::cout << "3. Геометрический смысл: операции с векторами в 2D пространстве" << std::endl;
    std::cout << "4. Применение: компьютерная графика, физика, геометрия" << std::endl;
    
    std::cout << "\n=== Программа завершается ===" << std::endl;
    
    return 0;
}