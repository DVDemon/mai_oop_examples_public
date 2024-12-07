#include<iostream>
#include <vector>

auto main() -> int {
    int elements[10];
    double results[10];

    for (int i = 0; i < 10; i++) elements[i]=i;

    auto transform = [](int i)  -> double {
        if (i < 5) return i + 1.0;
        else
            if (i % 2 == 0) return i / 2.0;
        else
            return i*i;
    };

    for (int i = 0; i < 10; i++) results[i]=transform(elements[i]);


    for(auto a: results) std::cout << a << std::endl;

    return 0;
}