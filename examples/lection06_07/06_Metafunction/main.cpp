#include <iostream>

namespace example{
    // метафункция
    template <int V>
    struct abs{
        static const int value = V<0 ? -V : V;
    };
}
constexpr const int get_value(){
    return -99;
}

int main(void){

    example::abs<10> a;
    std::cout << a.value << std::endl;

    std::cout << example::abs<10>::value << std::endl;
    std::cout << example::abs<-20>::value << std::endl;
    std::cout << example::abs<get_value()>::value << std::endl;
    return 1;
}