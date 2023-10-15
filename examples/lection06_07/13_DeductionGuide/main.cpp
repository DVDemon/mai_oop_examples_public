#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>

template <class T>
struct MyStruct{
    T value;
     MyStruct(T other) {
        value = other;
    }
};


MyStruct(const char*) -> MyStruct<std::string>; // help to deduct type


int main ()
{
    MyStruct m(1); // template type deduction by constructor
    MyStruct m2("Hello world");

    std::cout << "int:" << m.value << std::endl; 
    std::cout << "type:" << m2.value.size() << std::endl;

    return 0;
}