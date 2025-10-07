#ifndef POINT_H
#define POINT_H

#include <iostream>

class Number;

class Point
{
    // Дружественная функция вывода в поток
    friend std::ostream& operator<<(std::ostream& out, const Point& point);

public:
    // Конструктор по умолчанию
    Point() = default;
    
    // Конструктор с параметрами для инициализации координат
    Point(double x, double y);
    
    // Конструктор копирования
    Point(const Point& point);
    
    // АЛЬТЕРНАТИВНЫЙ СПОСОБ: Конструктор из Number
    // Закомментирован для демонстрации других способов преобразования
    // Point(const Number& number);

    // Деструктор по умолчанию
    ~Point() = default;

    // Оператор присваивания копированием (Copy Assignment Operator)
    // Стандартный оператор присваивания для объектов того же типа
    Point& operator=(const Point& right_operand)
    {
        std::cout << "Copy assignment operator called" << std::endl;
        if (this != &right_operand) {
            m_x = right_operand.m_x;
            m_y = right_operand.m_y;
        }
        return *this;
    }

    // Оператор присваивания для другого типа (Number)
    // СПОСОБ 1: Прямое присваивание p1 = n1
    void operator=(const Number& number);

private:
    double m_x{0.0};  // Координата x точки
    double m_y{0.0};  // Координата y точки
};

// Inline реализация оператора вывода в поток
inline std::ostream& operator<<(std::ostream& os, const Point& point)
{
    os << "Point [ x : " << point.m_x << ", y : " << point.m_y << " ]";
    return os;
}

#endif // POINT_H
