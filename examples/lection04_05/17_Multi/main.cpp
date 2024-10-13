#include <iostream>

struct Animal {
    void wow() {
        std::cout << "Wow!!!" << std::endl;
    }
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
    p.Bobr::wow();
    p.Duck::wow();

    return 0;
}
