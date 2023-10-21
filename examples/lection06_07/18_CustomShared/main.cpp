#include <iostream>

template<class T>
struct smart_ptr {
    smart_ptr(T* ptr) 
        : m_counter{new std::size_t{1}},
          m_ptr{ptr} {
    }
    smart_ptr(const smart_ptr& other) 
        : m_counter{ other.m_counter },
          m_ptr{ other.m_ptr } {
        ++(*m_counter); 
        std::cout << *m_counter << std::endl;
    }
    ~smart_ptr() {
        std::cout << "dtor:" << *m_counter << std::endl;
        if (--(*m_counter) == 0) {
            delete(m_ptr);
            delete(m_counter);
        }
        
    }
private:
    T* m_ptr;
    std::size_t* m_counter;
};

struct SomeStruct {
    SomeStruct() {
        std::cout << "ctor" << std::endl;
    }
    ~SomeStruct() {
        std::cout << "dtor" << std::endl;
    }
};

int main() {
    {
        smart_ptr<SomeStruct> ptr1{new SomeStruct}; // *ptr1.m_counter == 1
        {
            auto ptr2 = ptr1; // *ptr2.m_counter == 2 , *ptr1.m_counter == 2 
            auto ptr3 = ptr2; // *ptr3.m_counter == 3 , *ptr2.m_counter == 3 , *ptr1.m_counter == 3
        }
    }
    std::cout << "after scope" << std::endl << std::endl;

    return 0;
}