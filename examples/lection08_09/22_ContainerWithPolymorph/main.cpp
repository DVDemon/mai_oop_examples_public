#include <iostream>
#include <memory_resource>
#include <vector>
#include <concepts>
#include <memory>
#include <exception>
#include <algorithm>


// Пользовательский memory_resource, который использует операторы new и delete
class CustomMemoryResource : public std::pmr::memory_resource
{
    struct Block {
        size_t offset {0};
        size_t size {0};
    };

    static constexpr size_t max_size{600};
    char buffer[max_size];
    std::vector<Block> used_blocks;

public:
    void *do_allocate(size_t bytes, size_t alignment) override
    {
        // find free block
        size_t result = {0};
        for(const Block& b: used_blocks) 
            if ((result+bytes <= b.offset) || (result>= b.offset+b.size)) {}
             else result = b.offset+b.size +1;
    
        if(result+bytes >= max_size) throw std::bad_alloc();

        used_blocks.emplace_back(result,bytes);
        std::sort(used_blocks.begin(),used_blocks.end(),[](auto & lhv,auto & rhv) { return lhv.offset<=rhv.offset;});
        std::cout << "allocate: " << result << ":" << bytes << std::endl;
        return buffer+result;//::operator new(bytes);
    }

    void do_deallocate(void *ptr, size_t bytes, size_t alignment) override
    {
        std::cout << "deallocate: " << ptr << ":" << bytes << std::endl;
        for(size_t i=0;i< used_blocks.size();++i)
            if(ptr == buffer + used_blocks[i].offset) {
                used_blocks.erase(used_blocks.begin()+i);
                return;
            }
        throw std::logic_error("удаление не выделяемого блока");
    }

    bool do_is_equal(const std::pmr::memory_resource &other) const noexcept override
    {
        return this == &other;
    }
};

template <class T, class allocator_type>
    requires std::is_default_constructible_v<T> && std::is_same_v<allocator_type, std::pmr::polymorphic_allocator<T>>
class Array
{
private:
    struct PolymorphicDeleter
    {
        void operator()(T *ptr) const
        {
        }
    };

    using LimitedUniquePtr = std::unique_ptr<T, PolymorphicDeleter>;

    allocator_type allocator_;
    LimitedUniquePtr data_;
    std::size_t size_;

public:
    Array(std::size_t size, allocator_type alloc = {}) : allocator_(alloc),
                                                         //data_(allocator_.allocate_unique(size)),
                                                         size_(size)
    {
        T *raw_ptr = allocator_.allocate(size); 
        for(size_t i=0;i<size;++i) 
            allocator_.construct(raw_ptr+i);
        
        //allocator,con          // Allocate space for one T
        //new (raw_ptr) T(std::forward<Args>(args)...); // Use placement new with forwarded arguments
        data_ = std::unique_ptr<T, PolymorphicDeleter>(raw_ptr, PolymorphicDeleter{});
    }
    // Оператор доступа к элементам
    int &operator[](std::size_t index)
    {
        if (index < size_)
            return data_.get()[index];
        else
            throw std::out_of_range("выход за границы массива");
    }

    // Константный оператор доступа к элементам
    const int &operator[](std::size_t index) const
    {
        if (index < size_)
            return data_.get()[index];
        else
            throw std::out_of_range("выход за границы массива");
    }

    T* begin() {
        return data_.get();
    }

    T* end() {
        return (data_.get()+size_);
    }

    // Размер вектора
    std::size_t size() const
    {
        return size_;
    }
    ~Array() {
        if constexpr (std::is_destructible_v<T>)
            for(size_t i=0;i<size_;++i)
            std::allocator_traits<allocator_type>::destroy(allocator_, data_.get() + i);
        allocator_.deallocate(data_.get(),size_);
    }
};

int main()
{
    CustomMemoryResource customResource;
    std::pmr::polymorphic_allocator<int> allocator(&customResource);

    struct AB {
        int a;
        int b;
    };

    Array<AB, std::pmr::polymorphic_allocator<AB>> array(10, allocator);

    Array<int, std::pmr::polymorphic_allocator<int>> *array1,*array2,*array3,*array4;

    array1 = new Array<int, std::pmr::polymorphic_allocator<int>>(10,allocator);
    array2 = new Array<int, std::pmr::polymorphic_allocator<int>>(10,allocator);
    array3 = new Array<int, std::pmr::polymorphic_allocator<int>>(10,allocator);
    array4 = new Array<int, std::pmr::polymorphic_allocator<int>>(10,allocator);
   //Array<int, std::pmr::polymorphic_allocator<int>> array4(10, allocator);

    delete array2;
    delete array3;
    for(int k=0;k<10;++k)
    {
        std::cout << "Array number:" << k << std::endl;
        Array<int, std::pmr::polymorphic_allocator<int>> array(10, allocator);
        Array<int, std::pmr::polymorphic_allocator<int>> array99(40, allocator);
        for (int i = 0; i < 10; ++i) array[i] = i;
        for (int i : array) std::cout << i << " ";
        std::cout << std::endl << std::endl;
    }
    delete array1;
    delete array4;
    return 0;
}