#include <iostream>
#include "point.h"

int main(){

    Point p1(10,20);
    Point p2(3,4);
    //p1.print_info();

   // p1 << std::cout << p2;
    ((std::cout << p1) << p2) << std::endl;
   
    return 0;
}