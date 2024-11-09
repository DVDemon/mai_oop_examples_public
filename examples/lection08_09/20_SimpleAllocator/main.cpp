#include <iostream>
#include <memory>
#include <chrono>
#include <list>
#include <map>
#include <utility>

//#define DEBUG

namespace mai
{
    template <class T>
    class Allocator
    {
    private:
        char *_used_blocks;
        void **_free_blocks;
        uint64_t _free_count;

    public:
        static constexpr size_t max_count = 500000;
        using value_type = T;
        using pointer = T *;
        using const_pointer = const T *;
        using size_type = std::size_t;

        Allocator()
        {
            _used_blocks = (char *)malloc(sizeof(T) * max_count);
            _free_blocks = (void **)malloc(sizeof(void *) * max_count);

            for (uint64_t i = 0; i < max_count; i++)
                _free_blocks[i] = _used_blocks + i * sizeof(T);
            _free_count = max_count;
#ifdef DEBUG
            std::cout << "allocator: memory init" << std::endl;
#endif
        }

        ~Allocator()
        {
#ifdef DEBUG
            if (_free_count < max_count)
                std::cout << "allocator: Memory leak?" << std::endl;
            else
                std::cout << "allocator: Memory freed" << std::endl;
#endif

            delete _free_blocks;
            delete _used_blocks;

            _free_blocks = nullptr;
            _used_blocks = nullptr;
        }

        template <class U>
        struct rebind
        {
            using other = Allocator<U>;
        };

        // мы не используем параметр n - поэтому с std::vector данный аллокатор работать не будет
        T *allocate(size_t n)
        {
            T *result = nullptr;
            if (_free_count > 0)
            {
                result = (T *)_free_blocks[--_free_count];
#ifdef DEBUG
                std::cout << "allocator: Allocate " << (max_count - _free_count) << " of " << max_count << " Address:" << result << std::endl;
#endif
            }
            else
            {
                std::cout << "allocator: No memory exception :-)" << std::endl;
            }
            return result;
        }

        void deallocate(T *pointer, size_t)
        {
#ifdef DEBUG
            std::cout << "allocator: Deallocate block " << std::endl;
#endif
            _free_blocks[_free_count++] = pointer;
        }
        template <typename U, typename... Args>
        void construct(U *p, Args &&...args)
        {
            new (p) U(std::forward<Args>(args)...);
        }

        void destroy(pointer p)
        {
            p->~T();
        }
    };

    template <class T, class U>
    constexpr bool operator==(const Allocator<T> &lhs, const Allocator<U> &rhs) 
    {
        return true;
    }

    template <typename T, typename U, size_t BLOCK_COUNT>
    constexpr bool operator!=(const Allocator<T> &lhs, const Allocator<U> &rhs)  
    {
        return false;
    }
}

struct SomeStruct
{
    char buffer[1024];
};

void test1()
{
    auto begin = std::chrono::high_resolution_clock::now();
    std::list<SomeStruct> my_list;
    for (int i = 0; i < 500000; i++)
        my_list.push_back(SomeStruct());
    for (int i = 0; i < 500000; i++)
        my_list.erase(my_list.begin());
    auto end = std::chrono::high_resolution_clock::now();
    std::cout << "test1: " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << std::endl;
}

void test2()
{
    auto begin = std::chrono::high_resolution_clock::now();
    std::list<SomeStruct, mai::Allocator<SomeStruct>> my_list;
    for (int i = 0; i < 500000; i++)
        my_list.push_back(SomeStruct());
    for (int i = 0; i < 500000; i++)
        my_list.erase(my_list.begin());
    auto end = std::chrono::high_resolution_clock::now();
    std::cout << "test2: " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << std::endl;
}

int main(int argc, char **argv)
{
    test1();
    test2();

    // std::map<int, int, std::less<int>,mai::Allocator<std::pair<const int,int>>> my_map;

    // my_map[1]=10;
    // my_map[2]=20;
    // my_map[3]=30;


    // for(const auto& [k,v]: my_map)
    //     std::cout << k << "->" << v << std::endl;

    return 0;
}
