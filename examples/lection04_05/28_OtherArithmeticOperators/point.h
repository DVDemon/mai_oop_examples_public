#ifndef POINT_H
#define POINT_H
#include <iostream>

// Класс Point (Точка) - демонстрирует перегрузку арифметических операторов
class Point
{
    // FRIEND ФУНКЦИИ для перегрузки операторов
    // ПЕРЕГРУЗКА ОПЕРАТОРА ПОТОКОВОГО ВЫВОДА (<<) как friend функции
    friend std::ostream& operator<<(std::ostream& os, const Point& p);
    
    // ПЕРЕГРУЗКА АРИФМЕТИЧЕСКИХ ОПЕРАТОРОВ как friend функций
    // ВАЖНО: арифметические операторы обычно перегружаются как friend функции
    // для обеспечения симметрии и возможности работы с разными типами операндов
    
    // ОПЕРАТОР СЛОЖЕНИЯ (+) - возвращает новый объект
    friend Point operator+(const Point& left_operand, const Point& right_operand);
    
    // ОПЕРАТОР ВЫЧИТАНИЯ (-) - возвращает новый объект
    friend Point operator-(const Point& left_operand, const Point& right_operand);

public:
    // Конструктор по умолчанию
    Point() = default;
    
    // Конструктор с параметрами - использует список инициализации
    Point(double x_coordinate, double y_coordinate)
        : m_x(x_coordinate), m_y(y_coordinate) {
    }
    
    // Деструктор
    ~Point() = default;

    // Метод для вывода информации о точке (альтернатива оператору <<)
    void print_info() {
        std::cout << "Point [ x: " << m_x << ", y: " << m_y << "]" << std::endl;
    }

private:
    // Приватный метод для вычисления расстояния от начала координат
    double length() const;  // Функция для вычисления расстояния от точки (0,0)

private:
    // Приватные поля для координат точки
    double m_x{};  // Координата X
    double m_y{};  // Координата Y
};

// РЕАЛИЗАЦИЯ ПЕРЕГРУЖЕННОГО ОПЕРАТОРА ПОТОКОВОГО ВЫВОДА (<<)
// ВАЖНО: это friend функция - имеет доступ к приватным членам класса
// inline для оптимизации - функция определена в заголовочном файле
inline std::ostream& operator<<(std::ostream& os, const Point& p) {
    // FRIEND функция имеет прямой доступ к приватным полям p.m_x и p.m_y
    os << "Point [ x: " << p.m_x << ", y: " << p.m_y << "]";
    
    // ВАЖНО: возвращаем ссылку на поток для возможности цепочки операторов
    return os;
}

// РЕАЛИЗАЦИЯ ПЕРЕГРУЖЕННОГО ОПЕРАТОРА СЛОЖЕНИЯ (+)
// ВАЖНО: это friend функция - имеет доступ к приватным членам класса
// inline для оптимизации - функция определена в заголовочном файле
inline Point operator+(const Point& left_operand, const Point& right_operand) {
    // СЛОЖЕНИЕ ТОЧЕК: складываем соответствующие координаты
    // FRIEND функция имеет прямой доступ к приватным полям left_operand.m_x, left_operand.m_y
    // и right_operand.m_x, right_operand.m_y
    
    // ВАЖНО: возвращаем НОВЫЙ объект Point - не изменяем исходные объекты!
    return Point(left_operand.m_x + right_operand.m_x, 
                 left_operand.m_y + right_operand.m_y);
}

// РЕАЛИЗАЦИЯ ПЕРЕГРУЖЕННОГО ОПЕРАТОРА ВЫЧИТАНИЯ (-)
// ВАЖНО: это friend функция - имеет доступ к приватным членам класса
// inline для оптимизации - функция определена в заголовочном файле
inline Point operator-(const Point& left_operand, const Point& right_operand) {
    // ВЫЧИТАНИЕ ТОЧЕК: вычитаем соответствующие координаты
    // FRIEND функция имеет прямой доступ к приватным полям left_operand.m_x, left_operand.m_y
    // и right_operand.m_x, right_operand.m_y
    
    // ВАЖНО: возвращаем НОВЫЙ объект Point - не изменяем исходные объекты!
    return Point(left_operand.m_x - right_operand.m_x, 
                 left_operand.m_y - right_operand.m_y);
}

#endif // POINT_H
