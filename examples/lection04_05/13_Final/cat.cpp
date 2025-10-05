#include "cat.h"

// Конструктор с параметрами - использует список инициализации
Cat::Cat(std::string_view fur_style, std::string_view description)
    : Feline(fur_style, description)
{
}

// Виртуальный деструктор
Cat::~Cat() {
}

