#ifndef BULL_DOG_H
#define BULL_DOG_H
#include "dog.h"

// Класс BullDog (Бульдог) наследуется от Dog
// Демонстрирует невозможность переопределения final методов
class BullDog : public Dog
{
public:
    // Конструктор по умолчанию
    BullDog();
    
    // Виртуальный деструктор
    virtual ~BullDog();
    
    // ПРИМЕР ЗАКОММЕНТИРОВАННОГО КОДА:
    // Попытка переопределить final метод приведет к ошибке компиляции!
    // Dog::run() помечен как final, поэтому переопределение ЗАПРЕЩЕНО
    /*
    virtual void run() const override {
        std::cout << "Bulldog::run() called" << std::endl;
    }
    */
};

#endif // BULL_DOG_H
