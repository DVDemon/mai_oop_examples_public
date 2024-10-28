#include <type_traits>
#include <iostream>


/*
 void print(int value[5]){
    for(auto a: value)
        std::cout << a << " ";
    std::cout << std::endl;
  }

  void print(int* value){
      std::cout << "pointer:" << value << std::endl;
  }
*/
template <class T>
typename std::enable_if<std::is_array<T>::value,void>::type print(T& value){
    for(auto a: value)
        std::cout << a << " ";
    std::cout << std::endl;
}

template <class T>
typename std::enable_if<std::is_pointer<T>::value,void>::type print(T& value){
    std::cout << "pointer:" << value << std::endl;
}

template <class T>
typename std::enable_if<std::is_integral<T>::value,void>::type print(T& value){
    std::cout << "int:" << value << std::endl;
}

// Функция, которая работает только с целочисленными типами 
template<typename T, typename std::enable_if<std::is_integral<T>::value, int>::type = 0> 
void print_integer(T value) { 
  std::cout << "Integer value: " << value << std::endl; 
} 


int main(){
    int c=10;
    double d=1.0;
    print(c);
    print_integer<int>(c); 
    //print_integer(d); 

    
    int a[5] = {1,2,3,4,5};
    print(a);

    int *b = new int [10];
    print(b);

    delete[] b;
    return 0;
}