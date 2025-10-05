#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>
#include <string_view>
#include <iostream>

// Базовый класс Animal (Животное) - демонстрирует dynamic_cast
// ВАЖНО: для dynamic_cast нужна хотя бы одна виртуальная функция
class Animal
{
public:
    // Конструктор по умолчанию
    Animal() = default;
    
    // Конструктор с параметрами
    Animal(std::string_view description);
    
    // ВИРТУАЛЬНЫЙ деструктор - ОБЯЗАТЕЛЕН для dynamic_cast!
    // Без виртуальных функций dynamic_cast не будет работать
    virtual ~Animal();
    
    // ВИРТУАЛЬНАЯ функция - основа для dynamic_cast
    virtual void breathe() const {
        std::cout << "Animal::breathe called for: " << m_description << std::endl;
    }

protected:
    // Защищенное поле для описания животного
    std::string m_description;
};

#endif // ANIMAL_H
