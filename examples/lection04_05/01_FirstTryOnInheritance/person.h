#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <iostream>

class Person
{
public:
    Person();
    Person(std::string& first_name_param, std::string& last_name_param);
    ~Person();
    
    //Getters
    std::string get_first_name() const{
        return first_name;
    }
    
    std::string get_last_name() const{
        return last_name;
    }
	
    //Setters
    void set_first_name(std::string_view fn){
        first_name = fn;
    }
    void set_last_name(std::string_view ln){
        last_name = ln;
    }
    std::ostream& print(std::ostream& out);
private : 
    std::string first_name{"Mysterious"};
    std::string last_name{"Person"};
};


#endif // PERSON_H
