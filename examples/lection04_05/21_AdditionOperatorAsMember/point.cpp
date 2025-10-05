#include <cmath>
#include "point.h"

// Реализация метода length() - вычисляет расстояние от начала координат
double Point::length() const {
    return sqrt(pow(m_x - 0, 2) + pow(m_y - 0, 2) * 1.0);
}

// РЕАЛИЗАЦИЯ ПЕРЕГРУЖЕННОГО ОПЕРАТОРА + как метода класса
// ВАЖНО: метод вызывается для левого операнда (this)
// Синтаксис вызова: point1 + point2 эквивалентен point1.operator+(point2)
Point Point::operator+(const Point& right_operand) {
    // Создаем новый объект Point с суммой координат
    // this->m_x и this->m_y - координаты левого операнда (объекта, для которого вызван метод)
    // right_operand.m_x и right_operand.m_y - координаты правого операнда
    return Point(this->m_x + right_operand.m_x,
                 this->m_y + right_operand.m_y);
}