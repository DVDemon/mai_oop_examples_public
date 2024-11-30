#include <iostream>
#include <string>
#include <algorithm>

template <class It>
It remove_multi_whitespace(It it, It end_it)
{
    return std::unique(it, end_it,
                       [](const auto &a, const auto &b) {
                           return std::isspace(a) && std::isspace(b);
                       });
}

int main()
{
    std::string s{"fooo     bar    \t   baz"};
    std::cout << s << std::endl;
    s.erase(remove_multi_whitespace(std::begin(s), std::end(s)), std::end(s));
    std::cout << s << '\n';

    return 0;
}
