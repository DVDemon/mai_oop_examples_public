#ifndef POINT_H
#define POINT_H
#include <iostream>
#include <utility>

// Класс Point (Точка) - демонстрирует перегрузку составных операторов и переиспользование
class Point
{
    // FRIEND ФУНКЦИИ для перегрузки операторов
    // ПЕРЕГРУЗКА ОПЕРАТОРА ПОТОКОВОГО ВЫВОДА (<<) как friend функции
    friend std::ostream& operator<<(std::ostream& os, const Point& p);
    
    // ПЕРЕГРУЗКА АРИФМЕТИЧЕСКИХ ОПЕРАТОРОВ как friend функций
    // ВАЖНО: арифметические операторы переиспользуют составные операторы
    friend Point operator+(const Point& left_operand, const Point& right_operand);
    friend Point operator-(const Point& left_operand, const Point& right_operand);

    // ПЕРЕГРУЗКА СОСТАВНЫХ ОПЕРАТОРОВ как friend функций
    // ВАЖНО: составные операторы изменяют левый операнд и возвращают ссылку на него
    friend Point& operator+=(Point& left_operand, const Point& right_operand);
    friend Point& operator-=(Point& left_operand, const Point& right_operand);

    // ПЕРЕГРУЗКА СОСТАВНЫХ ОПЕРАТОРОВ как friend функций
    // ВАЖНО: составные операторы изменяют левый операнд и возвращают rvalue ссылку на него - это надо для цепочек вычислений A += B -= C
    friend Point&& operator+=(Point&& left_operand, const Point&& right_operand);
    friend Point&& operator-=(Point&& left_operand, const Point&& right_operand);

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

// РЕАЛИЗАЦИЯ ПЕРЕГРУЖЕННОГО СОСТАВНОГО ОПЕРАТОРА СЛОЖЕНИЯ (+=)
// ВАЖНО: это friend функция - имеет доступ к приватным членам класса
// inline для оптимизации - функция определена в заголовочном файле
inline Point& operator+=(Point& left_operand, const Point& right_operand) {
    // СОСТАВНОЕ СЛОЖЕНИЕ: изменяем левый операнд, добавляя к нему правый
    // FRIEND функция имеет прямой доступ к приватным полям left_operand.m_x, left_operand.m_y
    // и right_operand.m_x, right_operand.m_y
    
    // ВАЖНО: изменяем левый операнд (left_operand)
    left_operand.m_x += right_operand.m_x;
    left_operand.m_y += right_operand.m_y;
    
    // ВАЖНО: возвращаем ссылку на измененный левый операнд для возможности цепочки операторов
    return std::ref(left_operand);
}

inline Point&& operator+=(Point&& left_operand, const Point&& right_operand) {
    // СОСТАВНОЕ СЛОЖЕНИЕ: изменяем левый операнд, добавляя к нему правый
    // FRIEND функция имеет прямой доступ к приватным полям left_operand.m_x, left_operand.m_y
    // и right_operand.m_x, right_operand.m_y
    
    // ВАЖНО: изменяем левый операнд (left_operand)
    left_operand.m_x += right_operand.m_x;
    left_operand.m_y += right_operand.m_y;
    
    // ВАЖНО: возвращаем ссылку на измененный левый операнд для возможности цепочки операторов
    return std::move(left_operand);
}

// РЕАЛИЗАЦИЯ ПЕРЕГРУЖЕННОГО СОСТАВНОГО ОПЕРАТОРА ВЫЧИТАНИЯ (-=)
// ВАЖНО: это friend функция - имеет доступ к приватным членам класса
// inline для оптимизации - функция определена в заголовочном файле
inline Point& operator-=(Point& left_operand, const Point& right_operand) {
    // СОСТАВНОЕ ВЫЧИТАНИЕ: изменяем левый операнд, вычитая из него правый
    // FRIEND функция имеет прямой доступ к приватным полям left_operand.m_x, left_operand.m_y
    // и right_operand.m_x, right_operand.m_y
    
    // ВАЖНО: изменяем левый операнд (left_operand)
    left_operand.m_x -= right_operand.m_x;
    left_operand.m_y -= right_operand.m_y;
    
    // ВАЖНО: возвращаем ссылку на измененный левый операнд для возможности цепочки операторов
    return std::ref(left_operand);
}

inline Point&& operator-=(Point&& left_operand, const Point&& right_operand) {
    // СОСТАВНОЕ ВЫЧИТАНИЕ: изменяем левый операнд, вычитая из него правый
    // FRIEND функция имеет прямой доступ к приватным полям left_operand.m_x, left_operand.m_y
    // и right_operand.m_x, right_operand.m_y
    
    // ВАЖНО: изменяем левый операнд (left_operand)
    left_operand.m_x -= right_operand.m_x;
    left_operand.m_y -= right_operand.m_y;
    
    // ВАЖНО: возвращаем ссылку на измененный левый операнд для возможности цепочки операторов
    return std::move(left_operand);
}

// РЕАЛИЗАЦИЯ ПЕРЕГРУЖЕННОГО АРИФМЕТИЧЕСКОГО ОПЕРАТОРА СЛОЖЕНИЯ (+)
// ВАЖНО: это friend функция - имеет доступ к приватным членам класса
// inline для оптимизации - функция определена в заголовочном файле
// ПАТТЕРН ПЕРЕИСПОЛЬЗОВАНИЯ: арифметический оператор реализуется через составной оператор
inline Point operator+(const Point& left_operand, const Point& right_operand) {
    // ПЕРЕИСПОЛЬЗОВАНИЕ СОСТАВНОГО ОПЕРАТОРА +=
    // 1. Создаем копию левого операнда
    Point result_copy(left_operand);
    
    // 2. Используем составной оператор += для изменения копии
    result_copy += std::ref(right_operand);
    
    // 3. Возвращаем измененную копию
    return result_copy;
    
    // АЛЬТЕРНАТИВНАЯ ЗАПИСЬ: return result_copy += right_operand;
}

// РЕАЛИЗАЦИЯ ПЕРЕГРУЖЕННОГО АРИФМЕТИЧЕСКОГО ОПЕРАТОРА ВЫЧИТАНИЯ (-)
// ВАЖНО: это friend функция - имеет доступ к приватным членам класса
// inline для оптимизации - функция определена в заголовочном файле
// ПАТТЕРН ПЕРЕИСПОЛЬЗОВАНИЯ: арифметический оператор реализуется через составной оператор
inline Point operator-(const Point& left_operand, const Point& right_operand) {
    // ПЕРЕИСПОЛЬЗОВАНИЕ СОСТАВНОГО ОПЕРАТОРА -=
    // 1. Создаем копию левого операнда
    Point result_copy(left_operand);
    
    // 2. Используем составной оператор -= для изменения копии
    result_copy -= std::ref(right_operand);
    
    // 3. Возвращаем измененную копию
    return result_copy;
    
    // АЛЬТЕРНАТИВНАЯ ЗАПИСЬ: return result_copy -= right_operand;
}

#endif // POINT_H
