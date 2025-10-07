#include "car.h"

// Конструктор с параметрами для инициализации цвета и скорости
Car::Car(const std::string& color, double speed) : 
    m_color(color), m_speed(speed)
{
}

// Деструктор
Car::~Car()
{
    // Деструктор пустой, т.к. нет динамической памяти для освобождения
}
