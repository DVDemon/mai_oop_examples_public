#ifndef NON_POLYMORPHIC_H
#define NON_POLYMORPHIC_H

#include <iostream>

// Базовый класс StaticBase - демонстрирует typeid с НЕ полиморфными типами
// ВАЖНО: НЕ имеет виртуальных функций - статическое связывание
class StaticBase {
public:
    // ОБЫЧНАЯ функция (не виртуальная) - статическое связывание
    void do_something() {
        std::cout << "StaticBase::do_something() called" << std::endl;
    }
};

// Производный класс StaticDerived - демонстрирует статическое связывание
class StaticDerived : public StaticBase {
public:
    // ОБЫЧНАЯ функция (не виртуальная) - скрывает базовую функцию
    void do_something() {
        std::cout << "StaticDerived::do_something() called" << std::endl;
    }
};

#endif // NON_POLYMORPHIC_H
