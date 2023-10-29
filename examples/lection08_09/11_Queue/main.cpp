#include <iostream>
#include <queue>

void baseTest() {
    std::cout << "\nbaseTest\n";
    
    // No initialization constructor
    // std::queue<int> values = {0, 1, 2, 3, 4, 5, 6};
    std::queue<int> values;

    for (int i=0; i<10; ++i)
        values.push(i);

    while(!values.empty()) {
        std::cout << "size = " << values.size() << " back = " << values.back() << " front = " << values.front() << std::endl;
        values.pop();
    }
    std::cout << std::endl;
}

int main() {
    baseTest();

    return 0;
}