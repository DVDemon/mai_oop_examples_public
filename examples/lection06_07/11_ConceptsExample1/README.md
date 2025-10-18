# 11_ConceptsExample1 - Пользовательские концепции C++20

## Описание примера

Этот пример демонстрирует создание и использование **пользовательских концепций (custom concepts)** в C++20. Показывает, как концепции заменяют сложные SFINAE конструкции и делают код более читаемым и понятным.

## Ключевые концепции

### 1. Создание пользовательской концепции
```cpp
template <typename T>
concept OutputStreamable = requires(std::ostream& output_stream, T data){
    output_stream << data;
};
```
- **concept** - ключевое слово для создания концепции
- **requires** - выражение для проверки возможности операции
- **output_stream << data** - проверка поддержки вывода в поток

### 2. Использование концепции в шаблонах
```cpp
template <OutputStreamable T>
std::ostream& operator<<(std::ostream& output_stream, const std::vector<T>& vector_data)
```
- **OutputStreamable T** - ограничение типа T концепцией
- **Условная компиляция** на основе свойств типов
- **Более читаемый** синтаксис по сравнению с SFINAE

### 3. Практическое применение
- **Оператор вывода** для std::vector с ограничениями
- **Проверка типов** на этапе компиляции
- **Улучшение сообщений** об ошибках

## Особенности реализации

### Синтаксис концепций
- **concept Name = requires(expression)** - создание концепции
- **template <ConceptName T>** - использование концепции
- **requires(expression)** - проверка возможности операции

### Проверка на этапе компиляции
- **Компилятор проверяет** ограничения концепций
- **Ошибки компиляции** при несовместимых типах
- **Лучшие сообщения** об ошибках

### Замена SFINAE
- **Более читаемый** код
- **Понятные ограничения** типов
- **Современный подход** к метапрограммированию

## Ожидаемые результаты

```
=== ДЕМОНСТРАЦИЯ ПОЛЬЗОВАТЕЛЬСКИХ КОНЦЕПЦИЙ C++20 ===

1. Вывод вектора целых чисел:
   numbers :  [ 1 2 3 4 5 ]

2. Вывод вектора точек:
   points :  [ Point [ x : 10, y : 20] Point [ x : 59, y : 45] ]

3. Принцип работы пользовательских концепций:
   - concept OutputStreamable - пользовательская концепция
   - requires(expression) - проверка возможности операции
   - output_stream << data - проверка вывода в поток
   - template <OutputStreamable T> - использование концепции
   - Компилятор проверяет ограничения на этапе компиляции

4. Преимущества пользовательских концепций:
   - Читаемость кода
   - Лучшие сообщения об ошибках
   - Замена сложных SFINAE конструкций
   - Более понятные ограничения типов
   - Современный подход к метапрограммированию
```

## Компиляция и запуск

```bash
# Компиляция (требует C++20)
g++ -std=c++20 -O2 -o concepts_example1_program main.cpp

# Запуск
./concepts_example1_program
```

## Образовательная ценность

Этот пример демонстрирует:
- **Создание пользовательских концепций** в C++20
- **Синтаксис requires** для проверки операций
- **Использование концепций** в шаблонах
- **Преимущества концепций** над SFINAE
- **Практическое применение** в реальном коде

## Практическое применение

- **Библиотеки** используют концепции для ограничения типов
- **Замена SFINAE** на более читаемые конструкции
- **Улучшение качества** кода и его понимания
- **Современный подход** к метапрограммированию

## Связь с другими примерами

- **10_BuiltInConcepts** - встроенные концепции C++20
- **09_TypeTraits** - стандартные type traits
- **08_Types** - создание собственных type traits
- **06_Metafunction** - метафункции и вычисления на этапе компиляции

## Сравнение с SFINAE

### Старый способ (SFINAE)
```cpp
template<typename T>
typename std::enable_if<
    std::is_same<decltype(std::declval<std::ostream&>() << std::declval<T>()), 
                 std::ostream&>::value, 
    void>::type
function(T value) { /* ... */ }
```

### Новый способ (концепции)
```cpp
template <typename T>
concept OutputStreamable = requires(std::ostream& o, T d){
    o << d;
};

template <OutputStreamable T>
void function(T value) { /* ... */ }
```

## Дополнительные возможности

### Комбинирование концепций
```cpp
template <typename T>
concept NumericAndOutputStreamable = std::is_arithmetic_v<T> && 
                                   requires(std::ostream& o, T d){ o << d; };
```

### Сложные выражения requires
```cpp
template <typename T>
concept ComplexConcept = requires(T t){
    t.method1();
    t.method2();
    { t.method3() } -> std::convertible_to<int>;
};
```

### Концепции с параметрами
```cpp
template <typename T, typename U>
concept Convertible = requires(T t, U u){
    u = t;
    t = u;
};
```
