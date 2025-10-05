#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.h"

// Класс Circle (Круг) наследуется от абстрактного класса Shape
// Демонстрирует реализацию чистых виртуальных функций
class Circle : public Shape
{
public:
    // Конструктор по умолчанию
    Circle() = default;
    
    // Конструктор с параметрами
    Circle(double radius, std::string_view description);
    
    // Виртуальный деструктор
    virtual ~Circle() = default;
    
    // РЕАЛИЗАЦИЯ чистых виртуальных функций из Shape
    // ОБЯЗАТЕЛЬНО: все чистые виртуальные функции должны быть переопределены
    virtual double perimeter() const override {
        return (2 * PI * m_radius);  // Формула периметра круга: 2πr
    }

    virtual double surface() const override {
        return PI * m_radius * m_radius;  // Формула площади круга: πr²
    }

private:
    // Приватное поле для радиуса круга
    double m_radius{0.0};
    
    // Статическая константа π (пи)
    inline static double PI{3.14159265};
};

#endif // CIRCLE_H
