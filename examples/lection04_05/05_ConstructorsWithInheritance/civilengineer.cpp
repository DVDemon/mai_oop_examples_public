#include "person.h"
#include "engineer.h"
#include "civilengineer.h"
#include <iostream>

// Конструктор по умолчанию
// Автоматически вызываются конструкторы: Person::Person() → Engineer::Engineer() → CivilEngineer::CivilEngineer()
CivilEngineer::CivilEngineer() {
    std::cout << "Default constructor called for CivilEnginner ... " << std::endl;
}

// ПРАВИЛЬНЫЙ способ: конструктор с параметрами
// Вызываем конструктор Engineer через список инициализации
// Порядок вызова: 1) Person(...), 2) Engineer(...), 3) m_speciality(speciality), 4) тело конструктора
CivilEngineer::CivilEngineer(std::string_view fullname, int age,
                             std::string_view address, int contract_count,
                             std::string_view speciality)
    : Engineer(fullname, age, address, contract_count), m_speciality(speciality)
{
    std::cout << "Custom constructor called for CivilEnginner ... " << std::endl;
}

/*
// НЕПРАВИЛЬНЫЙ СПОСОБ #1: попытка прямой инициализации в теле конструктора
// ОШИБКА: m_address является private полем класса Person и недоступен в CivilEngineer!
// Также не вызывается конструктор базового класса, что может привести к проблемам
CivilEngineer::CivilEngineer(std::string_view fullname, int age,
                             std::string_view address, int contract_count,
                             std::string_view speciality)
{
    m_full_name = fullname;   // OK - public поле
    m_age = age;              // OK - protected поле (но так делать не рекомендуется)
    m_address = address;      // ОШИБКА КОМПИЛЯЦИИ - private поле Person недоступно!
    m_speciality = speciality;
    std::cout << "Custom constructor called for CivilEnginner ... " << std::endl;
}
*/

/*
// НЕПРАВИЛЬНЫЙ СПОСОБ #2: попытка инициализации полей базового класса в списке инициализации
// ОШИБКА: в списке инициализации производного класса можно инициализировать ТОЛЬКО:
//   - собственные поля производного класса
//   - вызывать конструкторы базовых классов
// НЕ МОЖЕМ напрямую инициализировать поля базового класса!
CivilEngineer::CivilEngineer(std::string_view fullname, int age,
                             std::string_view address, int contract_count,
                             std::string_view speciality)
    : m_full_name(fullname), m_age(age), m_address(address), m_speciality(speciality)  // ОШИБКА!
{
    std::cout << "Custom constructor called for CivilEnginner ... " << std::endl;
}
*/

// Деструктор
// Вызываются в обратном порядке: ~CivilEngineer() → ~Engineer() → ~Person()
CivilEngineer::~CivilEngineer() {
    std::cout << "CivilEngineer has died" << std::endl;
}
