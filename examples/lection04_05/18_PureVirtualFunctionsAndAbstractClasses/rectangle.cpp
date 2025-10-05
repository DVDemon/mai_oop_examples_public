#include "rectangle.h"

// Конструктор с параметрами - использует список инициализации
Rectangle::Rectangle(double width, double height, std::string_view description)
    : Shape(description), m_width(width), m_height(height)
{
}



