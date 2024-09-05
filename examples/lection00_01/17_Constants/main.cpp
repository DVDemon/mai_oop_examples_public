#include <iostream>



int main(){

    const int age {34};
    const float height {1.67f};

    //age = 55; // Can't modify
    //height = 1.8f;


    int years { 3 * age};

    const int born_date = years;

    std::cout << "age : " << age << std::endl;
    std::cout << "height : " << height << std::endl;
    std::cout << "years : " << years << std::endl;
    std::cout << "born : " << born_date << std::endl;
   
    return 0;
}