#include "person.h"
#include <iostream>

// Конструктор по умолчанию
// ВАЖНО: при создании объекта производного класса сначала вызывается конструктор базового класса
Person::Person() {
    std::cout << "Default constructor for Person called..." << std::endl;
}

// Конструктор с параметрами - использует список инициализации
Person::Person(std::string_view fullname, int age,
               std::string_view address)
    : m_full_name{fullname}, m_age{age}, m_address{address}
{
    std::cout << "Custom constructor for Person called..." << std::endl;
}

// Константный метод
void Person::do_something() const {
    std::cout << "Hello" << std::endl;
}

// Деструктор
// ВАЖНО: деструкторы вызываются в обратном порядке (от производного к базовому)
Person::~Person() {
}

