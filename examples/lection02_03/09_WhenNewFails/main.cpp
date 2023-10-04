#include <iostream>


int a;

namespace dd_example {
    int a;
}

int main(){

    a = 0;
    dd_example::a = 0;
    /*
    //int * data = new int[10000000000000000]; // 

    for(size_t i{0} ; i < 10000000 ; ++i){
        int * data = new int[100000000];
    }
    */

   //exception
   //*
    for(size_t i{0} ; i < 10 ; ++i){
        try{
            int * data = new int[1000000000000000];
        }catch(std::exception& ex){
            std::cout << "  Something went wrong : " << ex.what() << std::endl;
        }
    }
    //*/


   //std::nothrow
    for(size_t i{0} ; i < 10 ; ++i){
   
        int * data = new(std::nothrow) int[100000000000000];

        if(data!=nullptr){
            std::cout << "Data allocated" << std::endl;
        }else{
            std::cout << "Data allocation failed" << std::endl;
        }
       
    }


    std::cout << "Program ending well" << std::endl;
    
    return 0;
}