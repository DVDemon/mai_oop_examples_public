#include <iostream>       // std::cout
#include <functional>     // std::ref
#include <thread>         // std::thread
#include <future>         // std::promise, std::future
#include <exception>

void print_int (std::future<int>& fut) {
    try{
          int x = fut.get();
          std::cout << "value: " << x << '\n';
        }catch(...){
              std::cout << "Exception caught" << std::endl;
    }
}

int main ()
{
  std::promise<int> prom;                      // create promise
  std::future<int> fut = prom.get_future();    // engagement with future
  std::thread th1 (print_int, std::ref(fut));  // send future to new thread

  std::cout << "Press enter";
  std::cin.get();
  
  prom.set_exception( std::make_exception_ptr(10));
  //prom.set_value (10);                         // fulfill promise
                                               // (synchronizes with getting the future)
  th1.join();
  return 0;
}