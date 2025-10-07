#ifndef POINT_H
#define POINT_H
#include <iostream>

// Forward declaration для избежания циклических зависимостей
class Number;

// Класс Point (Точка) - демонстрирует пользовательские преобразования типов
class Point
{
    // FRIEND ФУНКЦИИ для перегрузки операторов
    friend std::ostream& operator<<(std::ostream& os, const Point& p);
    friend Point operator+(const Point& left_operand, const Point& right_operand);
    friend Point operator-(const Point& left_operand, const Point& right_operand);
    friend Point& operator+=(Point& left_operand, const Point& right_operand);
    friend Point& operator-=(Point& left_operand, const Point& right_operand);

public:
    // Конструктор по умолчанию
    Point() = default;
    
    // Конструктор с параметрами - использует список инициализации
    Point(double x_coordinate, double y_coordinate)
        : m_x(x_coordinate), m_y(y_coordinate) {
    }
    
    // ПРИМЕР ЗАКОММЕНТИРОВАННОГО КОДА - конструктор преобразования
    // ВАЖНО: конструктор преобразования позволяет неявное преобразование Number -> Point
    // explicit предотвращает неявные преобразования - делает их явными
    /*
    explicit Point(const Number& number_object) {
        std::cout << "Using the Point constructor for conversion" << std::endl;
        // Преобразуем Number в Point, используя значение Number как координаты
        m_x = static_cast<double>(number_object.get_wrapped_int());
        m_y = static_cast<double>(number_object.get_wrapped_int());
    }
    */
    
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
inline std::ostream& operator<<(std::ostream& os, const Point& p) {
    os << "Point [ x: " << p.m_x << ", y: " << p.m_y << "]";
    return os;
}

// РЕАЛИЗАЦИЯ ПЕРЕГРУЖЕННОГО СОСТАВНОГО ОПЕРАТОРА СЛОЖЕНИЯ (+=)
inline Point& operator+=(Point& left_operand, const Point& right_operand) {
    left_operand.m_x += right_operand.m_x;
    left_operand.m_y += right_operand.m_y;
    return left_operand;
}

// РЕАЛИЗАЦИЯ ПЕРЕГРУЖЕННОГО СОСТАВНОГО ОПЕРАТОРА ВЫЧИТАНИЯ (-=)
inline Point& operator-=(Point& left_operand, const Point& right_operand) {
    left_operand.m_x -= right_operand.m_x;
    left_operand.m_y -= right_operand.m_y;
    return left_operand;
}

// РЕАЛИЗАЦИЯ ПЕРЕГРУЖЕННОГО АРИФМЕТИЧЕСКОГО ОПЕРАТОРА СЛОЖЕНИЯ (+)
// ПАТТЕРН ПЕРЕИСПОЛЬЗОВАНИЯ: арифметический оператор реализуется через составной оператор
inline Point operator+(const Point& left_operand, const Point& right_operand) {
    Point result_copy(left_operand);
    return result_copy += right_operand;
}

// РЕАЛИЗАЦИЯ ПЕРЕГРУЖЕННОГО АРИФМЕТИЧЕСКОГО ОПЕРАТОРА ВЫЧИТАНИЯ (-)
// ПАТТЕРН ПЕРЕИСПОЛЬЗОВАНИЯ: арифметический оператор реализуется через составной оператор
inline Point operator-(const Point& left_operand, const Point& right_operand) {
    Point result_copy(left_operand);
    return result_copy -= right_operand;
}

#endif // POINT_H
