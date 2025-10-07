#ifndef CAR_H
#define CAR_H

#include <string>

class Car
{
public:
    // Конструктор по умолчанию
    Car() = default;
    
    // Конструктор с параметрами для инициализации цвета и скорости
    Car(const std::string& color, double speed);
    
    // Деструктор
    ~Car();
    
    // Геттер для получения скорости автомобиля
    double get_speed() const
    {
        return m_speed;
    }
    
    // Геттер для получения цвета автомобиля
    std::string get_color() const
    {
        return m_color;
    }

private:
    std::string m_color;  // Цвет автомобиля
    double m_speed;       // Скорость автомобиля
};

#endif // CAR_H
