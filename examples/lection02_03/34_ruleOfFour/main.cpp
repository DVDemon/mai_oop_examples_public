#include <iostream>
#include <string>

class Kitty {
    private:
        std::string name;
    public:
        Kitty() : name {"Vasyka"} {
            std::cout << name << " was born!" << std::endl;
        };

        Kitty(const std::string & n) : name {n} {
            std::cout << name << " was born!" << std::endl;
        };

        Kitty(const Kitty& other) : name {other.name} {
            std::cout << name << " was cloned!" << std::endl;
        }

        ~Kitty() {
            std::cout << name << " was missed" << std::endl;
        }
};

int main() {
    Kitty k1;
    Kitty k2("Mashka");
    Kitty k3(k2);
    Kitty k4{k3};
    Kitty k5=k4;

    return 0;
}