# 12_InheritanceAndPolymorphismWithStaticMembers

## Описание
Демонстрирует поведение **статических членов в наследовании** и их взаимодействие с **полиморфизмом**. Показывает, что статические члены НЕ наследуются и каждый класс имеет свой независимый экземпляр.

## Классовая диаграмма
```
┌─────────────────┐
│      Shape      │
├─────────────────┤
│ + virtual get_count() │ ← виртуальная функция
│ + virtual ~Shape      │ ← виртуальный деструктор
│ + static m_count      │ ← статический член Shape
│ # m_description       │
└─────────────────┘
         ▲
         │ public inheritance
         │
┌─────────────────┐
│     Ellipse     │
├─────────────────┤
│ + virtual get_count() │ ← override (возвращает Ellipse::m_count)
│ + static m_count      │ ← СВОЙ статический член (не Shape::m_count!)
│ - m_x_radius          │
│ - m_y_radius          │
└─────────────────┘
```

## Ключевые концепции

### 1. Статические члены НЕ наследуются
```cpp
class Shape {
public:
    static int m_count;  // Shape::m_count
};

class Ellipse : public Shape {
public:
    static int m_count;  // Ellipse::m_count - это ДРУГОЙ счетчик!
};
```

### 2. Независимые счетчики объектов
```cpp
// Создание объектов Shape
Shape shape1("shape1");  // Shape::m_count = 1
Shape shape2("shape2");  // Shape::m_count = 2

// Создание объекта Ellipse
Ellipse ellipse1(10, 12, "ellipse1");
// Shape::m_count = 3 (вызвался конструктор Shape)
// Ellipse::m_count = 1 (вызвался конструктор Ellipse)
```

### 3. Полиморфизм с виртуальными функциями
```cpp
Shape* shapes[]{&shape1, &ellipse1};

for (auto& shape_ptr : shapes) {
    // Полиморфный вызов get_count()
    // Shape::get_count() возвращает Shape::m_count
    // Ellipse::get_count() возвращает Ellipse::m_count
    std::cout << shape_ptr->get_count() << std::endl;
}
```

### 4. Двойное управление счетчиками
```cpp
// При создании Ellipse:
Ellipse::Ellipse(...) : Shape(...) {
    ++m_count;  // Увеличивает Ellipse::m_count
    // Shape::Shape() уже увеличил Shape::m_count
}

// При уничтожении Ellipse:
Ellipse::~Ellipse() {
    --m_count;  // Уменьшает Ellipse::m_count
    // Shape::~Shape() уменьшит Shape::m_count
}
```

## Файлы проекта
- `shape.h` / `shape.cpp` - базовый класс Shape со статическим счетчиком
- `ellipse.h` / `ellipse.cpp` - класс Ellipse с собственным статическим счетчиком
- `main.cpp` - демонстрация независимости статических членов и полиморфизма

## Компиляция и запуск
```bash
g++ -std=c++11 -o main main.cpp shape.cpp ellipse.cpp
./main
```

## Ожидаемый вывод
```
=== Создание объектов Shape ===
Shape count: 1
Shape count: 2
Shape count: 3
***********************************************
=== Создание объекта Ellipse ===
Shape count: 4
Ellipse count: 1
***********************************************
=== Демонстрация полиморфизма со статическими членами ===
--- Полиморфные вызовы get_count() ---
Count from polymorphic call: 3
Count from polymorphic call: 1
***********************************************
=== Важные выводы ===
1. Статические члены НЕ наследуются - каждый класс имеет свой
2. При создании Ellipse увеличиваются ОБА счетчика
3. Виртуальная функция get_count() возвращает 'свой' счетчик
4. Полиморфизм работает с виртуальными функциями, но статические члены независимы

=== Программа завершается ===
```

## Образовательная цель
Понимание того, что статические члены НЕ наследуются в C++, и каждый класс в иерархии имеет свой независимый экземпляр статического члена.

## Важные принципы

### 1. Статические члены не наследуются
- **Каждый класс** в иерархии наследования имеет **свой собственный** статический член
- **Shape::m_count** и **Ellipse::m_count** - это **разные переменные**
- **Нет общего** статического члена для всей иерархии

### 2. Инициализация статических членов
```cpp
// В заголовочном файле - только объявление
class Shape {
public:
    static int m_count;  // Объявление
};

// В .cpp файле - определение и инициализация
int Shape::m_count{0};   // Определение и инициализация

class Ellipse : public Shape {
public:
    static int m_count;  // Объявление СВОЕГО счетчика
};

int Ellipse::m_count{0}; // Определение и инициализация СВОЕГО счетчика
```

### 3. Управление счетчиками в конструкторах и деструкторах
```cpp
// При создании объекта Ellipse:
// 1. Вызывается Shape::Shape() - увеличивает Shape::m_count
// 2. Вызывается Ellipse::Ellipse() - увеличивает Ellipse::m_count

// При уничтожении объекта Ellipse:
// 1. Вызывается Ellipse::~Ellipse() - уменьшает Ellipse::m_count
// 2. Вызывается Shape::~Shape() - уменьшает Shape::m_count
```

### 4. Полиморфизм с виртуальными функциями
```cpp
// Виртуальная функция позволяет вернуть "правильный" счетчик
class Shape {
public:
    virtual int get_count() const {
        return m_count;  // Возвращает Shape::m_count
    }
};

class Ellipse : public Shape {
public:
    virtual int get_count() const override {
        return m_count;  // Возвращает Ellipse::m_count
    }
};

// Полиморфный вызов
Shape* ptr = new Ellipse();
int count = ptr->get_count();  // Возвращает Ellipse::m_count!
```

### 5. Отличие от обычных членов
```cpp
class Shape {
protected:
    std::string m_description;  // Наследуется - один экземпляр в каждом объекте
public:
    static int m_count;         // НЕ наследуется - отдельная переменная для каждого класса
};
```

## Практические применения
- **Подсчет объектов** каждого типа в иерархии
- **Статистика использования** различных классов
- **Мониторинг производительности** по типам объектов
- **Отладка** - отслеживание создания/уничтожения объектов

## Лучшие практики

### 1. Всегда инициализируйте статические члены
```cpp
// ХОРОШО
static int m_count{0};  // Явная инициализация

// ПЛОХО
static int m_count;     // Неопределенное поведение
```

### 2. Используйте виртуальные функции для доступа к статическим членам
```cpp
// ХОРОШО - полиморфный доступ
virtual int get_count() const override {
    return m_count;
}

// ПЛОХО - прямой доступ без полиморфизма
int get_static_count() const {
    return m_count;  // Не работает полиморфно
}
```

### 3. Документируйте независимость статических членов
```cpp
class Ellipse : public Shape {
public:
    // СОБСТВЕННЫЙ статический член - НЕ наследуется от Shape!
    static int m_count;
};
```

### 4. Используйте квалифицированные имена для ясности
```cpp
// Явно указывайте, какой счетчик используется
std::cout << "Shape count: " << Shape::m_count << std::endl;
std::cout << "Ellipse count: " << Ellipse::m_count << std::endl;
```

## Частые ошибки

### 1. Предположение о наследовании статических членов
```cpp
// ОШИБКА: Думать, что Ellipse::m_count наследует Shape::m_count
Ellipse ellipse1, ellipse2;
// Shape::m_count = 2, Ellipse::m_count = 2
// НО это два РАЗНЫХ счетчика!
```

### 2. Забывание инициализации статических членов
```cpp
// ОШИБКА: Не инициализировать статический член
class Shape {
public:
    static int m_count;  // Объявлен, но не определен!
};
```

### 3. Смешивание доступа к статическим членам
```cpp
// ОШИБКА: Прямой доступ без учета полиморфизма
Shape* ptr = new Ellipse();
int count = ptr->m_count;  // Всегда Shape::m_count, даже для Ellipse!
```

## Связанные концепции
- **Static members** - основы статических членов класса
- **Inheritance** - наследование в C++
- **Polymorphism** - полиморфизм с виртуальными функциями
- **Virtual functions** - виртуальные функции
- **Constructors and destructors** - конструкторы и деструкторы в наследовании
