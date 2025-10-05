#include <cmath>
#include "point.h"

// Реализация метода length() - вычисляет расстояние от начала координат
double Point::length() const {
    return sqrt(pow(m_x - 0, 2) + pow(m_y - 0, 2) * 1.0);
}


