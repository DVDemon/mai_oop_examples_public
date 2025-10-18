#include "dog.h"
#include <iostream>

// ============================================================================
// РЕАЛИЗАЦИЯ КЛАССА СОБАКИ
// ============================================================================

// Конструктор с именем
Dog::Dog(std::string name_param) : dog_name(name_param)
{
    std::cout << "Constructor for dog " << dog_name << " called." << std::endl;
}

// Деструктор
Dog::~Dog()
{
    std::cout << "Destructor for dog " << dog_name << " called" << std::endl;
}

