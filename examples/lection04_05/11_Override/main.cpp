#include <iostream>
#include <memory>
#include "shape.h"
#include "oval.h"
#include "circle.h"

int main() {
    // ДЕМОНСТРАЦИЯ ИСПОЛЬЗОВАНИЯ КЛЮЧЕВОГО СЛОВА OVERRIDE
    
    // Создание объектов разных типов
    Circle circle1(7.2, "circle1");
    Oval oval1(13.3, 1.2, "Oval1");
    Circle circle2(11.2, "circle2");
    Oval oval2(31.3, 15.2, "Oval2");
    Circle circle3(12.2, "circle3");
    Oval oval3(53.3, 9.2, "Oval3");

    std::cout << "=== Demonstration of override keyword ===" << std::endl;
    
    // Демонстрация полиморфизма с использованием указателей
    // Все виртуальные функции используют override, что гарантирует корректное переопределение
    Shape* shape_collection[]{&circle1, &oval1, &circle2, &oval2, &circle3, &oval3};
    
    std::cout << "--- Polymorphic calls with override safety ---" << std::endl;
    for (Shape* shape_ptr : shape_collection) {
        shape_ptr->draw();  // Вызывается правильная версия благодаря override
        std::cout << std::endl;
    }
    
    std::cout << "=== Benefits of using override ===" << std::endl;
    std::cout << "1. Compile-time safety: prevents accidental function hiding" << std::endl;
    std::cout << "2. Clear intent: explicitly shows function override" << std::endl;
    std::cout << "3. Refactoring safety: catches signature mismatches" << std::endl;
    std::cout << "4. Documentation: makes code more self-documenting" << std::endl;
    
    std::cout << "\n=== Program ending ===" << std::endl;
    // При завершении программы автоматически вызываются деструкторы
    // Виртуальные деструкторы обеспечивают правильное уничтожение объектов
    
    return 0;
}