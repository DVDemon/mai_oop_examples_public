#ifndef FELINE_H
#define FELINE_H
#include "animal.h"

// Класс Feline (Кошачьи) наследуется от Animal
// Демонстрирует виртуальную функцию, которая может быть помечена final в производных классах
class Feline : public Animal
{
public:
    // Конструктор по умолчанию
    Feline() = default;
    
    // Конструктор с параметрами
    Feline(std::string_view fur_style, std::string_view description);
    
    // Виртуальный деструктор
    virtual ~Feline();
    
    // ВИРТУАЛЬНАЯ функция run() - может быть переопределена в производных классах
    // В производных классах может быть помечена final для предотвращения дальнейшего переопределения
    virtual void run() const {
        std::cout << "Feline " << m_description << " is running" << std::endl;
    }
    
    // Публичное поле для стиля шерсти
    std::string m_fur_style;
};

#endif // FELINE_H
