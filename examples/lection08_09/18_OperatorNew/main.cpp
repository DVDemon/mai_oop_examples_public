#include <stdlib.h>
#include <iostream>
#include <exception>

const size_t  buffer_size = 80;
unsigned char buffer[buffer_size];
unsigned char *ptr = buffer;

class A {
private:
    int value;
public:

    A(int val) : value(val) {
         std::cout << "Constructor" << std::endl;
    };

    void *operator new(size_t size);
    void *operator new(size_t size,const char *msg);
    
    void operator delete(void *p);
    ~A(){
        std::cout << "Destructor" << std::endl;
    }
};


void* A::operator new(size_t size,const char *msg) {
    std::cout << "Message :" << msg << std::endl;
    return malloc(size);
}

void* A::operator new(size_t size) {
    if((ptr+size)>(buffer+buffer_size)) throw std::logic_error("no more space");
    void *result = ptr;
    ptr+=size;
    std::cout << "Allocated :" << size << "bytes" << std::endl;
    return result;  // return MyAllocator<A>::get().allocate(size);
}

void A::operator delete(void *p) {
    std::cout << "Deleted" << std::endl;
    //free(p);
}

int main() {

    {
        A a(1); // Тут не вызывается new!
        std::cout << "Inner block" << std::endl;
    }

    std::cout << std::endl << "Placement new" << std::endl;
    char * ptr = new char[sizeof(A)];
    A    * ptr_a1 = ::new (ptr) A(2018);
    ptr_a1->~A();
    delete[] ptr;

    std::cout << std::endl << "Custom new with paramenets" << std::endl;
    A    * ptr_a2 = new("Hello world") A(2019);
    delete ptr_a2;
    
    std::cout << std::endl << "Dynamic memory allocation" << std::endl;
    for(int i=0;i<buffer_size;i++){
        A* b = new A(i);
        delete b;
        std::cout << std::endl;
    };

    return 0;
}
