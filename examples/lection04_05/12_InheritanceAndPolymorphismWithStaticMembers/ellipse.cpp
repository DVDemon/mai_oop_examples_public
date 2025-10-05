#include "ellipse.h"

// ИНИЦИАЛИЗАЦИЯ собственного статического члена класса Ellipse
// ВАЖНО: это НЕ тот же счетчик, что и Shape::m_count!
int Ellipse::m_count{0};

// Конструктор с параметрами
Ellipse::Ellipse(double x_radius, double y_radius,
                 std::string_view description)
    : Shape(description), m_x_radius(x_radius),
                          m_y_radius(y_radius)
{
    // При создании объекта Ellipse увеличиваем СВОЙ статический счетчик
    // ВАЖНО: Shape::m_count тоже увеличится в конструкторе Shape!
    ++m_count;  // Увеличиваем Ellipse::m_count
}

// Конструктор по умолчанию
Ellipse::Ellipse()
    : Ellipse(0.0, 0.0, "NoDescription")
{
}

// Деструктор
Ellipse::~Ellipse()
{
    // При уничтожении объекта Ellipse уменьшаем СВОЙ статический счетчик
    // ВАЖНО: Shape::m_count тоже уменьшится в деструкторе Shape!
    --m_count;  // Уменьшаем Ellipse::m_count
}

