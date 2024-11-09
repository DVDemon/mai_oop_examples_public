#include <iostream>
#include <vector>

// Вектор распологается на стеке, а данные вектора - в куче
void testPlacing() {
    std::cout << "\ntestPlacing\n";

    int stackVariable = 0;
    std::vector<int> values = {0, 1, 2, 3};

    std::cout << "&stackVariable = " << &stackVariable << std::endl;
    std::cout << "&values        = " << &values << std::endl;
    std::cout << "values.data()  = " << values.data() << std::endl;

    for(const auto& v : values)
        std::cout << v << ' ';
    std::cout << std::endl;

    for(auto it = values.begin();it!=values.end();++it)
        std::cout << *it << ' ';
    std::cout << std::endl;


    int values2[] = {1,2,3,4,5};
    for(auto it = std::begin(values2);it!=std::end(values2);++it)
        std::cout << *it << ' ';
    std::cout << std::endl;

    int a[5] = {1,2,3,4,5};

    for(auto& v : a)
        std::cout << v << ' ';
    std::cout << std::endl;
}

// проверим по какой стратегии увеличивается количество элементов в Vector
void testReallocate() {
    std::cout << "\ntestReallocate\n";

    std::vector<int> values;

    auto capacity = values.capacity();
    std::cout << '[' << 0 << ']' << " capacity = " << values.capacity() << std::endl;
    for (int i=0; i<10000; ++i) {
        if (capacity != values.capacity()) {
            std::cout << '[' << i << ']' << " capacity = " << values.capacity() << std::endl;
            capacity = values.capacity();
        }
        values.push_back(i);
    }
    std::cout << std::endl;
}

// проверим метод резервации места
void testReserve() {
    std::cout << "\ntestReserve\n";

    const int count = 100;
    std::vector<int> values;

    values.reserve(count);
    std::cout << "capacity = " << values.capacity() << std::endl;

    for (int i=0; i<count/2; ++i)
        values.push_back(i);

    std::cout << "capacity = " << values.capacity() << std::endl;

    std::cout << "shrink_to_fit" << std::endl;
    values.shrink_to_fit();

    std::cout << "capacity = " << values.capacity() << std::endl;
    
    std::cout << "one more" << std::endl;
    values.push_back(42);

    std::cout << "capacity = " << values.capacity() << std::endl;
}

// проверим как работает итератор
void testIterator() {
    std::cout << "\ntestIterator\n";

    std::vector<int> values = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    values.reserve(20);
    std::cout << "capacity = " << values.capacity() << std::endl;

    std::cout << *values.begin() << std::endl;

    auto iter = std::next(values.cbegin(), 3); /// values.cbegin()+3
    
    std::cout << *iter << std::endl;

    ++iter;
    std::cout << *iter << std::endl;

    --iter;
    --iter;
    std::cout << *iter << std::endl;

    iter += 3;
    std::cout << *iter << std::endl;

    auto iterPos = std::distance(values.cbegin(), iter);
    std::cout << "iterPos = " << iterPos << std::endl;

    std::cout << "one more" << std::endl;
    values.push_back(42);    
    std::cout << "capacity = " << values.capacity() << std::endl;

    std::cout << "&values[0]       = " << &values[0] << std::endl;
    std::cout << "&values[iterPos] = " << &values[iterPos] << std::endl;
    values.shrink_to_fit();
    // Ooops. Iterator is invalid.
     std::cout << "&*iter           = " << &*iter << std::endl;

    auto iter2 = std::next(values.cbegin(), 3);
    std::cout << "*iter2 = " << *iter2 << std::endl;
    std::cout << "one more at the begining" << std::endl;
    values.insert(values.cbegin(), 42);

    // Ooops. Iterator is invalid.
    std::cout << "*iter2 = " << *iter2 << std::endl;
    iter2+=6;
    std::cout << "*iter2 = " << *iter2 << std::endl;
}


struct SomeStruct {

    SomeStruct(int value) : m_value{value} {

    }

    SomeStruct(const SomeStruct& other) 
        : m_value{other.m_value} {
        std::cout << '[' << m_value << "] copy!" << std::endl;
    }

    SomeStruct(SomeStruct&& other) noexcept
        : m_value{other.m_value} {
        std::cout << '[' << m_value << "] move!" << std::endl;
    }

    SomeStruct& operator=(SomeStruct&& other)  noexcept{
        m_value = other.m_value;
        other.m_value = 0;
        std::cout << '[' << m_value << "] operator= move!" << std::endl;
        return *this;
    }

    SomeStruct& operator=(const SomeStruct& other) {
        m_value = other.m_value;
        std::cout << '[' << m_value << "] operator= copy!" << std::endl;
        return *this;
    }
private:
    int m_value;
};

void testCustomReallocate() {
    std::cout << "\ntestCustomReallocate\n";
    std::vector<SomeStruct> values;

    for (int i=0; i<5; ++i) {
        std::cout << "capacity = " << values.capacity() << std::endl;
        
        // много копирований
        //*
        //SomeStruct entry{i};
        //values.push_back(entry);
        //values.push_back(SomeStruct(i));
        //*/
        values.emplace_back(i);
    }
}

int main() {

    testPlacing();
    testReallocate();
    testReserve();
    testIterator();
    testCustomReallocate();

    return 0;
}