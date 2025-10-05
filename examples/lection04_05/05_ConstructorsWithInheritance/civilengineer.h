#ifndef CIVIL_ENGINEER_H
#define CIVIL_ENGINEER_H

#include "engineer.h"

// Класс CivilEngineer (Инженер-строитель) наследуется от класса Engineer
// Цепочка наследования: Person → Engineer → CivilEngineer
class CivilEngineer : public Engineer
{
    friend std::ostream& operator<<(std::ostream&, const CivilEngineer& operand);

public:
    // Конструктор по умолчанию
    CivilEngineer();
    
    // Конструктор с параметрами
    // ВАЖНО: должен вызвать конструктор класса Engineer (который вызовет конструктор Person)
    CivilEngineer(std::string_view fullname, int age,
                  std::string_view address, int contract_count,
                  std::string_view speciality);
    
    // Деструктор
    ~CivilEngineer();
    
    void build_road() {
        // Эти строки закомментированы, т.к. демонстрируют ошибки доступа:
        // get_full_name();              // ОШИБКА - метод недоступен
        // m_full_name = "Daniel Gray";  // ОШИБКА - поле недоступно
        // m_age = 45;                   // ОШИБКА - protected поле недоступно здесь

        // Методы add() доступны, т.к. унаследованы от Person через Engineer
        add(10, 2);      // OK - метод add из Person
        add(10, 2, 4);   // OK - перегруженная версия add
    }

public:
    // Демонстрация невозможности использовать using для Person
    // using Person::do_something;  // ОШИБКА - не работает напрямую
    
private:
    // Собственное поле класса CivilEngineer
    std::string m_speciality{"None"};  // Специализация инженера-строителя
};

#endif // CIVIL_ENGINEER_H
