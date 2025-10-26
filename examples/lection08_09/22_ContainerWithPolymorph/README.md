# 22_ContainerWithPolymorph - Демонстрация пользовательского контейнера с полиморфными аллокаторами

## Описание

Этот пример демонстрирует создание пользовательского контейнера `Array` с поддержкой полиморфных аллокаторов (C++17) и кастомного `memory_resource` с буферной памятью. Показывает, как интегрировать полиморфные аллокаторы в собственные контейнеры и управлять памятью через предварительно выделенный буфер.

## Ключевые концепции

### 1. Пользовательские контейнеры
- **Назначение**: Создание собственных контейнеров с поддержкой аллокаторов
- **Совместимость**: Интеграция с полиморфными аллокаторами
- **Управление памятью**: Контроль над выделением и освобождением
- **Итераторы**: Поддержка итераторов для совместимости со STL

### 2. Буферная память
- **Предварительное выделение**: Один большой блок памяти
- **Отслеживание блоков**: Список занятых блоков с метаданными
- **Поиск свободного места**: Алгоритм поиска подходящего блока
- **Фрагментация**: Управление фрагментированной памятью

### 3. Полиморфные аллокаторы
- **Интеграция**: Использование в пользовательских контейнерах
- **Управление жизненным циклом**: Конструирование и разрушение объектов
- **Память**: Выделение и освобождение через memory_resource
- **Совместимость**: Работа с различными типами данных

### 4. C++20 Concepts
- **Ограничения типов**: Проверка требований к типам
- **Валидация**: Компиляторная проверка совместимости
- **Документация**: Явное указание требований
- **Безопасность**: Предотвращение ошибок типизации

## Структура кода

### Кастомный memory_resource с буферной памятью
```cpp
class CustomMemoryResource : public std::pmr::memory_resource {
    struct MemoryBlock {
        size_t offset{0};  // Смещение от начала буфера
        size_t size{0};    // Размер блока
    };

    static constexpr size_t BUFFER_SIZE{600};
    char memory_buffer[BUFFER_SIZE];
    std::vector<MemoryBlock> used_blocks;

public:
    void* do_allocate(size_t bytes, size_t alignment) override {
        // Поиск свободного блока в буфере
        size_t allocation_offset = 0;
        
        for (const MemoryBlock& block : used_blocks) {
            if ((allocation_offset + bytes <= block.offset) || 
                (allocation_offset >= block.offset + block.size)) {
                // Место найдено
            } else {
                allocation_offset = block.offset + block.size + 1;
            }
        }
        
        if (allocation_offset + bytes >= BUFFER_SIZE) {
            throw std::bad_alloc();
        }

        used_blocks.emplace_back(allocation_offset, bytes);
        return memory_buffer + allocation_offset;
    }
};
```

### Пользовательский контейнер Array
```cpp
template <class T, class allocator_type>
    requires std::is_default_constructible_v<T> && 
             std::is_same_v<allocator_type, std::pmr::polymorphic_allocator<T>>
class Array {
private:
    struct PolymorphicDeleter {
        void operator()(T* ptr) const {
            // Память освобождается через аллокатор
        }
    };

    allocator_type polymorphic_allocator;
    std::unique_ptr<T, PolymorphicDeleter> data_pointer;
    std::size_t array_size;

public:
    Array(std::size_t size, allocator_type alloc = {}) 
        : polymorphic_allocator(alloc), array_size(size) {
        
        T* raw_pointer = polymorphic_allocator.allocate(size);
        
        for (size_t i = 0; i < size; ++i) {
            polymorphic_allocator.construct(raw_pointer + i);
        }
        
        data_pointer = std::unique_ptr<T, PolymorphicDeleter>(raw_pointer, PolymorphicDeleter{});
    }
};
```

## Демонстрационные возможности

### 1. Создание буферного memory_resource
```cpp
CustomMemoryResource custom_memory_resource;
// Создается буфер размером 600 байт
```

### 2. Создание полиморфного аллокатора
```cpp
std::pmr::polymorphic_allocator<int> polymorphic_allocator(&custom_memory_resource);
// Аллокатор использует буферную память
```

### 3. Создание пользовательского контейнера
```cpp
Array<int, std::pmr::polymorphic_allocator<int>> array(10, polymorphic_allocator);
// Контейнер использует полиморфный аллокатор
```

### 4. Отслеживание операций с памятью
```cpp
// При создании/уничтожении контейнеров
// Выводятся сообщения о выделении/освобождении памяти
// с указанием смещений и размеров
```

## Образовательные цели

1. **Понимание пользовательских контейнеров**: Создание собственных контейнеров
2. **Интеграция с аллокаторами**: Использование полиморфных аллокаторов
3. **Буферная память**: Управление предварительно выделенной памятью
4. **C++20 Concepts**: Ограничения типов и валидация
5. **Практическое применение**: Реальные сценарии использования

## Ключевые улучшения в коде

### Имена переменных
- `Block` → `MemoryBlock` (более описательное)
- `max_size` → `BUFFER_SIZE` (константа в верхнем регистре)
- `buffer` → `memory_buffer` (более описательное)
- `used_blocks` → `used_blocks` (оставлено без изменений)
- `result` → `allocation_offset` (более описательное)
- `allocator_` → `polymorphic_allocator` (более описательное)
- `data_` → `data_pointer` (более описательное)
- `size_` → `array_size` (более описательное)
- `customResource` → `custom_memory_resource` (более описательное)
- `allocator` → `polymorphic_allocator` (более описательное)
- `array` → `structure_array, temp_array, large_array` (более описательные)
- `AB` → `TestStructure` (более описательное)
- `a, b` → `first_value, second_value` (более описательные)
- `array1, array2, array3, array4` → `array1, array2, array3, array4` (оставлено без изменений)
- `k` → `iteration` (в циклах)
- `i` → `element_index, element_value` (в циклах)

### Комментарии
- Подробные Doxygen-комментарии для всех функций и классов
- Объяснение назначения каждого метода и структуры
- Комментарии к демонстрационным шагам
- Предупреждения об особенностях буферной памяти

### Форматирование
- Единообразные отступы
- Логическая группировка кода
- Четкие разделители между секциями

## Требования

- C++20 или новее (для concepts)
- Компилятор с поддержкой PMR

## Сборка и запуск

```bash
# Компиляция
g++ -std=c++20 -o container_polymorph main.cpp

# Запуск
./container_polymorph
```

## Ожидаемый вывод

```
=== ДЕМОНСТРАЦИЯ КОНТЕЙНЕРА С ПОЛИМОРФНЫМИ АЛЛОКАТОРАМИ ===

1. Создание пользовательского memory_resource:
   Полиморфный аллокатор создан

2. Создание массива с пользовательской структурой:
   Выделение: смещение 0, размер 80 байт
   Массив структур создан

3. Создание множественных массивов:
   Выделение: смещение 80, размер 40 байт
   Выделение: смещение 120, размер 40 байт
   Выделение: смещение 160, размер 40 байт
   Выделение: смещение 200, размер 40 байт
   Четыре массива созданы

4. Освобождение части массивов:
   Освобождение: адрес 0x..., размер 40 байт
   Освобождение: адрес 0x..., размер 40 байт
   Два массива освобождены

5. Циклическое создание и использование массивов:
   Итерация 0:
   Выделение: смещение 240, размер 40 байт
   Выделение: смещение 280, размер 160 байт
   Содержимое: 0 1 2 3 4 5 6 7 8 9
   ...
   Итерация 9:
   Выделение: смещение 440, размер 40 байт
   Выделение: смещение 480, размер 160 байт
   Содержимое: 0 1 2 3 4 5 6 7 8 9

6. Освобождение оставшихся массивов:
   Освобождение: адрес 0x..., размер 40 байт
   Освобождение: адрес 0x..., размер 40 байт
   Все массивы освобождены

=== ДЕМОНСТРАЦИЯ ЗАВЕРШЕНА ===
```

## Сравнение с другими подходами

### Пользовательские контейнеры vs STL контейнеры
| Характеристика | Пользовательские контейнеры | STL контейнеры |
|----------------|---------------------------|---------------|
| **Гибкость** | Полная | Ограниченная |
| **Производительность** | Оптимизированная | Стандартная |
| **Сложность** | Высокая | Низкая |
| **Совместимость** | Требует тестирования | Гарантированная |
| **Отладка** | Сложная | Простая |

### Буферная память vs системная память
| Характеристика | Буферная память | Системная память |
|----------------|----------------|-----------------|
| **Производительность** | Быстрая | Медленная |
| **Ограничения** | Фиксированный размер | Неограниченная |
| **Управление** | Сложное | Простое |
| **Фрагментация** | Возможна | Минимальная |
| **Отладка** | Сложная | Простая |

## Ключевые особенности пользовательских контейнеров

### 1. Интеграция с аллокаторами
```cpp
template <class T, class allocator_type>
class Array {
    allocator_type polymorphic_allocator;
    
    Array(std::size_t size, allocator_type alloc = {}) 
        : polymorphic_allocator(alloc), array_size(size) {
        
        T* raw_pointer = polymorphic_allocator.allocate(size);
        // Конструирование объектов
        for (size_t i = 0; i < size; ++i) {
            polymorphic_allocator.construct(raw_pointer + i);
        }
    }
};
```

### 2. Управление жизненным циклом
```cpp
~Array() {
    if constexpr (std::is_destructible_v<T>) {
        for (size_t i = 0; i < array_size; ++i) {
            std::allocator_traits<allocator_type>::destroy(polymorphic_allocator, 
                                                          data_pointer.get() + i);
        }
    }
    polymorphic_allocator.deallocate(data_pointer.get(), array_size);
}
```

### 3. Поддержка итераторов
```cpp
T* begin() {
    return data_pointer.get();
}

T* end() {
    return data_pointer.get() + array_size;
}
```

### 4. C++20 Concepts
```cpp
template <class T, class allocator_type>
    requires std::is_default_constructible_v<T> && 
             std::is_same_v<allocator_type, std::pmr::polymorphic_allocator<T>>
class Array {
    // Реализация контейнера
};
```

## Практические применения

### 1. Специализированные контейнеры
```cpp
template <class T>
class PooledArray {
private:
    std::pmr::polymorphic_allocator<T> allocator;
    T* data;
    size_t size;
    
public:
    PooledArray(size_t size, std::pmr::memory_resource* resource) 
        : allocator(resource), size(size) {
        data = allocator.allocate(size);
        for (size_t i = 0; i < size; ++i) {
            allocator.construct(data + i);
        }
    }
    
    ~PooledArray() {
        for (size_t i = 0; i < size; ++i) {
            allocator.destroy(data + i);
        }
        allocator.deallocate(data, size);
    }
};
```

### 2. Отладочные контейнеры
```cpp
template <class T>
class DebugArray {
private:
    std::pmr::polymorphic_allocator<T> allocator;
    T* data;
    size_t size;
    
public:
    DebugArray(size_t size, std::pmr::memory_resource* resource) 
        : allocator(resource), size(size) {
        std::cout << "Создание массива размером " << size << std::endl;
        data = allocator.allocate(size);
        for (size_t i = 0; i < size; ++i) {
            allocator.construct(data + i);
        }
    }
    
    ~DebugArray() {
        std::cout << "Уничтожение массива размером " << size << std::endl;
        for (size_t i = 0; i < size; ++i) {
            allocator.destroy(data + i);
        }
        allocator.deallocate(data, size);
    }
};
```

### 3. Статистические контейнеры
```cpp
template <class T>
class StatsArray {
private:
    std::pmr::polymorphic_allocator<T> allocator;
    T* data;
    size_t size;
    static size_t total_allocations;
    static size_t total_deallocations;
    
public:
    StatsArray(size_t size, std::pmr::memory_resource* resource) 
        : allocator(resource), size(size) {
        total_allocations++;
        data = allocator.allocate(size);
        for (size_t i = 0; i < size; ++i) {
            allocator.construct(data + i);
        }
    }
    
    ~StatsArray() {
        total_deallocations++;
        for (size_t i = 0; i < size; ++i) {
            allocator.destroy(data + i);
        }
        allocator.deallocate(data, size);
    }
    
    static void print_stats() {
        std::cout << "Выделений: " << total_allocations 
                  << ", Освобождений: " << total_deallocations << std::endl;
    }
};
```

### 4. Алигнированные контейнеры
```cpp
template <class T>
class AlignedArray {
private:
    std::pmr::polymorphic_allocator<T> allocator;
    T* data;
    size_t size;
    
public:
    AlignedArray(size_t size, std::pmr::memory_resource* resource) 
        : allocator(resource), size(size) {
        data = allocator.allocate(size);
        for (size_t i = 0; i < size; ++i) {
            allocator.construct(data + i);
        }
    }
    
    ~AlignedArray() {
        for (size_t i = 0; i < size; ++i) {
            allocator.destroy(data + i);
        }
        allocator.deallocate(data, size);
    }
};
```

## Дополнительные возможности для изучения

1. **Многопоточность**: Потокобезопасные контейнеры
2. **Производительность**: Профилирование и оптимизация
3. **Отладка**: Инструментированные контейнеры
4. **Специализация**: Адаптация под конкретные задачи
5. **Интеграция**: Использование с существующими системами

## Ключевые преимущества и недостатки

### Преимущества
- **Гибкость**: Полный контроль над поведением
- **Производительность**: Оптимизация для конкретных случаев
- **Специализация**: Адаптация под конкретные задачи
- **Отладка**: Возможность отслеживания операций

### Недостатки
- **Сложность**: Высокая сложность реализации
- **Тестирование**: Требует тщательного тестирования
- **Совместимость**: Проблемы совместимости с библиотеками
- **Обучение**: Требует глубокого понимания C++

## Практические советы

### 1. Когда создавать пользовательские контейнеры
- **Специализированные задачи**: Когда STL контейнеры не подходят
- **Производительность**: Когда нужна оптимизация
- **Контроль**: Когда нужен полный контроль над поведением
- **Интеграция**: Когда нужна интеграция с существующими системами

### 2. Когда НЕ создавать пользовательские контейнеры
- **Стандартные задачи**: Когда STL контейнеры достаточны
- **Совместимость**: Когда нужна совместимость с библиотеками
- **Сложность**: Когда сложность не оправдана
- **Команда**: Когда команда не готова к сложности

### 3. Лучшие практики
- **Тестирование**: Тщательное тестирование всех сценариев
- **Документация**: Подробная документация поведения
- **Профилирование**: Измерение производительности
- **Отладка**: Инструментирование для отладки

## Буферная память

### Алгоритм поиска свободного блока
```cpp
void* do_allocate(size_t bytes, size_t alignment) override {
    size_t allocation_offset = 0;
    
    for (const MemoryBlock& block : used_blocks) {
        if ((allocation_offset + bytes <= block.offset) || 
            (allocation_offset >= block.offset + block.size)) {
            // Место найдено
        } else {
            allocation_offset = block.offset + block.size + 1;
        }
    }
    
    if (allocation_offset + bytes >= BUFFER_SIZE) {
        throw std::bad_alloc();
    }
    
    used_blocks.emplace_back(allocation_offset, bytes);
    return memory_buffer + allocation_offset;
}
```

### Управление фрагментацией
```cpp
// Сортировка блоков по смещению для оптимизации поиска
std::sort(used_blocks.begin(), used_blocks.end(),
          [](const MemoryBlock& left, const MemoryBlock& right) { 
              return left.offset <= right.offset; 
          });
```

### Освобождение блоков
```cpp
void do_deallocate(void* ptr, size_t bytes, size_t alignment) override {
    for (size_t i = 0; i < used_blocks.size(); ++i) {
        if (ptr == memory_buffer + used_blocks[i].offset) {
            used_blocks.erase(used_blocks.begin() + i);
            return;
        }
    }
    throw std::logic_error("Попытка освобождения не выделенного блока");
}
```

Этот пример отлично демонстрирует создание пользовательских контейнеров с полиморфными аллокаторами и помогает понять, когда и как использовать современные возможности C++20 для создания специализированных контейнеров.
