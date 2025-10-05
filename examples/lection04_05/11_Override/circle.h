#ifndef CIRCLE_H
#define CIRCLE_H
#include "oval.h"

// Класс Circle (Круг) наследуется от Oval
// Демонстрирует использование override на третьем уровне иерархии
class Circle : public Oval
{
public:
    // Конструктор по умолчанию
    Circle() = default;
    
    // Конструктор с параметром радиуса
    // ВАЖНО: Circle создается как Oval с одинаковыми x_radius и y_radius
    Circle(double radius, std::string_view description);
    
    // Деструктор
    ~Circle();
    
    // ПЕРЕОПРЕДЕЛЕНИЕ виртуальной функции с использованием override на третьем уровне
    // override гарантирует корректное переопределение виртуальной функции
    virtual void draw() const override {
        std::cout << "Circle::draw() called. Drawing " << m_description <<
            " with radius: " << get_x_rad() << std::endl;        
    }
};

#endif // CIRCLE_H
