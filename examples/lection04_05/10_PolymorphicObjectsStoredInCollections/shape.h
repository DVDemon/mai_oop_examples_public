#ifndef SHAPE_H
#define SHAPE_H

#include <string>
#include <string_view>
#include <iostream>

// Базовый абстрактный класс Shape (Фигура) - демонстрирует полиморфизм в коллекциях
class Shape
{
public:
    // Конструктор по умолчанию
    Shape() = default;
    
    // Конструктор с параметрами
    Shape(std::string_view description);
    
    // ВАЖНО: виртуальный деструктор для корректного полиморфизма
    virtual ~Shape();
    
    // ВИРТУАЛЬНАЯ функция - основа полиморфизма
    virtual void draw() const {
        std::cout << "Shape::draw() called. Drawing " << m_description << std::endl;
    }
    
protected:
    // PROTECTED поле - доступно для наследующих классов
    std::string m_description{""};
};

#endif // SHAPE_H
