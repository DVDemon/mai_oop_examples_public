#include <cstdlib>
#include <iostream>
#include <memory>

class B;

class A {
private:
    std::weak_ptr<B> b;
public:

    A(){
        std::cout << "Constructor: A" << std::endl; 
    }
    void LetsLock(std::shared_ptr<B> value) {
        b = value;
    }

    void Print() {
        std::cout << "Print: A" << std::endl;
    }

    ~A() {
        std::cout << "Destructor: A" << std::endl;
    }
};

class B {
private:
    std::weak_ptr<A> a;
public:

    B(){
      std::cout << "Constructor: B" << std::endl;    
    }
    
    void LetsLock(std::shared_ptr<A> value) {
        a = value;
    }

    void Print() {
        std::cout << "Print: B" << std::endl;
        std::shared_ptr<A> a_ptr = a.lock();
        if(a_ptr) a_ptr->Print();       
    }

    ~B() {
        std::cout << "Destructor: B" << std::endl;
    }
};

int main(int argc, char** argv) {

    std::shared_ptr<B> b(new B());
    std::shared_ptr<A> a(new A());
    {

        

        a->LetsLock(b);
        b->LetsLock(a);
    }
    
    std::cout << "Start printing ..." << std::endl;
    b->Print();  
    
    return 0;
}

