#include <cstdlib>
#include <iostream>
#include <exception>

void foo(int money)  noexcept {
        if(money<0) throw std::exception(); //непонятное исключение
    }


// Пример очень плохого стиля программирования
int main(int argc, char** argv) {
    try{
        foo(-1);
    }catch(...){
        std::cout << "Что-то пошло не так!" << std::endl;
    }
    
    std::cout << "Вот и все" << std::endl;
    
    return 0;
}

