# 17_SharedPtr - std::shared_ptr с разделяемым владением

## Описание примера

Этот пример демонстрирует **std::shared_ptr** - умный указатель с разделяемым владением, который использует счетчик ссылок для автоматического управления памятью. Показывает различные способы создания shared_ptr и использования кастомных делетеров.

## Ключевые концепции

### 1. std::shared_ptr - разделяемое владение
```cpp
std::shared_ptr<int> ptr1{new int{10}};           // Явное создание (не рекомендуется)
auto ptr2 = std::make_shared<int>(42);            // Рекомендуемый способ
std::shared_ptr<int> ptr3{init(), &deinit};      // С кастомным делетером
```

### 2. Счетчик ссылок (Reference Counting)
- **Разделяемое владение** - несколько shared_ptr могут владеть одним объектом
- **Автоматическое освобождение** - объект удаляется при последнем владельце
- **Thread-safe** - счетчик ссылок защищен от race conditions
- **Накладные расходы** - дополнительная память для счетчика

### 3. Кастомные делетеры
```cpp
// Функция-делетер
void deinit(int* ptr) { delete ptr; }
std::shared_ptr<int> ptr{init(), &deinit};

// Структура-делетер
struct CustomDeleter {
    void operator()(int* ptr) { delete ptr; }
};
std::shared_ptr<int> ptr{init(), CustomDeleter{}};

// std::function делетер
std::shared_ptr<int> ptr{init(), std::function<void(int*)>([](int* p) {delete p;})};

// Лямбда делетер
auto deleter = [](int* ptr) { delete ptr; };
std::shared_ptr<int> ptr{init(), deleter};
```

## Особенности реализации

### Создание shared_ptr
- **std::make_shared** - рекомендуется для эффективности
- **Явное new** - не рекомендуется из-за исключений
- **Кастомные делетеры** - для особых случаев освобождения

### Размеры объектов
- **shared_ptr** - обычно 16 байт (указатель + счетчик)
- **std::function** - обычно 32 байта (type erasure)
- **Лямбда без захвата** - 1 байт (пустой объект)
- **Лямбда с захватом** - размер зависит от захваченных переменных

### Принципы работы
- **Счетчик ссылок** - атомарный счетчик владельцев
- **Контрольный блок** - содержит счетчик и делетер
- **Автоматическое освобождение** - при счетчике = 0
- **Thread-safety** - безопасность в многопоточности

## Ожидаемые результаты

```
=== ДЕМОНСТРАЦИЯ STD::SHARED_PTR ===

1. Базовое использование shared_ptr:
   sizeof(shared_ptr) = 16 bytes
   Value: 10

2. Использование std::make_shared (рекомендуемый способ):
   sizeof(shared_ptr) = 16 bytes
   Value: 42

3. Кастомный делетер - функция:
   start
Object initialized
   sizeof(shared_ptr) = 16 bytes
Object deinitialized
   end

4. Кастомный делетер - структура:
   start
Object initialized
   sizeof(shared_ptr) = 16 bytes
CustomDeleter::operator() called
Object deinitialized
   end

5. Кастомный делетер - std::function:
   start
Object initialized
   sizeof(shared_ptr) = 16 bytes
   sizeof(std::function<void()>{}) = 32 bytes
Object deinitialized
   end

6. Кастомный делетер - лямбда (без захвата):
   start
Object initialized
   sizeof(shared_ptr) = 16 bytes
   sizeof(lambda_deleter) = 1 bytes
Object deinitialized
   end

7. Кастомный делетер - лямбда (с захватом):
   start
Object initialized
   sizeof(shared_ptr) = 16 bytes
   sizeof(lambda_deleter_with_capture) = 8 bytes
Object deinitialized
   end

8. Принципы работы shared_ptr:
   - Разделяемое владение ресурсом
   - Счетчик ссылок (reference counting)
   - Автоматическое освобождение при последнем владельце
   - Поддержка кастомных делетеров
   - Thread-safe счетчик ссылок
   - Дополнительные накладные расходы по сравнению с unique_ptr
```

## Компиляция и запуск

```bash
# Компиляция
g++ -std=c++17 -O2 -o shared_ptr_program main.cpp

# Запуск
./shared_ptr_program
```

## Образовательная ценность

Этот пример демонстрирует:
- **Разделяемое владение** - несколько владельцев одного ресурса
- **Счетчик ссылок** - автоматическое управление жизненным циклом
- **Кастомные делетеры** - гибкость в управлении ресурсами
- **Thread-safety** - безопасность в многопоточности
- **Накладные расходы** - компромисс между функциональностью и производительностью

## Практическое применение

### Когда использовать shared_ptr
- **Разделяемое владение** - когда несколько объектов должны владеть ресурсом
- **Неопределенный жизненный цикл** - когда время жизни объекта неизвестно
- **Кэширование** - для кэширования дорогих объектов
- **Обратные ссылки** - для циклических зависимостей

### Когда НЕ использовать shared_ptr
- **Единоличное владение** - используйте unique_ptr
- **Производительность** - накладные расходы на счетчик
- **Циклические ссылки** - могут привести к утечкам памяти
- **Простое владение** - когда время жизни очевидно

## Сравнение с unique_ptr

### std::unique_ptr
```cpp
std::unique_ptr<int> ptr = std::make_unique<int>(42);
// Единоличное владение
// Минимальные накладные расходы
// Move-only семантика
```

### std::shared_ptr
```cpp
std::shared_ptr<int> ptr = std::make_shared<int>(42);
// Разделяемое владение
// Дополнительные накладные расходы
// Copy и move семантика
```

## Дополнительные возможности

### Слабые ссылки
```cpp
std::shared_ptr<int> shared = std::make_shared<int>(42);
std::weak_ptr<int> weak = shared;  // Не увеличивает счетчик

if (auto locked = weak.lock()) {   // Проверка валидности
    // Использование locked
}
```

### Алиасинг
```cpp
std::shared_ptr<int> original = std::make_shared<int>(42);
std::shared_ptr<int> alias(original, original.get() + 1);  // Алиас на другой объект
```

### Кастомные делетеры для массивов
```cpp
struct ArrayDeleter {
    void operator()(int* ptr) { delete[] ptr; }
};
std::shared_ptr<int> array_ptr{new int[10], ArrayDeleter{}};
```

## Ограничения и особенности

### Ограничения shared_ptr
- **Накладные расходы** - дополнительная память для счетчика
- **Циклические ссылки** - могут привести к утечкам
- **Производительность** - атомарные операции для счетчика
- **Размер** - больше чем unique_ptr

### Особенности реализации
- **Контрольный блок** - содержит счетчик и делетер
- **Атомарные операции** - для thread-safety
- **Оптимизация** - make_shared объединяет объект и счетчик
- **Исключения** - безопасность при исключениях

## Рекомендации по использованию

### Лучшие практики
1. **Используйте make_shared** - для эффективности
2. **Избегайте циклических ссылок** - используйте weak_ptr
3. **Не используйте для простых случаев** - предпочитайте unique_ptr
4. **Проверяйте производительность** - накладные расходы могут быть значительными

### Антипаттерны
- **Избыточное использование** - когда unique_ptr достаточно
- **Циклические ссылки** - без weak_ptr
- **Смешивание с raw pointers** - может привести к проблемам
- **Игнорирование накладных расходов** - в критичных по производительности местах

## Связь с другими примерами

- **16_CustomUniquePointer** - пользовательский умный указатель
- **15_UniquePointers** - std::unique_ptr
- **14_VariadicTemplate** - variadic templates C++11
- **13_DeductionGuide** - deduction guides C++17

## Дополнительные возможности

### Расширенная функциональность
```cpp
// Проверка валидности
if (shared_ptr) { /* valid */ }

// Получение сырого указателя
int* raw = shared_ptr.get();

// Сброс указателя
shared_ptr.reset();

// Проверка уникальности
bool unique = shared_ptr.unique();

// Получение счетчика ссылок
long count = shared_ptr.use_count();
```

### Интеграция с STL
```cpp
std::vector<std::shared_ptr<int>> container;
container.push_back(std::make_shared<int>(42));

// Сортировка по значению
std::sort(container.begin(), container.end(), 
    [](const auto& a, const auto& b) { return *a < *b; });
```

### Многопоточность
```cpp
std::shared_ptr<int> shared = std::make_shared<int>(42);

// Безопасное использование в разных потоках
std::thread t1([shared]() { /* use shared */ });
std::thread t2([shared]() { /* use shared */ });
```

## Рекомендации по изучению

### Этапы изучения
1. **Понимание принципов** - разделяемое владение, счетчик ссылок
2. **Создание и использование** - make_shared, кастомные делетеры
3. **Сравнение с unique_ptr** - когда использовать что
4. **Многопоточность** - thread-safety, race conditions
5. **Производительность** - накладные расходы, оптимизация

### Практические упражнения
- **Создание кэша** - с использованием shared_ptr
- **Реализация observer** - с weak_ptr для обратных ссылок
- **Измерение производительности** - сравнение с unique_ptr
- **Отладка циклических ссылок** - использование weak_ptr
