#include <cmath>
#include "point.h"
#include "number.h"

// ПРИМЕР ЗАКОММЕНТИРОВАННОГО КОДА - конструктор преобразования
// ВАЖНО: этот конструктор позволяет неявное преобразование Number -> Point
// explicit предотвращает неявные преобразования - делает их явными
/*
Point::Point(const Number& number_object) 
    : Point(static_cast<double>(number_object.get_wrapped_int()),
            static_cast<double>(number_object.get_wrapped_int())) {
    std::cout << "Using the Point constructor for conversion" << std::endl;
}
*/

// Реализация метода length() - вычисляет расстояние от начала координат
double Point::length() const {
    return sqrt(pow(m_x - 0, 2) + pow(m_y - 0, 2) * 1.0);
}




