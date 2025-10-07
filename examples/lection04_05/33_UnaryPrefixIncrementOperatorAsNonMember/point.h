#ifndef POINT_H
#define POINT_H
#include <iostream>

class Number;

class Point
{
    // Дружественная функция вывода в поток
    friend std::ostream& operator<<(std::ostream& os, const Point& point);
    
    // Дружественная функция для префиксного оператора инкремента
    // ВАЖНО: Объявление как friend позволяет функции-оператору
    // обращаться к приватным членам класса
    friend void operator++(Point& operand);

public:
    // Конструктор по умолчанию
    Point() = default;
    
    // Конструктор с параметрами для инициализации координат
    Point(double x, double y) : m_x(x), m_y(y)
    {
    }

    /*
    АЛЬТЕРНАТИВНАЯ РЕАЛИЗАЦИЯ - оператор как метод класса:
    
    void operator++() {
        ++m_x;
        ++m_y;
    }
    
    В данном примере используется friend-функция для демонстрации
    различий между методами класса и внешними функциями-операторами
    */

    // Деструктор по умолчанию
    ~Point() = default;

private:
    // Метод для вычисления расстояния от начала координат (0,0) до точки
    double length() const;

private:
    double m_x{};  // Координата x точки
    double m_y{};  // Координата y точки
};

/*
АЛЬТЕРНАТИВНАЯ РЕАЛИЗАЦИЯ - inline friend-функция в заголовке:

inline void operator++(Point& operand) {
    ++(operand.m_x);
    ++(operand.m_y);
}

В данном примере реализация вынесена в .cpp файл для демонстрации
различных подходов к организации кода
*/

// Inline реализация оператора вывода в поток
inline std::ostream& operator<<(std::ostream& os, const Point& point)
{
    os << "Point [ x : " << point.m_x << ", y : " << point.m_y << "]";
    return os;
}

#endif // POINT_H
