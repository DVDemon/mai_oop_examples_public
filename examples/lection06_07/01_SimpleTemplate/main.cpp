#include <iostream>
#include <string>

// шаблон класса с параметром - типом
template <class T>  struct Container{
	 T payload;
     Container(const T& value) : payload(value){};
};

// шаблон функции с параметром типом
template <class T> T print(T value){
    std::cout << "Value:" << value << " size:" << sizeof(T) << std::endl;
    return value;
}

// шаблон класса с параметром - константой
template<int V> struct foo{
    static const int value = V;
};

int main(int argc, char** argv) {
    // компилятор сам догадается какой параметр шаблона мы хотели подставить
    // print<int>(10); 
    // print(10); 
    print<const char*>("Hello world!");
    print<std::string>("Hello world!");
    print(std::string("Hello world!"));

    // // или можем указать явно
    // print<double>(0.5);
    // print<char>(48);
    
    // // простое создание шаблона
    // Container<int> a(10);

    // // // параметром шаблона может быть тип сгененерированный на основе шаблона
    // Container<Container<const char*> > 
    //     b(Container<const char*>("Hi there!"));
    // std::cout << b.payload.payload << std::endl;

    // // так странно можно обратится к 10
    constexpr int A =10;
    std::cout << foo<A>::value << std::endl;
    
    return 0;
}


