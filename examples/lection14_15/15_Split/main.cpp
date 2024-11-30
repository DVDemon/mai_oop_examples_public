#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>
#include <list>


template <class InIt, class OutIt, class T, class F>
InIt split(InIt it, InIt end_it, OutIt out_it, T split_val, F bin_func)
{
    while (it != end_it) {
        auto slice_end  = std::find(it, end_it, split_val);
        if(slice_end!=it)
        *out_it++ = bin_func(it, slice_end);

        if (slice_end == end_it) { return end_it; }
        it = std::next(slice_end);
    }
    return it;
}

int main()
{
    const std::string s {"a-b-c----d-e-f-g"};
    auto binfunc =[](auto it_a, auto it_b) {return std::string(it_a, it_b);};

    std::list<std::string> l;

    split(begin(s), end(s), std::back_inserter(l), '-', binfunc);

    std::copy(begin(l), end(l), std::ostream_iterator<std::string>{std::cout, "\n"});

    return 0;
}
