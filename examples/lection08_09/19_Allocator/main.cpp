#include <vector>
#include <map>
#include <iostream>
#include <memory>

/**
 * Пространство имен для демонстрации кастомного аллокатора
 * Содержит реализацию аллокатора с фиксированным размером блока
 */
namespace mai {
    /**
     * Кастомный аллокатор с фиксированным размером блока
     * Демонстрирует создание аллокатора для STL контейнеров
     * 
     * @tparam T - тип элементов для выделения
     * @tparam BLOCK_SIZE - размер блока памяти
     */
    template <class T, size_t BLOCK_SIZE>
    class allocator {
    private:
        std::shared_ptr<T[]> memory_buffer;      // Буфер для хранения элементов
        std::shared_ptr<size_t> free_index;      // Индекс следующего свободного элемента

    public:
        // ========================================================================
        // ТИПЫ ДЛЯ СОВМЕСТИМОСТИ СО STL
        // ========================================================================
        using value_type = T;
        using pointer = T*;
        using const_pointer = const T*;
        using size_type = std::size_t;

        /**
         * Конструктор аллокатора
         * Инициализирует буфер и индекс свободного места
         */
        allocator() : memory_buffer{} {
            std::cout << "   Конструктор аллокатора вызван" << std::endl;
            static_assert(BLOCK_SIZE > 0, "Размер блока должен быть больше 0");
            free_index = std::make_shared<size_t>(0);
        }

        /**
         * Деструктор аллокатора
         * Выводит информацию о разрушении
         */
        ~allocator() {
            std::cout << "   Деструктор аллокатора вызван" << std::endl;
        }

        /**
         * Оператор присваивания
         * Копирует состояние другого аллокатора
         */
        allocator<T, BLOCK_SIZE>& operator=(const allocator<T, BLOCK_SIZE>& other) {
            std::cout << "   Оператор присваивания аллокатора" << std::endl;
            this->memory_buffer = other.memory_buffer;
            this->free_index = other.free_index;
            return *this;
        }

        /**
         * Структура rebind для совместимости с STL
         * Позволяет STL контейнерам создавать аллокаторы для других типов
         */
        template <typename U>
        struct rebind {
            using other = allocator<U, BLOCK_SIZE>;
        };

        /**
         * Выделение памяти для n элементов
         * @param n - количество элементов для выделения
         * @return указатель на выделенную память
         */
        T* allocate(size_t n) {
            std::cout << "   Выделение памяти для " << n << " элементов" << std::endl;
            
            // Создание буфера при первом обращении
            if (!memory_buffer) {
                memory_buffer = std::shared_ptr<T[]>(new T[BLOCK_SIZE]);
            }

            // Проверка доступности места в буфере
            if ((BLOCK_SIZE - *free_index) < n) {
                throw std::bad_alloc();
            }
            
            T* allocated_pointer = &(memory_buffer[*free_index]);
            *free_index += n;

            return allocated_pointer;
        }

        /**
         * Освобождение памяти
         * В данной реализации не выполняет реального освобождения
         * @param pointer - указатель на освобождаемую память
         * @param n - количество элементов
         */
        void deallocate(T* pointer, size_t n) {
            std::cout << "   Освобождение памяти для " << n << " элементов" << std::endl;
            // В данной реализации память не освобождается
            // Это упрощенная демонстрация
        }

        /**
         * Конструирование объекта в выделенной памяти
         * @param p - указатель на память для конструирования
         * @param args - аргументы конструктора
         */
        template <typename U, typename... Args>
        void construct(U* p, Args&&... args) {
            std::cout << "   Конструирование объекта" << std::endl;
            new (p) U(std::forward<Args>(args)...);
        }

        /**
         * Разрушение объекта
         * @param p - указатель на объект для разрушения
         */
        void destroy(pointer p) {
            std::cout << "   Разрушение объекта" << std::endl;
            p->~T();
        }
    };
}


/**
 * Псевдоним типа для map с кастомным аллокатором
 * Демонстрирует использование аллокатора с ассоциативными контейнерами
 */
using map_type_with_allocator = 
    std::map<int, int, std::less<int>, mai::allocator<std::pair<const int, int>, 10>>;

/**
 * Основная функция - демонстрация кастомного аллокатора
 * Показывает использование аллокатора с различными STL контейнерами
 */
int main() {
    std::cout << "=== ДЕМОНСТРАЦИЯ КАСТОМНОГО АЛЛОКАТОРА ===" << std::endl;

    // ========================================================================
    // ДЕМОНСТРАЦИЯ 1: СОЗДАНИЕ И КОПИРОВАНИЕ АЛЛОКАТОРОВ
    // ========================================================================
    std::cout << "\n1. Создание и копирование аллокаторов:" << std::endl;
    mai::allocator<int, 10> first_allocator;
    mai::allocator<int, 10> second_allocator = first_allocator;

    // ========================================================================
    // ДЕМОНСТРАЦИЯ 2: ИСПОЛЬЗОВАНИЕ С VECTOR
    // ========================================================================
    std::cout << "\n2. Использование с std::vector:" << std::endl;
    std::vector<int, mai::allocator<int, 100>> integer_vector;
    
    std::cout << "   Заполнение вектора значениями:" << std::endl;
    for (size_t element_index = 0; element_index < 10; ++element_index) {
        integer_vector.push_back(element_index);
    }

    std::cout << "   Содержимое вектора:" << std::endl;
    for (size_t element_index = 0; element_index < 10; ++element_index) {
        std::cout << "   " << integer_vector[element_index] << std::endl;
    }


    return 0;
}
