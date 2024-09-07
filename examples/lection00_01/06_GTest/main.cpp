#include <iostream>
#include "include/solve_func.h"

int main()
{
  int lhv,rhv;
  std::cout << "введите ширину:";
  std::cin  >> lhv;
  std::cout << "введите высоту:";
  std::cin  >> rhv;


  std::cout << "result: " << solve_func(lhv,rhv) << std::endl;

  return 0;
}
