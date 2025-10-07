#include "number.h"

// Конструктор с параметром - использует список инициализации
Number::Number(int integer_value) 
    : m_wrapped_int(integer_value) {
}

// РЕАЛИЗАЦИЯ ПЕРЕГРУЖЕННОГО ОПЕРАТОРА ПОТОКОВОГО ВЫВОДА (<<)
// ВАЖНО: это friend функция - имеет доступ к приватным членам класса
std::ostream& operator<<(std::ostream& output_stream, const Number& number_object) {
    // FRIEND функция имеет прямой доступ к приватному полю number_object.m_wrapped_int
    output_stream << "Number: [" << number_object.m_wrapped_int << "]";
    
    // ВАЖНО: возвращаем ссылку на поток для возможности цепочки операторов
    return output_stream;
}

// РЕАЛИЗАЦИЯ ПЕРЕГРУЖЕННОГО АРИФМЕТИЧЕСКОГО ОПЕРАТОРА СЛОЖЕНИЯ (+)
// ВАЖНО: это friend функция - имеет доступ к приватным членам класса
Number operator+(const Number& left_operand, const Number& right_operand) {
    // СЛОЖЕНИЕ: складываем обернутые значения
    return Number(left_operand.m_wrapped_int + right_operand.m_wrapped_int);
}

// РЕАЛИЗАЦИЯ ПЕРЕГРУЖЕННОГО АРИФМЕТИЧЕСКОГО ОПЕРАТОРА ВЫЧИТАНИЯ (-)
// ВАЖНО: это friend функция - имеет доступ к приватным членам класса
Number operator-(const Number& left_operand, const Number& right_operand) {
    // ВЫЧИТАНИЕ: вычитаем обернутые значения
    return Number(left_operand.m_wrapped_int - right_operand.m_wrapped_int);
}

// РЕАЛИЗАЦИЯ ПЕРЕГРУЖЕННОГО АРИФМЕТИЧЕСКОГО ОПЕРАТОРА УМНОЖЕНИЯ (*)
// ВАЖНО: это friend функция - имеет доступ к приватным членам класса
Number operator*(const Number& left_operand, const Number& right_operand) {
    // УМНОЖЕНИЕ: умножаем обернутые значения
    return Number(left_operand.m_wrapped_int * right_operand.m_wrapped_int);
}

// РЕАЛИЗАЦИЯ ПЕРЕГРУЖЕННОГО АРИФМЕТИЧЕСКОГО ОПЕРАТОРА ДЕЛЕНИЯ (/)
// ВАЖНО: это friend функция - имеет доступ к приватным членам класса
Number operator/(const Number& left_operand, const Number& right_operand) {
    // ДЕЛЕНИЕ: делим обернутые значения (целочисленное деление)
    return Number(left_operand.m_wrapped_int / right_operand.m_wrapped_int);
}

// РЕАЛИЗАЦИЯ ПЕРЕГРУЖЕННОГО АРИФМЕТИЧЕСКОГО ОПЕРАТОРА ОСТАТКА ОТ ДЕЛЕНИЯ (%)
// ВАЖНО: это friend функция - имеет доступ к приватным членам класса
Number operator%(const Number& left_operand, const Number& right_operand) {
    // ОСТАТОК ОТ ДЕЛЕНИЯ: вычисляем остаток от деления обернутых значений
    return Number(left_operand.m_wrapped_int % right_operand.m_wrapped_int);
}

// Деструктор
Number::~Number() {
}
