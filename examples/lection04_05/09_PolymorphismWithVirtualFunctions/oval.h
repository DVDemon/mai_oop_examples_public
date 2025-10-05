#ifndef OVAL_H
#define OVAL_H
#include "shape.h"

// Класс Oval (Овал) наследуется от Shape
// Демонстрирует переопределение виртуальной функции draw()
class Oval : public Shape
{
public:
    // Конструктор по умолчанию
    Oval() = default;
    
    // Конструктор с параметрами
    Oval(double x_radius, double y_radius,
         std::string_view description);
    
    // Деструктор
    ~Oval();
    
    // ПЕРЕОПРЕДЕЛЕНИЕ виртуальной функции draw()
    // virtual означает, что эта функция может быть переопределена в дальнейших наследниках
    virtual void draw() const {
        std::cout << "Oval::draw() called. Drawing " << m_description <<
            " with m_x_radius: " << m_x_radius << " and m_y_radius: " << m_y_radius 
            << std::endl;
    }

public:
    // Геттеры для радиусов
    double get_x_rad() const {
        return m_x_radius;
    }
    
    double get_y_rad() const {
        return m_y_radius;
    }
 
private:
    // Собственные поля класса Oval
    double m_x_radius{0.0};
    double m_y_radius{0.0};
};

#endif // OVAL_H
