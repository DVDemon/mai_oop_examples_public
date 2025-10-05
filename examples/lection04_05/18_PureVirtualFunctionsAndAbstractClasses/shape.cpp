#include "shape.h"

// Конструктор с параметрами - использует список инициализации
Shape::Shape(std::string_view description)
    : m_description(description)
{
}

