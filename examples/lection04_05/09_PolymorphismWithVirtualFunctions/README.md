# 09_PolymorphismWithVirtualFunctions

## Описание
Демонстрирует **полиморфизм с виртуальными функциями** - одну из ключевых концепций объектно-ориентированного программирования в C++.

## Классовая диаграмма
```
┌─────────────────┐
│      Shape      │
├─────────────────┤
│ + virtual draw()│ ← виртуальная функция
│ + virtual ~Shape│ ← виртуальный деструктор
│ # m_description │
└─────────────────┘
         ▲
         │ public inheritance
         │
┌─────────────────┐
│      Oval       │
├─────────────────┤
│ + virtual draw()│ ← переопределение
│ + get_x_rad()   │
│ + get_y_rad()   │
│ - m_x_radius    │
│ - m_y_radius    │
└─────────────────┘
         ▲
         │ public inheritance
         │
┌─────────────────┐
│     Circle      │
├─────────────────┤
│ + virtual draw()│ ← переопределение
└─────────────────┘
```

## Ключевые концепции

### 1. Виртуальные функции
```cpp
class Shape {
public:
    // ВИРТУАЛЬНАЯ функция - основа полиморфизма
    virtual void draw() const {
        std::cout << "Shape::draw() called..." << std::endl;
    }
    
    // ВАЖНО: виртуальный деструктор для корректного полиморфизма
    virtual ~Shape();
};
```

### 2. Переопределение виртуальных функций
```cpp
class Oval : public Shape {
public:
    // ПЕРЕОПРЕДЕЛЕНИЕ виртуальной функции
    virtual void draw() const override {
        std::cout << "Oval::draw() called..." << std::endl;
    }
};

class Circle : public Oval {
public:
    // ПЕРЕОПРЕДЕЛЕНИЕ на третьем уровне иерархии
    virtual void draw() const override {
        std::cout << "Circle::draw() called..." << std::endl;
    }
};
```

### 3. Полиморфизм через указатели
```cpp
Shape* shape_pointer = &base_shape;
shape_pointer->draw();  // Shape::draw()

shape_pointer = &oval_shape;
shape_pointer->draw();  // Oval::draw() - вызывается правильная версия!

shape_pointer = &circle_shape;
shape_pointer->draw();  // Circle::draw() - полиморфизм работает!
```

### 4. Полиморфизм через ссылки
```cpp
Shape& shape_reference = circle_shape;
shape_reference.draw();  // Circle::draw() - правильный тип вызывается!
```

### 5. Полиморфизм в функциях
```cpp
void draw_shape(Shape* shape_pointer) {
    shape_pointer->draw();  // Вызовется правильная версия благодаря полиморфизму
}

void draw_shape_v1(const Shape& shape_reference) {
    shape_reference.draw();  // Полиморфизм работает и через ссылки
}
```

### 6. Полиморфизм в коллекциях
```cpp
// Массив указателей на базовый класс, содержащий объекты разных типов
Shape* shape_collection[]{&base_shape, &oval_shape, &circle_shape};

// Для каждого элемента вызывается правильная версия draw()!
for (Shape* shape_ptr : shape_collection) {
    shape_ptr->draw();  // Полиморфный вызов
}
```

## Файлы проекта
- `shape.h` / `shape.cpp` - базовый класс Shape с виртуальными функциями
- `oval.h` / `oval.cpp` - класс Oval с переопределением виртуальных функций
- `circle.h` / `circle.cpp` - класс Circle с переопределением на третьем уровне
- `main.cpp` - демонстрация всех аспектов полиморфизма

## Компиляция и запуск
```bash
g++ -o main main.cpp shape.cpp oval.cpp circle.cpp
./main
```

## Ожидаемый вывод
```
=== Polymorphism with base pointers ===
Shape::draw() called. Drawing Base Shape
Oval::draw() called. Drawing Oval Shape with m_x_radius: 2 and m_y_radius: 3.5
Circle::draw() called. Drawing Circle Shape with radius: 3.3

=== Polymorphism with base references ===
Circle::draw() called. Drawing Circle Shape with radius: 3.3

=== Polymorphism in functions ===
Circle::draw() called. Drawing Circle Shape with radius: 3.3
Circle::draw() called. Drawing Circle Shape with radius: 3.3

=== Polymorphism in collections ===
Shape::draw() called. Drawing Base Shape
Oval::draw() called. Drawing Oval Shape with m_x_radius: 2 and m_y_radius: 3.5
Circle::draw() called. Drawing Circle Shape with radius: 3.3
```

## Образовательная цель
Понимание полиморфизма с виртуальными функциями - способности объектов разных типов отвечать на один и тот же вызов метода по-разному.

## Важные принципы

### 1. Виртуальные функции
- **Ключевое слово `virtual`** делает функцию полиморфной
- Виртуальные функции могут быть **переопределены** в производных классах
- **Позднее связывание** (late binding) - решение о том, какую функцию вызвать, принимается во время выполнения

### 2. Виртуальный деструктор
- **Обязательно** делать деструктор виртуальным в базовом классе
- Обеспечивает **правильное уничтожение** объектов в полиморфной иерархии
- Без виртуального деструктора возможны **утечки памяти**

### 3. Переопределение vs Скрытие
- **Переопределение** (`virtual` + `override`) - полиморфное поведение
- **Скрытие** (без `virtual`) - простое скрытие символов
- При переопределении вызывается правильная версия функции

### 4. Механизм работы
- Компилятор создает **таблицу виртуальных функций** (vtable)
- Каждый объект содержит **указатель на vtable**
- Во время выполнения выбирается правильная функция

## Практические применения
- **Графические интерфейсы** - разные виджеты с общей функцией `draw()`
- **Игровая разработка** - разные типы персонажей с общей функцией `update()`
- **Системы управления** - разные типы устройств с общей функцией `process()`
- **Файловые системы** - разные типы файлов с общей функцией `save()`

## Отличия от других языков
- В C++ полиморфизм **явный** (нужно указывать `virtual`)
- В Java все методы по умолчанию виртуальные
- В C# используется `virtual`/`override` как в C++
