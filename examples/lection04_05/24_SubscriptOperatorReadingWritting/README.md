# 24_SubscriptOperatorReadingWritting

## Описание
Демонстрирует **перегрузку оператора индексации (operator[]) для чтения и записи** в C++. Показывает, как перегрузить оператор `[]` как не-const метод, возвращающий ссылку, что позволяет как читать, так и изменять координаты точки по индексу.

## Классовая диаграмма
```
┌─────────────────┐
│      Point      │
├─────────────────┤
│ + Point()       │ ← конструктор по умолчанию
│ + Point(x, y)   │ ← конструктор с параметрами
│ + ~Point()      │ ← деструктор
│ + operator[](index)& │ ← ПЕРЕГРУЖЕННЫЙ ОПЕРАТОР [] (чтение и запись)
│ + print_info()  │ ← метод вывода
│ - length()      │ ← приватный метод
│ - m_x           │ ← координата X (индекс 0)
│ - m_y           │ ← координата Y (индекс 1)
└─────────────────┘
```

## Ключевые концепции

### 1. Перегрузка оператора [] для чтения и записи
```cpp
class Point {
public:
    // Возвращает ссылку - позволяет изменять
    double& operator[](size_t index) {
        assert((index == 0) || (index == 1));
        return (index == 0) ? m_x : m_y;
    }
};

// Использование
Point p(10, 20);
p[0] = 35.6;        // Запись - изменение X координаты
double x = p[0];    // Чтение - получение X координаты
p[1] += 5.0;        // Изменение через оператор +=
```

### 2. Возврат ссылки
```cpp
// Возврат ССЫЛКИ позволяет изменять объект
double& operator[](size_t index) {
    return m_data[index];  // Возвращает ссылку на элемент
}

// Использование
object[0] = 42;     // Изменяет m_data[0]
object[1] += 10;    // Изменяет m_data[1]
```

### 3. Не-const методы
```cpp
// НЕ const метод - МОЖЕТ изменять объект
double& operator[](size_t index) {
    // Может изменять поля объекта
    return m_x;  // OK - возвращает ссылку для изменения
}
```

### 4. Операторы присваивания
```cpp
Point p(10, 20);

// Прямое присваивание
p[0] = 35.6;

// Составные операторы присваивания
p[0] += 5.0;   // p[0] = p[0] + 5.0
p[1] -= 3.0;   // p[1] = p[1] - 3.0
p[0] *= 2.0;   // p[0] = p[0] * 2.0
p[1] /= 4.0;   // p[1] = p[1] / 4.0
```

## Файлы проекта
- `point.h` - объявление класса Point с перегруженным оператором []
- `point.cpp` - реализация методов класса Point
- `main.cpp` - демонстрация использования оператора [] для чтения и записи

## Компиляция и запуск
```bash
g++ -o main main.cpp point.cpp
./main
```

## Ожидаемый вывод
```
=== Демонстрация перегрузки оператора [] для чтения и записи ===
--- Исходное состояние точки ---
Initial point: Point [ x: 10, y: 20]

--- Демонстрация чтения через оператор [] ---
Reading X coordinate: point_object[0] = 10
Reading Y coordinate: point_object[1] = 20

--- Демонстрация записи через оператор [] ---
Changing X coordinate: point_object[0] = 35.6
Changing Y coordinate: point_object[1] = 23.9

--- Состояние точки после изменения ---
Modified point: Point [ x: 35.6, y: 23.9]

--- Дополнительные примеры использования ---
Sum of coordinates before modification: 59.5
Incrementing X coordinate by 1...
Incrementing Y coordinate by 2...
Point after increment: Point [ x: 36.6, y: 25.9]
Y coordinate is greater than or equal to X coordinate

=== Важные выводы ===
1. Оператор [] возвращает ССЫЛКУ для чтения и записи
2. НЕ const метод - МОЖЕТ изменять объект
3. Синтаксис: object[index] = value (запись)
4. Синтаксис: value = object[index] (чтение)
5. Assert проверяет корректность индекса

=== Преимущества оператора [] для записи ===
1. Естественный синтаксис изменения элементов
2. Возможность использования в выражениях
3. Поддержка операторов присваивания (+=, -=, *=, /=)
4. Интеграция с алгоритмами STL

=== Программа завершается ===
```

## Образовательная цель
Понимание перегрузки оператора индексации для чтения и записи, возврата ссылок и не-const методов.

## Важные принципы

### 1. Синтаксис перегрузки operator[] для записи
```cpp
class MyClass {
public:
    // Для чтения и записи (возврат ссылки)
    ReturnType& operator[](size_t index);
    
    // Для только чтения (возврат значения)
    ReturnType operator[](size_t index) const;
};
```

### 2. Возврат ссылки vs значения
```cpp
class Point {
public:
    // Возврат ссылки - позволяет изменять
    double& operator[](size_t index) {
        return m_data[index];  // Возвращает ссылку
    }
    
    // Возврат значения - только чтение
    double operator[](size_t index) const {
        return m_data[index];  // Возвращает копию
    }
};
```

### 3. Const vs не-const методы
```cpp
class Point {
public:
    // НЕ const метод - может изменять объект
    double& operator[](size_t index) {
        // Может изменять поля
        return m_data[index];
    }
    
    // Const метод - не может изменять объект
    double operator[](size_t index) const {
        // Только чтение
        return m_data[index];
    }
};
```

### 4. Операторы присваивания
```cpp
Point p(10, 20);

// Прямое присваивание
p[0] = 35.6;

// Составные операторы
p[0] += 5.0;   // Эквивалентно: p[0] = p[0] + 5.0
p[1] -= 3.0;   // Эквивалентно: p[1] = p[1] - 3.0
p[0] *= 2.0;   // Эквивалентно: p[0] = p[0] * 2.0
p[1] /= 4.0;   // Эквивалентно: p[1] = p[1] / 4.0

// Инкремент и декремент
++p[0];        // Префиксный инкремент
p[1]++;        // Постфиксный инкремент
--p[0];        // Префиксный декремент
p[1]--;        // Постфиксный декремент
```

### 5. Проверка индексов
```cpp
double& operator[](size_t index) {
    // Assert для проверки корректности индекса
    assert((index == 0) || (index == 1));
    
    // Или с исключениями
    if (index >= 2) {
        throw std::out_of_range("Index out of range");
    }
    
    return m_data[index];
}
```

## Практические применения

### 1. Математические векторы
```cpp
class Vector3D {
public:
    double& operator[](size_t index) {
        assert(index < 3);
        return m_coords[index];
    }
    
private:
    double m_coords[3];  // x, y, z
};

Vector3D v(1, 2, 3);
v[0] = 10;      // Изменить X координату
v[1] += 5;      // Увеличить Y координату на 5
double z = v[2]; // Прочитать Z координату
```

### 2. Динамические массивы
```cpp
class MyArray {
public:
    int& operator[](size_t index) {
        assert(index < m_size);
        return m_data[index];
    }
    
private:
    int* m_data;
    size_t m_size;
};

MyArray arr(10);
arr[0] = 42;    // Установить первый элемент
arr[5] += 10;   // Увеличить шестой элемент
int val = arr[3]; // Прочитать четвертый элемент
```

### 3. Матрицы
```cpp
class Matrix {
public:
    double& operator[](size_t index) {
        assert(index < rows * cols);
        return m_data[index];
    }
    
private:
    double* m_data;
    size_t rows, cols;
};

Matrix m(3, 4);  // 3x4 матрица
m[0] = 1.0;      // Установить элемент (0,0)
m[5] += 2.0;     // Увеличить элемент (1,1)
```

### 4. Контейнеры с проверкой
```cpp
class SafeArray {
public:
    int& operator[](size_t index) {
        if (index >= m_size) {
            throw std::out_of_range("Index out of range");
        }
        return m_data[index];
    }
    
private:
    int* m_data;
    size_t m_size;
};
```

## Лучшие практики

### 1. Возвращайте ссылку для записи
```cpp
// ХОРОШО - возврат ссылки для изменения
double& operator[](size_t index) {
    assert(index < size);
    return m_data[index];
}

// ПЛОХО - возврат значения не позволяет изменять
double operator[](size_t index) {
    assert(index < size);
    return m_data[index];  // Копия, изменения не сохранятся
}
```

### 2. Используйте не-const методы для записи
```cpp
// ХОРОШО - не-const метод для изменения
double& operator[](size_t index) {
    return m_data[index];
}

// ПЛОХО - const метод не может изменять
double& operator[](size_t index) const {
    return m_data[index];  // ОШИБКА КОМПИЛЯЦИИ!
}
```

### 3. Проверяйте индексы
```cpp
// ХОРОШО - проверка индекса
double& operator[](size_t index) {
    assert(index < size);
    return m_data[index];
}

// ПЛОХО - отсутствие проверки
double& operator[](size_t index) {
    return m_data[index];  // Опасность выхода за границы
}
```

### 4. Предоставляйте const версию для чтения
```cpp
class Point {
public:
    // Для чтения и записи
    double& operator[](size_t index) {
        assert((index == 0) || (index == 1));
        return (index == 0) ? m_x : m_y;
    }
    
    // Для только чтения
    double operator[](size_t index) const {
        assert((index == 0) || (index == 1));
        return (index == 0) ? m_x : m_y;
    }
};
```

## Сравнение: Чтение vs Чтение и запись

### Только чтение (const метод)
```cpp
class Point {
public:
    double operator[](size_t index) const {
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
        return (index == 0) ? m_x : m_y;
    }
};

Point p(10, 20);
double x = p[0];  // OK - чтение
p[0] = 5;         // OK - запись
p[1] += 10;       // OK - изменение через +=
```

## Частые ошибки

### 1. Возврат значения вместо ссылки
```cpp
// ПЛОХО - возврат значения
double operator[](size_t index) {
    return m_data[index];  // Копия, изменения не сохранятся
}

// ХОРОШО - возврат ссылки
double& operator[](size_t index) {
    return m_data[index];  // Ссылка, изменения сохраняются
}
```

### 2. Const метод для записи
```cpp
// ПЛОХО - const метод не может изменять
double& operator[](size_t index) const {
    return m_data[index];  // ОШИБКА КОМПИЛЯЦИИ!
}

// ХОРОШО - не-const метод
double& operator[](size_t index) {
    return m_data[index];
}
```

### 3. Отсутствие проверки индексов
```cpp
// ПЛОХО - отсутствие проверки
double& operator[](size_t index) {
    return m_data[index];  // Опасность выхода за границы
}

// ХОРОШО - проверка индекса
double& operator[](size_t index) {
    assert(index < size);
    return m_data[index];
}
```

### 4. Возврат ссылки на локальную переменную
```cpp
// ПЛОХО - ссылка на локальную переменную
double& operator[](size_t index) {
    double local = m_data[index];
    return local;  // ОШИБКА! local уничтожается при выходе
}

// ХОРОШО - ссылка на член класса
double& operator[](size_t index) {
    return m_data[index];
}
```

## Связанные концепции
- **Operator overloading** - перегрузка операторов
- **References** - ссылки
- **Const methods** - константные методы
- **Indexing** - индексирование
- **Assignment operators** - операторы присваивания
- **Array access** - доступ к массивам
- **Container interface** - интерфейс контейнеров
- **Mutable access** - изменяемый доступ
