#include <iostream>
#include "circle.h"
#include "rectangle.h"

int main() {
    // ДЕМОНСТРАЦИЯ ЧИСТЫХ ВИРТУАЛЬНЫХ ФУНКЦИЙ И АБСТРАКТНЫХ КЛАССОВ
    
    std::cout << "=== Демонстрация абстрактных классов ===" << std::endl;
    
    // ПРИМЕР ЗАКОММЕНТИРОВАННОГО КОДА:
    // Shape* shape_ptr = new Shape;  // ОШИБКА КОМПИЛЯЦИИ!
    // Абстрактный класс НЕ МОЖЕТ быть инстанцирован напрямую
    // из-за наличия чистых виртуальных функций
    
    std::cout << "--- Создание объектов конкретных классов ---" << std::endl;
    
    // Создание объекта Rectangle через указатель на абстрактный класс
    const Shape* rectangle_pointer = new Rectangle(10, 10, "rect1");
    
    // Вызов виртуальной функции - полиморфизм работает!
    double rectangle_surface = rectangle_pointer->surface();
    
    // Демонстрация typeid для определения реального типа объекта
    std::cout << "Dynamic type of rectangle_pointer: " << typeid(*rectangle_pointer).name() << std::endl;
    std::cout << "The surface of rectangle is: " << rectangle_surface << std::endl;
    
    std::cout << "--------------" << std::endl;
    
    // Создание объекта Circle через указатель на абстрактный класс
    const Shape* circle_pointer = new Circle(10, "circle1");
    
    // Вызов виртуальной функции - полиморфизм работает!
    double circle_surface = circle_pointer->surface();
    
    // Демонстрация typeid для определения реального типа объекта
    std::cout << "Dynamic type of circle_pointer: " << typeid(*circle_pointer).name() << std::endl;
    std::cout << "The surface of the circle is: " << circle_surface << std::endl;
    
    std::cout << "\n=== Демонстрация полиморфизма с абстрактными классами ===" << std::endl;
    
    // Массив указателей на абстрактный класс
    const Shape* shapes[] = {rectangle_pointer, circle_pointer};
    
    std::cout << "--- Полиморфные вызовы через массив ---" << std::endl;
    for (int i = 0; i < 2; ++i) {
        std::cout << "Shape " << i + 1 << ":" << std::endl;
        std::cout << "  Type: " << typeid(*shapes[i]).name() << std::endl;
        std::cout << "  Surface: " << shapes[i]->surface() << std::endl;
        std::cout << "  Perimeter: " << shapes[i]->perimeter() << std::endl;
        std::cout << std::endl;
    }
    
    std::cout << "=== Важные выводы ===" << std::endl;
    std::cout << "1. Абстрактные классы не могут быть инстанцированы напрямую" << std::endl;
    std::cout << "2. Чистые виртуальные функции (= 0) ДОЛЖНЫ быть переопределены" << std::endl;
    std::cout << "3. Полиморфизм работает с указателями на абстрактные классы" << std::endl;
    std::cout << "4. Абстрактные классы определяют интерфейс для производных классов" << std::endl;
    std::cout << "5. Виртуальный деструктор обязателен для полиморфных классов" << std::endl;
    
    std::cout << "\n=== Программа завершается ===" << std::endl;
    
    // Освобождение памяти
    delete rectangle_pointer;
    delete circle_pointer;
    
    return 0;
}