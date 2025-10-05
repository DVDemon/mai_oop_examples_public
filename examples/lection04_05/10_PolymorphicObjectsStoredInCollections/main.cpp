#include <iostream>
#include "shape.h"
#include "oval.h"
#include "circle.h"

int main() {
    // ДЕМОНСТРАЦИЯ ХРАНЕНИЯ ПОЛИМОРФНЫХ ОБЪЕКТОВ В КОЛЛЕКЦИЯХ
    
    // Создание объектов разных типов
    Circle circle1(7.2, "circle1");
    Oval oval1(13.3, 1.2, "Oval1");
    Circle circle2(11.2, "circle2");
    Oval oval2(31.3, 15.2, "Oval2");
    Circle circle3(12.2, "circle3");
    Oval oval3(53.3, 9.2, "Oval3");

    std::cout << "=== PROBLEM: Object Slicing in Arrays ===" << std::endl;
    
    // ПРОБЛЕМА: Если хранить объекты по значению в массиве базового класса,
    // происходит object slicing - данные производных классов "срезаются"!
    std::cout << "Size of Circle object: " << sizeof(circle1) << " bytes" << std::endl;
    std::cout << "Size of Shape object: " << sizeof(Shape{}) << " bytes" << std::endl;
    
    // ОШИБКА: Object Slicing - все объекты становятся Shape!
    Shape shapes_by_value[]{circle1, oval1, circle2, oval2, circle3, oval3};
    
    std::cout << "\n--- Object slicing demonstration ---" << std::endl;
    for (Shape& shape_ref : shapes_by_value) {
        std::cout << "Size of sliced object: " << sizeof(shape_ref) << " bytes" << std::endl;
        shape_ref.draw();  // Всегда вызывается Shape::draw()!
    }
    
    std::cout << "\n=== SOLUTION: Using Pointers ===" << std::endl;
    
    // РЕШЕНИЕ: Использование указателей на базовый класс
    // Указатели сохраняют полиморфизм и предотвращают object slicing
    Shape* shapes_by_pointer[]{&circle1, &oval1, &circle2, &oval2, &circle3, &oval3};
    
    std::cout << "--- Polymorphism preserved with pointers ---" << std::endl;
    for (Shape* shape_ptr : shapes_by_pointer) {
        std::cout << "Size of actual object: " << sizeof(*shape_ptr) << " bytes" << std::endl;
        shape_ptr->draw();  // Вызывается правильная версия draw()!
        std::cout << std::endl;
    }
    
    std::cout << "=== Why References Don't Work in Arrays ===" << std::endl;
    
    // Почему ссылки не работают в массивах:
    // const Shape& shapes_refs[]{circle1, oval1, circle2, oval2, circle3, oval3};  // ОШИБКА КОМПИЛЯЦИИ!
    // Ссылки не являются lvalue-assignable (не могут быть присвоены повторно)
    
    std::cout << "References cannot be stored in arrays because they are not assignable." << std::endl;
    std::cout << "Use pointers instead for polymorphic collections." << std::endl;
    
    std::cout << "\n=== Program ending ===" << std::endl;
    // При завершении программы автоматически вызываются деструкторы
    // Виртуальные деструкторы обеспечивают правильное уничтожение объектов
    
    return 0;
}