#include <iostream>

// складывает второе и третье "число" и приводит его к типу первого
template <class A,class B,class C>
struct Foo{
    A add(B b, C c){
        return static_cast<A>(b+c);
    }
};

template <class A>
struct Foo<A,char,char>{
    A add(char b,char c){
        return static_cast<A>(b+c-'0'-'0');
    }
};

template <class A,class B,class C>
A add(B b, C c){
        return static_cast<A>(b+c);
};

/*
// for function - not allowed
template <class A>
A add<A,char,char>(char b,char c){
        return static_cast<A>(b+c-'0'-'0');
};
//*/

int main(){

    std::cout<< Foo<int,int,int>().add(5,3) << std::endl;
    std::cout<< Foo<int,char,char>().add('2','2') << std::endl;
    std::cout<< Foo<char,char,char>().add(48,1) << std::endl;

    std::cout<< add<int,int,int>(1,2) << std::endl;
    std::cout<< add<int,char,char>('1','2') << std::endl;
    return 1;
}