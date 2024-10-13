#include <iostream>

template <class CHILD> class Base {
    public:
        void facade() noexcept {
            try{
                static_cast<CHILD*>(this)->do_action();
            }catch(...){
                std::cout << "some exceeption" << std::endl;
            }
        }
};

class Child : public Base<Child> {
    friend  Base<Child>;
    protected: 
        void do_action() {
            std::cout << "some action" << std::endl;
        }
};

int main() {

    Child c;
    c.facade();
    return 0;
}