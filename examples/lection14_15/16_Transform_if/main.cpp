#include <iostream>
#include <iterator>
#include <numeric>

template <class T>
auto map(T fn)
{
    return [=] (auto reduce_fn) {
        return [=] (auto accumulator, auto input) {   // перенаправляем вызов в reduce_fb
            return reduce_fn(accumulator, fn(input)); // copy_and_advance(accumulator,twice(input))
        };
    };
}

template <class T>
auto filter(T predicate) // сюда передадим параметр even
{
    return [=] (auto reduce_fn) { // reduce_fn = map(twice)(copy_and_advance)
        return [=] (auto accumulator, auto input) { // эта функия вернется для std::accumulate
            if (predicate(input)) { // если even(input) == true
                return reduce_fn(accumulator, input); // вызовится результат 
            } else {
                return accumulator;
            }
        };
    };
}

int main()
{
    std::istream_iterator<int> it {std::cin};
    std::istream_iterator<int> end_it;

    auto even  ([](int i) { return i % 2 == 0; });
    auto twice ([](int i) { return i * 2; });

    auto copy_and_advance ([](auto it, auto input) {
        *it = input;
        return ++it;
    });

    std::accumulate(it, end_it,
            std::ostream_iterator<int>{std::cout, ", "},
            filter(even)( // мы вызываем функцию filter с параметром even, 
                          // которая вернет функцию, которую мы то же вызываем c параметром map(twice(copy_and_advance))
                map(twice)( // reduce_fn получается вызовом функии map
                    copy_and_advance
                )
            ));
    std::cout << '\n';
}
