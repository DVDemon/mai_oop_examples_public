#include "person.h"
#include <iostream>

// Конструктор с параметрами - использует список инициализации
Person::Person(std::string_view fullname, int age,
               const std::string address)
    : m_full_name{fullname}, m_age{age}, m_address{address}
{
}

// Константный метод - может быть вызван у const объектов
void Person::do_something() const {
    std::cout << "Hello" << std::endl;
}

// Деструктор
Person::~Person() {
}

