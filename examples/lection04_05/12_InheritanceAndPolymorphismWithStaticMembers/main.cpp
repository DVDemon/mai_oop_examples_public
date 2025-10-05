#include <iostream>
#include "ellipse.h"

int main() {
    // ДЕМОНСТРАЦИЯ СТАТИЧЕСКИХ ЧЛЕНОВ В НАСЛЕДОВАНИИ И ПОЛИМОРФИЗМЕ
    
    std::cout << "=== Создание объектов Shape ===" << std::endl;
    
    // Создание объектов Shape - увеличивает Shape::m_count
    Shape shape_object1("shape1");
    std::cout << "Shape count: " << Shape::m_count << std::endl;  // 1
    
    Shape shape_object2("shape2");
    std::cout << "Shape count: " << Shape::m_count << std::endl;  // 2
    
    Shape shape_object3;  // Конструктор по умолчанию
    std::cout << "Shape count: " << Shape::m_count << std::endl;  // 3
    
    std::cout << "***********************************************" << std::endl;
    
    std::cout << "=== Создание объекта Ellipse ===" << std::endl;
    
    // Создание объекта Ellipse - увеличивает И Shape::m_count И Ellipse::m_count!
    Ellipse ellipse_object(10, 12, "ellipse1");
    
    std::cout << "Shape count: " << Shape::m_count << std::endl;    // 4 (3 + 1)
    std::cout << "Ellipse count: " << Ellipse::m_count << std::endl; // 1
    
    std::cout << "***********************************************" << std::endl;
    
    std::cout << "=== Демонстрация полиморфизма со статическими членами ===" << std::endl;
    
    // ДЕМОНСТРАЦИЯ ПОЛИМОРФИЗМА с виртуальными функциями
    // ВАЖНО: get_count() возвращает разные значения в зависимости от типа объекта!
    Shape* shape_collection[]{&shape_object1, &ellipse_object};
    
    std::cout << "--- Полиморфные вызовы get_count() ---" << std::endl;
    for (auto& shape_ptr : shape_collection) {
        // Для Shape::get_count() возвращает Shape::m_count
        // Для Ellipse::get_count() возвращает Ellipse::m_count
        std::cout << "Count from polymorphic call: " << shape_ptr->get_count() << std::endl;
    }
    
    std::cout << "***********************************************" << std::endl;
    
    std::cout << "=== Важные выводы ===" << std::endl;
    std::cout << "1. Статические члены НЕ наследуются - каждый класс имеет свой" << std::endl;
    std::cout << "2. При создании Ellipse увеличиваются ОБА счетчика" << std::endl;
    std::cout << "3. Виртуальная функция get_count() возвращает 'свой' счетчик" << std::endl;
    std::cout << "4. Полиморфизм работает с виртуальными функциями, но статические члены независимы" << std::endl;
    
    std::cout << "\n=== Программа завершается ===" << std::endl;
    // При выходе из main() автоматически вызываются деструкторы
    // Shape::~Shape() уменьшит Shape::m_count
    // Ellipse::~Ellipse() уменьшит Ellipse::m_count
    
    return 0;
}