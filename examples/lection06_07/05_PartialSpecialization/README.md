# Частичная специализация шаблонов

## Описание
Этот пример демонстрирует **частичную специализацию шаблонов** (partial template specialization) - создание специализаций для части параметров шаблона, оставляя остальные параметры свободными.

## Ключевые концепции

### 1. Базовый шаблон
```cpp
template <class A, class B, class C>
struct Foo {
    A add(B first_value, C second_value) {
        return static_cast<A>(first_value + second_value);
    }
};
```

### 2. Частичная специализация
```cpp
// Специализация для случаев, когда B=char и C=char
// A остается параметром шаблона
template <class A>
struct Foo<A, char, char> {
    A add(char first_char, char second_char) {
        return static_cast<A>(first_char + second_char - '0' - '0');
    }
};
```

## Особенности частичной специализации

### Синтаксис
```cpp
template <class A>           // Остающиеся параметры
struct Foo<A, char, char> {  // Специализация для char, char
    // Специальная реализация
};
```

### Ограничения для функций
```cpp
// ❌ НЕ разрешено - частичная специализация функций
template <class A>
A add<A, char, char>(char b, char c) { ... }

// ✅ Разрешено - полная специализация функций
template <>
int add<int, char, char>(char b, char c) { ... }
```

## Использование

### Базовый шаблон
```cpp
Foo<int, int, int> foo1;
foo1.add(5, 3);  // 8 (обычное сложение)
```

### Частичная специализация
```cpp
Foo<int, char, char> foo2;
foo2.add('2', '2');  // 4 (специальная логика для char)
```

### Различия в поведении
```cpp
// Базовый шаблон: '1' + '2' = 49 + 50 = 99 (ASCII коды)
add<int, char, char>('1', '2');  // 99

// Частичная специализация: '2' + '2' - '0' - '0' = 2 + 2 = 4
Foo<int, char, char>().add('2', '2');  // 4
```

## Компиляция и запуск
```bash
g++ -std=c++17 -Wall -Wextra main.cpp -o partial_specialization
./partial_specialization
```

## Ожидаемый вывод
```
Foo<int,int,int>().add(5,3) = 8
Foo<int,char,char>().add('2','2') = 4
Foo<char,char,char>().add('0',1) = 
add<int,int,int>(1,2) = 3
add<int,char,char>('1','2') = 99
```

## Практические применения

### STL примеры
```cpp
// std::vector<T*> - частичная специализация для указателей
template <class T>
class vector<T*> {
    // Специальная реализация для указателей
};

// std::remove_reference<T&> - частичная специализация
template <class T>
struct remove_reference<T&> {
    using type = T;
};
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
template <class T, class U>
struct MyClass { /* общая логика */ };

// Специализация для указателей
template <class T>
struct MyClass<T*, T*> { /* оптимизированная логика */ };
```

## Преимущества частичной специализации
- ✅ **Гибкость**: специализация для групп типов
- ✅ **Оптимизация**: специальная логика для конкретных случаев
- ✅ **Переиспользование**: один шаблон для разных комбинаций
- ✅ **Типобезопасность**: компилятор выбирает правильную версию

## Сравнение с полной специализацией

| Тип специализации | Синтаксис | Параметры | Пример |
|-------------------|-----------|-----------|---------|
| **Полная** | `template <> struct Foo<char, char, char>` | Все параметры фиксированы | `Foo<char, char, char>` |
| **Частичная** | `template <class A> struct Foo<A, char, char>` | Часть параметров свободна | `Foo<int, char, char>`, `Foo<double, char, char>` |

## Ограничения
- ❌ **Функции**: частичная специализация не разрешена для функций
- ❌ **Переменные**: частичная специализация не разрешена для переменных
- ✅ **Классы**: частичная специализация разрешена только для классов
