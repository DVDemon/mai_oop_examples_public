#include <iostream>     // std::cout
#include <iterator>     // std::back_insert_iterator
#include <vector>       // std::vector
//#include <algorithm>    // std::copy

//* копируем из bar в back_it
template<class InputIterator, class OutputIterator >
OutputIterator my_copy(InputIterator first, InputIterator last, OutputIterator result) {
        while (first != last) {
            *result = *first;
            ++result;
            ++first;
        }
        return result;
    }
//*/

int main() {
    std::vector<int> foo;
    std::vector<int> bar;
    for (int i = 1; i <= 5; i++) {
        bar.push_back(i * 10);
    }

    std::back_insert_iterator< std::vector<int> >  back_it(foo);
    my_copy(bar.begin(), bar.end(), back_it);
    //std::copy(bar.begin(), bar.end(), back_it);

    std::cout << "foo:";
    for (auto i : foo) std::cout << ' ' << i;
    std::cout << std::endl;

    return 0;
}