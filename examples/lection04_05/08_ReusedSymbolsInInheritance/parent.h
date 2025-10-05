#ifndef PARENT_H
#define PARENT_H

#include <iostream>

// Базовый класс Parent (Родитель) - демонстрирует переиспользование символов в наследовании
class Parent
{
public:
    // Конструктор по умолчанию
    Parent() = default;
    
    // Конструктор с параметром
    Parent(int member_var) : m_member_var(member_var) {
    }
    
    // Деструктор
    ~Parent() = default;
    
    // Метод для вывода значения поля m_member_var
    void print_var() const {
        std::cout << "The value in parent is: " << m_member_var << std::endl;
    }

protected:
    // PROTECTED поле - будет "скрыто" полем с тем же именем в производном классе
    int m_member_var{100};  // Значение по умолчанию: 100
};

#endif // PARENT_H
