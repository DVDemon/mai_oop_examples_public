#ifndef CROW_H
#define CROW_H
#include "bird.h"

// Класс Crow (Ворона) наследуется от Bird
// Демонстрирует невозможность переопределения final методов
class Crow : public Bird
{
public:
    // Конструктор по умолчанию
    Crow() = default;
    
    // Конструктор с параметрами
    Crow(std::string_view wing_color, std::string_view description);
    
    // Виртуальный деструктор
    virtual ~Crow();
    
    // СОБСТВЕННАЯ виртуальная функция Crow
    virtual void cow() const {
        std::cout << "Crow::cow called for crow: " << m_description << std::endl;
    }
    
    // ПРИМЕР ЗАКОММЕНТИРОВАННОГО КОДА:
    // Попытка переопределить final метод приведет к ошибке компиляции!
    // Bird::fly() помечен как final, поэтому переопределение ЗАПРЕЩЕНО
    /*
    virtual void fly() const override {
        // Этот код НЕ скомпилируется - fly() помечен как final в Bird
    }
    */
};

#endif // CROW_H
