#ifndef FELINE_H
#define FELINE_H
#include "animal.h"

// Класс Feline (Кошачьи) наследуется от Animal
// Демонстрирует dynamic_cast для производных классов
class Feline : public Animal
{
public:
    // Конструктор по умолчанию
    Feline() = default;
    
    // Конструктор с параметрами
    Feline(std::string_view fur_style, std::string_view description);
    
    // Виртуальный деструктор
    virtual ~Feline();
    
    // ВИРТУАЛЬНАЯ функция - может быть переопределена в производных классах
    virtual void run() const {
        std::cout << "Feline " << m_description << " is running" << std::endl;
    }
    
    // ОБЫЧНАЯ функция (не виртуальная) - демонстрирует доступ через dynamic_cast
    // Эта функция доступна только объектам типа Feline и его производных классов
    void do_some_feline_thingy() {
        std::cout << "Doing some feline thingy..." << std::endl;
    }
    
    // Публичное поле для стиля шерсти
    std::string m_fur_style;
};

#endif // FELINE_H
