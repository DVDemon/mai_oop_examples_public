#ifndef POINT_H
#define POINT_H
#include <iostream>
#include <cassert>

// Класс Point (Точка) - демонстрирует перегрузку оператора [] для чтения
class Point
{
public:
    // Конструктор по умолчанию
    Point() = default;
    
    // Конструктор с параметрами - использует список инициализации
    Point(double x, double y)
        : m_x(x), m_y(y) {
    }
    
    // Деструктор
    ~Point() = default;

    // ПЕРЕГРУЗКА ОПЕРАТОРА [] для ЧТЕНИЯ (только чтение)
    // Синтаксис: ReturnType operator[](ParameterType index) const
    // ВАЖНО: const метод - НЕ МОЖЕТ изменять объект, только читать
    double operator[](size_t index) const {
        // ASSERT для проверки корректности индекса
        // ВАЖНО: assert проверяет условие и завершает программу при ошибке
        assert((index == 0) || (index == 1));
        
        // Логика доступа к координатам по индексу
        if (index == 0) {
            return m_x;  // Индекс 0 - координата X
        } else {
            return m_y;  // Индекс 1 - координата Y
        }
    }

    // Метод для вывода информации о точке
    void print_info() {
        std::cout << "Point [ x: " << m_x << ", y: " << m_y << "]" << std::endl;
    }

private:
    // Приватный метод для вычисления расстояния от начала координат
    double length() const;  // Функция для вычисления расстояния от точки (0,0)

private:
    // Приватные поля для координат точки
    // ВАЖНО: индексы соответствуют: 0 = m_x, 1 = m_y
    double m_x{};  // Индекс 0 - координата X
    double m_y{};  // Индекс 1 - координата Y
};

#endif // POINT_H
