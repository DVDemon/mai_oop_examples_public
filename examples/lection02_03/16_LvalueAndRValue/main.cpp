#include <iostream>

void foo(std::string &val)
{
    val = "I am foo";
}

std::string &boo(std::string val)
{
    val = "I am boo";
    return val; // что вы об этом думаете?
}

std::string&& booRL(std::string &&val)
{
    std::cout << "R*val: " << &val << std::endl;
    return std::move(val);
}

std::string& booRL(std::string &val)
{
    std::cout << "L*val: " << &val << std::endl;
    return val;
}

int main()
{
    std::string value = "Hello world!";

    std::cout << "value = " << value << std::endl;
    foo(value);
    std::cout << "value = " << value << std::endl;
    std::string &val2 = boo(value); 
    std::cout << "value = " << val2 << std::endl;

    std::cout << "*value: " << &value << " , *val2: " << &val2 << std::endl;

    std::string &&val3 = std::move(booRL("Some value"));
    //std::string val3 = std::move(booRL("Some value"));
    //std::string val3 = booRL(value);
    std::cout << "*val3: " << &val3 << std::endl;
    std::cout << "result: " << val3 << std::endl;
    return 1;
}