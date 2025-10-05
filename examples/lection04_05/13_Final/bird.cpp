#include "bird.h"

// Конструктор с параметрами - использует список инициализации
Bird::Bird(std::string_view wing_color, std::string_view description)
    : Animal(description), m_wing_color(wing_color)
{
}

// Виртуальный деструктор
Bird::~Bird() {
}

