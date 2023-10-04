
#include "person.h"
#include "engineer.h"
#include "civilengineer.h"
#include <iostream>

CivilEngineer::CivilEngineer()
{
    std::cout << "Default constructor called for CivilEngineer ... " << std::endl;
}



CivilEngineer::CivilEngineer(std::string_view fullname,int age,
    std::string_view address,int contract_count, std::string_view speciality)
     : Engineer(fullname,age,address,contract_count), m_speciality(speciality)
{
    std::cout << "Custom constructor called for CivilEngineer ... " << std::endl;
}

CivilEngineer::CivilEngineer(const CivilEngineer& source)
    : Engineer(source) , m_speciality(source.m_speciality)
{
    std::cout << "Custom copy constructor called for CivilEngineer ... " << std::endl;
}


CivilEngineer::~CivilEngineer()
{
    std::cout << "Destructor called for CivilEngineer ..." << std::endl;
}
