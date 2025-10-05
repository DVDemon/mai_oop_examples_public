#include <iostream>
#include "shape.h"
#include "oval.h"
#include "circle.h"

// Функция для демонстрации полиморфизма через указатели
void draw_shape(Shape* shape_pointer) {
    shape_pointer->draw();  // Вызовется правильная версия draw() благодаря полиморфизму
}

// Функция для демонстрации полиморфизма через ссылки
void draw_shape_v1(const Shape& shape_reference) {
    shape_reference.draw();  // Вызовется правильная версия draw() благодаря полиморфизму
}

int main() {
    // ДЕМОНСТРАЦИЯ ПОЛИМОРФИЗМА С ВИРТУАЛЬНЫМИ ФУНКЦИЯМИ
    
    // Создание объектов разных типов
    Shape base_shape("Base Shape");
    Oval oval_shape(2.0, 3.5, "Oval Shape");
    Circle circle_shape(3.3, "Circle Shape");
    
    std::cout << "=== Direct method calls ===" << std::endl;
    
    // Прямые вызовы методов (не демонстрируют полиморфизм)
    // base_shape.draw();
    // oval_shape.draw();
    // circle_shape.draw();
    
    std::cout << "\n=== Polymorphism with base pointers ===" << std::endl;
    
    // ДЕМОНСТРАЦИЯ ПОЛИМОРФИЗМА через указатели на базовый класс
    Shape* shape_pointer = &base_shape;
    shape_pointer->draw();  // Shape::draw() - вызывается метод базового класса
    
    shape_pointer = &oval_shape;
    shape_pointer->draw();  // Oval::draw() - вызывается метод производного класса!
    
    shape_pointer = &circle_shape;
    shape_pointer->draw();  // Circle::draw() - вызывается метод самого производного класса!
    
    std::cout << "\n=== Polymorphism with base references ===" << std::endl;
    
    // ДЕМОНСТРАЦИЯ ПОЛИМОРФИЗМА через ссылки на базовый класс
    Shape& shape_reference = circle_shape;
    shape_reference.draw();  // Circle::draw() - вызывается метод правильного типа!
    
    std::cout << "\n=== Polymorphism in functions ===" << std::endl;
    
    // ДЕМОНСТРАЦИЯ ПОЛИМОРФИЗМА в функциях
    draw_shape(&circle_shape);    // Circle::draw()
    draw_shape_v1(circle_shape);  // Circle::draw()
    
    std::cout << "\n=== Polymorphism in collections ===" << std::endl;
    
    // ДЕМОНСТРАЦИЯ ПОЛИМОРФИЗМА в коллекциях
    // Массив указателей на базовый класс, содержащий объекты разных типов
    Shape* shape_collection[]{&base_shape, &oval_shape, &circle_shape};
    
    // Для каждого элемента вызывается правильная версия draw()!
    for (Shape* shape_ptr : shape_collection) {
        shape_ptr->draw();  // Полиморфный вызов
    }
    
    std::cout << "\n=== Program ending ===" << std::endl;
    // При завершении программы автоматически вызываются деструкторы
    // Виртуальные деструкторы обеспечивают правильное уничтожение объектов
    
    return 0;
}