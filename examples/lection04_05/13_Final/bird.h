#ifndef BIRD_H
#define BIRD_H
#include "animal.h"

// Класс Bird (Птица) наследуется от Animal
// Демонстрирует использование final для виртуальных функций
class Bird : public Animal
{
public:
    // Конструктор по умолчанию
    Bird() = default;
    
    // Конструктор с параметрами
    Bird(std::string_view wing_color, std::string_view description);
    
    // Виртуальный деструктор
    virtual ~Bird();
    
    // ФИНАЛЬНАЯ виртуальная функция
    // virtual final означает:
    // 1. virtual - функция может быть переопределена в производных классах
    // 2. final - но ТОЛЬКО в первом уровне наследования, дальше переопределение ЗАПРЕЩЕНО
    // ВАЖНО: virtual и final НЕ противоречат друг другу!
    virtual void fly() const final {
        std::cout << "Bird::fly() called for bird: " << m_description << std::endl;
    }
    
private:
    // Приватное поле для цвета крыльев
    std::string m_wing_color;
};

#endif // BIRD_H
