#include <thread>
#include <iostream>

class MyClass{
public:
    MyClass() {
        std::cout << "Constructor" << std::endl;
    }

    MyClass(const MyClass& other) {
        std::cout << "Copy constructor" << std::endl;
    }


    MyClass(const MyClass&& other) {
        std::cout << "Move constructor" << std::endl;
    }

    MyClass& operator=(const MyClass &other){
        std::cout << "Copy operator" << std::endl;
        return *this;
    }

    MyClass& operator=(MyClass &&other) noexcept{
        std::cout << "Move operator" << std::endl;
        return *this;
    }

    void operator()(const char* param) {
        std::cout << param << std::endl;
    }

    ~MyClass() {
        std::cout << "Destructor" << std::endl;
    }
};

int main() {
    MyClass cls;

    // copy operation
    std::cout << std::endl << "Copy ----------" << std::endl;

    std::thread my_thread1(cls,"Hello world!");
    my_thread1.join();
    
    // move operation 
    std::cout << std::endl << "Move ----------" << std::endl;
    std::thread my_thread2(std::move(cls),"Hello world!");
    my_thread2.join();
    
    // no move or copy

    std::cout << std::endl << "Ref -----------" << std::endl;
    std::thread my_thread3(std::ref(cls),"Hello world!");
    my_thread3.join();
    


    return 0;
}

