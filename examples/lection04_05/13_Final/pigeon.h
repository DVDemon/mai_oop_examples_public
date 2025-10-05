#ifndef PIGEON_H
#define PIGEON_H
#include "bird.h"

// Класс Pigeon (Голубь) наследуется от Bird
// Демонстрирует наследование от класса с final методами
class Pigeon : public Bird
{
public:
    // Конструктор по умолчанию
    Pigeon() = default;
    
    // Конструктор с параметрами
    Pigeon(std::string_view wing_color, std::string_view description);
    
    // Виртуальный деструктор
    virtual ~Pigeon();
    
    // СОБСТВЕННАЯ виртуальная функция Pigeon
    virtual void coo() const {
        std::cout << "Pigeon::coo called for pigeon: " << m_description << std::endl;
    }
    
    // ВАЖНО: fly() НЕ МОЖЕТ быть переопределен, так как он помечен как final в Bird
};

#endif // PIGEON_H
