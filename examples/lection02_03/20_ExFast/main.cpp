#include <iostream>
#include <chrono>

int calc(int param,int &error){
    switch(param){
        case 0: error = 1;
                return 0;
        default: 
                return param;
    }
};

int calc(int param){
    switch(param){
        case 0: throw 1;
        default: 
                return param;
    }
};


int main(){

    int value = 0;
    int error = 0;

    // без исключений
    std::chrono::time_point<std::chrono::high_resolution_clock> start 
    = std::chrono::high_resolution_clock::now();
    for(int i=0;i<1000000;++i) 
        value += calc(i%2,error);
    std::chrono::time_point<std::chrono::high_resolution_clock> finish 
    = std::chrono::high_resolution_clock::now();

    std::cout << "result = " << std::chrono::duration_cast<std::chrono::microseconds>(finish-start).count() << std::endl;
    


    // теперь помереем исключения
    value = 0;
    start = std::chrono::high_resolution_clock::now();
    for(int i=0;i<1000000;++i){
        try{
        value += calc(i%2);
        }catch(...){
            ++error;
        }
    }
    finish = std::chrono::high_resolution_clock::now();

    std::cout << "result = " << std::chrono::duration_cast<std::chrono::microseconds>(finish-start).count() << std::endl;
    
    
    return 0;
}