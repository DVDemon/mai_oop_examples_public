
#include "person.h"
#include "engineer.h"
#include "civilengineer.h"
#include <iostream>

// Конструктор по умолчанию
// Автоматически вызываются конструкторы: Person::Person() → Engineer::Engineer() → CivilEngineer::CivilEngineer()
CivilEngineer::CivilEngineer() {
    std::cout << "Default constructor called for CivilEngineer..." << std::endl;
}

// Конструктор с параметрами
// Вызываем конструктор Engineer через список инициализации
// Порядок вызова: 1) Person(...), 2) Engineer(...), 3) m_speciality(speciality), 4) тело конструктора
CivilEngineer::CivilEngineer(std::string_view fullname, int age,
                             std::string_view address, int contract_count,
                             std::string_view speciality)
    : Engineer(fullname, age, address, contract_count), m_speciality(speciality)
{
    std::cout << "Custom constructor called for CivilEngineer..." << std::endl;
}

// Конструктор копирования
// Вызываем конструктор копирования Engineer, который вызовет конструктор копирования Person
CivilEngineer::CivilEngineer(const CivilEngineer& source)
    : Engineer(source), m_speciality(source.m_speciality)
{
    std::cout << "Custom copy constructor called for CivilEngineer..." << std::endl;
}

// Деструктор
// ВАЖНО: деструкторы вызываются в обратном порядке: ~CivilEngineer() → ~Engineer() → ~Person()
CivilEngineer::~CivilEngineer() {
    std::cout << "Destructor called for CivilEngineer..." << std::endl;
}
