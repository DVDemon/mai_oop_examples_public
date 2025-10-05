#include "feline.h"

// Конструктор с параметрами - использует список инициализации
Feline::Feline(std::string_view fur_style, std::string_view description)
    : Animal(description), m_fur_style(fur_style)
{
}

// Виртуальный деструктор
Feline::~Feline() {
    std::cout << "Feline destructor called" << std::endl;
}

