# 18_OperatorNew - Демонстрация перегрузки операторов new/delete

## Описание

Этот пример демонстрирует перегрузку операторов `new` и `delete` в C++, показывая различные способы выделения памяти, включая кастомные аллокаторы, placement new и управление памятью через буферы.

## Ключевые концепции

### 1. Перегрузка операторов new/delete
- **Назначение**: Кастомизация выделения и освобождения памяти
- **Синтаксис**: `void* operator new(size_t size)`
- **Параметры**: Размер выделяемой памяти
- **Возврат**: Указатель на выделенную память

### 2. Кастомные аллокаторы
- **Буферная память**: Использование предварительно выделенного буфера
- **Управление**: Контроль над выделением и освобождением
- **Производительность**: Избежание системных вызовов
- **Ограничения**: Ограниченный размер буфера

### 3. Placement new
- **Назначение**: Размещение объекта в предварительно выделенной памяти
- **Синтаксис**: `::new (pointer) Type(constructor_args)`
- **Управление**: Требует явного вызова деструктора
- **Применение**: Пул объектов, оптимизация производительности

### 4. Перегрузка с параметрами
- **Синтаксис**: `void* operator new(size_t size, param_type param)`
- **Вызов**: `new (param) Type(constructor_args)`
- **Применение**: Передача дополнительной информации в аллокатор
- **Гибкость**: Различные стратегии выделения памяти

## Структура кода

### Демонстрационный класс
```cpp
class CustomAllocatorDemo {
private:
    int stored_value;

public:
    CustomAllocatorDemo(int value) : stored_value(value) {
        std::cout << "Конструктор вызван для значения: " << stored_value << std::endl;
    }

    // Перегрузка оператора new
    void* operator new(size_t size);
    
    // Перегрузка оператора new с параметрами
    void* operator new(size_t size, const char* message);
    
    // Перегрузка оператора delete
    void operator delete(void* pointer);

    ~CustomAllocatorDemo() {
        std::cout << "Деструктор вызван для значения: " << stored_value << std::endl;
    }
};
```

### Кастомный аллокатор
```cpp
void* CustomAllocatorDemo::operator new(size_t size) {
    // Проверка доступности места в буфере
    if ((current_buffer_pointer + size) > (memory_buffer + BUFFER_SIZE)) {
        throw std::logic_error("Недостаточно места в буфере");
    }
    
    void* allocated_memory = current_buffer_pointer;
    current_buffer_pointer += size;
    std::cout << "Выделено: " << size << " байт из буфера" << std::endl;
    return allocated_memory;
}
```

## Демонстрационные возможности

### 1. Стековое выделение памяти
```cpp
{
    CustomAllocatorDemo stack_object(1);
    // Объект автоматически уничтожен при выходе из блока
}
```

### 2. Placement new
```cpp
char* pre_allocated_memory = new char[sizeof(CustomAllocatorDemo)];
CustomAllocatorDemo* placement_object = ::new (pre_allocated_memory) CustomAllocatorDemo(2018);

// Явный вызов деструктора
placement_object->~CustomAllocatorDemo();
delete[] pre_allocated_memory;
```

### 3. Кастомный new с параметрами
```cpp
CustomAllocatorDemo* parameterized_object = new ("Привет, мир!") CustomAllocatorDemo(2019);
delete parameterized_object;
```

### 4. Динамическое выделение из буфера
```cpp
for (int i = 0; i < BUFFER_SIZE; ++i) {
    try {
        CustomAllocatorDemo* buffer_object = new CustomAllocatorDemo(i);
        delete buffer_object;
    } catch (const std::logic_error& error) {
        std::cout << "ОШИБКА: " << error.what() << std::endl;
        break;
    }
}
```

## Образовательные цели

1. **Понимание перегрузки операторов**: new/delete как операторы
2. **Управление памятью**: Кастомные аллокаторы и стратегии
3. **Placement new**: Размещение в предварительно выделенной памяти
4. **Параметризованные операторы**: Передача дополнительной информации
5. **Практическое применение**: Когда использовать кастомные аллокаторы

## Ключевые улучшения в коде

### Имена переменных
- `A` → `CustomAllocatorDemo` (более описательное)
- `buffer_size` → `BUFFER_SIZE` (константа в верхнем регистре)
- `buffer` → `memory_buffer` (более описательное)
- `ptr` → `current_buffer_pointer` (более описательное)
- `value` → `stored_value` (более описательное)
- `val` → `value` (более краткое)
- `a` → `stack_object` (более описательное)
- `ptr` → `pre_allocated_memory, placement_object, parameterized_object, buffer_object` (более описательные)
- `b` → `buffer_object` (более описательное)
- `i` → `iteration` (в циклах)

### Комментарии
- Подробные Doxygen-комментарии для всех функций и классов
- Объяснение назначения каждого демонстрационного блока
- Комментарии к демонстрационным шагам
- Предупреждения об особенностях перегрузки операторов

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
g++ -std=c++11 -o operator_new main.cpp

# Запуск
./operator_new
```

## Ожидаемый вывод

```
=== ДЕМОНСТРАЦИЯ ПЕРЕГРУЗКИ ОПЕРАТОРОВ NEW/DELETE ===

1. Стековое выделение памяти (НЕ вызывает operator new):
   Конструктор вызван для значения: 1
   Внутренний блок - объект на стеке
   Деструктор вызван для значения: 1
   Объект автоматически уничтожен при выходе из блока

2. Placement new (размещение в предварительно выделенной памяти):
   Конструктор вызван для значения: 2018
   Деструктор вызван для значения: 2018

3. Кастомный new с параметрами:
   Сообщение: Привет, мир!
   Выделение памяти через malloc: 4 байт
   Конструктор вызван для значения: 2019
   Деструктор вызван для значения: 2019
   Память освобождена (кастомный delete)

4. Динамическое выделение памяти из буфера:
   Размер буфера: 80 байт
   Выделено: 4 байт из буфера
   Конструктор вызван для значения: 0
   Деструктор вызван для значения: 0
   Память освобождена (кастомный delete)
   Итерация 0 завершена
   ...
   Выделено: 4 байт из буфера
   Конструктор вызван для значения: 19
   Деструктор вызван для значения: 19
   Память освобождена (кастомный delete)
   Итерация 19 завершена
   ОШИБКА на итерации 20: Недостаточно места в буфере

=== ДЕМОНСТРАЦИЯ ЗАВЕРШЕНА ===
```

## Сравнение с другими подходами

### Перегрузка new/delete vs стандартное выделение
| Характеристика | Перегрузка new/delete | Стандартное выделение |
|----------------|----------------------|----------------------|
| **Контроль** | Полный контроль | Ограниченный |
| **Производительность** | Может быть быстрее | Стандартная |
| **Сложность** | Высокая | Низкая |
| **Отладка** | Сложная | Простая |
| **Память** | Кастомная стратегия | Системная |

### Placement new vs обычный new
| Характеристика | Placement new | Обычный new |
|----------------|---------------|-------------|
| **Память** | Предварительно выделена | Выделяется автоматически |
| **Деструктор** | Требует явного вызова | Вызывается автоматически |
| **Управление** | Полное | Автоматическое |
| **Производительность** | Может быть быстрее | Стандартная |
| **Сложность** | Высокая | Низкая |

## Ключевые особенности перегрузки операторов

### 1. Синтаксис перегрузки
```cpp
// Обычная перегрузка
void* operator new(size_t size);

// Перегрузка с параметрами
void* operator new(size_t size, const char* message);

// Перегрузка delete
void operator delete(void* pointer);
```

### 2. Вызов перегруженных операторов
```cpp
// Обычный вызов
CustomAllocatorDemo* obj1 = new CustomAllocatorDemo(42);

// Вызов с параметрами
CustomAllocatorDemo* obj2 = new ("Сообщение") CustomAllocatorDemo(42);

// Placement new
char* memory = new char[sizeof(CustomAllocatorDemo)];
CustomAllocatorDemo* obj3 = ::new (memory) CustomAllocatorDemo(42);
```

### 3. Управление памятью
```cpp
// Кастомный аллокатор
void* CustomAllocatorDemo::operator new(size_t size) {
    if ((current_buffer_pointer + size) > (memory_buffer + BUFFER_SIZE)) {
        throw std::logic_error("Недостаточно места в буфере");
    }
    
    void* allocated_memory = current_buffer_pointer;
    current_buffer_pointer += size;
    return allocated_memory;
}
```

### 4. Обработка ошибок
```cpp
try {
    CustomAllocatorDemo* obj = new CustomAllocatorDemo(42);
    delete obj;
} catch (const std::logic_error& error) {
    std::cout << "Ошибка выделения памяти: " << error.what() << std::endl;
}
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
    static void* operator new(size_t size) {
        std::cout << "Выделение " << size << " байт" << std::endl;
        return std::malloc(size);
    }
    
    static void operator delete(void* ptr) {
        std::cout << "Освобождение памяти" << std::endl;
        std::free(ptr);
    }
};
```

### 3. Алигнированные аллокаторы
```cpp
class AlignedAllocator {
public:
    static void* operator new(size_t size) {
        return std::aligned_alloc(64, size);  // 64-байтное выравнивание
    }
    
    static void operator delete(void* ptr) {
        std::free(ptr);
    }
};
```

### 4. Статистика выделения памяти
```cpp
class MemoryStats {
private:
    static size_t total_allocated;
    static size_t allocation_count;
    
public:
    static void* operator new(size_t size) {
        total_allocated += size;
        allocation_count++;
        std::cout << "Всего выделено: " << total_allocated 
                  << " байт в " << allocation_count << " операциях" << std::endl;
        return std::malloc(size);
    }
    
    static void operator delete(void* ptr) {
        std::free(ptr);
    }
};
```

## Дополнительные возможности для изучения

1. **Массивы**: Перегрузка `operator new[]` и `operator delete[]`
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

### 1. Когда использовать перегрузку new/delete
- **Специализированные аллокаторы**: Когда нужен особый контроль
- **Отладка**: Для отслеживания выделения памяти
- **Производительность**: Когда стандартные аллокаторы неэффективны
- **Ограниченная память**: В embedded системах

### 2. Когда НЕ использовать перегрузку new/delete
- **Стандартные задачи**: Когда стандартные аллокаторы достаточны
- **Библиотечный код**: Когда нужна совместимость
- **Сложность**: Когда сложность не оправдана
- **Команда**: Когда команда не готова к сложности

### 3. Лучшие практики
- **Тестирование**: Тщательное тестирование аллокаторов
- **Документация**: Подробная документация поведения
- **Отладка**: Инструментирование для отладки
- **Производительность**: Профилирование производительности

## Placement new

### Основы
```cpp
// Выделение памяти
char* memory = new char[sizeof(MyClass)];

// Placement new
MyClass* obj = ::new (memory) MyClass(42);

// Явный вызов деструктора
obj->~MyClass();

// Освобождение памяти
delete[] memory;
```

### Применения
- **Пул объектов**: Переиспользование объектов
- **Оптимизация**: Избежание системных вызовов
- **Специализированная память**: Выделение в особых областях
- **Отладка**: Контроль над размещением объектов

## Кастомные аллокаторы

### Простой аллокатор
```cpp
class SimpleAllocator {
private:
    char* buffer;
    size_t size;
    size_t offset;
    
public:
    SimpleAllocator(size_t buffer_size) : size(buffer_size), offset(0) {
        buffer = new char[size];
    }
    
    ~SimpleAllocator() {
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

### Статистический аллокатор
```cpp
class StatsAllocator {
private:
    static size_t total_allocated;
    static size_t allocation_count;
    
public:
    static void* operator new(size_t size) {
        total_allocated += size;
        allocation_count++;
        std::cout << "Выделено " << size << " байт (всего: " 
                  << total_allocated << ")" << std::endl;
        return std::malloc(size);
    }
    
    static void operator delete(void* ptr) {
        std::free(ptr);
    }
};
```

Этот пример отлично демонстрирует возможности перегрузки операторов new/delete и помогает понять, когда и как использовать кастомные аллокаторы в C++.
