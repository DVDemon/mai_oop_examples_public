#include "person.h"
#include "engineer.h"
#include <iostream>

// Конструктор по умолчанию
// Автоматически вызывается конструктор по умолчанию Person::Person()
Engineer::Engineer() {
    std::cout << "Default constructor for Engineer called..." << std::endl;
}

// Конструктор с параметрами
// Используем список инициализации для вызова конструктора базового класса Person
Engineer::Engineer(std::string_view fullname, int age,
                   std::string_view address, int contract_count_param)
    : Person(fullname, age, address), contract_count(contract_count_param)
{
    std::cout << "Custom constructor for Engineer called..." << std::endl;
}

// Конструктор копирования
// Вызываем конструктор копирования базового класса Person
Engineer::Engineer(const Engineer& source)
    : Person(source), contract_count(source.contract_count)
{
    std::cout << "Custom copy constructor for Engineer called..." << std::endl;
}

// Деструктор
// ВАЖНО: деструкторы вызываются в обратном порядке (от производного к базовому)
Engineer::~Engineer() {
    std::cout << "Destructor for Engineer called..." << std::endl;
}


