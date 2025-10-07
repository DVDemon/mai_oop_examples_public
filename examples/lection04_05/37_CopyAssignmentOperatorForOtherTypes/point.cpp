#include <cmath>
#include "point.h"
#include "car.h"

// Вычисление расстояния от начала координат (0, 0) до точки
// Используется формула Евклидова расстояния: d = sqrt((x - 0)² + (y - 0)²)
double Point::length() const
{
    return sqrt(pow(m_x - 0, 2) + pow(m_y - 0, 2) * 1.0);
}

// Реализация оператора присваивания для другого типа (Car)
// ВАЖНО: Это НЕ стандартный оператор присваивания
// Позволяет присваивать объект Car объекту Point
// 
// Логика преобразования:
// - Координаты x и y устанавливаются равными скорости автомобиля
// - Данные (p_data) также устанавливаются равными скорости автомобиля
void Point::operator=(const Car& car)
{
    std::cout << "Assignment operator for Car type called" << std::endl;
    
    // Устанавливаем координаты равными скорости автомобиля
    m_x = car.get_speed();
    m_y = car.get_speed();
    
    // Устанавливаем данные равными скорости автомобиля
    *p_data = static_cast<int>(car.get_speed());
}

// Реализация конструктора копирования
Point::Point(const Point& point)
{
    std::cout << "Copy constructor called to copy point " << point << std::endl;
    
    // Проверка на самокопирование (обычно не происходит в конструкторе)
    if (this != &point) {
        // В конструкторе копирования p_data еще не инициализирован,
        // поэтому НЕ вызываем delete
        p_data = new int(*(point.p_data));       // Выделяем новую память и копируем данные
        m_x = point.m_x;                         // Копируем координату x
        m_y = point.m_y;                         // Копируем координату y
    }
}

