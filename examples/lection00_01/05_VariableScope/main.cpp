#include <iostream>

int global_var1{23}; // global variable

void some_other_function(){
 //   local_var = 5;
}

void some_function(){
    int local_var{10};
    std::cout << "Inside function global_var : " << global_var1 << std::endl;
    std::cout << "Inside function local_var : " << local_var << std::endl;
    some_other_function();
    {
        int local_local{3};
    }
    //std::cout << local_local << std::endl;
}





int main(){
 std::cout << "Inside main function global_var : " << global_var1 << std::endl;
 int local_var{5};
 some_function();
   
    return 0;
}