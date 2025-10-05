#ifndef ENGINEER_H
#define ENGINEER_H
#include "person.h"

// Класс Engineer (Инженер) наследуется от класса Person публичным наследованием
class Engineer : public Person
{
    // НАСЛЕДОВАНИЕ КОНСТРУКТОРОВ: делаем конструкторы Person доступными для Engineer
    // Теперь можно создавать объекты Engineer используя конструкторы Person
    using Person::Person;  // Наследуем все конструкторы Person

public:
    // Альтернативные конструкторы Engineer (закомментированы для демонстрации наследования)
    /*
    Engineer();                    // Конструктор по умолчанию
    Engineer(const Engineer& source);  // Конструктор копирования
    */
    
    // Дополнительный конструктор Engineer с дополнительным параметром
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
