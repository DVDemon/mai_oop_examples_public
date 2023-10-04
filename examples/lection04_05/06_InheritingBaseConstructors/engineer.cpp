#include "person.h"
#include "engineer.h"
#include <iostream>

/*
Engineer::Engineer()
{
    std::cout << "Default constructor for Engineer called..." << std::endl;
}





Engineer::Engineer(const Engineer& source)
     : Person(source)
        , contract_count(source.contract_count)
{
    std::cout << "Custom copy constructor for Engineer called..." << std::endl;
}
//*/
Engineer::Engineer(std::string_view fullname,int age,
    std::string_view address,int contract_count_param) : 
Person(fullname,age,address),contract_count(contract_count_param)
{
    std::cout << "Custom constructor for Engineer called..." << std::endl;
}

Engineer::~Engineer()
{
}


