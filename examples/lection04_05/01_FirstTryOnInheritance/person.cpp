#include "person.h"

Person::Person(){
}

Person::Person(std::string& first_name_param, std::string& last_name_param)
   // : first_name(first_name_param), last_name(last_name_param)
{
    first_name = first_name_param;
    last_name  =last_name_param;
}

std::ostream& Person::print(std::ostream& out){
    out << "Person : " << get_first_name()
             << " " << get_last_name() << "]";
    return out;
}


Person::~Person()
{
}

