#include <iostream>
#include <memory>
#include <initializer_list>

class OutOfBoundException
{
};

template <class ItemType, class ArrayType>
class ArrayIterator
{
private:
    ArrayType *array;
    size_t index;
    size_t size;

public:
    ArrayIterator(ArrayType *value, size_t i, size_t s) : array(value), index(i), size(s){};

    ItemType operator*()
    {
        if (index >= size)
            throw OutOfBoundException();
        return (*array)[index];
    }

    ItemType operator->()
    {
        if (index >= size)
            throw OutOfBoundException();
        return (*array)[index];
    }

    bool operator!=(ArrayIterator<ItemType, ArrayType> const &other) const
    {
        return (other.index != index) || (other.array != array);
    }

    ArrayIterator<ItemType, ArrayType> &operator++()
    {
        ++index;
        return *this;
    }
};

template <class T>
class DynamicArray
{
private:
    std::unique_ptr<T[]> data;
    const size_t size;

public:
    DynamicArray(size_t s) : size(s)
    {
        data.reset(new T[size]);
    }

    DynamicArray(std::initializer_list<T> list) : size(list.size()), data(new T[list.size()])
    {
        std::copy(list.begin(), list.end(), data.get());        
    };

    T &operator[](size_t index)
    {
        if (index >= size)
            throw OutOfBoundException();
        return data.get()[index];
    }

    ArrayIterator<T, DynamicArray<T>> begin() // первый элемент массива
    {
        return ArrayIterator<T, DynamicArray<T>>(this, 0, size);
    }

    ArrayIterator<T, DynamicArray<T>> end() // элементы сразу за последним элементом массива
    {
        return ArrayIterator<T, DynamicArray<T>>(this, size, size);
    }
};

int main(int argc, char **argv)
{

    DynamicArray<int> array(10);

    array[0] = 10;
    array[1] = 8;
    array[2] = 9;

    //*
    auto it1 = array.begin();

    ++it1;
    // std::next(it1,3);
    //it1+=3;
    std::cout << *it1 << std::endl;

    std::cout << "Iterator:" << std::endl;
    for (ArrayIterator<int, DynamicArray<int>> it = array.begin(); it != array.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    std::cout << "Iterator 2:" << std::endl;
    for (auto it = std::begin(array); it != std::end(array); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    //*
    std::cout << "Ranger for:" << std::endl;
    for (auto a : array)
        std::cout << a << " ";
    std::cout << std::endl;

    std::cout << "Initializer list:" << std::endl;
    DynamicArray<int> array2{1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (auto a : array2)
        std::cout << a << " ";
    //*/

    std::cout << std::endl;

    return 0;
}
