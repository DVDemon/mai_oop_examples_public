#include <iostream>

void braces_1(){
    std::cout <<  "Braces 1" << std::endl;
    std::cout << (1,2,3,4,5,6) << std::endl;
}


void braces_2(){
    std::cout <<  "Braces 2" << std::endl;
    std::cout << (std::cout << "1+2=",2) << std::endl;
}

template<class... Args>
void iterate_3(Args... args) {
    std::cout <<  "Braces 3" << std::endl;
    int a[sizeof...(args)] = {args...};
    std::cout << std::endl;
    for(auto i:a) std::cout << '[' << i << ']' << std::endl;
}

template<class... Args>
void iterate_4(Args... args) {
    std::cout <<  "Braces 4" << std::endl;
    int i{0};
    int a[sizeof...(args)] = {(std::cout << args, ++i)...}; // {(std::cout << 1,1), (std::cout << 2,2),}
    std::cout << std::endl;
    for(auto i:a) std::cout << '[' << i << ']' << std::endl;
}

void braces_5() {
    std::cout <<  "Braces 5" << std::endl;
    int a[3] = {(std::cout << 1, 0), (std::cout << 2.0, 0), (std::cout << "tri", 0)};
    std::cout << std::endl;
    for(auto i:a) std::cout << '[' << i << ']' << std::endl;
}



auto main() -> int{
    braces_1();
    braces_2();
    iterate_3(1,2,3,4,5);
    iterate_4(1,2,3,4,5,"Hello");
    braces_5();

    return 1;
}