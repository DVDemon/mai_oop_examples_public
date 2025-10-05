#include <cmath>
#include "point.h"

// РЕАЛИЗАЦИЯ ПЕРЕГРУЖЕННОГО ОПЕРАТОРА + как НЕ-ЧЛЕНА КЛАССА (friend функция)
// ВАЖНО: это НЕ метод класса, а обычная функция с доступом к приватным членам
// Синтаксис вызова: point1 + point2 эквивалентен operator+(point1, point2)
Point operator+(const Point& left, const Point& right) {
    // FRIEND функция имеет прямой доступ к приватным полям left.m_x, left.m_y
    // и right.m_x, right.m_y без использования геттеров
    return Point(left.m_x + right.m_x, left.m_y + right.m_y);
}

// Реализация метода length() - вычисляет расстояние от начала координат
double Point::length() const {
    return sqrt(pow(m_x - 0, 2) + pow(m_y - 0, 2) * 1.0);
}

// ПРИМЕР ЗАКОММЕНТИРОВАННОГО КОДА - дублирование реализации:
/*
Point operator+(const Point& left, const Point& right) {
    return Point(left.m_x + right.m_x, left.m_y + right.m_y);
}
*/

