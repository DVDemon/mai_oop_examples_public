#ifndef SHAPE_H
#define SHAPE_H
#include <iostream>
#include <string>
#include <string_view>

// Базовый класс Shape - демонстрирует статические члены в наследовании
class Shape
{
public:
    // Конструктор по умолчанию
    Shape();
    
    // Конструктор с параметрами
    Shape(std::string_view description);
    
    // Виртуальный деструктор для корректного полиморфизма
    virtual ~Shape();
    
    // Обычная функция (не виртуальная)
    void draw() const {
        std::cout << "Shape::draw() called for: " << m_description << std::endl;
    }
    
    // ВИРТУАЛЬНАЯ функция для демонстрации полиморфизма со статическими членами
    // Возвращает значение статического счетчика объектов
    virtual int get_count() const {
        return m_count;
    }
    
    // СТАТИЧЕСКИЙ член класса - общий для всех объектов класса Shape
    // ВАЖНО: статические члены НЕ наследуются, каждый класс имеет свой экземпляр
    static int m_count;

protected:
    // Защищенное поле для описания фигуры
    std::string m_description;
};

#endif // SHAPE_H
