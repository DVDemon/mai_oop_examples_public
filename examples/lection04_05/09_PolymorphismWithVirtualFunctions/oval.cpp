#include "oval.h"

// Конструктор с параметрами - использует список инициализации
Oval::Oval(double x_radius, double y_radius,
           std::string_view description)
    : Shape(description), m_x_radius(x_radius), m_y_radius(y_radius)
{
}

// Деструктор
Oval::~Oval() {
}

