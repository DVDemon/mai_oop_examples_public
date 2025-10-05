#include "animal.h"

// Конструктор с параметрами - использует список инициализации
Animal::Animal(std::string_view description)
    : m_description(description)
{
}

// Виртуальный деструктор
// ВАЖНО: виртуальный деструктор необходим для корректной работы dynamic_cast
Animal::~Animal() {
    std::cout << "Animal destructor called" << std::endl;
}

