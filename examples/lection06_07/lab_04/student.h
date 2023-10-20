#pragma once
#include <concepts>
#include <iostream>

#include "human.h"

template <Number T>
class Student : public Human<T>
{
    friend std::ostream &operator<<(std::ostream &os, const Student<T> &rhv)
    {
        os << "Student [ tricky:" << rhv.tricky << ", lazy:" << rhv.lazy << ", greedy:" << rhv.greedy << "]";
        return os;
    }

private:
    T tricky{};
    T lazy{};
    T greedy{};

public:
    Student() = default;
    Student(const T &_age,
            const T &_tricky,
            const T &_lazy,
            const T &_greedy) : Human<T>(_age),
                                tricky(_tricky),
                                lazy(_lazy),
                                greedy(_greedy)
    {
    }

    // try to comment
    void print(std::ostream & os) override {
            os << *this;
        }

    T &operator[](int index)
    {
        assert(index < 3);
        switch (index)
        {
        case 0:
            return tricky;
        case 1:
            return lazy;
        case 2:
            return greedy;
        default:
            return tricky;
        }
    }
};
