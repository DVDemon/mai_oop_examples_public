# 21_Polymorph - Демонстрация полиморфных аллокаторов

## Описание

Этот пример демонстрирует работу с полиморфными аллокаторами (C++17) и пользовательскими memory_resource. Показывает, как создать собственный memory_resource и использовать его с полиморфными аллокаторами для управления памятью в STL контейнерах.

## Ключевые концепции

### 1. Полиморфные аллокаторы (C++17)
- **Назначение**: Универсальные аллокаторы с полиморфным поведением
- **Основа**: Используют memory_resource для выделения памяти
- **Гибкость**: Можно менять стратегию выделения во время выполнения
- **Совместимость**: Работают со всеми PMR контейнерами

### 2. Memory Resource
- **Интерфейс**: Абстрактный базовый класс для управления памятью
- **Методы**: do_allocate(), do_deallocate(), do_is_equal()
- **Полиморфизм**: Различные реализации для разных стратегий
- **Выравнивание**: Поддержка выравнивания памяти

### 3. PMR контейнеры
- **std::pmr::vector**: Вектор с полиморфным аллокатором
- **std::pmr::string**: Строка с полиморфным аллокатором
- **std::pmr::map**: Ассоциативный контейнер с полиморфным аллокатором
- **Совместимость**: Полная совместимость со стандартными контейнерами

### 4. Пользовательские memory_resource
- **Наследование**: От std::pmr::memory_resource
- **Реализация**: Переопределение виртуальных методов
- **Стратегии**: Различные подходы к управлению памятью
- **Отладка**: Возможность отслеживания выделения памяти

## Структура кода

### Пользовательский memory_resource
```cpp
class CustomMemoryResource : public std::pmr::memory_resource {
public:
    // Выделение памяти с заданным выравниванием
    void* do_allocate(size_t bytes, size_t alignment) override {
        std::cout << "Выделение " << bytes << " байт с выравниванием " << alignment << std::endl;
        return ::operator new(bytes);
    }

    // Освобождение памяти
    void do_deallocate(void* ptr, size_t bytes, size_t alignment) override {
        std::cout << "Освобождение " << bytes << " байт по адресу " << ptr << std::endl;
        ::operator delete(ptr);
    }

    // Сравнение с другим memory_resource
    bool do_is_equal(const std::pmr::memory_resource& other) const noexcept override {
        return this == &other;
    }
};
```

### Использование с полиморфными аллокаторами
```cpp
// Создание пользовательского memory_resource
CustomMemoryResource custom_memory_resource;

// Создание полиморфного аллокатора
std::pmr::polymorphic_allocator<int> polymorphic_allocator(&custom_memory_resource);

// Использование с PMR контейнерами
std::pmr::vector<int> integer_vector(polymorphic_allocator);
```

## Демонстрационные возможности

### 1. Создание пользовательского memory_resource
```cpp
CustomMemoryResource custom_memory_resource;
// Создается экземпляр пользовательского memory_resource
```

### 2. Создание полиморфного аллокатора
```cpp
std::pmr::polymorphic_allocator<int> polymorphic_allocator(&custom_memory_resource);
// Создается полиморфный аллокатор, использующий пользовательский memory_resource
```

### 3. Использование с PMR контейнерами
```cpp
std::pmr::vector<int> integer_vector(polymorphic_allocator);
// Создается вектор с полиморфным аллокатором
```

### 4. Отслеживание операций с памятью
```cpp
// При добавлении элементов в вектор
// Вызываются методы do_allocate() и do_deallocate()
// с выводом информации о выделении/освобождении памяти
```

## Образовательные цели

1. **Понимание полиморфных аллокаторов**: Современный подход к управлению памятью
2. **Memory Resource**: Абстракция для управления памятью
3. **PMR контейнеры**: Контейнеры с полиморфными аллокаторами
4. **Пользовательские реализации**: Создание собственных memory_resource
5. **Практическое применение**: Когда использовать полиморфные аллокаторы

## Ключевые улучшения в коде

### Имена переменных
- `customResource` → `custom_memory_resource` (более описательное)
- `allocator` → `polymorphic_allocator` (более описательное)
- `vec` → `integer_vector` (более описательное)
- `i` → `element_value` (в циклах)

### Комментарии
- Подробные Doxygen-комментарии для всех функций и классов
- Объяснение назначения каждого метода memory_resource
- Комментарии к демонстрационным шагам
- Предупреждения об особенностях полиморфных аллокаторов

### Форматирование
- Единообразные отступы
- Логическая группировка кода
- Четкие разделители между секциями

## Требования

- C++17 или новее
- Компилятор с поддержкой PMR

## Сборка и запуск

```bash
# Компиляция
g++ -std=c++17 -o polymorph main.cpp

# Запуск
./polymorph
```

## Ожидаемый вывод

```
=== ДЕМОНСТРАЦИЯ ПОЛИМОРФНЫХ АЛЛОКАТОРОВ ===

1. Создание пользовательского memory_resource:
   Пользовательский memory_resource создан

2. Создание полиморфного аллокатора:
   Полиморфный аллокатор создан

3. Использование с std::pmr::vector:
   Вектор с полиморфным аллокатором создан

4. Добавление элементов в вектор:
   Добавлен элемент: 0
   Выделение 4 байт с выравниванием 4
   Добавлен элемент: 1
   Выделение 8 байт с выравниванием 8
   ...
   Добавлен элемент: 9
   Выделение 40 байт с выравниванием 8

5. Содержимое вектора:
   0 1 2 3 4 5 6 7 8 9

=== ДЕМОНСТРАЦИЯ ЗАВЕРШЕНА ===
```

## Сравнение с другими подходами

### Полиморфные аллокаторы vs обычные аллокаторы
| Характеристика | Полиморфные аллокаторы | Обычные аллокаторы |
|----------------|----------------------|------------------|
| **Гибкость** | Высокая (смена стратегии) | Низкая (фиксированная) |
| **Производительность** | Хорошая | Хорошая |
| **Сложность** | Средняя | Низкая |
| **Совместимость** | PMR контейнеры | Все контейнеры |
| **Отладка** | Удобная | Сложная |

### PMR контейнеры vs обычные контейнеры
| Характеристика | PMR контейнеры | Обычные контейнеры |
|----------------|---------------|------------------|
| **Аллокаторы** | Полиморфные | Обычные |
| **Гибкость** | Высокая | Низкая |
| **Производительность** | Хорошая | Хорошая |
| **Совместимость** | C++17+ | Все версии |
| **Отладка** | Удобная | Сложная |

## Ключевые особенности полиморфных аллокаторов

### 1. Полиморфное поведение
```cpp
std::pmr::polymorphic_allocator<int> allocator1(&memory_resource1);
std::pmr::polymorphic_allocator<int> allocator2(&memory_resource2);

// Разные стратегии выделения памяти
// в зависимости от переданного memory_resource
```

### 2. Гибкость во время выполнения
```cpp
std::pmr::vector<int> vec;

// Можно изменить стратегию выделения памяти
vec.get_allocator().resource() = &new_memory_resource;
```

### 3. Отслеживание операций
```cpp
class DebugMemoryResource : public std::pmr::memory_resource {
    void* do_allocate(size_t bytes, size_t alignment) override {
        std::cout << "Выделение " << bytes << " байт" << std::endl;
        return std::malloc(bytes);
    }
    
    void do_deallocate(void* ptr, size_t bytes, size_t alignment) override {
        std::cout << "Освобождение " << bytes << " байт" << std::endl;
        std::free(ptr);
    }
    
    bool do_is_equal(const std::pmr::memory_resource& other) const noexcept override {
        return this == &other;
    }
};
```

### 4. Совместимость с PMR контейнерами
```cpp
// Все PMR контейнеры поддерживают полиморфные аллокаторы
std::pmr::vector<int> vec(allocator);
std::pmr::string str(allocator);
std::pmr::map<int, int> map(allocator);
```

## Практические применения

### 1. Отладочные аллокаторы
```cpp
class DebugMemoryResource : public std::pmr::memory_resource {
private:
    size_t total_allocated = 0;
    size_t allocation_count = 0;
    
public:
    void* do_allocate(size_t bytes, size_t alignment) override {
        total_allocated += bytes;
        allocation_count++;
        std::cout << "Выделено " << bytes << " байт (всего: " << total_allocated << ")" << std::endl;
        return std::malloc(bytes);
    }
    
    void do_deallocate(void* ptr, size_t bytes, size_t alignment) override {
        std::cout << "Освобождено " << bytes << " байт" << std::endl;
        std::free(ptr);
    }
    
    bool do_is_equal(const std::pmr::memory_resource& other) const noexcept override {
        return this == &other;
    }
};
```

### 2. Пул объектов
```cpp
class PoolMemoryResource : public std::pmr::memory_resource {
private:
    std::vector<char> pool;
    size_t current_offset;
    
public:
    PoolMemoryResource(size_t pool_size) : pool(pool_size), current_offset(0) {}
    
    void* do_allocate(size_t bytes, size_t alignment) override {
        if (current_offset + bytes > pool.size()) {
            throw std::bad_alloc();
        }
        void* ptr = pool.data() + current_offset;
        current_offset += bytes;
        return ptr;
    }
    
    void do_deallocate(void* ptr, size_t bytes, size_t alignment) override {
        // В пуле объекты не освобождаются индивидуально
    }
    
    bool do_is_equal(const std::pmr::memory_resource& other) const noexcept override {
        return this == &other;
    }
};
```

### 3. Статистические аллокаторы
```cpp
class StatsMemoryResource : public std::pmr::memory_resource {
private:
    size_t peak_usage = 0;
    size_t current_usage = 0;
    
public:
    void* do_allocate(size_t bytes, size_t alignment) override {
        current_usage += bytes;
        peak_usage = std::max(peak_usage, current_usage);
        return std::malloc(bytes);
    }
    
    void do_deallocate(void* ptr, size_t bytes, size_t alignment) override {
        current_usage -= bytes;
        std::free(ptr);
    }
    
    bool do_is_equal(const std::pmr::memory_resource& other) const noexcept override {
        return this == &other;
    }
    
    size_t get_peak_usage() const { return peak_usage; }
    size_t get_current_usage() const { return current_usage; }
};
```

### 4. Алигнированные аллокаторы
```cpp
class AlignedMemoryResource : public std::pmr::memory_resource {
public:
    void* do_allocate(size_t bytes, size_t alignment) override {
        return std::aligned_alloc(alignment, bytes);
    }
    
    void do_deallocate(void* ptr, size_t bytes, size_t alignment) override {
        std::free(ptr);
    }
    
    bool do_is_equal(const std::pmr::memory_resource& other) const noexcept override {
        return this == &other;
    }
};
```

## Дополнительные возможности для изучения

1. **Многопоточность**: Потокобезопасные memory_resource
2. **Производительность**: Профилирование различных стратегий
3. **Отладка**: Инструментированные memory_resource
4. **Специализация**: Адаптация под конкретные задачи
5. **Интеграция**: Использование с существующими системами

## Ключевые преимущества и недостатки

### Преимущества
- **Гибкость**: Возможность смены стратегии во время выполнения
- **Отладка**: Удобное отслеживание операций с памятью
- **Производительность**: Оптимизация для конкретных случаев
- **Совместимость**: Работа со всеми PMR контейнерами

### Недостатки
- **Сложность**: Более сложная реализация
- **Совместимость**: Требует C++17 и PMR контейнеры
- **Производительность**: Небольшие накладные расходы
- **Обучение**: Требует понимания современных концепций

## Практические советы

### 1. Когда использовать полиморфные аллокаторы
- **Отладка**: Когда нужно отслеживать операции с памятью
- **Производительность**: Когда нужна оптимизация выделения памяти
- **Гибкость**: Когда нужна смена стратегии во время выполнения
- **Современность**: Когда используется C++17+

### 2. Когда НЕ использовать полиморфные аллокаторы
- **Совместимость**: Когда нужна совместимость со старыми версиями C++
- **Простота**: Когда сложность не оправдана
- **Производительность**: Когда накладные расходы критичны
- **Обучение**: Когда команда не готова к сложности

### 3. Лучшие практики
- **Тестирование**: Тщательное тестирование производительности
- **Профилирование**: Измерение реальной производительности
- **Документация**: Подробная документация поведения
- **Отладка**: Инструментирование для отладки

## Memory Resource

### Обязательные методы
```cpp
class CustomMemoryResource : public std::pmr::memory_resource {
public:
    // Выделение памяти
    void* do_allocate(size_t bytes, size_t alignment) override;
    
    // Освобождение памяти
    void do_deallocate(void* ptr, size_t bytes, size_t alignment) override;
    
    // Сравнение с другим memory_resource
    bool do_is_equal(const std::pmr::memory_resource& other) const noexcept override;
};
```

### Выравнивание памяти
```cpp
void* do_allocate(size_t bytes, size_t alignment) override {
    // alignment - требуемое выравнивание (обычно степень двойки)
    // bytes - размер выделяемой памяти
    return std::aligned_alloc(alignment, bytes);
}
```

### Сравнение memory_resource
```cpp
bool do_is_equal(const std::pmr::memory_resource& other) const noexcept override {
    // Возвращает true, если это тот же объект
    // или если аллокаторы эквивалентны
    return this == &other;
}
```

## PMR контейнеры

### Доступные контейнеры
```cpp
std::pmr::vector<T>           // Вектор с полиморфным аллокатором
std::pmr::string              // Строка с полиморфным аллокатором
std::pmr::map<K, V>           // Ассоциативный контейнер
std::pmr::set<T>              // Множество
std::pmr::list<T>             // Список
std::pmr::deque<T>            // Двусторонняя очередь
```

### Использование
```cpp
// Создание с полиморфным аллокатором
std::pmr::vector<int> vec(allocator);

// Создание с пользовательским memory_resource
CustomMemoryResource resource;
std::pmr::vector<int> vec(&resource);
```

Этот пример отлично демонстрирует современные возможности C++17 для управления памятью и помогает понять, когда и как использовать полиморфные аллокаторы для оптимизации производительности и отладки.
