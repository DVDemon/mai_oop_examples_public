#include <vector>
#include <map>
#include <iostream>

namespace mai
{
    template <class T, size_t BLOCK_SIZE>
    class allocator
    {
    private:
        T *_buffer;
        size_t _free_index;

    public:
        using value_type = T;
        using pointer = T *;
        using const_pointer = const T *;
        using size_type = std::size_t;

        allocator() : _buffer{}, _free_index(0)
        {
            static_assert(BLOCK_SIZE > 0);
        }

        ~allocator()
        {
            free(_buffer);
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
                _buffer = (T *)malloc(sizeof(T) * BLOCK_SIZE);

            if ((BLOCK_SIZE - _free_index) < n)
                throw std::bad_alloc();
            T *pointer = (_buffer + _free_index);
            _free_index += n;

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
            new (p) U(std::forward<Args>(args)...);
        }

        void destroy(pointer p)
        {
            p->~T();
        }
    };
}

template <int N>
int factorial()
{
    return N * factorial<N - 1>();
}
template <>
int factorial<0>()
{
    return 1;
}

using map_type_with_allocator =
    std::map<int, int, std::less<int>, mai::allocator<std::pair<const int, int>, 10>>;

template <int N>
void fill_map(map_type_with_allocator &map)
{
    map.insert(std::pair<int, int>(N, factorial<N>()));
    fill_map<N - 1>(map);
}

template <>
void fill_map<0>(map_type_with_allocator &map)
{
    map.insert(std::pair<int, int>(0, factorial<0>()));
}

auto main() -> int
{

    // заполняем значением факториала
    map_type_with_allocator my_map_with_allocator;
    fill_map<9>(my_map_with_allocator);

    for (auto p : my_map_with_allocator)
        std::cout << p.first << " " << p.second << std::endl;
    return 0;
}
