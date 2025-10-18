# Специализация шаблонов

## Описание
Этот пример демонстрирует **специализацию шаблонов** (template specialization) - создание специальных версий шаблона для конкретных типов.

## Ключевые концепции

### 1. Базовый шаблон (Primary Template)
```cpp
template <class T>
class MyContainer {
    T element;
public:
    MyContainer(T arg) : element(arg) {}
    T increase() { return ++element; }
    T decrease() { return --element; }
};
```

### 2. Специализация шаблона (Template Specialization)
```cpp
template <>
class MyContainer<char> {
    char element;
public:
    MyContainer(char arg) : element(arg) {}
    char uppercase() { /* специальная логика */ }
    char increase() { /* переопределение для char */ }
    char decrease() { /* переопределение для char */ }
};
```

## Особенности специализации

### Синтаксис специализации
```cpp
template <>  // Пустые угловые скобки означают полную специализацию
class MyContainer<char> {
    // Специальная реализация только для типа char
};
```

### Переопределение методов
```cpp
// Для int: increase() = ++element (арифметическое увеличение)
// Для char: increase() = uppercase() (преобразование в верхний регистр)
```

### Специальные методы
```cpp
// Метод uppercase() доступен только для MyContainer<char>
char_container.uppercase();  // Работает
int_container.uppercase();   // Ошибка компиляции
```

## Использование

### Базовый шаблон
```cpp
MyContainer<int> int_container(7);
int_container.increase();  // 8 (арифметическое увеличение)
```

### Специализация
```cpp
MyContainer<char> char_container('j');
char_container.uppercase();  // 'J' (специальный метод)
char_container.increase();   // 'J' (uppercase для char)
char_container.decrease();   // 'j' (lowercase для char)
```

## Компиляция и запуск
```bash
g++ -std=c++17 -Wall -Wextra main.cpp -o specialization
./specialization
```

## Ожидаемый вывод
```
int increase(): 8
char uppercase(): J
char increase(): J
char decrease(): j
```

## Практические применения

### STL примеры
```cpp
// std::vector<bool> - специализация для оптимизации
std::vector<bool> bits;  // Специальная реализация для bool

// std::hash<T> - специализации для разных типов
std::hash<std::string> string_hasher;
std::hash<int> int_hasher;
```

### Метапрограммирование
```cpp
template <class T>
struct is_pointer { static const bool value = false; };

template <class T>
struct is_pointer<T*> { static const bool value = true; };
```

### Оптимизация
```cpp
// Общая реализация
template <class T>
void process(T value) { /* общая логика */ }

// Специализация для указателей
template <class T>
void process(T* pointer) { /* оптимизированная логика для указателей */ }
```

## Преимущества специализации
- ✅ **Оптимизация**: специальная логика для конкретных типов
- ✅ **Семантика**: разное поведение для разных типов
- ✅ **Производительность**: избежание ненужных операций
- ✅ **Типобезопасность**: компилятор выбирает правильную версию

## Типы специализации
1. **Полная специализация**: `template <> class MyContainer<char>`
2. **Частичная специализация**: `template <class T> class MyContainer<T*>`
3. **Специализация функций**: `template <> void func<char>(char c)`
