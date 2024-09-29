#include <iostream>

int main()
{
    const char *message{"Hello World!"};
    std::cout << "message : " << message << std::endl;

    //*message = "B"; // Compiler error
    std::cout << "*message : " << message[3] << std::endl;

    // Allow users to modify the string
    char message1[]{"Hello World!"};
    message1[7] = 'B';
    std::cout << "message1 : " << message1 << std::endl;

    return 0;
}