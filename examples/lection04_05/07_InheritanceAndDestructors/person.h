#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <string_view>

// Базовый класс Person (Персона) - представляет человека с полным именем, возрастом и адресом
class Person
{
public:
    // Конструктор по умолчанию
    Person();
    
    // Конструктор с параметрами
    Person(std::string_view fullname, int age,
           std::string_view address);
    
    // Конструктор копирования
    Person(const Person& source);
    
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

    // Перегруженные методы add
    int add(int a, int b) const {
        return a + b;
    }

    int add(int a, int b, int c) const {
        return a + b + c;
    }

    // Константный метод
    void do_something() const;

public:
    // PUBLIC поле - доступно везде
    std::string m_full_name{"None"};

protected:
    // PROTECTED поле - доступно в классе и его наследниках
    int m_age{0};

private:
    // PRIVATE поле - доступно только в самом классе Person
    std::string m_address{"None"};
};

#endif // PERSON_H
