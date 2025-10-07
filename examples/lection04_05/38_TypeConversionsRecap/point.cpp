#include "point.h"
#include "number.h"

// Конструктор с параметрами для инициализации координат
Point::Point(double x, double y) : m_x(x), m_y(y)
{
}

/*
АЛЬТЕРНАТИВНЫЙ СПОСОБ: Конструктор из Number
Этот способ закомментирован для демонстрации других методов преобразования

Point::Point(const Number& number) {
    std::cout << "Point Constructor from Number called..." << std::endl;
    m_x = m_y = number.get_wrapped_int();
}
*/

// Реализация оператора присваивания для другого типа (Number)
// СПОСОБ 1: Прямое присваивание p1 = n1
void Point::operator=(const Number& number)
{
    std::cout << "Point Copy assignment operator from Number called..." << std::endl;
    m_x = m_y = number.get_wrapped_int();
}

// Реализация конструктора копирования
Point::Point(const Point& point)
{
    std::cout << "Copy constructor called to copy point " << point << std::endl;
    if (this != &point) {
        m_x = point.m_x;
        m_y = point.m_y;
    }
}
