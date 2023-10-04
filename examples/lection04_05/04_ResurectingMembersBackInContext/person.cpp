#include "person.h"
#include <iostream>

Person::Person(std::string_view fullname, int age,
    const std::string address) 
        : m_full_name{fullname}, m_age{age},
            m_address{address}
{
}

void Person::do_something() const{
    std::cout << "Hello" << std::endl;
}

Person::~Person()
{
}


