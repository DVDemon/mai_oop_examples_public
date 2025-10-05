#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>
#include <string_view>
#include <iostream>

// Базовый класс Animal (Животное) - демонстрирует использование final
class Animal
{
public:
    // Конструктор по умолчанию
    Animal() = default;
    
    // Конструктор с параметрами
    Animal(std::string_view description);
    
    // Виртуальный деструктор для корректного полиморфизма
    virtual ~Animal();
    
    // ВИРТУАЛЬНАЯ функция - основа полиморфизма
    // virtual означает, что эта функция может быть переопределена в производных классах
    virtual void breathe() const {
        std::cout << "Animal::breathe called for: " << m_description << std::endl;
    }
    
protected:
    // Защищенное поле для описания животного
    std::string m_description;
};

#endif // ANIMAL_H
