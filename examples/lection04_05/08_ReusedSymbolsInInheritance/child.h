#ifndef CHILD_H
#define CHILD_H

#include "parent.h"

// Класс Child (Ребенок) наследуется от Parent
// ДЕМОНСТРАЦИЯ: переиспользование символов - поля с одинаковыми именами в базовом и производном классах
class Child : public Parent
{
public:
    // Конструктор по умолчанию
    Child();
    
    // Конструктор с параметром
    // ВАЖНО: инициализирует только поле Child, а не Parent!
    Child(int member_var) : m_member_var(member_var) {
    }
    
    // Деструктор
    ~Child() = default;
    
    // Переопределенный метод print_var
    // ВАЖНО: этот метод "скрывает" метод Parent::print_var()
    void print_var() const {
        std::cout << "The value in child is: " << m_member_var << std::endl;
    }
    
    // Метод для демонстрации доступа к полям с одинаковыми именами
    void show_values() const {
        // Обращение к полю Child (private поле Child)
        std::cout << "The value in child is: " << m_member_var << std::endl;
        
        // Обращение к полю Parent через квалифицированное имя
        // ВАЖНО: Parent::m_member_var доступен, т.к. поле protected в Parent
        std::cout << "The value in parent is: " << Parent::m_member_var << std::endl;
    }

private:
    // ПРИВАТНОЕ поле с тем же именем, что и в Parent!
    // Это поле "скрывает" protected поле Parent::m_member_var
    int m_member_var{1000};  // Значение по умолчанию: 1000
};

#endif // CHILD_H
