#include <iostream>
#include <iterator>
#include <vector>

template <class Container>
  class back_insert_iterator 
{
protected:
  Container* container;

public:
  typedef Container container_type;
  explicit back_insert_iterator (Container& x) : container(&x) {}
  
  // копирование знаения 
  back_insert_iterator<Container>& 
  operator= (const typename Container::value_type& value)
    { container->push_back(value); return *this; }
  
  // перемещение значения
  back_insert_iterator<Container>& 
  operator= (typename Container::value_type&& value)
    { container->push_back(std::move(value)); return *this; }
  
  // стандартный набор операторов
  back_insert_iterator<Container>& operator* ()
    { return *this; }
  back_insert_iterator<Container>& operator++ ()
    { return *this; }
  back_insert_iterator<Container> operator++ (int)
    { return *this; }
};

int main(int argc, char** argv) {

    std::vector<int> target;
    int src[]={1,2,3,4,5,6,7,8,9};
    
    back_insert_iterator<std::vector<int>> iterator(target);
    for(int i:src) iterator=i;
    
    for(int i:target) std::cout << i << std::endl;
    return 0;
}

