#include "number.h"
#include "point.h"

// Конструктор с параметром
// Отсутствие ключевого слова explicit позволяет использовать этот конструктор
// для неявного преобразования int -> Number
Number::Number(int value) : m_wrapped_int(value)
{
}

// Реализация оператора преобразования типа из Number в Point
// СПОСОБ 2: Неявное преобразование Number -> Point
// Позволяет использовать Number везде, где ожидается Point
Number::operator Point() const
{
    std::cout << "Using type conversion from Number to Point" << std::endl;
    return Point(static_cast<double>(m_wrapped_int),
                 static_cast<double>(m_wrapped_int));
}

// Реализация оператора вывода в поток
std::ostream& operator<<(std::ostream& out, const Number& number)
{
    out << "Number : [" << number.m_wrapped_int << "]";
    return out;
}

// Арифметические операторы реализованы как внешние friend-функции
// ВАЖНО: Это позволяет неявное преобразование для ОБОИХ операндов
// Например: n1 + 5 (5 преобразуется в Number(5))
//          5 + n1 (5 преобразуется в Number(5))

Number operator+(const Number& left_operand, const Number& right_operand)
{
    return Number(left_operand.m_wrapped_int + right_operand.m_wrapped_int);
}

Number operator-(const Number& left_operand, const Number& right_operand)
{
    return Number(left_operand.m_wrapped_int - right_operand.m_wrapped_int);
}

Number operator*(const Number& left_operand, const Number& right_operand)
{
    return Number(left_operand.m_wrapped_int * right_operand.m_wrapped_int);
}

Number operator/(const Number& left_operand, const Number& right_operand)
{
    return Number(left_operand.m_wrapped_int / right_operand.m_wrapped_int);
}

Number operator%(const Number& left_operand, const Number& right_operand)
{
    return Number(left_operand.m_wrapped_int % right_operand.m_wrapped_int);
}

// Деструктор
Number::~Number()
{
    // Деструктор пустой, т.к. нет динамической памяти для освобождения
}


