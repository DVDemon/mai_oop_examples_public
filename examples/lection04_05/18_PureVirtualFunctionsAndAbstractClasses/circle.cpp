#include "circle.h"

// Конструктор с параметрами - использует список инициализации
Circle::Circle(double radius, std::string_view description)
    : Shape(description), m_radius(radius)
{
}

