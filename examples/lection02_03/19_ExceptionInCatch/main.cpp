#include <cstdlib>
#include <iostream>
#include <exception>

class PrintCheck{
public:
    PrintCheck(int money){
        if(money<0) throw std::exception(); //непонятное исключение
        std::cout << "Total:" << money << std::endl;
    }
};

// Пример очень плохого стиля программирования
int main(int argc, char** argv) {

    int money = 0;
    try{
        
        std::cin >> money;
        if(money<0) throw std::exception(); // непонятное исключение
        if(money==0) throw 0;
        
    }catch(std::exception ex){
        std::cout << "Да у тебя кредит!?" << std::endl;
        PrintCheck A(money); // А вот тут исключение уже не ловится
    }catch(int){
        std::cout << "Голытьба!" << std::endl;
    }
    
    std::cout << "Thank you for your money:" << money << std::endl;
    
    return 0;
}

