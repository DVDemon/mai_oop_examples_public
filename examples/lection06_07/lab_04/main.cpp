#include <iostream>
#include <string>

#include "student.h"
#include "array.h"
#include <memory>

int main(){

    Student<int> s1(1,2,3,4);
    Student<std::string> s2;

    s1[0] = 7;
    std::cout << s1 << std::endl;

    s2[2] = "not much";
    std::cout << s2 << std::endl;

    Array<std::shared_ptr<Human<int>>> array{
                                    std::make_shared<Student<int>>(1,2,3,4),
                                    std::make_shared<Student<int>>(2,5,8,40),
                                    std::make_shared<Student<int>>(3,6,9,41),
                                    std::make_shared<Student<int>>(4,7,10,42)
                                };

    for(size_t i=0;i<array.size();++i)
        std::cout << *array[i] << std::endl;

    std::cout << "Print ----------------" << std::endl;

    for(size_t i=0;i<array.size();++i) {
         array[i]->print(std::cout);
         std::cout << std::endl;
    }

    Array<std::shared_ptr<Human<int>>> array2 = array;


    std::cout << "Print array2 ----------------" << std::endl;

    for(size_t i=0;i<array2.size();++i) {
         array2[i]->print(std::cout);
         std::cout << std::endl;
    }

    Array<std::shared_ptr<Human<int>>> array3 = std::move(array2);


    std::cout << "Print array3 ----------------" << std::endl;

    for(size_t i=0;i<array3.size();++i) {
         array3[i]->print(std::cout);
         std::cout << std::endl;
    }

    return 1;
}