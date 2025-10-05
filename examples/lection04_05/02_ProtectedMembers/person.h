#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <iostream>

// Базовый класс Person (Персона) - представляет любого человека с именем и фамилией
class Person
{
public:
    // Конструктор по умолчанию
    Person();
    
    // Конструктор с параметрами для инициализации имени и фамилии
    Person(std::string& first_name_param, std::string& last_name_param);
    
    // Деструктор
    ~Person();
    
    // Геттеры (методы для получения значений полей)
    std::string get_first_name() const {
        return first_name;
    }
    
    std::string get_last_name() const {
        return last_name;
    }
    
    // Сеттеры (методы для установки значений полей)
    void set_first_name(std::string_view fn) {
        first_name = fn;
    }
    
    void set_last_name(std::string_view ln) {
        last_name = ln;
    }
    
    // Метод для вывода информации о персоне
    std::ostream& print(std::ostream& out);
    
protected:
    // ЗАЩИЩЕННЫЕ (PROTECTED) поля - доступны для наследующих классов
    // В отличие от private, производные классы могут напрямую обращаться к этим полям
    std::string first_name{"Mysterious"};  // Имя по умолчанию
    std::string last_name{"Person"};       // Фамилия по умолчанию
};

#endif // PERSON_H
