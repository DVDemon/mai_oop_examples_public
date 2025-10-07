#include "number.h"

// Конструктор с параметром
// Отсутствие ключевого слова explicit позволяет использовать этот конструктор
// для неявного преобразования int -> Number
Number::Number(int value) : m_wrapped_int(value)
{
    // Для отладки можно раскомментировать:
    // std::cout << "Number constructor called with value: " << value << std::endl;
}

// Перегрузка оператора вывода в поток
// Позволяет использовать std::cout << number_object
std::ostream& operator<<(std::ostream& out, const Number& number)
{
    out << "Number : [" << number.m_wrapped_int << "]";
    return out;
}

// Перегрузка оператора сложения
// Благодаря friend-объявлению и неявному конструктору:
// - (n1 + 2) работает: 2 преобразуется в Number(2)
// - (2 + n1) работает: 2 преобразуется в Number(2)
Number operator+(const Number& left_operand, const Number& right_operand)
{
    // Для отладки можно раскомментировать:
    // std::cout << "operator+ called" << std::endl;
    return Number(left_operand.m_wrapped_int + right_operand.m_wrapped_int);
}

// Перегрузка оператора вычитания
Number operator-(const Number& left_operand, const Number& right_operand)
{
    return Number(left_operand.m_wrapped_int - right_operand.m_wrapped_int);
}

// Перегрузка оператора умножения
Number operator*(const Number& left_operand, const Number& right_operand)
{
    return Number(left_operand.m_wrapped_int * right_operand.m_wrapped_int);
}

// Перегрузка оператора деления
Number operator/(const Number& left_operand, const Number& right_operand)
{
    return Number(left_operand.m_wrapped_int / right_operand.m_wrapped_int);
}

// Перегрузка оператора взятия остатка
Number operator%(const Number& left_operand, const Number& right_operand)
{
    return Number(left_operand.m_wrapped_int % right_operand.m_wrapped_int);
}

// Деструктор
Number::~Number()
{
    // Деструктор пустой, т.к. нет динамической памяти для освобождения
}
