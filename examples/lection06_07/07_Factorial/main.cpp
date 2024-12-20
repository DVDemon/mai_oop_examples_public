#include <iostream>
#include <chrono>

// факториал с помощью функций
template <uint64_t value> uint64_t Factorial(){
  return Factorial<value-1>()*value;    
}

template <> uint64_t Factorial<1>(){
  return 1ull;    
}

// факториал с помощью классов
template<uint64_t n>
struct fact{
    static const uint64_t value = fact<n-1>::value * n;
};
 
template<>
struct fact<1>{
   static const uint64_t value = 1ull;
};
 

template<uint64_t n>
uint64_t cool_factorial(){
  if constexpr (n>1) return cool_factorial<n-1>()*n;
                else return 1ull;
};

// замереем скорость работы 
int main() {
  // факториал - функция - 1
    auto begin = std::chrono::high_resolution_clock::now();
    std::cout << "Factorial: " << Factorial<50>() << std::endl;
    auto end = std::chrono::high_resolution_clock::now();
    std::cout << std::chrono::duration_cast <std::chrono::microseconds>( end - begin ).count()<< std::endl;
 
  // факториал - мета-функция - 2
    begin = std::chrono::high_resolution_clock::now();
    std::cout << "fact: " <<fact<50>::value << std::endl;
    end = std::chrono::high_resolution_clock::now();
    std::cout << std::chrono::duration_cast <std::chrono::microseconds>( end - begin ).count()<< std::endl;
 
   // факториал - мета-функция - 3
    begin = std::chrono::high_resolution_clock::now();
    std::cout << "cool_factorial: " << cool_factorial<50>() << std::endl;
    end = std::chrono::high_resolution_clock::now();
    std::cout << std::chrono::duration_cast <std::chrono::microseconds>( end - begin ).count()<< std::endl;
 
  // факториал - обычный цикл - 4
    begin = std::chrono::high_resolution_clock::now();
    uint64_t value=1;
    for(int i=1;i<=50;i++) value*=i;
    std::cout << "simple: " << value << std::endl;
    end = std::chrono::high_resolution_clock::now();
    std::cout << std::chrono::duration_cast <std::chrono::microseconds>( end - begin ).count()<< std::endl;
    
    return 0;
}

