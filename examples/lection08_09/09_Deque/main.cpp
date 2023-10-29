#include <deque>
#include <iostream>

void testPlacing() {
    std::cout << "\ntestPlacing\n";

    int stackVariable = 0;
    std::deque<int> values = {0, 1, 2, 3, 4, 5};

    std::cout << "&stackVariable = " << &stackVariable << std::endl;
    std::cout << "&values        = " << &values << std::endl;
    std::cout << "&values[0]     = " << &values[0] << std::endl;

    auto ptr1 = &values[0];
    for (int i = 1; i < 1000; ++i) {
        values.push_back(i);
        auto ptr2 = &values.back();

        if(i>0)
        if (((ptr2 - ptr1) > 1) || ((ptr2 - ptr1) < -1)) {
            std::cout << "bucket detected!\n";
            std::cout << "i = " << i << std::endl;
            std::cout << "ptr1 = " << ptr1 << std::endl;
            std::cout << "ptr2 = " << ptr2 << std::endl;
            std::cout << "diff = " << (ptr2 - ptr1) << std::endl;
        }
        ptr1 = ptr2;
    }
}

void testIterator() {
    std::cout << "\ntestIterator\n";

    std::deque<int> values = {0, 1, 2, 3, 4, 5, 6, 7, 8};

    auto iter = std::next(values.cbegin(), 3);
    std::cout << *iter << std::endl;

    ++iter;
    std::cout << *iter << std::endl;

    --iter;
    --iter;
    std::cout << *iter << std::endl;

    iter += 3;
    std::cout << *iter << std::endl;

    auto iterPos = std::distance(values.cbegin(), iter);
    std::cout << "iterPos = " << iterPos << std::endl;

    auto ptr = &*iter;
    std::cout << "one more" << std::endl;
    values.push_back(42);    

    std::cout << "&values[0]       = " << &values[0] << std::endl;
    std::cout << "&values[iterPos] = " << &values[iterPos] << std::endl;

    // Iterator is invalid here.
    // std::cout << *iter << std::endl;
    // But pointer is still valid
    std::cout << *ptr << std::endl;

    auto iter2 = std::next(values.cbegin(), 3);
    std::cout << "*iter2 = " << *iter2 << std::endl;
    
    std::cout << "add in the middle" << std::endl;
    values.insert(iter2, 42);
    
    // Iterator may be invalid here
    std::cout << "*iter2 = " << *iter2 << std::endl;
    // And pointer may be invalid here
    std::cout << *ptr << std::endl;

    for (auto& v : values)
        std::cout << v << ' ';
    std::cout << std::endl;
}

int main() {
    testPlacing();
    testIterator();    

    return 0;
}