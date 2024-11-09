#include <vector>
#include <map>
#include <iostream>
#include <memory>

namespace mai
{
    template <class T, size_t BLOCK_SIZE>
    class allocator
    {
    private:
        std::shared_ptr<T[]>     _buffer;
        std::shared_ptr<size_t>  _free_index;

    public:
        using value_type = T;
        using pointer = T *;
        using const_pointer = const T *;
        using size_type = std::size_t;

        allocator() : _buffer{}
        {
            std::cout << "constructor" << std::endl;
            static_assert(BLOCK_SIZE > 0);
             _free_index = std::make_shared<size_t>(0);
        }

        ~allocator()
        {
            std::cout << "destructor" << std::endl;
        }

        allocator<T,BLOCK_SIZE> operator=(const allocator<T,BLOCK_SIZE> &other){
            std::cout << "copy" << std::endl;
            this->_buffer = other._buffer;
            this->_free_index = other._free_index;
            return *this;
        }

        template <typename U>
        struct rebind
        {
            using other = allocator<U, BLOCK_SIZE>;
        };

        T *allocate(size_t n)
        {
            std::cout << "allocate" << std::endl;
            if (!_buffer)
                _buffer = std::shared_ptr<T[]>(new T[BLOCK_SIZE]);//(T *)malloc(sizeof(T) * BLOCK_SIZE);

            if ((BLOCK_SIZE - *_free_index) < n)
                throw std::bad_alloc();
            T *pointer = &(_buffer[* _free_index]);
            *_free_index += n;

            return pointer;
        }

        void deallocate(T *, size_t)
        {
            // тут надо бы удалить память
            std::cout << "deallocate" << std::endl;
        }

        template <typename U, typename... Args>
        void construct(U *p, Args &&...args)
        {
            std::cout << "construct" << std::endl;
            new (p) U(std::forward<Args>(args)...);
        }

        void destroy(pointer p)
        {
            std::cout << "destory" << std::endl;
            p->~T();
        }
    };
}


using map_type_with_allocator =
    std::map<int, int, std::less<int>, mai::allocator<std::pair<const int, int>, 10>>;

auto main() -> int
{
    // mai::allocator<int,10> a;
    // mai::allocator<int,10> b=a;

    // // заполняем значением факториала
    // map_type_with_allocator my_map_with_allocator;
    // my_map_with_allocator[1]=2;
    // my_map_with_allocator[2]=4;
    // my_map_with_allocator[3]=6;
    // my_map_with_allocator[4]=7;

    // for (auto p : my_map_with_allocator)
    //     std::cout << p.first << " " << p.second << std::endl;


    std::vector<int,mai::allocator<int,100>> my_vector;
    for(size_t i=0;i<10;++i) my_vector.push_back(i);

    for(size_t i=0;i<10;++i) std::cout << my_vector[i] << std::endl;
    return 0;
}
