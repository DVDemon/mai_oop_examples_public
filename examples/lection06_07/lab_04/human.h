#pragma once
#include <concepts>
#include <iostream>

template <typename T>
concept Number = std::is_default_constructible<T>::value || std::integral<T> || std::floating_point<T>;

template <Number T>
class Human {
        friend std::ostream &operator<<(std::ostream &os, const Human<T> &rhv)
    {
        os << "Human [ age:" << rhv.age <<  "]";
        return os;
    }
    private:
        T age;
    public:
        Human() =  default;
        Human(const T& _age) : age(_age) {

        }

        virtual void print(std::ostream & os) {
            os << *this;
        }
};