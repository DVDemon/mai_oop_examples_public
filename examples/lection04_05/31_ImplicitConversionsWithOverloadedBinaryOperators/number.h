#include <iostream>

class Number
{
    // Дружественная функция вывода в поток
    friend std::ostream& operator<<(std::ostream& out, const Number& number);

    // Дружественные арифметические операторы
    // ВАЖНО: Объявление операторов как friend-функций позволяет неявное преобразование
    // для ОБОИХ операндов (левого и правого). Это позволяет писать как n1 + 2, так и 2 + n1
    friend Number operator+(const Number& left_operand, const Number& right_operand);
    friend Number operator-(const Number& left_operand, const Number& right_operand);
    friend Number operator*(const Number& left_operand, const Number& right_operand);
    friend Number operator/(const Number& left_operand, const Number& right_operand);
    friend Number operator%(const Number& left_operand, const Number& right_operand);

public:
    // Конструктор по умолчанию
    Number() = default;
    
    // Конструктор НЕ explicit - позволяет неявное преобразование из int в Number
    // Например: Number n = 5; или при вызове функции, ожидающей Number
    Number(int value);

    // Явный оператор преобразования в double
    // Ключевое слово explicit запрещает неявное преобразование Number -> double
    // Нужно писать: double d = static_cast<double>(n);
    explicit operator double() const {
        return static_cast<double>(m_wrapped_int);
    }

    /*
    ВАЖНОЕ ЗАМЕЧАНИЕ для студентов:
    Если бы мы объявили operator+ как метод класса (а не friend-функцию):
    
    Number operator+(const Number& right_operand) const {
        return Number(m_wrapped_int + right_operand.m_wrapped_int);
    }
    
    То выражение (n1 + 2) работало бы корректно (2 неявно преобразуется в Number),
    НО выражение (2 + n1) НЕ работало бы, т.к. у int нет метода operator+,
    принимающего Number.
    
    С friend-функцией оба операнда могут быть неявно преобразованы,
    поэтому работают оба варианта: (n1 + 2) и (2 + n1)
    */

    // Геттер для получения обернутого значения
    int get_wrapped_int() const {
        return m_wrapped_int;
    }

    ~Number();

private:
    int m_wrapped_int{0};  // Обернутое целое число
};