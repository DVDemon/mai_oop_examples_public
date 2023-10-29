#include <iostream>
#include <memory>
#include <chrono>
#include <list>
#include <vector>

//#define DEBUG

namespace mai {
    template<class T,size_t BLOCK_COUNT>
    class allocator {
        private:
            char  *_used_blocks;
            void  **_free_blocks;
            uint64_t _free_count;

        public:
            using value_type = T;
            using pointer = T * ;
            using const_pointer = const T*;
            using size_type = std::size_t;

            allocator() {
                static_assert(BLOCK_COUNT>0);
                _used_blocks = (char*) malloc(sizeof(T) * BLOCK_COUNT);
                _free_blocks = (void**) malloc(sizeof (void*)*BLOCK_COUNT);

                for (uint64_t i = 0; i < BLOCK_COUNT; i++) 
                    _free_blocks[i] = _used_blocks + i * sizeof(T);
                _free_count = BLOCK_COUNT;
                #ifdef DEBUG
                std::cout << "allocator: memory init" << std::endl;  
                #endif             
            }

            ~allocator(){
                #ifdef DEBUG
                if (_free_count < BLOCK_COUNT) std::cout << "allocator: Memory leak?" << std::endl;
                                     else std::cout << "allocator: Memory freed" << std::endl;
                #endif 

                delete _free_blocks;
                delete _used_blocks;
            }

            /*static allocator get(){
                static allocator _instance;
                return instance;
            }*/

            template<typename U>
            struct rebind {
                using other = allocator<U,BLOCK_COUNT>;
            };

            // мы не используем параметр n - поэтому с std::vector данный аллокатор работать не будет
            T* allocate(size_t n) {
                T *result = nullptr;
                if (_free_count > 0) {
                    result = (T*)_free_blocks[--_free_count];
                    #ifdef DEBUG
                    std::cout << "allocator: Allocate " << (BLOCK_COUNT-_free_count) << " of " << BLOCK_COUNT << " Address:" << result << std::endl;
                    #endif
                } else {
                    std::cout << "allocator: No memory exception :-)" << std::endl;
                }
                return result;
            }

            void deallocate(T* pointer,  size_t ) {
                #ifdef DEBUG
                std::cout << "allocator: Deallocate block "<< std::endl;
                #endif
                _free_blocks[_free_count++] = pointer;
            }


            template<typename U, typename ...Args>
            void construct(U *p, Args &&...args) {
                new (p) U(std::forward<Args>(args)...);
            }

            void destroy(pointer p) {
                p->~T();
            }

    };
}

struct SomeStruct{
    char buffer[1024];
};


void test1(){
    auto begin = std::chrono::high_resolution_clock::now();
    std::list<SomeStruct> my_list;
    for(int i=0;i<100000;i++) my_list.push_back(SomeStruct());
    for(int i=0;i<100000;i++) my_list.erase(my_list.begin());
    auto end = std::chrono::high_resolution_clock::now();
    std::cout << "test1: " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << std::endl;
 
}

void test2(){
    auto begin = std::chrono::high_resolution_clock::now();
    std::list<SomeStruct,mai::allocator<SomeStruct,100000>> my_list;
    for(int i=0;i<100000;i++) my_list.push_back(SomeStruct());
    for(int i=0;i<100000;i++) my_list.erase(my_list.begin());
    auto end = std::chrono::high_resolution_clock::now();
    std::cout << "test2: " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << std::endl;
 
}

int main(int argc, char** argv) {
    test1();
    test2();
 
    return 0;
}

