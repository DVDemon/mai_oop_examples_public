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



    // Постфиксный оператор (p++)
    // ВАЖНО: Параметр int - это фиктивный параметр для различения
    // префиксного и постфиксного операторов. Значение параметра не используется.
    Point operator++(int) {
        Point local_point(*this);  // Сохраняем текущее состояние
        m_x++;
		m_y++;                 // Инкрементируем объект (вызываем префиксный оператор)
        return local_point;        // Возвращаем старое значение
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
