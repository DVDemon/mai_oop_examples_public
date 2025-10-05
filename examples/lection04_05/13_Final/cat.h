#ifndef CAT_H
#define CAT_H
#include "feline.h"

// Класс Cat (Кошка) наследуется от Feline
// Демонстрирует использование final для КЛАССОВ
class Cat final : public Feline
{
public:
    // Конструктор по умолчанию
    Cat() = default;
    
    // Конструктор с параметрами
    Cat(std::string_view fur_style, std::string_view description);
    
    // Виртуальный деструктор
    virtual ~Cat();
    
    // ВИРТУАЛЬНАЯ функция - технически бесполезна в final классе
    // ВАЖНО: Cat помечен как final, поэтому никто не может наследоваться от него
    // Виртуальные функции в final классах не имеют смысла для полиморфизма
    virtual void miaw() const {
        std::cout << "Cat::miaw() called for cat " << m_description << std::endl;
    }
    
    // ПЕРЕОПРЕДЕЛЕНИЕ виртуальной функции из Feline
    // Эта функция полезна, так как переопределяет поведение базового класса
    virtual void run() const override {
        std::cout << "Cat::run() called - cat is running gracefully" << std::endl;
    }
};

#endif // CAT_H
