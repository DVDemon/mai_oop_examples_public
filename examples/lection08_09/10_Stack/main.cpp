#include <iostream>
#include <stack>

void baseTest() {
    std::cout << "\nbaseTest\n";

    // No initialization constructor
    // std::stack<int> values = {0, 1, 2, 3, 4, 5, 6};
    std::stack<int> values;

    for (int i=0; i<10; ++i)
        values.push(i);

    while(!values.empty()) {
        std::cout << "size = " << values.size() << " top = " << values.top() << std::endl;
        values.pop();
    }
    std::cout << std::endl;
}

void iteratorTest() {
    // std::stack does not have iterators....
}

int main() {
    baseTest();

    return 0;
}