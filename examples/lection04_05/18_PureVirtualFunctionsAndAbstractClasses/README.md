# 18_PureVirtualFunctionsAndAbstractClasses

## Описание
Демонстрирует **чистые виртуальные функции и абстрактные классы** в C++. Показывает, как создать абстрактный базовый класс `Shape` с чистыми виртуальными функциями и его конкретные реализации `Circle` и `Rectangle`.

## Классовая диаграмма
```
┌────────────----------─────┐
│      Shape      │ ← АБСТРАКТНЫЙ КЛАСС
├─────────----------────────┤
│ + virtual ~Shape│ ← виртуальный деструктор
│ + virtual perimeter() = 0 │ ← ЧИСТАЯ виртуальная функция
│ + virtual surface() = 0   │ ← ЧИСТАЯ виртуальная функция
│ # Shape(description)      │ ← protected конструктор
│ - m_description           │
└────────────----------─────┘
         ▲
         │ public inheritance
         │
┌────────----------─────────┐
│     Circle      │ ← КОНКРЕТНЫЙ КЛАСС
├──────----------───────────┤
│ + Circle(radius, desc)    │
│ + virtual perimeter()     │ ← реализация чистой виртуальной
│ + virtual surface()       │ ← реализация чистой виртуальной
│ - m_radius                │
│ - static PI               │
└─────────────----------────┘
         ▲
         │ public inheritance
         │
┌───────────----------──────┐
│    Rectangle    │ ← КОНКРЕТНЫЙ КЛАСС
├────────────────----------─┤
│ + Rectangle(w, h, desc)   │
│ + virtual perimeter()     │ ← реализация чистой виртуальной
│ + virtual surface()       │ ← реализация чистой виртуальной
│ - m_width                 │
│ - m_height                │
└─────────----------────────┘
```

## Ключевые концепции

### 1. Чистые виртуальные функции
```cpp
class Shape {
public:
    // Чистые виртуальные функции - делают класс абстрактным
    virtual double perimeter() const = 0;  // = 0 означает "чистая"
    virtual double surface() const = 0;    // = 0 означает "чистая"
};
```

### 2. Абстрактные классы
```cpp
// Shape - абстрактный класс из-за чистых виртуальных функций
// Shape* ptr = new Shape;  // ОШИБКА КОМПИЛЯЦИИ!
// Нельзя создать объект абстрактного класса
```

### 3. Реализация чистых виртуальных функций
```cpp
class Circle : public Shape {
public:
    // ОБЯЗАТЕЛЬНО: переопределить все чистые виртуальные функции
    virtual double perimeter() const override {
        return 2 * PI * m_radius;  // Формула периметра круга
    }
    
    virtual double surface() const override {
        return PI * m_radius * m_radius;  // Формула площади круга
    }
};
```

### 4. Полиморфизм с абстрактными классами
```cpp
// Можно использовать указатели на абстрактный класс
const Shape* shapes[] = {new Rectangle(10, 10, "rect"), 
                         new Circle(10, "circle")};

// Полиморфные вызовы работают
for (auto shape : shapes) {
    std::cout << "Surface: " << shape->surface() << std::endl;
    std::cout << "Perimeter: " << shape->perimeter() << std::endl;
}
```

## Файлы проекта
- `shape.h` / `shape.cpp` - абстрактный базовый класс Shape
- `circle.h` / `circle.cpp` - конкретный класс Circle
- `rectangle.h` / `rectangle.cpp` - конкретный класс Rectangle
- `main.cpp` - демонстрация абстрактных классов и полиморфизма

## Компиляция и запуск
```bash
g++ -std=c++11 -o main main.cpp shape.cpp circle.cpp rectangle.cpp
./main
```

## Ожидаемый вывод
```
=== Демонстрация абстрактных классов ===
--- Создание объектов конкретных классов ---
Dynamic type of rectangle_pointer: 9Rectangle
The surface of rectangle is: 100
--------------
Dynamic type of circle_pointer: 6Circle
The surface of the circle is: 314.159

=== Демонстрация полиморфизма с абстрактными классами ===
--- Полиморфные вызовы через массив ---
Shape 1:
  Type: 9Rectangle
  Surface: 100
  Perimeter: 40

Shape 2:
  Type: 6Circle
  Surface: 314.159
  Perimeter: 62.8319

=== Важные выводы ===
1. Абстрактные классы не могут быть инстанцированы напрямую
2. Чистые виртуальные функции (= 0) ДОЛЖНЫ быть переопределены
3. Полиморфизм работает с указателями на абстрактные классы
4. Абстрактные классы определяют интерфейс для производных классов
5. Виртуальный деструктор обязателен для полиморфных классов

=== Программа завершается ===
```

## Образовательная цель
Понимание концепции абстрактных классов и чистых виртуальных функций, их роли в определении интерфейсов и обеспечении полиморфизма.

## Важные принципы

### 1. Что такое абстрактный класс?
- **Класс с хотя бы одной чистой виртуальной функцией** (= 0)
- **Не может быть инстанцирован напрямую**
- **Предназначен для наследования** и определения интерфейса
- **Служит базой для конкретных классов**

### 2. Чистые виртуальные функции
```cpp
class AbstractBase {
public:
    // Чистая виртуальная функция - ОБЯЗАТЕЛЬНО переопределить
    virtual void pureVirtualFunction() = 0;
    
    // Обычная виртуальная функция - можно переопределить
    virtual void virtualFunction() { /* реализация */ }
    
    // Обычная функция - нельзя переопределить
    void normalFunction() { /* реализация */ }
};
```

### 3. Правила реализации
- **Все чистые виртуальные функции ДОЛЖНЫ быть переопределены** в производных классах
- **Если хотя бы одна чистая виртуальная функция не переопределена**, класс остается абстрактным
- **Производный класс становится конкретным** только после реализации всех чистых виртуальных функций

### 4. Конструкторы и деструкторы
```cpp
class AbstractShape {
protected:
    // PROTECTED конструктор - предотвращает прямое создание
    AbstractShape() = default;
    
public:
    // ВИРТУАЛЬНЫЙ деструктор - ОБЯЗАТЕЛЕН для полиморфных классов
    virtual ~AbstractShape() = default;
};
```

### 5. Преимущества абстрактных классов
- **Определение интерфейса** - четкий контракт для производных классов
- **Принудительная реализация** - гарантия наличия определенных методов
- **Полиморфизм** - единый интерфейс для разных реализаций
- **Расширяемость** - легко добавлять новые типы

## Практические применения

### 1. Определение интерфейсов
```cpp
class Drawable {
public:
    virtual void draw() const = 0;
    virtual void move(int x, int y) = 0;
    virtual ~Drawable() = default;
};

class Circle : public Drawable {
public:
    void draw() const override { /* рисование круга */ }
    void move(int x, int y) override { /* перемещение круга */ }
};
```

### 2. Фабричные паттерны
```cpp
class Animal {
public:
    virtual void makeSound() = 0;
    virtual ~Animal() = default;
};

class AnimalFactory {
public:
    static Animal* createAnimal(const std::string& type);
};
```

### 3. Плагинные системы
```cpp
class Plugin {
public:
    virtual void initialize() = 0;
    virtual void execute() = 0;
    virtual void cleanup() = 0;
    virtual ~Plugin() = default;
};
```

### 4. Итераторы и контейнеры
```cpp
class Iterator {
public:
    virtual bool hasNext() = 0;
    virtual int next() = 0;
    virtual ~Iterator() = default;
};
```

## Лучшие практики

### 1. Используйте protected конструкторы
```cpp
// ХОРОШО - предотвращает прямое создание
class AbstractBase {
protected:
    AbstractBase() = default;
};

// ПЛОХО - позволяет прямое создание (если нет чистых виртуальных функций)
class AbstractBase {
public:
    AbstractBase() = default;
};
```

### 2. Всегда делайте деструктор виртуальным
```cpp
// ХОРОШО - виртуальный деструктор
class AbstractBase {
public:
    virtual ~AbstractBase() = default;
};

// ПЛОХО - невиртуальный деструктор
class AbstractBase {
public:
    ~AbstractBase() = default;  // Проблемы с полиморфизмом
};
```

### 3. Документируйте интерфейс
```cpp
class Shape {
public:
    // Чистая виртуальная функция для вычисления периметра
    // ДОЛЖНА быть реализована в производных классах
    virtual double perimeter() const = 0;
    
    // Чистая виртуальная функция для вычисления площади
    // ДОЛЖНА быть реализована в производных классах
    virtual double surface() const = 0;
};
```

### 4. Используйте override для явности
```cpp
// ХОРОШО - явно показывает переопределение
class Circle : public Shape {
public:
    virtual double perimeter() const override { /* реализация */ }
    virtual double surface() const override { /* реализация */ }
};
```

## Частые ошибки

### 1. Попытка создать объект абстрактного класса
```cpp
// ОШИБКА: Cannot instantiate abstract class
Shape* shape = new Shape;  // Ошибка компиляции!
```

### 2. Неполная реализация чистых виртуальных функций
```cpp
// ОШИБКА: класс остается абстрактным
class IncompleteCircle : public Shape {
public:
    virtual double perimeter() const override { return 0; }
    // Забыли реализовать surface()!
};

// IncompleteCircle* circle = new IncompleteCircle;  // Ошибка!
```

### 3. Невиртуальный деструктор
```cpp
// ОШИБКА: проблемы с полиморфизмом
class AbstractBase {
public:
    ~AbstractBase() = default;  // Должно быть virtual!
};

AbstractBase* ptr = new Derived;
delete ptr;  // Может не вызвать деструктор Derived
```

### 4. Публичный конструктор в абстрактном классе
```cpp
// ПЛОХО: позволяет создание объектов
class AbstractBase {
public:
    AbstractBase() = default;  // Должно быть protected
    virtual void method() = 0;
};

AbstractBase* ptr = new AbstractBase;  // Ошибка компиляции, но лучше предотвратить
```

## Связанные концепции
- **Virtual functions** - виртуальные функции
- **Polymorphism** - полиморфизм
- **Inheritance** - наследование
- **Interfaces** - интерфейсы
- **Pure virtual functions** - чистые виртуальные функции
- **Abstract classes** - абстрактные классы
- **Override** - ключевое слово override
- **Virtual destructors** - виртуальные деструкторы
- **Design patterns** - паттерны проектирования
