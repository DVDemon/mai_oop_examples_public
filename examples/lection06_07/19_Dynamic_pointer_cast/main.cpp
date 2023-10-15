#include <cstdlib>
#include <iostream>
#include <memory>

struct A
{
    A(){};
    virtual void Do()
    {
        std::cout << "A" << std::endl;
    }
};

struct B : public A
{
    const int b = 1;

    void Do() override
    {
        std::cout << "B" << std::endl;
    }
    void DoB()
    {
        std::cout << "B second function" << std::endl;
    }
};

struct C : public A
{
    const char *c= "Hello!";
    void Do() override
    {
        std::cout << "C" << std::endl;
    }
    void DoC()
    {
        std::cout << "C second function" << std::endl;
    }


};

auto main() -> int
{
    std::shared_ptr<B> b(new B());
    std::shared_ptr<A> ptr = b;

    if (std::shared_ptr<B> ptr_b = std::dynamic_pointer_cast<B>(ptr))
    {
        ptr_b->Do();
    }

    if (std::shared_ptr<C> ptr_c = std::dynamic_pointer_cast<C>(ptr))
    {
        ptr_c->Do();
    }
    else
        std::cout << "Oops" << std::endl;

    return 0;
}
