#include <iostream>
#include <string>

template <class ...Ts> struct  overloaded : Ts ...{
    using Ts::operator() ...;
};

template <class ...Ts>  overloaded(Ts ...) -> overloaded<Ts ...>;


auto main() -> int{

    auto func = overloaded {
        [](int i){
            std::cout << i << std::endl;
        },
        [](std::string str){
            std::cout << str << std::endl;
        }
    };

    func(7);
    func("hello world!");

    return 1;
}