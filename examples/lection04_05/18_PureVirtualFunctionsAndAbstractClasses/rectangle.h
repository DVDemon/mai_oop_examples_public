#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.h"

// Класс Rectangle (Прямоугольник) наследуется от абстрактного класса Shape
// Демонстрирует реализацию чистых виртуальных функций
class Rectangle : public Shape
{
public:
    // Конструктор по умолчанию
    Rectangle() = default;
    
    // Конструктор с параметрами
    Rectangle(double width, double height, std::string_view description);
    
    // Виртуальный деструктор
    virtual ~Rectangle() = default;

public:
    // РЕАЛИЗАЦИЯ чистых виртуальных функций из Shape
    // ОБЯЗАТЕЛЬНО: все чистые виртуальные функции должны быть переопределены
    virtual double perimeter() const override {
        return (2 * m_width + 2 * m_height);  // Формула периметра: 2(w + h)
    }
    
    virtual double surface() const override {
        return (m_width * m_height);  // Формула площади: w × h
    }

private:
    // Приватные поля для размеров прямоугольника
    double m_width{0.0};
    double m_height{0.0};
};

#endif // RECTANGLE_H
