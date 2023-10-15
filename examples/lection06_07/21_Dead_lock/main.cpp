#include <cstdlib>
#include <iostream>
#include <memory>

class B;

class A {
private:
    std::shared_ptr<B> b;
public:

    void LetsLock(std::shared_ptr<B> value) {
        b = value;
    }
    ~A(){
         std::cout << "A killed!" << std::endl;
    }
};

class B {
private:
    std::shared_ptr<A> a;
public:

    void LetsLock(std::shared_ptr<A> value) {
        a = value;
    }
    ~B(){
        std::cout << "B killed!" << std::endl;
    }
};


int main(int argc, char** argv) {

    std::shared_ptr<A> a(new A());
    std::shared_ptr<B> b(new B());
    a->LetsLock(b);
    b->LetsLock(a);

    std::cout << b.use_count() << std::endl;
    std::cout << a.use_count() << std::endl;
    return 0;
}

