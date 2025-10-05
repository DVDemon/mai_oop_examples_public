#include "circle.h"

// Конструктор Circle с параметром радиуса
// ВАЖНО: Circle наследуется от Oval, поэтому передаем radius как x_radius и y_radius
Circle::Circle(double radius, std::string_view description)
    : Oval(radius, radius, description)  // Круг = овал с равными радиусами
{
}

// Деструктор
Circle::~Circle() {
}

