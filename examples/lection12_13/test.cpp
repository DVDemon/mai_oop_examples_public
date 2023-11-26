#include <iostream>
#include <array>
#include <algorithm>
#include <math.h>

auto main() -> int {
    std::array<int,10> arr;
    int i{0};
    std::transform(std::begin(arr),std::end(arr),std::begin(arr),
                    [&i](int a) { a =pow(2,i++); std::cout << a << " " ;return a;});

    return 0;
}