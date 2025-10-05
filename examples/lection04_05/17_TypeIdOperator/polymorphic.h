#ifndef POLYMORPHIC_H
#define POLYMORPHIC_H

#include <iostream>

// Базовый класс DynamicBase - демонстрирует typeid с полиморфными типами
// ВАЖНО: имеет виртуальные функции для поддержки полиморфизма
class DynamicBase {
public:
    // ВИРТУАЛЬНАЯ функция - обеспечивает полиморфизм
    virtual void do_something() {
        std::cout << "DynamicBase::do_something() called" << std::endl;
    }
    
    // ВИРТУАЛЬНЫЙ деструктор - обязателен для полиморфных классов
    virtual ~DynamicBase() = default;
};

// Производный класс DynamicDerived - демонстрирует typeid с производными типами
class DynamicDerived : public DynamicBase {
public:
    // ПЕРЕОПРЕДЕЛЕНИЕ виртуальной функции с override
    virtual void do_something() override {
        std::cout << "DynamicDerived::do_something() called" << std::endl;
    }
    
    // ВИРТУАЛЬНЫЙ деструктор
    virtual ~DynamicDerived() = default;
};

#endif // POLYMORPHIC_H
