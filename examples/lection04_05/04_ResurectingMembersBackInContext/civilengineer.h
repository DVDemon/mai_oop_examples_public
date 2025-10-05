#ifndef CIVIL_ENGINEER_H
#define CIVIL_ENGINEER_H

#include "engineer.h"

// Класс CivilEngineer (Инженер-строитель) наследуется от Engineer PUBLIC наследованием
// Важно понимать, что Person является private базовым классом для Engineer,
// поэтому CivilEngineer может работать только с теми членами Person, которые
// были "воскрешены" в Engineer через using
class CivilEngineer : public Engineer
{
public:
    CivilEngineer();
    ~CivilEngineer();
    
    void build_road() {
        // get_full_name();              // ОШИБКА - метод protected в Engineer (благодаря using)
        // m_full_name = "Daniel Gray";  // ОШИБКА - поле НЕ было "воскрешено" в Engineer
        m_age = 45;                      // OK - m_age был "воскрешен" как protected в Engineer
        m_address = "";                  // OK - m_address был "воскрешен" как protected в Engineer

        // Оба метода add доступны, т.к. были "воскрешены" как public в Engineer
        add(10, 2);      // OK - метод add из Person доступен через "воскрешение"
        add(10, 2, 4);   // OK - перегруженная версия add
    }

public:
    // ДЕМОНСТРАЦИЯ: нельзя "воскресить" метод do_something, т.к. он недоступен
    // Person является private базовым классом для Engineer
    // using Person::do_something;  // ОШИБКА КОМПИЛЯЦИИ - Person недоступен из CivilEngineer
    
private:
    // Собственное поле класса CivilEngineer
    std::string m_speciality{"None"};  // Специализация инженера-строителя
};

#endif // CIVIL_ENGINEER_H
