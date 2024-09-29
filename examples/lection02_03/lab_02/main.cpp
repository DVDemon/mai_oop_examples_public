#include <iostream>
#include "dasharray.h"


int main(){

    DashArray ds1 {'1','1','1','1','1','1','1'};
    ds1.print(std::cout) << std::endl;

    DashArray ds2{'1','1','1'};
    ds2.print(std::cout) << std::endl;

    DashArray ds3(ds1.add(ds2));
    ds3.print(std::cout) << std::endl;

    DashArray ds4(std::move(ds3));
    ds4.print(std::cout) << std::endl;

    DashArray ds5(DashArray {'1','1','1','1','1','1','1'});
    

    try{

        DashArray ds5 = ds4.remove(ds2);
        ds5.print(std::cout) << std::endl;

        DashArray ds6 = ds2.remove(ds4);
        ds5.print(std::cout) << std::endl;

    }catch(std::exception &ex){
        std::cerr << "exception:" << ex.what() << std::endl;
    }

    return 1;
}