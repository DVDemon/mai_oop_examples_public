#include <thread>
#include <iostream>
#include <cmath>

void my_function(){
    std::cout << "Start work " << std::endl;
    double result = 0;
    for(uint64_t i=1;i<900000000;i++) result+=std::log10(i);
    std::cout << "Done " << std::endl;
}


int main() {

    std:: cout << "Single thread:" << std::endl;
    my_function();
    my_function();
    
    std::cout << std::endl << "Two thread:" << std::endl;
    std::thread my_thread1(my_function);
    std::thread my_thread2(my_function);
    
    std::cout << "3rd thread" << std::endl;
    
    my_thread1.join();
    my_thread2.join();
    

    return 0;
}

