#ifndef SHAPE_H
#define SHAPE_H

#include <string>
#include <string_view>

// АБСТРАКТНЫЙ класс Shape - демонстрирует чистые виртуальные функции
// ВАЖНО: абстрактный класс не может быть инстанцирован напрямую!
class Shape
{
protected:
    // PROTECTED конструкторы - предотвращают прямое создание объектов Shape
    Shape() = default;
    Shape(std::string_view description);

public:
    // ВИРТУАЛЬНЫЙ деструктор - ОБЯЗАТЕЛЕН для полиморфных классов!
    // ВАЖНО: если деструктор не public, нельзя удалять объекты через указатели на базовый класс
    virtual ~Shape() = default;
    
    // ЧИСТЫЕ ВИРТУАЛЬНЫЕ ФУНКЦИИ - делают класс абстрактным
    // = 0 означает, что функция ДОЛЖНА быть переопределена в производных классах
    virtual double perimeter() const = 0;  // Чистая виртуальная функция
    virtual double surface() const = 0;    // Чистая виртуальная функция

private:
    // Приватное поле для описания фигуры
    std::string m_description;
};

#endif // SHAPE_H
