# 25_SubscriptOperatorForCollectionTypes

## Описание
Демонстрирует **перегрузку оператора индексации (operator[]) для коллекций с const и не-const версиями** в C++. Показывает, как создать две версии оператора `[]` - одну для чтения и записи (не-const), другую для только чтения (const), что позволяет работать как с обычными, так и с константными объектами.

## Классовая диаграмма
```
┌─────────────────┐
│     Scores      │
├─────────────────┤
│ - Scores() = delete │ ← удаленный конструктор по умолчанию
│ + Scores(name)  │ ← конструктор с параметром
│ + operator[](index)& │ ← ПЕРЕГРУЗКА [] (не-const версия)
│ + operator[](index) const │ ← ПЕРЕГРУЗКА [] (const версия)
│ + print_info()  │ ← метод вывода
│ - m_course_name │ ← название курса
│ - m_scores[20]  │ ← массив оценок
└─────────────────┘
```

## Ключевые концепции

### 1. Двойная перегрузка оператора []
```cpp
class Scores {
public:
    // Не-const версия - для чтения и записи
    double& operator[](size_t index);
    
    // Const версия - только для чтения
    double operator[](size_t index) const;
};

// Использование
Scores math("Math");
const Scores geo("Geography");

math[0] = 73.7;        // Вызывается не-const версия
double grade = geo[0]; // Вызывается const версия
```

### 2. Автоматический выбор версии
```cpp
Scores scores("Math");
const Scores const_scores("Geography");

// Компилятор автоматически выбирает нужную версию
scores[0] = 85.5;           // Не-const версия (возвращает ссылку)
double val = const_scores[0]; // Const версия (возвращает значение)
```

### 3. Возвращаемые типы
```cpp
// Не-const версия - возвращает ссылку
double& operator[](size_t index) {
    return m_scores[index];  // Ссылка для изменения
}

// Const версия - возвращает значение
double operator[](size_t index) const {
    return m_scores[index];  // Копия для чтения
}
```

### 4. Работа с константными объектами
```cpp
const Scores geo("Geography");

// Можно читать
double grade = geo[5];  // OK - вызывается const версия

// Нельзя изменять
// geo[5] = 90.0;       // ОШИБКА КОМПИЛЯЦИИ!
```

## Файлы проекта
- `scores.h` - объявление класса Scores с двумя версиями оператора []
- `scores.cpp` - реализация операторов [] и методов класса
- `main.cpp` - демонстрация работы с const и не-const версиями

## Компиляция и запуск
```bash
g++ -o main main.cpp scores.cpp
./main
```

## Ожидаемый вывод
```
=== Демонстрация оператора [] для коллекций ===
--- Исходное состояние оценок ---
Math : [ 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 ]

--- Заполнение массива оценок через оператор [] ---
Calling non-const operator[] (reference version)
Calling non-const operator[] (reference version)
Calling non-const operator[] (reference version)
...

--- Состояние оценок после заполнения ---
Math : [ 73.7 74.26 74.82 75.38 75.94 76.5 77.06 77.62 78.18 78.74 79.3 79.86 80.42 80.98 81.54 82.1 82.66 83.22 83.78 84.34 ]

------

--- Демонстрация const версии оператора [] ---
Calling const operator[] (value version)
Reading from const object - geo[3]: 0

--- Дополнительные примеры использования ---
Reading from non-const object:
Calling non-const operator[] (reference version)
Reading from const object:
Calling const operator[] (value version)
Math grade[5]: 76.5
Geography grade[5]: 0

--- Демонстрация записи через не-const версию ---
Modifying grade through non-const operator[]:
Calling non-const operator[] (reference version)
Modified math_scores[10]: 95.5

=== Важные выводы ===
1. Две версии оператора []: const и не-const
2. Не-const версия возвращает ссылку для записи
3. Const версия возвращает значение для только чтения
4. Константные объекты могут вызывать только const версии
5. Компилятор автоматически выбирает нужную версию

=== Преимущества двойной перегрузки ===
1. Безопасность - const объекты защищены от изменения
2. Эффективность - const версия может быть оптимизирована
3. Гибкость - работа как с изменяемыми, так и с константными объектами
4. Совместимость с STL - стандартные контейнеры используют тот же подход

=== Программа завершается ===
```

## Образовательная цель
Понимание двойной перегрузки оператора [] для коллекций, автоматического выбора версии компилятором и работы с константными объектами.

## Важные принципы

### 1. Синтаксис двойной перегрузки
```cpp
class MyContainer {
public:
    // Не-const версия - для изменения
    ElementType& operator[](size_t index);
    
    // Const версия - для только чтения
    ElementType operator[](size_t index) const;
};
```

### 2. Правила выбора версии
```cpp
MyContainer container;
const MyContainer const_container;

// Автоматический выбор компилятором
container[0] = value;        // Не-const версия (для записи)
ElementType val = container[0];    // Не-const версия (для чтения)
ElementType val2 = const_container[0]; // Const версия (только чтение)
```

### 3. Возвращаемые типы
```cpp
// Не-const версия - возвращает ссылку
int& operator[](size_t index) {
    return m_data[index];  // Возвращает ссылку для изменения
}

// Const версия - возвращает значение
int operator[](size_t index) const {
    return m_data[index];  // Возвращает копию для чтения
}
```

### 4. Константная корректность
```cpp
const MyContainer container;

// Можно
int value = container[0];  // Вызывается const версия

// Нельзя
// container[0] = 42;      // ОШИБКА! Const объект нельзя изменять
```

### 5. Проверка границ
```cpp
int& operator[](size_t index) {
    assert(index < size);  // Проверка границ
    return m_data[index];
}

int operator[](size_t index) const {
    assert(index < size);  // Та же проверка в const версии
    return m_data[index];
}
```

## Практические применения

### 1. Стандартные контейнеры
```cpp
std::vector<int> vec(10);
const std::vector<int> const_vec(10);

vec[0] = 42;           // Не-const версия
int val = const_vec[0]; // Const версия
```

### 2. Кастомные массивы
```cpp
class SafeArray {
public:
    int& operator[](size_t index) {
        if (index >= size) throw std::out_of_range("Index out of range");
        return m_data[index];
    }
    
    int operator[](size_t index) const {
        if (index >= size) throw std::out_of_range("Index out of range");
        return m_data[index];
    }
};
```

### 3. Матрицы
```cpp
class Matrix {
public:
    double& operator[](size_t index) {
        return m_data[index];
    }
    
    double operator[](size_t index) const {
        return m_data[index];
    }
};
```

### 4. Строковые буферы
```cpp
class StringBuffer {
public:
    char& operator[](size_t index) {
        return m_buffer[index];
    }
    
    char operator[](size_t index) const {
        return m_buffer[index];
    }
};
```

## Лучшие практики

### 1. Всегда предоставляйте обе версии
```cpp
// ХОРОШО - обе версии
class MyClass {
public:
    int& operator[](size_t index);
    int operator[](size_t index) const;
};

// ПЛОХО - только одна версия
class MyClass {
public:
    int& operator[](size_t index);  // Нет const версии
};
```

### 2. Используйте одинаковую логику
```cpp
// ХОРОШО - одинаковая логика в обеих версиях
int& operator[](size_t index) {
    assert(index < size);
    return m_data[index];
}

int operator[](size_t index) const {
    assert(index < size);  // Та же проверка
    return m_data[index];
}
```

### 3. Документируйте различия
```cpp
class MyClass {
public:
    // Возвращает ссылку для изменения элемента
    int& operator[](size_t index);
    
    // Возвращает копию для только чтения
    int operator[](size_t index) const;
};
```

### 4. Используйте подходящие типы возврата
```cpp
// ХОРОШО - ссылка для изменения, значение для чтения
int& operator[](size_t index);
int operator[](size_t index) const;

// ПЛОХО - обе версии возвращают ссылку
int& operator[](size_t index);
int& operator[](size_t index) const;  // Const версия тоже возвращает ссылку
```

## Сравнение: Одна vs Две версии

### Одна версия (только не-const)
```cpp
class MyClass {
public:
    int& operator[](size_t index);
};

MyClass obj;
const MyClass const_obj;

obj[0] = 42;        // OK
int val = obj[0];   // OK
// int val2 = const_obj[0]; // ОШИБКА! Const объект не может вызвать не-const метод
```

### Две версии (const и не-const)
```cpp
class MyClass {
public:
    int& operator[](size_t index);
    int operator[](size_t index) const;
};

MyClass obj;
const MyClass const_obj;

obj[0] = 42;           // OK - не-const версия
int val = obj[0];      // OK - не-const версия
int val2 = const_obj[0]; // OK - const версия
```

## Частые ошибки

### 1. Отсутствие const версии
```cpp
// ПЛОХО - нет const версии
class MyClass {
public:
    int& operator[](size_t index);
};

const MyClass obj;
// int val = obj[0];  // ОШИБКА! Не может вызвать не-const метод

// ХОРОШО - есть const версия
class MyClass {
public:
    int& operator[](size_t index);
    int operator[](size_t index) const;
};
```

### 2. Неправильный возвращаемый тип в const версии
```cpp
// ПЛОХО - const версия возвращает ссылку
int& operator[](size_t index) const {
    return m_data[index];  // ОШИБКА! Const метод не может вернуть не-const ссылку
}

// ХОРОШО - const версия возвращает значение
int operator[](size_t index) const {
    return m_data[index];
}
```

### 3. Разная логика в версиях
```cpp
// ПЛОХО - разная логика
int& operator[](size_t index) {
    assert(index < size);
    return m_data[index];
}

int operator[](size_t index) const {
    return m_data[index];  // Нет проверки границ!
}

// ХОРОШО - одинаковая логика
int& operator[](size_t index) {
    assert(index < size);
    return m_data[index];
}

int operator[](size_t index) const {
    assert(index < size);  // Та же проверка
    return m_data[index];
}
```

### 4. Отсутствие проверки границ
```cpp
// ПЛОХО - нет проверки границ
int& operator[](size_t index) {
    return m_data[index];  // Опасность выхода за границы
}

// ХОРОШО - есть проверка границ
int& operator[](size_t index) {
    assert(index < size);
    return m_data[index];
}
```

## Связанные концепции
- **Operator overloading** - перегрузка операторов
- **Const methods** - константные методы
- **Function overloading** - перегрузка функций
- **Const correctness** - константная корректность
- **Collections** - коллекции
- **Container interface** - интерфейс контейнеров
- **Automatic version selection** - автоматический выбор версии
- **STL compatibility** - совместимость со STL
