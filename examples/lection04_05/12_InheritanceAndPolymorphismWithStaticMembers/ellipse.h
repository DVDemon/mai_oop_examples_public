#ifndef ELLIPSE_H
#define ELLIPSE_H
#include "shape.h"

// Класс Ellipse наследуется от Shape
// Демонстрирует собственный статический член в производном классе
class Ellipse : public Shape
{
public:
    // Конструктор по умолчанию
    Ellipse();
    
    // Конструктор с параметрами
    Ellipse(double x_radius, double y_radius,
            std::string_view description);
    
    // Деструктор
    ~Ellipse();
    
    // ПЕРЕОПРЕДЕЛЕНИЕ виртуальной функции с override
    // ВАЖНО: возвращает СВОЙ статический счетчик, а не базового класса!
    virtual int get_count() const override {
        return m_count;  // Возвращает Ellipse::m_count, а не Shape::m_count
    }

    // СОБСТВЕННЫЙ статический член класса Ellipse
    // ВАЖНО: это НЕ тот же статический член, что и в Shape!
    // Каждый класс в иерархии имеет свой независимый статический счетчик
    static int m_count;
	
private:
    // Собственные поля класса Ellipse
    double m_x_radius;
    double m_y_radius;
};

#endif // ELLIPSE_H
