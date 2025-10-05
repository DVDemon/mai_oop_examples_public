#include "dog.h"

// Конструктор с параметрами - использует список инициализации
Dog::Dog(std::string_view fur_style, std::string_view description)
    : Feline(fur_style, description)
{
}

// Виртуальный деструктор
Dog::~Dog() {
    std::cout << "Dog destructor called" << std::endl;
}

