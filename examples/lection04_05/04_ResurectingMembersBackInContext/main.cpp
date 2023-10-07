#include <iostream>
#include "person.h"
#include "engineer.h"
#include "civilengineer.h"

int main(){

    
    const Person p;

    std::cout << p.get_address() << std::endl; //const
  
   
    return 0;
}