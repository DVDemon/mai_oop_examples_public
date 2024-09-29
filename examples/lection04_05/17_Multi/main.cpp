#include <iostream>

struct Animal {

};

struct Duck : Animal {
    void swim() {
        std::cout << "swim" << std::endl;
    }
};

struct Bobr :  Animal {
    void make_a_dam() {
        std::cout << "dam!!!" << std::endl;
    }
};

struct Platypus : Duck, Bobr {

};

int main() {

    Duck d;
    Bobr b;

    Platypus p;
    p.swim();
    p.make_a_dam();

    return 0;
}
