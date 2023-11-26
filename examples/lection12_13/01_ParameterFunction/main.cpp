#include <iostream>

int addition(int x, int y)
{
    return x + y;
}

int subtraction(int x, int y)
{
    return x - y;
}

int multiplication(int x, int y)
{
    return x * y;
}

int division(int x, int y)
{
    return x / y;
}

using FuncType = int(int,int);

void PassingFunc(FuncType fn, int x, int y)
{
    std::cout << "Result = " << fn(x, y) << std::endl;
}

auto main() -> int
{
    int i, a, b;

    // Displaying menu for user
    std::cout << "Select mode:" << std::endl;
    std::cout << "1. Addition" << std::endl;
    std::cout << "2. Subtraction" << std::endl;
    std::cout << "3. Multiplication" << std::endl;
    std::cout << "4. Division" << std::endl;
    std::cout << "Choice: ";
    std::cin >> i;

    // Preventing user to select
    // unavailable modes
    if (i < 1 || i > 4)
    {
        std::cout << "Please select available mode!";
        return 1;
    }

    // Getting input from user for variable a
    std::cout << "a -> ";
    std::cin >> a;

    // Getting input from user for variable b
    std::cout << "b -> ";
    std::cin >> b;

    
    switch (i)
    {
    case 1:
        PassingFunc(addition, a, b);
        break;
    case 2:
        PassingFunc(subtraction, a, b);
        break;
    case 3:
        PassingFunc(multiplication, a, b);
        break;
    case 4:
        PassingFunc(division, a, b);
        break;
    }

    return 0;
}