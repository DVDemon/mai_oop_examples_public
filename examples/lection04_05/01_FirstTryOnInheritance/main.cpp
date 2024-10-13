#include <iostream>
#include "player.h"


int main(){

    Player p1("Basketball");
    p1.set_first_name("John");
    p1.set_last_name("Snow");
    //p1.print(std::cout);

    static_cast<Person>(p1).print(std::cout);
   
    return 0;
}