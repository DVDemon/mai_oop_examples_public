
#ifndef NUMBER_H
#define NUMBER_H

#include <iostream>
#include "point.h"

// Класс Number (Число) - демонстрирует пользовательские преобразования типов
// Включает преобразующие операторы (conversion operators)
class Number
{
    // FRIEND ФУНКЦИИ для перегрузки операторов
    friend std::ostream& operator<<(std::ostream& output_stream, const Number& number_object);

    // АРИФМЕТИЧЕСКИЕ ОПЕРАТОРЫ как friend функций
    friend Number operator+(const Number& left_operand, const Number& right_operand);
    friend Number operator-(const Number& left_operand, const Number& right_operand);
    friend Number operator*(const Number& left_operand, const Number& right_operand);
    friend Number operator/(const Number& left_operand, const Number& right_operand);
    friend Number operator%(const Number& left_operand, const Number& right_operand);

public:
    // Конструктор по умолчанию
    Number() = default;
    
    // Конструктор с параметром - использует список инициализации
    Number(int integer_value);

    // ПРЕОБРАЗУЮЩИЕ ОПЕРАТОРЫ (Conversion Operators)
    // ВАЖНО: explicit предотвращает неявные преобразования, делает их явными
    
    // ОПЕРАТОР ПРЕОБРАЗОВАНИЯ В DOUBLE
    // explicit означает, что преобразование Number -> double должно быть явным
    explicit operator double() const {
        // Преобразуем int в double
        return static_cast<double>(m_wrapped_int);
    }
    
    // ОПЕРАТОР ПРЕОБРАЗОВАНИЯ В POINT
    // explicit означает, что преобразование Number -> Point должно быть явным
    explicit operator Point() const {
        std::cout << "Custom conversion from Number to Point" << std::endl;
        // Преобразуем Number в Point, используя значение как обе координаты
        return Point(static_cast<double>(m_wrapped_int),
                     static_cast<double>(m_wrapped_int));
    }

    // Геттер для получения обернутого значения
    int get_wrapped_int() const {
        return m_wrapped_int;
    }

    // Деструктор
    ~Number();

private:
    // Приватное поле для хранения обернутого целого числа
    int m_wrapped_int{0};
};

#endif // NUMBER_H