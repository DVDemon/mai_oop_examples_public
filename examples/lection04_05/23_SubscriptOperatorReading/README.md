# 23_SubscriptOperatorReading

## Описание
Демонстрирует **перегрузку оператора индексации (operator[]) для чтения** в C++. Показывает, как перегрузить оператор `[]` как const метод для доступа к координатам точки по индексу, обеспечивая безопасность только для чтения.

## Классовая диаграмма
```
┌─────────────────┐
│      Point      │
├─────────────────┤
│ + Point()       │ ← конструктор по умолчанию
│ + Point(x, y)   │ ← конструктор с параметрами
│ + ~Point()      │ ← деструктор
│ + operator[](index) const │ ← ПЕРЕГРУЖЕННЫЙ ОПЕРАТОР [] (только чтение)
│ + print_info()  │ ← метод вывода
│ - length()      │ ← приватный метод
│ - m_x           │ ← координата X (индекс 0)
│ - m_y           │ ← координата Y (индекс 1)
└─────────────────┘
```

## Ключевые концепции

### 1. Перегрузка оператора [] для чтения
```cpp
class Point {
public:
    // Const метод - только для чтения
    double operator[](size_t index) const {
        assert((index == 0) || (index == 1));
        if (index == 0) return m_x;  // X координата
        else return m_y;             // Y координата
    }
};

// Использование
Point p(10, 20);
double x = p[0];  // X координата: 10
double y = p[1];  // Y координата: 20
```

### 2. Const методы
```cpp
// Const метод НЕ МОЖЕТ изменять объект
double operator[](size_t index) const {
    // Только чтение данных
    return m_x;  // OK
    // m_x = 5;  // ОШИБКА! Нельзя изменять в const методе
}
```

### 3. Синтаксис вызова
```cpp
Point p(10, 20);

// Инфиксная запись (естественная)
double x = p[0];

// Эквивалентная запись через метод
double x = p.operator[](0);
```

### 4. Проверка индекса
```cpp
double operator[](size_t index) const {
    // Assert проверяет корректность индекса
    assert((index == 0) || (index == 1));
    // При неверном индексе программа завершится с ошибкой
}
```

## Файлы проекта
- `point.h` - объявление класса Point с перегруженным оператором []
- `point.cpp` - реализация методов класса Point
- `main.cpp` - демонстрация использования оператора []

## Компиляция и запуск
```bash
g++ -o main main.cpp point.cpp
./main
```

## Ожидаемый вывод
```
=== Демонстрация перегрузки оператора [] для чтения ===
--- Создание точки ---
Point object: Point [ x: 10, y: 20]

--- Доступ к координатам через оператор [] ---
point_object[0] (X coordinate): 10
point_object[1] (Y coordinate): 20

--- Дополнительные примеры использования ---
X coordinate extracted: 10
Y coordinate extracted: 20
Sum of coordinates: 30

=== Важные выводы ===
1. Оператор [] перегружается как const метод для чтения
2. Синтаксис: object[index] эквивалентен object.operator[](index)
3. Const метод НЕ МОЖЕТ изменять объект, только читать
4. Assert проверяет корректность индекса
5. Индекс 0 = X координата, индекс 1 = Y координата

=== Преимущества оператора [] ===
1. Естественный синтаксис доступа к элементам
2. Возможность использования в циклах и алгоритмах
3. Унифицированный интерфейс для контейнеров
4. Проверка корректности индекса через assert

=== Программа завершается ===
```

## Образовательная цель
Понимание перегрузки оператора индексации для чтения, const методов и проверки корректности индексов.

## Важные принципы

### 1. Синтаксис перегрузки operator[]
```cpp
class MyClass {
public:
    // Для чтения (const метод)
    ReturnType operator[](size_t index) const;
    
    // Для записи (не-const метод)
    ReturnType& operator[](size_t index);
};
```

### 2. Const методы
```cpp
class Point {
public:
    // Const метод - только чтение
    double operator[](size_t index) const {
        return m_data[index];  // OK - чтение
        // m_data[index] = 5;  // ОШИБКА - изменение
    }
    
    // Не-const метод - может изменять
    double& operator[](size_t index) {
        return m_data[index];  // Возвращает ссылку для изменения
    }
};
```

### 3. Проверка индексов
```cpp
// Использование assert
double operator[](size_t index) const {
    assert(index < size);  // Проверка границ
    return m_data[index];
}

// Использование исключений
double operator[](size_t index) const {
    if (index >= size) {
        throw std::out_of_range("Index out of range");
    }
    return m_data[index];
}
```

### 4. Типы индексов
```cpp
class Point {
public:
    // size_t - беззнаковый тип
    double operator[](size_t index) const;
    
    // int - знаковый тип
    double operator[](int index) const;
    
    // enum - типобезопасные индексы
    enum Index { X = 0, Y = 1 };
    double operator[](Index index) const;
};
```

### 5. Возвращаемые типы
```cpp
class MyClass {
public:
    // Возврат по значению (только чтение)
    double operator[](size_t index) const;
    
    // Возврат по ссылке (чтение и запись)
    double& operator[](size_t index);
    
    // Возврат по константной ссылке (только чтение, эффективно)
    const double& operator[](size_t index) const;
};
```

## Практические применения

### 1. Математические векторы
```cpp
class Vector3D {
public:
    double operator[](size_t index) const {
        assert(index < 3);
        return m_coords[index];
    }
    
private:
    double m_coords[3];  // x, y, z
};

Vector3D v(1, 2, 3);
double x = v[0];  // x = 1
double y = v[1];  // y = 2
double z = v[2];  // z = 3
```

### 2. Матрицы
```cpp
class Matrix {
public:
    double operator[](size_t index) const {
        assert(index < rows * cols);
        return m_data[index];
    }
    
private:
    double* m_data;
    size_t rows, cols;
};
```

### 3. Кастомные контейнеры
```cpp
class MyArray {
public:
    int operator[](size_t index) const {
        assert(index < m_size);
        return m_data[index];
    }
    
private:
    int* m_data;
    size_t m_size;
};
```

### 4. Геометрические объекты
```cpp
class Triangle {
public:
    Point operator[](size_t index) const {
        assert(index < 3);
        return m_vertices[index];
    }
    
private:
    Point m_vertices[3];
};
```

## Лучшие практики

### 1. Используйте const методы для чтения
```cpp
// ХОРОШО - const метод для чтения
double operator[](size_t index) const {
    assert(index < size);
    return m_data[index];
}

// ПЛОХО - не-const метод для чтения
double operator[](size_t index) {
    assert(index < size);
    return m_data[index];  // Позволяет изменение
}
```

### 2. Проверяйте индексы
```cpp
// ХОРОШО - проверка индекса
double operator[](size_t index) const {
    assert(index < size);
    return m_data[index];
}

// ПЛОХО - отсутствие проверки
double operator[](size_t index) const {
    return m_data[index];  // Может привести к ошибкам
}
```

### 3. Документируйте семантику индексов
```cpp
class Point {
public:
    // Индекс 0 = X координата, индекс 1 = Y координата
    double operator[](size_t index) const {
        assert((index == 0) || (index == 1));
        return (index == 0) ? m_x : m_y;
    }
};
```

### 4. Используйте подходящие типы индексов
```cpp
// ХОРОШО - size_t для беззнаковых индексов
double operator[](size_t index) const;

// ХОРОШО - enum для типобезопасности
enum Coord { X = 0, Y = 1 };
double operator[](Coord coord) const;
```

## Сравнение: Только чтение vs Чтение и запись

### Только чтение (const метод)
```cpp
class Point {
public:
    double operator[](size_t index) const {
        assert((index == 0) || (index == 1));
        return (index == 0) ? m_x : m_y;
    }
};

Point p(10, 20);
double x = p[0];  // OK - чтение
// p[0] = 5;      // ОШИБКА - нельзя изменить
```

### Чтение и запись (не-const метод)
```cpp
class Point {
public:
    double& operator[](size_t index) {
        assert((index == 0) || (index == 1));
        return (index == 0) ? m_x : m_y;
    }
};

Point p(10, 20);
double x = p[0];  // OK - чтение
p[0] = 5;         // OK - запись
```

## Частые ошибки

### 1. Отсутствие const для чтения
```cpp
// ПЛОХО - не-const метод для чтения
double operator[](size_t index) {
    return m_data[index];  // Позволяет изменение
}

// ХОРОШО - const метод для чтения
double operator[](size_t index) const {
    return m_data[index];  // Только чтение
}
```

### 2. Отсутствие проверки индексов
```cpp
// ПЛОХО - отсутствие проверки
double operator[](size_t index) const {
    return m_data[index];  // Опасность выхода за границы
}

// ХОРОШО - проверка индекса
double operator[](size_t index) const {
    assert(index < size);
    return m_data[index];
}
```

### 3. Неправильный возвращаемый тип
```cpp
// ПЛОХО - возврат по значению для больших объектов
Point operator[](size_t index) const {
    return m_vertices[index];  // Копирование объекта
}

// ХОРОШО - возврат по константной ссылке
const Point& operator[](size_t index) const {
    return m_vertices[index];  // Без копирования
}
```

### 4. Неясная семантика индексов
```cpp
// ПЛОХО - неясная семантика
double operator[](size_t index) const {
    return m_data[index];  // Что означает индекс?
}

// ХОРОШО - ясная семантика
double operator[](size_t index) const {
    assert((index == 0) || (index == 1));
    // 0 = X координата, 1 = Y координата
    return (index == 0) ? m_x : m_y;
}
```

## Связанные концепции
- **Operator overloading** - перегрузка операторов
- **Const methods** - константные методы
- **Indexing** - индексирование
- **Assert** - проверка утверждений
- **Array access** - доступ к массивам
- **Container interface** - интерфейс контейнеров
- **Bounds checking** - проверка границ
- **Read-only access** - доступ только для чтения
