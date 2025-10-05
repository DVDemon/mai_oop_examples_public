#include "person.h"
#include <iostream>

// Конструктор по умолчанию
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

// Конструктор копирования
Person::Person(const Person& source)
    : m_full_name(source.m_full_name), m_age(source.m_age),
      m_address(source.m_address)
{
    std::cout << "Custom copy constructor for Person called..." << std::endl;
}

// Константный метод
void Person::do_something() const {
    std::cout << "Hello" << std::endl;
}

// Деструктор
Person::~Person() {
}

