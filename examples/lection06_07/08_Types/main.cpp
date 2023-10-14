#include <iostream>

// тип как параметр
template <class T>
struct is_int{
    static const bool value = false;
};

template <>
struct is_int<int>{
    static const bool value = true;
};

// тип как результат
template<class T>
struct remove_pointer {
    using type = T;
};

template<class T>
struct remove_pointer<T*> {
    using type = T;
};


int main(){

    std::cout << "Is bool int? " << is_int<bool>::value << std::endl;
    std::cout << "Is int int?  " << is_int<int>::value << std::endl;

    int *value = nullptr;





    value = new typename remove_pointer<decltype(value)>::type;
    *value = 10;
    delete value;

    return 1;
}