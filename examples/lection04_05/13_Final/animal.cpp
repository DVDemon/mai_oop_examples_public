#include "animal.h"

// Конструктор с параметрами - использует список инициализации
Animal::Animal(std::string_view description)
    : m_description(description)
{
}

// Виртуальный деструктор
// ВАЖНО: виртуальный деструктор обеспечивает правильное уничтожение объектов в полиморфной иерархии
Animal::~Animal() {
}

