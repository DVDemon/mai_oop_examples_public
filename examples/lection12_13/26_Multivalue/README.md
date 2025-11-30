# Пример: Корутины - Возврат нескольких значений

## Описание

Данный пример демонстрирует, как корутины могут возвращать **несколько значений одновременно** через составные типы (например, `std::pair`) - расширяет возможности генераторов для работы с комплексными данными.

## Суть примера

### Генератор с парой значений

```cpp
Generator sequence() {
    for (int i = 0; i < 10; ++i) {
        co_yield {i, i * 2};  // Возвращает пару значений
    }
}
```

**Особенности:**
- **Составное значение** - возвращает `std::pair<int, int>`
- **Два значения одновременно** - индекс и его удвоенное значение
- **Структурированная передача** - значения связаны логически

### Использование

```cpp
auto gen = sequence();
while (gen.next()) {
    auto [yieldedValue, otherValue] = gen.getValue();  // Structured binding
    std::cout << "Yielded: " << yieldedValue 
              << ", Other: " << otherValue << std::endl;
}
```

**Результат:** Пары (0,0), (1,2), (2,4), (3,6), ..., (9,18)

## Архитектура

### Promise type с несколькими полями

```cpp
struct promise_type {
    int current_value;   // Первое значение
    int other_value;     // Второе значение
    
    std::suspend_always yield_value(std::pair<int, int> value) {
        current_value = value.first;   // Сохраняем первое значение
        other_value = value.second;    // Сохраняем второе значение
        return {};
    }
};
```

**Ключевые изменения:**
- **Два поля** вместо одного для хранения значений
- **`yield_value` принимает `std::pair`** вместо `int`
- **Распаковка пары** при сохранении значений

### Метод получения значений

```cpp
std::pair<int, int> getValue() {
    return {h.promise().current_value, h.promise().other_value};
}
```

**Возвращает:** Пару значений, которые были переданы через `co_yield`.

## Принцип работы

### Передача составных значений

```
Корутина:
    co_yield {i, i * 2}
    ↓
yield_value(std::pair<int, int> value)
    ↓
current_value = value.first  (i)
other_value = value.second   (i * 2)
    ↓
[корутина приостановлена]

Потребитель:
    gen.getValue()
    ↓
    {current_value, other_value}
    ↓
    auto [yieldedValue, otherValue] = ...
    ↓
    [использование обоих значений]
```

## Сравнение с предыдущими примерами

### 24_CoSimple - Одно значение

```cpp
std::suspend_always yield_value(int value) {
    current_value = value;  // Одно значение
    return {};
}

int current_value() {
    return *coro.promise().current_value;  // Возвращает int
}
```

**Характеристики:**
- Возвращает одно значение типа `int`
- Простая структура данных
- Один метод для получения значения

### 26_Multivalue - Несколько значений

```cpp
std::suspend_always yield_value(std::pair<int, int> value) {
    current_value = value.first;   // Два значения
    other_value = value.second;
    return {};
}

std::pair<int, int> getValue() {
    return {current_value, other_value};  // Возвращает pair
}
```

**Характеристики:**
- Возвращает составное значение (`std::pair`)
- Два связанных значения одновременно
- Structured binding для удобного доступа

## Преимущества возврата нескольких значений

### Логическая связность

```cpp
co_yield {index, value};        // Индекс и значение
co_yield {x, y};                // Координаты точки
co_yield {key, value};          // Ключ-значение
co_yield {timestamp, data};     // Временная метка и данные
```

**Преимущества:**
- **Связанные данные вместе** - не нужно делать два вызова
- **Атомарность** - значения генерируются одновременно
- **Семантика** - ясно, что значения связаны

### Удобство использования

```cpp
// Structured binding (C++17)
auto [x, y] = gen.getValue();

// Доступ к отдельным значениям
auto pair = gen.getValue();
int first = pair.first;
int second = pair.second;
```

**Гибкость:**
- Можно использовать structured binding
- Можно работать с парой как с объектом
- Удобный доступ к обоим значениям

## Типичные применения

### Координаты и геометрия

```cpp
Generator points() {
    for (int i = 0; i < 100; ++i) {
        co_yield {x_coord(i), y_coord(i)};  // Точки на графике
    }
}
```

### Ключ-значение пары

```cpp
Generator keyValuePairs() {
    for (const auto& item : data) {
        co_yield {item.key(), item.value()};  // Словарь
    }
}
```

### Временные ряды

```cpp
Generator timeSeries() {
    for (auto timestamp : timestamps) {
        co_yield {timestamp, getValue(timestamp)};  // Время и значение
    }
}
```

### Статистика

```cpp
Generator statistics() {
    for (int i = 0; i < data.size(); ++i) {
        co_yield {i, calculateStat(data, i)};  // Индекс и статистика
    }
}
```

## Расширение на больше значений

### Три значения (концептуально)

```cpp
struct promise_type {
    int value1;
    int value2;
    int value3;
    
    std::suspend_always yield_value(std::tuple<int, int, int> value) {
        value1 = std::get<0>(value);
        value2 = std::get<1>(value);
        value3 = std::get<2>(value);
        return {};
    }
};

// Использование
co_yield {1, 2, 3};
auto [a, b, c] = gen.getValue();
```

### Структуры данных

```cpp
struct Point {
    int x, y, z;
};

struct promise_type {
    Point current_point;
    
    std::suspend_always yield_value(Point p) {
        current_point = p;
        return {};
    }
};

// Использование
co_yield Point{1, 2, 3};
Point p = gen.getValue();
```

## Важные моменты

### Тип возвращаемого значения

```cpp
std::suspend_always yield_value(std::pair<int, int> value) {
    // Тип должен совпадать с типом в co_yield
}
```

**Важно:** Тип параметра `yield_value` должен совпадать с типом в `co_yield`.

### Structured binding

```cpp
auto [first, second] = gen.getValue();  // C++17
```

**Требования:**
- C++17 или выше
- Тип должен поддерживать structured binding (pair, tuple, структуры)

### Производительность

```cpp
std::pair<int, int> getValue() {
    return {h.promise().current_value, h.promise().other_value};
}
```

**Особенности:**
- Возврат по значению (копирование)
- Для больших структур можно использовать ссылки
- Оптимизация компилятором (RVO, move semantics)

## Связь с предыдущими примерами

- `24_CoSimple` - корутины с одним значением
- `25_CoFibonacci` - бесконечные последовательности
- `26_Multivalue` - корутины с несколькими значениями
- `05_LambdaGen` - генераторы через лямбды (альтернативный подход)

Это демонстрирует гибкость корутин для работы с различными типами данных - от простых значений до составных структур, показывая как они могут эффективно передавать связанные данные одновременно.

