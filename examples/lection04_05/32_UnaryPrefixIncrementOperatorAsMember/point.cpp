#include <cmath>
#include "point.h"

// Вычисление расстояния от начала координат (0, 0) до точки
// Используется формула Евклидова расстояния: d = sqrt((x - 0)² + (y - 0)²)
double Point::length() const
{
    return sqrt(pow(m_x - 0, 2) + pow(m_y - 0, 2) * 1.0);
}
