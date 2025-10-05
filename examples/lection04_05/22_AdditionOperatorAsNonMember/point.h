#ifndef POINT_H
#define POINT_H
#include <iostream>

// Класс Point (Точка) - демонстрирует перегрузку операторов как friend функций
class Point
{
    // FRIEND ФУНКЦИЯ - имеет доступ к приватным членам класса
    // ПЕРЕГРУЗКА ОПЕРАТОРА + как НЕ-ЧЛЕНА КЛАССА (friend функция)
    // Синтаксис: friend ReturnType operatorOp(ParameterType1 param1, ParameterType2 param2)
    friend Point operator+(const Point& left, const Point& right);

public:
    // Конструктор по умолчанию
    Point() = default;
    
    // Конструктор с параметрами - использует список инициализации
    Point(double x, double y)
        : m_x(x), m_y(y) {
    }

    // Деструктор
    ~Point() = default;

    // Метод для вывода информации о точке
    void print_info() {
        std::cout << "Point [ x: " << m_x << ", y: " << m_y << "]" << std::endl;
    }

private:
    // Приватный метод для вычисления расстояния от начала координат
    double length() const;  // Функция для вычисления расстояния от точки (0,0)

private:
    // Приватные поля для координат точки
    // ВАЖНО: friend функция имеет доступ к этим приватным полям
    double m_x{};
    double m_y{};
};

#endif // POINT_H