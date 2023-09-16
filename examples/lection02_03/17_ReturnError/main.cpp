#include <iostream>
#include <exception>

bool print_div(int a,int b){
    if(b!=0) {
        std::cout << (a/b) << std::endl;
        return true;
    } else return false;  
}

int calculate_div(int a,int b, bool& result){
    if(b!=0) {
        result = true;
        return (a/b);
    } else {
        result = false;
        return 0; // why zero? 
    }
}


int calculate_div(int a,int b){
    // проверки
    if(b==0) throw std::logic_error("b can't be equal to zero");

    // алгоритм
    return a/b;
}

int main(){

    if(!print_div(4,2)) std::cout << "error" << std::endl;
    if(!print_div(4,0)) std::cout << "error" << std::endl;

    bool result{};
    int c{};
    
    c= calculate_div(4,2,result);
    if(result) std::cout << "4/2=" << c << std::endl;

    c= calculate_div(4,0,result);
    if(!result) std::cout << "4/0 has no reasons" << std::endl;

    try{
        std::cout << "result:" << calculate_div(4,0) << std::endl;
        // ...
    }catch(std::exception& ex){ //try to remove &
        std::cout <<"exception:" <<  ex.what() << std::endl;
    }

    std::cout << "End of code" << std::endl;
    return 0;
}