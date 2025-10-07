#ifndef POINT_H
#define POINT_H
#include <iostream>

class Number;

class Point
{
    // Дружественная функция вывода в поток
    friend std::ostream& operator<<(std::ostream& os, const Point& point);
    
    // Дружественные функции для префиксных операторов
    friend Point& operator++(Point& operand);  // Префиксный инкремент (++p)
    friend Point& operator--(Point& operand);  // Префиксный декремент (--p)

public:
    // Конструктор по умолчанию
    Point() = default;
    
    // Конструктор с параметрами для инициализации координат
    Point(double x, double y) : m_x(x), m_y(y)
    {
    }

    // Деструктор по умолчанию
    ~Point() = default;

private:
    // Метод для вычисления расстояния от начала координат (0,0) до точки
    double length() const;

private:
    double m_x{};  // Координата x точки
    double m_y{};  // Координата y точки
};

// Объявления постфиксных операторов как внешних функций
// ВАЖНО: Параметр int - это фиктивный параметр для различения
// префиксных (без параметров) и постфиксных (с int параметром) операторов
Point operator++(Point& operand, int);  // Постфиксный инкремент (p++)
Point operator--(Point& operand, int);  // Постфиксный декремент (p--)

// Inline реализация оператора вывода в поток
inline std::ostream& operator<<(std::ostream& os, const Point& point)
{
    os << "Point [ x : " << point.m_x << ", y : " << point.m_y << "]";
    return os;
}

#endif // POINT_H
