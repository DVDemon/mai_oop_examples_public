#include <iostream>
#include <exception>



void proc2(void) {
    try {

        std::cout << "Proc2 called" << std::endl;
        //std::string().at(1); // this generates an std::out_of_range
        throw 42; //custom class

    } catch (int ex1) {
        std::cout << "int in Proc2" << std::endl;

    } catch (const std::exception& e) {
        std::cout << "Unknown exception:" << e.what() << std::endl;
        throw;
    }
}

void proc1(void) {
    try {
        std::cout << "Proc1 called" << std::endl;
        proc2();
    } catch (const std::exception& e) {
        std::cout << "Exception in Proc1:" << e.what() << std::endl;
    }
}

int main() {
    proc1();
    return 0;
}

