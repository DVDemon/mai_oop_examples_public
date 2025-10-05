#ifndef ENGINEER_H
#define ENGINEER_H
#include "person.h"

// Класс Engineer (Инженер) использует ПРИВАТНОЕ наследование от Person
// ВАЖНО: при private наследовании ВСЕ public и protected члены базового класса
// становятся ПРИВАТНЫМИ в производном классе и недоступны извне
class Engineer : private Person
{
public:
    Engineer();
    ~Engineer();
    
    void build_something() {
        m_full_name = "John Snow";  // OK - public поле базового класса доступно
        m_age = 23;                 // OK - protected поле базового класса доступно
        // m_address = "897-78-723"; // ОШИБКА - поле protected, но без "воскрешения" недоступно здесь
    }

    // ВОСКРЕШЕНИЕ ЧЛЕНОВ: делаем метод add снова PUBLIC
    // Теперь объекты Engineer могут вызывать метод add(), хотя наследование private
    using Person::add;

protected:
    // ВОСКРЕШЕНИЕ ЧЛЕНОВ: делаем методы и поля PROTECTED для наследников Engineer
    // Это позволяет классам, наследующимся от Engineer, использовать эти члены
    using Person::get_full_name;
    using Person::get_age;
    using Person::get_address;
    using Person::m_address;  // "воскрешаем" поле m_address
    using Person::m_age;

public:
    // Геттер для собственного поля класса Engineer
    int get_contract_count() const {
        return contract_count;
    }
    
private:
    // Собственное поле класса Engineer
    int contract_count{0};
};

#endif // ENGINEER_H
