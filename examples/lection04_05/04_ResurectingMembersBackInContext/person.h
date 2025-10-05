#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <string_view>

// Базовый класс Person (Персона) - представляет человека с полным именем, возрастом и адресом
class Person
{
public:
    // Конструктор по умолчанию
    Person() = default;
    
    // Конструктор с параметрами
    Person(std::string_view fullname, int age,
           const std::string address);
    
    // Деструктор
    ~Person();

    // Геттеры (const-методы для получения значений полей)
    std::string get_full_name() const {
        return m_full_name;
    }

    int get_age() const {
        return m_age;
    }

    std::string get_address() const {
        return m_address;
    }

    // Перегруженный метод add (неконстантная версия - может изменять объект)
    int add(int a, int b) {
        m_address = "Not none";
        return a + b;
    }

    // Перегруженный метод add (константная версия - не может изменять объект)
    int add(int a, int b, int c) const {
        return a + b + c;
    }

    // Константный метод
    void do_something() const;

public:
    // PUBLIC поле - доступно везде
    std::string m_full_name{"None"};

protected:
    // PROTECTED поля - доступны в классе и его наследниках
    int m_age{0};
    std::string m_address{"None"};
};

#endif // PERSON_H
