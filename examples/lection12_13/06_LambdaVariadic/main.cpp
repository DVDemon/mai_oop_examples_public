#include <iostream>
#include <functional>

template <class T, class ...Ts>
auto concat(T t, Ts ...ts)
{
    if constexpr (sizeof...(ts) > 0) {
        return [=](auto ...parameters) {
          return t(concat(ts...)(parameters...)); };
    } else  {
        return t; // возвращает самую правую функцию
    }
}

// int plus(int a,int b){
//     std::cout << " sum("<< a << ","<< b <<")>" ;
//     return a+b;
// };

int main()
{
    auto plus   = [] (int a,int b) {std::cout << " sum("<< a << ","<< b <<")>" ; return a+b;};
    auto twice  = [] (int i) { std::cout << " twice>" << i << ' ';return i * 2; };
    auto thrice = [] (int i) { std::cout << " thrice>" << i << ' '; return i * 3; };

    auto combined = concat(twice, thrice, plus);

    /*
     t(int a, int b) -> plus(2,3)
     t(concat(t)(int a, int b)) -> t(t(int a, int b)) -> thrice(plus(int a, int b)) 

     ....combined(int a, int b) -> twice(thrice(plus(int a, int b)))
    */

    std::cout << combined(2, 3) << std::endl;
    //twice(thrice(plus(2,3)));
}
