#include <iostream>
#include <memory_resource>
#include <vector>

// Пользовательский memory_resource, который использует операторы new и delete
class CustomMemoryResource : public std::pmr::memory_resource {
public:
    void* do_allocate(size_t bytes, size_t alignment) override {
        return ::operator new(bytes);
    }

    void do_deallocate(void* ptr, size_t bytes, size_t alignment) override {
        ::operator delete(ptr);
    }

    bool do_is_equal(const std::pmr::memory_resource& other) const noexcept override {
        return this == &other;
    }
};

int main() {
    // Создаем экземпляр пользовательского memory_resource
    CustomMemoryResource customResource;

    // Создаем полиморфный аллокатор, использующий наш пользовательский memory_resource
    std::pmr::polymorphic_allocator<int> allocator(&customResource);

    // Создаем вектор, использующий наш полиморфный аллокатор
    std::pmr::vector<int> vec(allocator);

    // Добавляем элементы в вектор
    for (int i = 0; i < 10; ++i) {
        vec.push_back(i);
    }

    // Выводим элементы вектора
    for (int i : vec) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}