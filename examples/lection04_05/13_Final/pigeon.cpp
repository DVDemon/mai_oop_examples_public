#include "pigeon.h"

// Конструктор с параметрами - использует список инициализации
Pigeon::Pigeon(std::string_view wing_color, std::string_view description)
    : Bird(wing_color, description)
{
}

// Виртуальный деструктор
Pigeon::~Pigeon() {
}

