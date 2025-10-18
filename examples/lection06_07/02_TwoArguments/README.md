# Шаблоны с несколькими параметрами

## Описание
Этот пример демонстрирует работу с шаблонами, имеющими несколько параметров-типов, и показывает возможности вложенных шаблонов.

## Ключевые концепции

### 1. Шаблон класса с двумя параметрами
```cpp
template <class A, class B>
class Sum {
    A a;
    B b;
public:
    Sum(A a_value, B b_value) : a(a_value), b(b_value) {}
};
```

### 2. Вложенные шаблоны
```cpp
// Один из параметров - это другой шаблонный тип
Sum<int, Sum<int, int>> sum_of_sum(1, Sum<int, int>(2, 3));
```

### 3. Глубокая вложенность
```cpp
// Сложные типы из шаблонов
Sum<int, Sum<int, Sum<int, Sum<int, int>>>> deep_nesting(...);
```

## Особенности

### Дружественные функции в шаблонах
```cpp
template <class C, class D>
friend std::ostream& operator<<(std::ostream& os, const Sum<C, D>& sum);
```

### Внешние функции-шаблоны
```cpp
template <class A, class B>
std::ostream& operator<<(std::ostream& os, const Sum<A, B>& sum) {
    os << sum.a << "," << sum.b << " ";
    return os;
}
```

## Использование

### Простые типы
```cpp
Sum<int, int> simple_sum(1, 2);
```

### Вложенные типы
```cpp
Sum<int, Sum<int, int>> sum_of_sum(1, Sum<int, int>(2, 3));
```

### Глубокая вложенность
```cpp
Sum<int, Sum<int, Sum<int, Sum<int, int>>>> deep_nesting(
    1, 
    Sum<int, Sum<int, Sum<int, int>>>(2, ...)
);
```

## Компиляция и запуск
```bash
g++ -std=c++17 -Wall -Wextra main.cpp -o two_arguments
./two_arguments
```

## Ожидаемый вывод
```
Simple sum: 1,2 
Sum of sum: 1,2,3 
Deep nesting: 1,2,3,4,5 
```

## Практические применения
- **STL контейнеры**: `std::map<K, V>`, `std::pair<T1, T2>`
- **Умные указатели**: `std::shared_ptr<T>`, `std::unique_ptr<T>`
- **Метапрограммирование**: сложные типы времени компиляции
- **Функциональное программирование**: композиция функций
