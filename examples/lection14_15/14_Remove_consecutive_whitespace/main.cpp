#include <iostream>
#include <string>
#include <algorithm>

/*
std::unique - это алгоритм из стандартной библиотеки C++, 
который используется для удаления последовательных дубликатов в диапазоне элементов. 
Он не изменяет размер контейнера, а лишь перемещает уникальные элементы в начало диапазона,
оставляя "хвост" с неопределенными значениями.
*/
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
