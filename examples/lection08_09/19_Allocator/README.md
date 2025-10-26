# 19_Allocator - Демонстрация кастомного аллокатора

## Описание

Этот пример демонстрирует создание кастомного аллокатора для STL контейнеров. Показывает, как реализовать аллокатор с фиксированным размером блока, совместимый со стандартными контейнерами C++, и как использовать его с различными STL контейнерами.

## Ключевые концепции

### 1. Кастомные аллокаторы
- **Назначение**: Управление выделением памяти для STL контейнеров
- **Совместимость**: Должны соответствовать интерфейсу std::allocator
- **Производительность**: Могут оптимизировать выделение памяти
- **Специализация**: Адаптация под конкретные задачи

### 2. Интерфейс аллокатора
- **allocate()**: Выделение памяти для n элементов
- **deallocate()**: Освобождение выделенной памяти
- **construct()**: Конструирование объекта в выделенной памяти
- **destroy()**: Разрушение объекта
- **rebind**: Структура для совместимости с STL

### 3. Буферная память
- **Фиксированный размер**: Предварительно выделенный блок памяти
- **Управление**: Отслеживание свободного места
- **Производительность**: Избежание системных вызовов
- **Ограничения**: Ограниченный размер буфера

### 4. Совместимость со STL
- **Типы**: value_type, pointer, const_pointer, size_type
- **rebind**: Позволяет STL создавать аллокаторы для других типов
- **Контейнеры**: Работа с vector, map, list и другими
- **Итераторы**: Поддержка итераторов контейнеров

## Структура кода

### Кастомный аллокатор
```cpp
template <class T, size_t BLOCK_SIZE>
class allocator {
private:
    std::shared_ptr<T[]> memory_buffer;      // Буфер для хранения элементов
    std::shared_ptr<size_t> free_index;       // Индекс следующего свободного элемента

public:
    using value_type = T;
    using pointer = T*;
    using const_pointer = const T*;
    using size_type = std::size_t;

    // Конструктор
    allocator() : memory_buffer{} {
        static_assert(BLOCK_SIZE > 0);
        free_index = std::make_shared<size_t>(0);
    }

    // Выделение памяти
    T* allocate(size_t n) {
        if (!memory_buffer) {
            memory_buffer = std::shared_ptr<T[]>(new T[BLOCK_SIZE]);
        }
        
        if ((BLOCK_SIZE - *free_index) < n) {
            throw std::bad_alloc();
        }
        
        T* allocated_pointer = &(memory_buffer[*free_index]);
        *free_index += n;
        return allocated_pointer;
    }

    // Освобождение памяти
    void deallocate(T* pointer, size_t n) {
        // В данной реализации память не освобождается
    }

    // Конструирование объекта
    template <typename U, typename... Args>
    void construct(U* p, Args&&... args) {
        new (p) U(std::forward<Args>(args)...);
    }

    // Разрушение объекта
    void destroy(pointer p) {
        p->~T();
    }
};
```

### Использование с контейнерами
```cpp
// С vector
std::vector<int, mai::allocator<int, 100>> integer_vector;

// С map
using map_type_with_allocator = 
    std::map<int, int, std::less<int>, mai::allocator<std::pair<const int, int>, 10>>;
```

## Демонстрационные возможности

### 1. Создание аллокатора
```cpp
mai::allocator<int, 10> first_allocator;
mai::allocator<int, 10> second_allocator = first_allocator;
```

### 2. Использование с vector
```cpp
std::vector<int, mai::allocator<int, 100>> integer_vector;

for (size_t i = 0; i < 10; ++i) {
    integer_vector.push_back(i);
}
```

### 3. Использование с map
```cpp
map_type_with_allocator my_map_with_allocator;
my_map_with_allocator[1] = 2;
my_map_with_allocator[2] = 4;
my_map_with_allocator[3] = 6;
my_map_with_allocator[4] = 7;
```

### 4. Отслеживание операций
```cpp
// Аллокатор выводит информацию о каждой операции
// - Конструктор/деструктор
// - Выделение/освобождение памяти
// - Конструирование/разрушение объектов
```

## Образовательные цели

1. **Понимание аллокаторов**: Как работают аллокаторы в STL
2. **Интерфейс аллокатора**: Обязательные методы и типы
3. **Совместимость**: Как обеспечить совместимость со STL
4. **Управление памятью**: Контроль над выделением и освобождением
5. **Практическое применение**: Когда использовать кастомные аллокаторы

## Ключевые улучшения в коде

### Имена переменных
- `_buffer` → `memory_buffer` (более описательное)
- `_free_index` → `free_index` (более описательное)
- `a` → `first_allocator` (более описательное)
- `b` → `second_allocator` (более описательное)
- `my_vector` → `integer_vector` (более описательное)
- `i` → `element_index` (в циклах)
- `p` → `pair` (в циклах)

### Комментарии
- Подробные Doxygen-комментарии для всех функций и классов
- Объяснение назначения каждого метода аллокатора
- Комментарии к демонстрационным шагам
- Предупреждения об особенностях реализации

### Форматирование
- Единообразные отступы
- Логическая группировка кода
- Четкие разделители между секциями

## Требования

- C++11 или новее
- Компилятор с поддержкой STL

## Сборка и запуск

```bash
# Компиляция
g++ -std=c++11 -o allocator main.cpp

# Запуск
./allocator
```

## Ожидаемый вывод

```
=== ДЕМОНСТРАЦИЯ КАСТОМНОГО АЛЛОКАТОРА ===

1. Создание и копирование аллокаторов:
   Конструктор аллокатора вызван
   Оператор присваивания аллокатора

2. Использование с std::vector:
   Конструктор аллокатора вызван
   Заполнение вектора значениями:
   Выделение памяти для 1 элементов
   Конструирование объекта
   Выделение памяти для 2 элементов
   Конструирование объекта
   ...
   Содержимое вектора:
   0
   1
   2
   3
   4
   5
   6
   7
   8
   9

3. Использование с std::map (закомментировано для простоты):
   // map_type_with_allocator my_map_with_allocator;
   // my_map_with_allocator[1] = 2;
   // my_map_with_allocator[2] = 4;
   // my_map_with_allocator[3] = 6;
   // my_map_with_allocator[4] = 7;
   // for (auto pair : my_map_with_allocator)
   //     std::cout << pair.first << " " << pair.second << std::endl;

=== ДЕМОНСТРАЦИЯ ЗАВЕРШЕНА ===
```

## Сравнение с другими подходами

### Кастомный аллокатор vs стандартный аллокатор
| Характеристика | Кастомный аллокатор | Стандартный аллокатор |
|----------------|-------------------|---------------------|
| **Контроль** | Полный контроль | Ограниченный |
| **Производительность** | Может быть быстрее | Стандартная |
| **Сложность** | Высокая | Низкая |
| **Отладка** | Сложная | Простая |
| **Память** | Кастомная стратегия | Системная |

### Буферный аллокатор vs системный аллокатор
| Характеристика | Буферный аллокатор | Системный аллокатор |
|----------------|-------------------|-------------------|
| **Память** | Предварительно выделена | Выделяется по требованию |
| **Производительность** | Быстрая | Медленная |
| **Ограничения** | Ограниченный размер | Неограниченный |
| **Управление** | Простое | Сложное |

## Ключевые особенности кастомных аллокаторов

### 1. Обязательные типы
```cpp
using value_type = T;
using pointer = T*;
using const_pointer = const T*;
using size_type = std::size_t;
```

### 2. Обязательные методы
```cpp
// Выделение памяти
T* allocate(size_t n);

// Освобождение памяти
void deallocate(T* pointer, size_t n);

// Конструирование объекта
template <typename U, typename... Args>
void construct(U* p, Args&&... args);

// Разрушение объекта
void destroy(pointer p);
```

### 3. Структура rebind
```cpp
template <typename U>
struct rebind {
    using other = allocator<U, BLOCK_SIZE>;
};
```

### 4. Совместимость со STL
```cpp
// Работа с vector
std::vector<int, mai::allocator<int, 100>> vector_with_allocator;

// Работа с map
std::map<int, int, std::less<int>, mai::allocator<std::pair<const int, int>, 10>> map_with_allocator;
```

## Практические применения

### 1. Пул объектов
```cpp
class ObjectPool {
private:
    std::vector<char> pool_memory;
    size_t current_offset;
    
public:
    ObjectPool(size_t pool_size) : pool_memory(pool_size), current_offset(0) {}
    
    void* allocate(size_t size) {
        if (current_offset + size > pool_memory.size()) {
            throw std::bad_alloc();
        }
        void* ptr = pool_memory.data() + current_offset;
        current_offset += size;
        return ptr;
    }
};
```

### 2. Отладочные аллокаторы
```cpp
class DebugAllocator {
public:
    static void* allocate(size_t size) {
        std::cout << "Выделение " << size << " байт" << std::endl;
        return std::malloc(size);
    }
    
    static void deallocate(void* ptr, size_t size) {
        std::cout << "Освобождение " << size << " байт" << std::endl;
        std::free(ptr);
    }
};
```

### 3. Алигнированные аллокаторы
```cpp
class AlignedAllocator {
public:
    static void* allocate(size_t size) {
        return std::aligned_alloc(64, size);  // 64-байтное выравнивание
    }
    
    static void deallocate(void* ptr, size_t size) {
        std::free(ptr);
    }
};
```

### 4. Статистические аллокаторы
```cpp
class StatsAllocator {
private:
    static size_t total_allocated;
    static size_t allocation_count;
    
public:
    static void* allocate(size_t size) {
        total_allocated += size;
        allocation_count++;
        std::cout << "Всего выделено: " << total_allocated 
                  << " байт в " << allocation_count << " операциях" << std::endl;
        return std::malloc(size);
    }
    
    static void deallocate(void* ptr, size_t size) {
        std::free(ptr);
    }
};
```

## Дополнительные возможности для изучения

1. **Массивы**: Поддержка operator new[] и operator delete[]
2. **Исключения**: Обработка ошибок в аллокаторах
3. **Выравнивание**: Алигнированные аллокаторы
4. **Отладка**: Инструментированные аллокаторы
5. **Производительность**: Профилирование аллокаторов

## Ключевые преимущества и недостатки

### Преимущества
- **Контроль**: Полный контроль над выделением памяти
- **Производительность**: Оптимизация для конкретных случаев
- **Отладка**: Возможность отслеживания выделения памяти
- **Специализация**: Адаптация под конкретные задачи

### Недостатки
- **Сложность**: Высокая сложность реализации
- **Отладка**: Сложность отладки кастомных аллокаторов
- **Совместимость**: Проблемы совместимости с библиотеками
- **Ошибки**: Высокий риск ошибок в управлении памятью

## Практические советы

### 1. Когда использовать кастомные аллокаторы
- **Специализированные задачи**: Когда нужен особый контроль
- **Отладка**: Для отслеживания выделения памяти
- **Производительность**: Когда стандартные аллокаторы неэффективны
- **Ограниченная память**: В embedded системах

### 2. Когда НЕ использовать кастомные аллокаторы
- **Стандартные задачи**: Когда стандартные аллокаторы достаточны
- **Библиотечный код**: Когда нужна совместимость
- **Сложность**: Когда сложность не оправдана
- **Команда**: Когда команда не готова к сложности

### 3. Лучшие практики
- **Тестирование**: Тщательное тестирование аллокаторов
- **Документация**: Подробная документация поведения
- **Отладка**: Инструментирование для отладки
- **Производительность**: Профилирование производительности

## Буферная память

### Принцип работы
```cpp
class BufferAllocator {
private:
    char* buffer;
    size_t size;
    size_t offset;
    
public:
    BufferAllocator(size_t buffer_size) : size(buffer_size), offset(0) {
        buffer = new char[size];
    }
    
    ~BufferAllocator() {
        delete[] buffer;
    }
    
    void* allocate(size_t bytes) {
        if (offset + bytes > size) {
            throw std::bad_alloc();
        }
        void* ptr = buffer + offset;
        offset += bytes;
        return ptr;
    }
};
```

### Преимущества
- **Производительность**: Быстрое выделение памяти
- **Предсказуемость**: Известное время выделения
- **Контроль**: Полный контроль над памятью
- **Отладка**: Легко отслеживать использование

### Недостатки
- **Ограничения**: Ограниченный размер буфера
- **Память**: Дополнительное потребление памяти
- **Сложность**: Сложность управления буфером
- **Гибкость**: Менее гибкий чем системные аллокаторы

## Совместимость со STL

### Обязательные типы
```cpp
using value_type = T;
using pointer = T*;
using const_pointer = const T*;
using size_type = std::size_t;
using difference_type = std::ptrdiff_t;
```

### Обязательные методы
```cpp
// Выделение памяти
pointer allocate(size_type n);

// Освобождение памяти
void deallocate(pointer p, size_type n);

// Конструирование объекта
template <typename U, typename... Args>
void construct(U* p, Args&&... args);

// Разрушение объекта
void destroy(pointer p);
```

### Структура rebind
```cpp
template <typename U>
struct rebind {
    using other = allocator<U, BLOCK_SIZE>;
};
```

Этот пример отлично демонстрирует создание кастомных аллокаторов и помогает понять, когда и как использовать их в C++ для оптимизации производительности и управления памятью.
