# Простые шаблоны C++

## Описание
Этот пример демонстрирует базовые концепции шаблонов (templates) в C++:

- **Шаблоны классов** с параметрами-типами
- **Шаблоны функций** с автоматическим выводом типов
- **Шаблоны с параметрами-константами** (non-type template parameters)

## Ключевые концепции

### 1. Шаблон класса
```cpp
template <class T>
struct Container {
    T payload;
    Container(const T& value) : payload(value) {}
};
```

### 2. Шаблон функции
```cpp
template <class T>
T print(T value) {
    std::cout << "Value: " << value << " size: " << sizeof(T) << std::endl;
    return value;
}
```

### 3. Шаблон с параметром-константой
```cpp
template <int V>
struct foo {
    static const int value = V;
};
```

## Использование

### Явное указание типа
```cpp
print<int>(10);
Container<std::string> container("Hello");
```

### Автоматический вывод типа
```cpp
print(10);        // Компилятор выведет int
print("Hello");   // Компилятор выведет const char*
```

### Параметры-константы
```cpp
constexpr int A = 10;
foo<A>::value;    // Результат: 10
```

## Компиляция и запуск
```bash
g++ -std=c++17 -Wall -Wextra main.cpp -o template_example
./template_example
```

## Ожидаемый вывод
```
Value: Hello world! size: 8
Value: Hello world! size: 32
Value: Hello world! size: 32
foo<10>::value = 10
```
