#include <iostream>
#include <cassert>

template<class T>
struct smart_ptr {
    //*
    smart_ptr() 
        : m_ptr{nullptr} {
    }
    smart_ptr(T* ptr) : m_ptr{ptr} {
    }
    //*/
//*
    smart_ptr& operator=(const smart_ptr&) = delete;
    smart_ptr& operator=(smart_ptr&& other) noexcept{
        if(m_ptr) delete m_ptr;
        m_ptr = other.m_ptr;
        other.m_ptr = nullptr;
        return *this;
    }
//*/
    ~smart_ptr() {
        delete m_ptr;
        m_ptr = nullptr;
    }

    T* get() { 
        return m_ptr; 
    }
private:
    T* m_ptr;
};

struct SomeClass {
    SomeClass() {
        std::cout << "ctor" << std::endl;
    }
    ~SomeClass() {
        std::cout << "dtor" << std::endl;
    }
};

auto main() -> int {
    smart_ptr<SomeClass> ptr1;

    std::cout << "start" << std::endl;
    {
        SomeClass* raw_ptr = new SomeClass();

        std::cout << "size ptr=" << sizeof(raw_ptr) << std::endl;
        smart_ptr<SomeClass> ptr2{raw_ptr};

        std::cout << "size smart_ptr=" << sizeof(ptr2) << std::endl;
        smart_ptr<SomeClass> ptr1;
        ptr1 = std::move(ptr2); //дублируем

        //assert(ptr2.get());

        ptr2 = smart_ptr<SomeClass>{new SomeClass()}; // затираем
    }
    std::cout << "end" << std::endl;
    return 0;
}