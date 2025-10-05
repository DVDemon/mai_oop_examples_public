#ifndef ENGINEER_H
#define ENGINEER_H
#include "person.h"

// Класс Engineer (Инженер) наследуется от класса Person публичным наследованием
class Engineer : public Person
{
    friend std::ostream& operator<<(std::ostream& out, const Engineer& operand);

public:
    // Конструктор по умолчанию
    Engineer();
    
    // Конструктор с параметрами
    // ВАЖНО: должен вызвать конструктор базового класса Person
    Engineer(std::string_view fullname, int age,
             std::string_view address, int contract_count);
    
    // Деструктор
    ~Engineer();
    
    void build_something() {
        m_full_name = "John Snow";  // OK - public поле базового класса
        m_age = 23;                 // OK - protected поле базового класса
        // m_address = "897-78-723"; // ОШИБКА - private поле базового класса недоступно
    }

    // Геттер для собственного поля класса Engineer
    int get_contract_count() const {
        return contract_count;
    }
    
private:
    // Собственное поле класса Engineer
    int contract_count{0};
};

#endif // ENGINEER_H
