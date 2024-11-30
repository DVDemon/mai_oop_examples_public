#include <iostream>       // std::cout
#include <future>         // std::async, std::future
#include <chrono>         // std::chrono::milliseconds

// a non-optimized way of checking for prime numbers:
bool is_prime (unsigned long long x) {
  for (unsigned long long i=2; i<x; ++i) if (x%i==0) return false;
  return true;
}

auto main () -> int
{
  // call function asynchronously:
  std::future<bool> fut = std::async (is_prime,444444443); 
  
  // do something while waiting for function to set future:
  // std::cout << "checking, please wait" << std::endl;
  // std::chrono::milliseconds span (100);

  // while (fut.wait_for(span) == std::future_status::timeout)
  //     std::cout << '.' << std::flush;

  bool x = fut.get();     // retrieve return value

  std::cout << "\n444444443 " << (x?"is":"is not") << " prime.\n";

  // std::cout << "\n444444443 =" << std::async(
  //       [](unsigned long long x ){
  //         for (unsigned long long i=2; i<x; ++i) if (x%i==0) return false;
  //           return true;},444444443).get() << std::endl;

  return 0;
}