#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
#include <tuple>

// возвращает 
// - следующий элемент не равный тому, который находится по указателю it
// - сам элемент
// - расстояние до следующего (не равного этому элементу)

template <class It> std::tuple<It, char, size_t> occurrences(It it, It end_it)
{
    if (it == end_it) { return {it, '?', 0}; }

    const char c {*it};
    const auto diff  = std::find_if(it, end_it, [c](char x) { return c != x; });

    return {diff, c, std::distance(it, diff)};
}


// архивируем
std::string compress(const std::string &s)
{
    const auto end_it = std::end(s); // определяем конец строки
    std::stringstream r;

    for (auto it = std::begin(s); it != end_it;) {
        const auto [next_diff, c, n] = occurrences(it, end_it);
        r << c << n;
        it = next_diff;
    }

    return r.str();
}

std::string decompress(const std::string &s)
{
    std::stringstream ss{s};
    std::stringstream r;

    char c;
    size_t n;
    while (ss >> c >> n) {
        r << std::string(n, c);
    }

    return r.str();
}

int main()
{
    std::string s {"aaaaaaaaabbbbbbbcccccccc"};
    std::cout << compress(s) << std::endl;
    std::cout << decompress(compress(s)) << std::endl;
}
