#include "number.h"



Number::Number(int value) : m_wrapped_int(value)
{
    //std::cout << "construct:" << value << std::endl;
}

std::ostream& operator<<(std::ostream& out , const Number& number){
    out << "Number : [" << number.m_wrapped_int << "]";
    return out;
}



Number operator+(const Number& left_operand, const Number& right_operand){
 //std::cout << "plus operator" << std::endl;
 return Number(left_operand.m_wrapped_int + right_operand.m_wrapped_int);    
}

Number operator-(const Number& left_operand, const Number& right_operand){
 return Number(left_operand.m_wrapped_int - right_operand.m_wrapped_int);    
}
Number operator*(const Number& left_operand, const Number& right_operand){
 return Number(left_operand.m_wrapped_int * right_operand.m_wrapped_int);    
}
Number operator/(const Number& left_operand, const Number& right_operand){
 return Number(left_operand.m_wrapped_int / right_operand.m_wrapped_int);    
}
Number operator%(const Number& left_operand, const Number& right_operand){
 return Number(left_operand.m_wrapped_int % right_operand.m_wrapped_int);    
    
}

Number::~Number()
{
}
