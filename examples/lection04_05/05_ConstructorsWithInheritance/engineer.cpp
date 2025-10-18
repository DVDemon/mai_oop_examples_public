#include "person.h"
#include "engineer.h"
#include <iostream>

// Конструктор по умолчанию
// Автоматически вызывается конструктор по умолчанию Person::Person()
Engineer::Engineer() {
    std::cout << "Default constructor for Engineer called..." << std::endl;
}

// Конструктор с параметрами
// ВАЖНО: используем список инициализации для вызова конструктора базового класса Person
// Порядок выполнения: 1) Person(fullname, age, address), 2) contract_count(contract_count_param), 3) тело конструктора
Engineer::Engineer(std::string_view fullname, int age,
                   std::string_view address, int contract_count_param)
    : Person(fullname, age, address), contract_count(contract_count_param)
{
    std::cout << "Custom constructor for Engineer called..." << std::endl;
}

// Деструктор
Engineer::~Engineer() {
     std::cout << "Engineer has died" << std::endl;
}

