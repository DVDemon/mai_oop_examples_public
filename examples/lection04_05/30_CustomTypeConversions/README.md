# 30_CustomTypeConversions

## Описание
Демонстрирует **пользовательские преобразования типов (Custom Type Conversions)** в C++. Показывает, как перегрузить преобразующие операторы (conversion operators) и конструкторы преобразования (converting constructors) для обеспечения явного и неявного преобразования между пользовательскими типами и базовыми типами.

## Классовая диаграмма
```
┌─────────────────┐
│      Number     │
├─────────────────┤
│ + Number()      │ ← конструктор по умолчанию
│ + Number(int)   │ ← конструктор с параметром
│ + ~Number()     │ ← деструктор
│ + get_wrapped_int() │ ← геттер
│ - m_wrapped_int │ ← обернутое значение
└─────────────────┘
         │
         │ explicit
         │ operator
         ▼
┌─────────────────┐
│ operator double() │ ← ПРЕОБРАЗУЮЩИЙ ОПЕРАТОР
├─────────────────┤
│ + explicit      │ ← предотвращает неявные преобразования
│ + static_cast   │ ← требует явного преобразования
│ + Number->double│ ← преобразование типа
└─────────────────┘
         │
         │ explicit
         │ operator
         ▼
┌─────────────────┐
│ operator Point() │ ← ПРЕОБРАЗУЮЩИЙ ОПЕРАТОР
├─────────────────┤
│ + explicit      │ ← предотвращает неявные преобразования
│ + static_cast   │ ← требует явного преобразования
│ + Number->Point │ ← преобразование типа
└─────────────────┘

┌─────────────────┐
│      Point      │
├─────────────────┤
│ + Point()       │ ← конструктор по умолчанию
│ + Point(x, y)   │ ← конструктор с параметрами
│ + ~Point()      │ ← деструктор
│ - m_x, m_y      │ ← координаты
└─────────────────┘
         ▲
         │ (закомментирован)
         │ explicit constructor
         │
┌─────────────────┐
│ Point(Number&)  │ ← КОНСТРУКТОР ПРЕОБРАЗОВАНИЯ
├─────────────────┤
│ + explicit      │ ← предотвращает неявные преобразования
│ + Number->Point │ ← преобразование типа
│ + static_cast   │ ← требует явного преобразования
└─────────────────┘
```

## Ключевые концепции

### 1. Преобразующие операторы (Conversion Operators)
```cpp
class Number {
public:
    // ЯВНЫЙ оператор преобразования в double
    explicit operator double() const {
        return static_cast<double>(m_wrapped_int);
    }
    
    // ЯВНЫЙ оператор преобразования в Point
    explicit operator Point() const {
        return Point(static_cast<double>(m_wrapped_int),
                     static_cast<double>(m_wrapped_int));
    }
    
private:
    int m_wrapped_int;
};

// Использование
Number n(42);
double d = static_cast<double>(n);  // Явное преобразование
Point p = static_cast<Point>(n);    // Явное преобразование
```

### 2. Конструкторы преобразования (Converting Constructors)
```cpp
class Point {
public:
    // ЯВНЫЙ конструктор преобразования из Number
    explicit Point(const Number& number_object) 
        : m_x(static_cast<double>(number_object.get_wrapped_int())),
          m_y(static_cast<double>(number_object.get_wrapped_int())) {
    }
    
private:
    double m_x, m_y;
};

// Использование
Number n(42);
Point p = static_cast<Point>(n);  // Явное преобразование через конструктор
```

### 3. Explicit ключевое слово
```cpp
// БЕЗ explicit - неявное преобразование разрешено
operator double() const {
    return static_cast<double>(m_wrapped_int);
}

// С explicit - только явное преобразование
explicit operator double() const {
    return static_cast<double>(m_wrapped_int);
}

// Использование
Number n(42);
double d1 = n;                    // ОШИБКА с explicit
double d2 = static_cast<double>(n); // OK с explicit
```

### 4. Static_cast для явных преобразований
```cpp
Number n(42);

// Явное преобразование через static_cast
double d = static_cast<double>(n);
Point p = static_cast<Point>(n);

// Использование в функциях
void func(double value);
func(static_cast<double>(n));  // Явное преобразование
```

## Файлы проекта
- `number.h` - объявление класса Number с преобразующими операторами
- `number.cpp` - реализация методов класса Number
- `point.h` - объявление класса Point с конструктором преобразования (закомментирован)
- `point.cpp` - реализация методов класса Point
- `main.cpp` - демонстрация использования пользовательских преобразований

## Компиляция и запуск
```bash
g++ -o main main.cpp number.cpp point.cpp
./main
```

## Ожидаемый вывод
```
=== Демонстрация пользовательских преобразований типов ===
--- Исходные объекты Number ---
First number: Number: [22]
Second number: Number: [10]

--- Демонстрация преобразующего оператора Number -> double ---
Результат явного преобразования Number -> double: 32

--- Демонстрация преобразующего оператора Number -> Point ---
Преобразование first_number в Point:
Custom conversion from Number to Point
Printing the point from use_point_function: Point [ x: 22, y: 22]

--- Дополнительные примеры преобразований ---
Прямое преобразование Number -> double: 22
Прямое преобразование Number -> Point: Point [ x: 10, y: 10]
Использование в выражении: 32

--- Демонстрация арифметических операторов Number ---
Number operations:
Number: [22] + Number: [10] = Number: [32]
Number: [22] - Number: [10] = Number: [12]
Number: [22] * Number: [10] = Number: [220]
Number: [22] / Number: [10] = Number: [2]
Number: [22] % Number: [10] = Number: [2]

=== Важные выводы ===
1. Преобразующие операторы позволяют преобразование типа объекта
2. explicit предотвращает неявные преобразования
3. static_cast используется для явного преобразования
4. Синтаксис: explicit operator TargetType() const
5. Преобразующие операторы являются методами класса

=== Типы пользовательских преобразований ===
1. Преобразующие операторы (conversion operators)
   - operator TargetType() const
   - Позволяют преобразование Source -> Target
2. Конструкторы преобразования (converting constructors)
   - Target(const Source& source)
   - Позволяют преобразование Source -> Target

=== Преимущества explicit ===
1. Предотвращает неожиданные неявные преобразования
2. Делает код более явным и понятным
3. Помогает избежать ошибок компиляции
4. Соответствует принципу явности кода

=== Применение пользовательских преобразований ===
1. Математические классы - преобразование в базовые типы
2. Обертки (wrappers) - преобразование в обернутые типы
3. Совместимость с существующими API
4. Упрощение интерфейса классов

=== Программа завершается ===
```

## Образовательная цель
Понимание пользовательских преобразований типов, explicit ключевого слова, преобразующих операторов и конструкторов преобразования в C++.

## Важные принципы

### 1. Синтаксис преобразующих операторов
```cpp
class MyClass {
public:
    // ЯВНЫЙ оператор преобразования
    explicit operator TargetType() const {
        // Логика преобразования
        return target_value;
    }
    
private:
    // Приватные поля
};

// Использование
MyClass obj;
TargetType target = static_cast<TargetType>(obj);
```

### 2. Explicit предотвращает неявные преобразования
```cpp
// БЕЗ explicit - неявное преобразование разрешено
operator double() const {
    return static_cast<double>(value);
}

// Использование
Number n(42);
double d = n;  // OK - неявное преобразование

// С explicit - только явное преобразование
explicit operator double() const {
    return static_cast<double>(value);
}

// Использование
Number n(42);
double d = n;                    // ОШИБКА - неявное преобразование запрещено
double d = static_cast<double>(n); // OK - явное преобразование
```

### 3. Static_cast для явных преобразований
```cpp
Number n(42);

// Явное преобразование
double d = static_cast<double>(n);
Point p = static_cast<Point>(n);

// Использование в функциях
void func(double value);
func(static_cast<double>(n));  // Явное преобразование

// Использование в выражениях
double result = static_cast<double>(n1) + static_cast<double>(n2);
```

### 4. Конструкторы преобразования
```cpp
class TargetClass {
public:
    // ЯВНЫЙ конструктор преобразования
    explicit TargetClass(const SourceClass& source) {
        // Логика преобразования
        value = source.get_value();
    }
    
private:
    int value;
};

// Использование
SourceClass source(42);
TargetClass target = static_cast<TargetClass>(source);
```

### 5. Forward declarations
```cpp
// В point.h
class Number;  // Forward declaration

class Point {
    // Можем использовать Number в объявлениях
    explicit Point(const Number& n);
};

// В point.cpp
#include "number.h"  // Полное определение Number
```

## Практические применения

### 1. Математические классы
```cpp
class Fraction {
public:
    explicit operator double() const {
        return static_cast<double>(numerator) / denominator;
    }
    
    explicit operator int() const {
        return numerator / denominator;
    }
    
private:
    int numerator, denominator;
};

Fraction f(22, 7);
double pi_approx = static_cast<double>(f);
int integer_part = static_cast<int>(f);
```

### 2. Обертки (Wrappers)
```cpp
class SafeInt {
public:
    explicit operator int() const {
        return value;
    }
    
    explicit operator bool() const {
        return value != 0;
    }
    
private:
    int value;
};

SafeInt safe(42);
int normal_int = static_cast<int>(safe);
bool is_nonzero = static_cast<bool>(safe);
```

### 3. Строковые преобразования
```cpp
class StringWrapper {
public:
    explicit operator std::string() const {
        return internal_string;
    }
    
    explicit operator const char*() const {
        return internal_string.c_str();
    }
    
private:
    std::string internal_string;
};

StringWrapper wrapper("Hello");
std::string str = static_cast<std::string>(wrapper);
const char* cstr = static_cast<const char*>(wrapper);
```

### 4. Совместимость с API
```cpp
class ModernClass {
public:
    explicit operator LegacyClass() const {
        return LegacyClass(modern_value);
    }
    
private:
    int modern_value;
};

// Использование с legacy API
ModernClass modern(42);
LegacyClass legacy = static_cast<LegacyClass>(modern);
legacy_api_function(legacy);
```

## Лучшие практики

### 1. Всегда используйте explicit для преобразующих операторов
```cpp
// ХОРОШО - explicit оператор
class Number {
public:
    explicit operator double() const {
        return static_cast<double>(value);
    }
};

// ПЛОХО - неявное преобразование
class Number {
public:
    operator double() const {
        return static_cast<double>(value);
    }
};
```

### 2. Всегда используйте explicit для конструкторов преобразования
```cpp
// ХОРОШО - explicit конструктор
class Point {
public:
    explicit Point(const Number& n) {
        x = static_cast<double>(n.get_value());
        y = static_cast<double>(n.get_value());
    }
};

// ПЛОХО - неявное преобразование
class Point {
public:
    Point(const Number& n) {
        x = static_cast<double>(n.get_value());
        y = static_cast<double>(n.get_value());
    }
};
```

### 3. Используйте static_cast для явных преобразований
```cpp
// ХОРОШО - явное преобразование
Number n(42);
double d = static_cast<double>(n);

// ПЛОХО - C-style cast
Number n(42);
double d = (double)n;
```

### 4. Предотвращайте потерю информации
```cpp
class SafeInt {
public:
    explicit operator int() const {
        if (value > INT_MAX || value < INT_MIN) {
            throw std::overflow_error("Conversion overflow");
        }
        return static_cast<int>(value);
    }
    
private:
    long long value;
};
```

### 5. Используйте const для преобразующих операторов
```cpp
// ХОРОШО - const оператор
explicit operator double() const {
    return static_cast<double>(value);
}

// ПЛОХО - не-const оператор
explicit operator double() {
    return static_cast<double>(value);
}
```

## Сравнение: явные vs неявные преобразования

### Явные преобразования (explicit)
```cpp
class Number {
public:
    explicit operator double() const {
        return static_cast<double>(value);
    }
};

Number n(42);
double d = static_cast<double>(n);  // Явное преобразование
```

### Неявные преобразования (без explicit)
```cpp
class Number {
public:
    operator double() const {
        return static_cast<double>(value);
    }
};

Number n(42);
double d = n;  // Неявное преобразование
```

## Частые ошибки

### 1. Забывание explicit
```cpp
// ПЛОХО - неявное преобразование
class Number {
public:
    operator double() const {
        return static_cast<double>(value);
    }
};

// Использование
Number n(42);
double d = n;  // Неожиданное неявное преобразование

// ХОРОШО - явное преобразование
class Number {
public:
    explicit operator double() const {
        return static_cast<double>(value);
    }
};

// Использование
Number n(42);
double d = static_cast<double>(n);  // Явное преобразование
```

### 2. Не-const преобразующие операторы
```cpp
// ПЛОХО - не-const оператор
explicit operator double() {
    return static_cast<double>(value);
}

// ХОРОШО - const оператор
explicit operator double() const {
    return static_cast<double>(value);
}
```

### 3. Потеря информации при преобразовании
```cpp
// ПЛОХО - потеря информации
class Fraction {
public:
    explicit operator int() const {
        return numerator / denominator;  // Потеря дробной части
    }
    
private:
    int numerator, denominator;
};

// ХОРОШО - сохранение информации
class Fraction {
public:
    explicit operator double() const {
        return static_cast<double>(numerator) / denominator;
    }
    
private:
    int numerator, denominator;
};
```

### 4. Циклические зависимости
```cpp
// ПЛОХО - циклическая зависимость
#include "number.h"
#include "point.h"

// ХОРОШО - forward declaration
class Number;  // Forward declaration
class Point {
    explicit Point(const Number& n);
};
```

## Связанные концепции
- **Type conversion** - преобразование типов
- **Explicit conversions** - явные преобразования
- **Implicit conversions** - неявные преобразования
- **Conversion operators** - преобразующие операторы
- **Converting constructors** - конструкторы преобразования
- **Static cast** - статическое приведение типов
- **Type safety** - безопасность типов
- **Forward declarations** - предварительные объявления
