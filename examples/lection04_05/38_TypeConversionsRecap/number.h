#ifndef NUMBER_H
#define NUMBER_H

#include <iostream>

class Point;

class Number
{
    // Дружественная функция вывода в поток
    friend std::ostream& operator<<(std::ostream& out, const Number& number);
    
    // Дружественные арифметические операторы
    // ВАЖНО: Объявление операторов как friend-функций позволяет неявное преобразование
    // для ОБОИХ операндов (левого и правого)
    friend Number operator+(const Number& left_operand, const Number& right_operand);
    friend Number operator-(const Number& left_operand, const Number& right_operand);
    friend Number operator*(const Number& left_operand, const Number& right_operand);
    friend Number operator/(const Number& left_operand, const Number& right_operand);
    friend Number operator%(const Number& left_operand, const Number& right_operand);

public:
    // Конструктор по умолчанию
    Number() = default;
    
    // Конструктор с параметром (НЕ explicit - позволяет неявное преобразование)
    Number(int value);

    // Оператор преобразования типа из Number в Point
    // СПОСОБ 2: Неявное преобразование Number -> Point
    // Позволяет использовать Number везде, где ожидается Point
    operator Point() const;

    // Геттер для получения обернутого значения
    int get_wrapped_int() const
    {
        return m_wrapped_int;
    }

    // Деструктор
    ~Number();

private:
    int m_wrapped_int{0};  // Обернутое целое число
};

#endif // NUMBER_H
