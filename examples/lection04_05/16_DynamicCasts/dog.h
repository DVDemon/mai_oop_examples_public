#ifndef DOG_H
#define DOG_H
#include "feline.h"

// Класс Dog (Собака) наследуется от Feline
// Демонстрирует dynamic_cast для многоуровневой иерархии
class Dog : public Feline
{
public:
    // Конструктор по умолчанию
    Dog() = default;
    
    // Конструктор с параметрами
    Dog(std::string_view fur_style, std::string_view description);
    
    // Виртуальный деструктор
    virtual ~Dog();
    
    // ВИРТУАЛЬНАЯ функция - может быть переопределена в производных классах
    virtual void bark() const {
        std::cout << "Dog::bark called: Woof!" << std::endl;
    }

    // ОБЫЧНАЯ функция (не виртуальная) - демонстрирует доступ через dynamic_cast
    // Эта функция доступна только объектам типа Dog и его производных классов
    void do_some_dog_thingy() {
        std::cout << "Doing some dog thingy..., speed: " << m_speed << std::endl;
    }

private:
    // Приватное поле для скорости
    double m_speed{};
};

#endif // DOG_H
