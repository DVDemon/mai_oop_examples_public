#ifndef DOG_H
#define DOG_H
#include "feline.h"

// Класс Dog (Собака) наследуется от Feline
// Демонстрирует использование final для методов
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
    
    // ФИНАЛЬНАЯ функция - НЕ МОЖЕТ быть переопределена в производных классах!
    // override final означает:
    // 1. override - мы переопределяем виртуальную функцию из Feline
    // 2. final - дальнейшее переопределение в производных классах ЗАПРЕЩЕНО
    void run() const override final {
        std::cout << "Dog::run called" << std::endl;
    }
};

#endif // DOG_H
