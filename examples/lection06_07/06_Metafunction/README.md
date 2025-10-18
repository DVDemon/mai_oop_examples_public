# Метафункции

## Описание
Этот пример демонстрирует **метафункции** (metafunctions) - шаблоны, которые выполняют вычисления на этапе компиляции, а не во время выполнения программы.

## Ключевые концепции

### 1. Метафункция
```cpp
template <int value>
struct abs {
    static const int result = value < 0 ? -value : value;
};
```

### 2. Использование метафункции
```cpp
// Прямой доступ к результату
example::abs<10>::result;        // 10
example::abs<-20>::result;      // 20

// Создание объекта
example::abs<10> abs_instance;
abs_instance.result;             // 10
```

### 3. Constexpr функции
```cpp
constexpr int get_value() {
    return -99;
}

// Использование в метафункции
example::abs<get_value()>::result;  // 99
```

## Особенности метафункций

### Вычисления на этапе компиляции
```cpp
// Все вычисления происходят во время компиляции
// В runtime код содержит только константы
static const int result = value < 0 ? -value : value;
```

### Производительность
- ✅ **Нулевые накладные расходы**: вычисления происходят на этапе компиляции
- ✅ **Оптимизация**: компилятор может оптимизировать код
- ✅ **Константы**: результаты становятся константами времени компиляции

### Ограничения
- ❌ **Только константы**: параметры должны быть известны на этапе компиляции
- ❌ **Ограниченные вычисления**: не все операции доступны в constexpr контексте

## Использование

### Базовое использование
```cpp
// Прямой доступ
std::cout << example::abs<10>::result << std::endl;    // 10
std::cout << example::abs<-20>::result << std::endl;   // 20
```

### С constexpr функциями
```cpp
constexpr int get_value() { return -99; }
std::cout << example::abs<get_value()>::result << std::endl;  // 99
```

### Создание объектов
```cpp
example::abs<10> abs_instance;
std::cout << abs_instance.result << std::endl;  // 10
```

## Компиляция и запуск
```bash
g++ -std=c++17 -Wall -Wextra main.cpp -o metafunction
./metafunction
```

## Ожидаемый вывод
```
abs_instance.result = 10
example::abs<10>::result = 10
example::abs<-20>::result = 20
example::abs<get_value()>::result = 99
```

## Практические применения

### STL примеры
```cpp
// std::integral_constant
template <class T, T v>
struct integral_constant {
    static constexpr T value = v;
    using value_type = T;
    using type = integral_constant;
};

// std::is_same
template <class T, class U>
struct is_same : std::false_type {};

template <class T>
struct is_same<T, T> : std::true_type {};
```

### Метапрограммирование
```cpp
// Вычисление факториала
template <int N>
struct factorial {
    static const int value = N * factorial<N-1>::value;
};

template <>
struct factorial<0> {
    static const int value = 1;
};

// Использование
factorial<5>::value;  // 120
```

### Условная компиляция
```cpp
// Выбор типа на основе условия
template <bool condition>
struct conditional {
    using type = int;
};

template <>
struct conditional<false> {
    using type = double;
};

// Использование
conditional<true>::type;   // int
conditional<false>::type;  // double
```

## Преимущества метафункций
- ✅ **Производительность**: вычисления на этапе компиляции
- ✅ **Типобезопасность**: проверка типов на этапе компиляции
- ✅ **Оптимизация**: компилятор может оптимизировать код
- ✅ **Константы**: результаты становятся константами

## Современные альтернативы
```cpp
// C++11: constexpr функции
constexpr int abs(int value) {
    return value < 0 ? -value : value;
}

// C++14: constexpr переменные
constexpr int result = abs(-10);  // 10

// C++17: if constexpr
if constexpr (condition) {
    // Код, выполняемый на этапе компиляции
}
```

## Сравнение с обычными функциями

| Аспект | Обычная функция | Метафункция |
|--------|-----------------|-------------|
| **Время выполнения** | Runtime | Compile-time |
| **Производительность** | Накладные расходы | Нулевые накладные расходы |
| **Ограничения** | Минимальные | Только константы |
| **Использование** | `func(10)` | `MetaFunc<10>::value` |
