#ifndef POINT_H
#define POINT_H
#include <iostream>

// Класс Point (Точка) - демонстрирует перегрузку операторов как методов класса
class Point
{
public:
    // Конструктор по умолчанию
    Point() = default;
    
    // Конструктор с параметрами - использует список инициализации
    Point(double x, double y)
        : m_x(x), m_y(y) {
    }
    
    // Деструктор
    ~Point() = default;

    // ПЕРЕГРУЗКА ОПЕРАТОРА + как МЕТОД КЛАССА
    // Синтаксис: Point operator+(const Point& right_operand)
    // Вызывается как: point1 + point2 (что эквивалентно point1.operator+(point2))
    Point operator+(const Point& right_operand);

    // ПРИМЕР ЗАКОММЕНТИРОВАННОГО КОДА - inline реализация:
    /*
    Point operator+(const Point& right_operand) {
        return Point(m_x + right_operand.m_x,
                     m_y + right_operand.m_y);
    }
    */

    // Метод для вывода информации о точке
    void print_info() {
        std::cout << "Point [ x: " << m_x << ", y: " << m_y << "]" << std::endl;
    }

private:
    // Приватный метод для вычисления расстояния от начала координат
    double length() const;  // Функция для вычисления расстояния от точки (0,0)

private:
    // Приватные поля для координат точки
    double m_x{};
    double m_y{};
};

#endif // POINT_H
