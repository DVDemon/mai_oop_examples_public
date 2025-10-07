#ifndef POINT_H
#define POINT_H
#include <iostream>

class Number;

class Point
{
    // Дружественная функция вывода в поток
    friend std::ostream& operator<<(std::ostream& os, const Point& point);

public:
    // Конструктор по умолчанию
    Point() = default;
    
    // Конструктор с параметрами для инициализации координат
    Point(double x, double y) : m_x(x), m_y(y)
    {
    }

    // Перегрузка префиксного оператора инкремента (++p)
    // ВАЖНО: Префиксный оператор ++ не принимает параметров
    // 
    // ЗАМЕЧАНИЕ: В данной реализации оператор возвращает void,
    // что не позволяет использовать его в выражениях типа: Point p2 = ++p1;
    // Правильная реализация должна возвращать Point& (ссылку на себя),
    // но для демонстрации базового синтаксиса используется упрощенный вариант
    void operator++()
    {
        ++m_x;  // Увеличиваем координату x на 1
        ++m_y;  // Увеличиваем координату y на 1
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

// Inline реализация оператора вывода в поток
inline std::ostream& operator<<(std::ostream& os, const Point& point)
{
    os << "Point [ x : " << point.m_x << ", y : " << point.m_y << "]";
    return os;
}

#endif // POINT_H
