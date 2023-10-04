#include "person.h"
#include <iostream>

Person::Person(){
    std::cout << "Default constructor for Person called..." << std::endl;
}

Person::Person(std::string_view fullname, int age,
    std::string_view address) 
        : m_full_name{fullname}, m_age{age},
            m_address{address}
{
        std::cout << "Custom constructor for Person called..." << std::endl;
}

void Person::do_something() const{
    std::cout << "Hello" << std::endl;
}




Person::~Person()
{
}


