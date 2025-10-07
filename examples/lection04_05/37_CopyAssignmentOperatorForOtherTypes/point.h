#ifndef POINT_H
#define POINT_H
#include <iostream>

class Car; // Forward declaration

class Point
{
    // Дружественная функция вывода в поток
    friend std::ostream& operator<<(std::ostream& os, const Point& point);

public:
    // Конструктор по умолчанию
    Point() = default;
    
    // Конструктор с параметрами для инициализации координат и данных
    Point(double x, double y, int data) : 
        m_x(x), m_y(y), p_data(new int(data))
    {
    }
    
    // Конструктор копирования
    Point(const Point& point);

    // Оператор присваивания копированием (Copy Assignment Operator)
    // Стандартный оператор присваивания для объектов того же типа
    Point& operator=(const Point& right_operand)
    {
        std::cout << "Copy assignment operator called" << std::endl;
        if (this != &right_operand) {
            delete p_data;
            p_data = new int(*(right_operand.p_data));
            m_x = right_operand.m_x;
            m_y = right_operand.m_y;
        }
        return *this;
    }

    // Оператор присваивания для другого типа (Car)
    // ВАЖНО: Это НЕ стандартный оператор присваивания
    // Позволяет присваивать объект Car объекту Point
    void operator=(const Car& car);

    // Метод для изменения данных
    void set_data(int data)
    {
        *p_data = data;
    }

    // Деструктор по умолчанию
    ~Point() = default;

private:
    // Метод для вычисления расстояния от начала координат (0,0) до точки
    double length() const;

private:
    double m_x{};      // Координата x точки
    double m_y{};      // Координата y точки
    int* p_data;        // Указатель на данные в куче
};

// Inline реализация оператора вывода в поток
inline std::ostream& operator<<(std::ostream& os, const Point& point)
{
    os << "Point [ x : " << point.m_x << ", y : " << point.m_y 
       << " data : " << *(point.p_data) << "]";
    return os;
}

#endif // POINT_H
