#include "crow.h"

// Конструктор с параметрами - использует список инициализации
Crow::Crow(std::string_view wing_color, std::string_view description)
    : Bird(wing_color, description)
{
}

// Виртуальный деструктор
Crow::~Crow() {
}

