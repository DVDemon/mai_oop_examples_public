#include <memory>
#include <iostream>
 
struct Good: public std::enable_shared_from_this<Good> 
{
    std::shared_ptr<Good> getptr() {
        return shared_from_this();
    }
};
 
struct Bad
{
    std::shared_ptr<Bad> getptr() {
        return std::shared_ptr<Bad>(this);
    }
    ~Bad() { std::cout << "Bad::~Bad() called\n"; }
};
 
int main()
{
    // Good: the two shared_ptr's share the same object
    std::shared_ptr<Good> gp1 = std::make_shared<Good>();
    std::shared_ptr<Good> gp2 = gp1->getptr();

    std::cout << "gp2.use_count() = " << gp2.use_count() << '\n';
 
    // Bad: shared_from_this is called without having std::shared_ptr owning the caller 
    try {
        std::cout << "begin braces" << std::endl;
        std::shared_ptr<Bad> not_so_good = std::make_shared<Bad>();
        std::cout << "middle braces" << std::endl;
        std::shared_ptr<Bad> gp1 = not_so_good->getptr();
         std::cout << "gp1.use_count() = " << gp1.use_count() << '\n';
        std::cout << "end braces" << std::endl;
    } catch(std::exception & e) {

        std::cout << e.what() << '\n';    
    } // UB: double-delete of Bad
    return 0;
} 