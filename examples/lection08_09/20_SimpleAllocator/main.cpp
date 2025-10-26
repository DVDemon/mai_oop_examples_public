#include <iostream>
#include <memory>
#include <chrono>
#include <list>
#include <map>
#include <utility>

// Раскомментируйте для отладочного вывода
//#define DEBUG

/**
 * Пространство имен для демонстрации простого аллокатора
 * Содержит реализацию аллокатора с пулом объектов
 */
namespace mai {
    /**
     * Простой аллокатор с пулом объектов
     * Демонстрирует создание аллокатора для оптимизации производительности
     * 
     * @tparam T - тип элементов для выделения
     */
    template <class T>
    class Allocator {
    private:
        char* used_blocks;        // Буфер для хранения объектов
        void** free_blocks;       // Массив указателей на свободные блоки
        uint64_t free_count;      // Количество свободных блоков

    public:
        static constexpr size_t max_count = 500000;  // Максимальное количество объектов
        using value_type = T;
        using pointer = T*;
        using const_pointer = const T*;
        using size_type = std::size_t;

        /**
         * Конструктор аллокатора
         * Инициализирует пул объектов и массив свободных блоков
         */
        Allocator() {
            used_blocks = (char*)malloc(sizeof(T) * max_count);
            free_blocks = (void**)malloc(sizeof(void*) * max_count);

            // Инициализация массива свободных блоков
            for (uint64_t block_index = 0; block_index < max_count; block_index++) {
                free_blocks[block_index] = used_blocks + block_index * sizeof(T);
            }
            free_count = max_count;
            
#ifdef DEBUG
            std::cout << "   Аллокатор: память инициализирована" << std::endl;
#endif
        }

        /**
         * Деструктор аллокатора
         * Освобождает выделенную память и проверяет на утечки
         */
        ~Allocator() {
#ifdef DEBUG
            if (free_count < max_count) {
                std::cout << "   Аллокатор: Возможна утечка памяти?" << std::endl;
            } else {
                std::cout << "   Аллокатор: Память освобождена" << std::endl;
            }
#endif

            free(free_blocks);
            free(used_blocks);

            free_blocks = nullptr;
            used_blocks = nullptr;
        }

        /**
         * Структура rebind для совместимости с STL
         * Позволяет STL контейнерам создавать аллокаторы для других типов
         */
        template <class U>
        struct rebind {
            using other = Allocator<U>;
        };

        /**
         * Выделение памяти для одного объекта
         * ВАЖНО: Данный аллокатор не поддерживает выделение для n > 1
         * Поэтому с std::vector данный аллокатор работать не будет
         * 
         * @param n - количество элементов (игнорируется, всегда 1)
         * @return указатель на выделенную память
         */
        T* allocate(size_t n) {
            T* result = nullptr;
            if (free_count > 0) {
                result = (T*)free_blocks[--free_count];
#ifdef DEBUG
                std::cout << "   Аллокатор: Выделено " << (max_count - free_count) 
                          << " из " << max_count << " Адрес: " << result << std::endl;
#endif
            } else {
                std::cout << "   Аллокатор: Нет свободной памяти :-)" << std::endl;
            }
            return result;
        }

        /**
         * Освобождение памяти
         * Возвращает блок в пул свободных блоков
         * 
         * @param pointer - указатель на освобождаемую память
         * @param n - количество элементов (игнорируется)
         */
        void deallocate(T* pointer, size_t) {
#ifdef DEBUG
            std::cout << "   Аллокатор: Освобождение блока" << std::endl;
#endif
            free_blocks[free_count++] = pointer;
        }

        /**
         * Конструирование объекта в выделенной памяти
         * 
         * @param p - указатель на память для конструирования
         * @param args - аргументы конструктора
         */
        template <typename U, typename... Args>
        void construct(U* p, Args&&... args) {
            new (p) U(std::forward<Args>(args)...);
        }

        /**
         * Разрушение объекта
         * 
         * @param p - указатель на объект для разрушения
         */
        void destroy(pointer p) {
            p->~T();
        }
    };

    /**
     * Оператор сравнения аллокаторов
     * Все аллокаторы считаются равными для совместимости со STL
     */
    template <class T, class U>
    constexpr bool operator==(const Allocator<T>& lhs, const Allocator<U>& rhs) {
        return true;
    }

    /**
     * Оператор неравенства аллокаторов
     * Все аллокаторы считаются равными для совместимости со STL
     */
    template <typename T, typename U, size_t BLOCK_COUNT>
    constexpr bool operator!=(const Allocator<T>& lhs, const Allocator<U>& rhs) {
        return false;
    }
}

/**
 * Тестовая структура для демонстрации производительности
 * Содержит буфер размером 1KB для имитации реальных объектов
 */
struct TestStructure {
    char buffer[1024];  // Буфер для имитации реальных данных
};

/**
 * Тест производительности со стандартным аллокатором
 * Демонстрирует время работы с системным выделением памяти
 */
void testStandardAllocator() {
    auto start_time = std::chrono::high_resolution_clock::now();
    
    std::list<TestStructure> standard_list;
    
    // Добавление 500,000 элементов
    for (int element_index = 0; element_index < 500000; element_index++) {
        standard_list.push_back(TestStructure());
    }
    
    // Удаление всех элементов
    for (int element_index = 0; element_index < 500000; element_index++) {
        standard_list.erase(standard_list.begin());
    }
    
    auto end_time = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);
    std::cout << "   Стандартный аллокатор: " << duration.count() << " микросекунд" << std::endl;
}

/**
 * Тест производительности с кастомным аллокатором
 * Демонстрирует время работы с пулом объектов
 */
void testCustomAllocator() {
    auto start_time = std::chrono::high_resolution_clock::now();
    
    std::list<TestStructure, mai::Allocator<TestStructure>> custom_list;
    
    // Добавление 500,000 элементов
    for (int element_index = 0; element_index < 500000; element_index++) {
        custom_list.push_back(TestStructure());
    }
    
    // Удаление всех элементов
    for (int element_index = 0; element_index < 500000; element_index++) {
        custom_list.erase(custom_list.begin());
    }
    
    auto end_time = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);
    std::cout << "   Кастомный аллокатор: " << duration.count() << " микросекунд" << std::endl;
}

/**
 * Основная функция - демонстрация производительности аллокаторов
 * Сравнивает производительность стандартного и кастомного аллокаторов
 */
int main(int argc, char** argv) {
    std::cout << "=== ДЕМОНСТРАЦИЯ ПРОИЗВОДИТЕЛЬНОСТИ АЛЛОКАТОРОВ ===" << std::endl;

    // ========================================================================
    // ДЕМОНСТРАЦИЯ 1: СТАНДАРТНЫЙ АЛЛОКАТОР
    // ========================================================================
    std::cout << "\n1. Тест со стандартным аллокатором:" << std::endl;
    testStandardAllocator();

    // ========================================================================
    // ДЕМОНСТРАЦИЯ 2: КАСТОМНЫЙ АЛЛОКАТОР
    // ========================================================================
    std::cout << "\n2. Тест с кастомным аллокатором:" << std::endl;
    testCustomAllocator();

    // ========================================================================
    // ДЕМОНСТРАЦИЯ 3: ИСПОЛЬЗОВАНИЕ С MAP (ЗАКОММЕНТИРОВАНО)
    // ========================================================================
    std::cout << "\n3. Использование с std::map (закомментировано):" << std::endl;
    std::cout << "   // std::map<int, int, std::less<int>, mai::Allocator<std::pair<const int, int>>> my_map;" << std::endl;
    std::cout << "   // my_map[1] = 10;" << std::endl;
    std::cout << "   // my_map[2] = 20;" << std::endl;
    std::cout << "   // my_map[3] = 30;" << std::endl;
    std::cout << "   // for (const auto& [key, value] : my_map)" << std::endl;
    std::cout << "   //     std::cout << key << \"->\" << value << std::endl;" << std::endl;

    std::cout << "\n=== ДЕМОНСТРАЦИЯ ЗАВЕРШЕНА ===" << std::endl;
    return 0;
}
