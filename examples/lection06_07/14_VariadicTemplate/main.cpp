#include <iostream>
#include <typeinfo>

/**
 * Шаблон для печати
 */
template <class T> void print(const T& t) {
    std::cout << t << std::endl;
}

template <class First, class... Rest> 
   void print(const First& first, const Rest&... rest) {
    std::cout << first << ", ";
    print(rest...); // хвостовая рекурсия на стадии компиляции!
}

/**
 * Шаблон для сложения
 */
template <class T> T add(const T t) {
    return t;
}

template <class First, class... T> 
First add(const First first, const T... v) {
    return first + (First) add(v...); // хвостовая рекурсия на стадии компиляции!
}

int main(int argc, char** argv) {
    //double value = add<double,double,int>(1.1, 2.0, 21);
    auto value = add(1.1, 2.0, 21);
    std::cout << typeid(value).name() <<  " " << value << std::endl;

   
    print(10, 20);
    print(100, 200, 300);
    print<int, double, int>(1, 2.0, 3);
    print("first", 2, "third", 3.14159);
    
    
    return 0;
}

