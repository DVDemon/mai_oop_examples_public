# 11_Override

## Описание
Демонстрирует использование ключевого слова **`override`** в C++11+ для безопасного переопределения виртуальных функций.

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
│ + virtual draw()│ ← override для безопасности
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
│ + virtual draw()│ ← override на третьем уровне
└─────────────────┘
```

## Ключевые концепции

### 1. Ключевое слово override (C++11+)
```cpp
// В базовом классе
class Shape {
public:
    virtual void draw() const;  // виртуальная функция
};

// В производном классе
class Oval : public Shape {
public:
    virtual void draw() const override;  // override гарантирует корректное переопределение
};
```

### 2. Преимущества override
```cpp
class Base {
public:
    virtual void draw(int x);  // функция с параметром
};

// БЕЗ override - может скрыть функцию вместо переопределения
class Derived1 : public Base {
public:
    virtual void draw();  // ОШИБКА: скрывает Base::draw(int), а не переопределяет
};

// С override - компилятор выдаст ошибку
class Derived2 : public Base {
public:
    virtual void draw() override;  // ОШИБКА КОМПИЛЯЦИИ: не переопределяет Base::draw(int)
};
```

### 3. Многоуровневое наследование с override
```cpp
// Третий уровень иерархии также может использовать override
class Circle : public Oval {
public:
    virtual void draw() const override;  // override работает на любом уровне
};
```

### 4. Безопасность при рефакторинге
```cpp
// Если изменить сигнатуру в базовом классе:
class Shape {
public:
    virtual void draw(std::string_view description);  // изменили сигнатуру
};

// Компилятор выдаст ошибку для всех классов с override
class Oval : public Shape {
public:
    virtual void draw() const override;  // ОШИБКА: не переопределяет новую функцию
};
```

## Файлы проекта
- `shape.h` / `shape.cpp` - базовый класс Shape с виртуальной функцией
- `oval.h` / `oval.cpp` - класс Oval с переопределением через override
- `circle.h` / `circle.cpp` - класс Circle с override на третьем уровне
- `main.cpp` - демонстрация полиморфизма с безопасностью override

## Компиляция и запуск
```bash
g++ -std=c++11 -o main main.cpp shape.cpp oval.cpp circle.cpp
./main
```

## Ожидаемый вывод
```
=== Demonstration of override keyword ===
--- Polymorphic calls with override safety ---
Circle::draw() called. Drawing circle1 with radius: 7.2

Oval::draw() called. Drawing Oval1 with m_x_radius: 13.3 and m_y_radius: 1.2

Circle::draw() called. Drawing circle2 with radius: 11.2

Oval::draw() called. Drawing Oval2 with m_x_radius: 31.3 and m_y_radius: 15.2

Circle::draw() called. Drawing circle3 with radius: 12.2

Oval::draw() called. Drawing Oval3 with m_x_radius: 53.3 and m_y_radius: 9.2

=== Benefits of using override ===
1. Compile-time safety: prevents accidental function hiding
2. Clear intent: explicitly shows function override
3. Refactoring safety: catches signature mismatches
4. Documentation: makes code more self-documenting

=== Program ending ===
```

## Образовательная цель
Понимание важности использования `override` для безопасного переопределения виртуальных функций в современном C++.

## Важные принципы

### 1. Что такое override?
- **`override`** - это ключевое слово C++11+, которое указывает, что функция переопределяет виртуальную функцию базового класса
- **Компилятор проверяет**, что функция действительно переопределяет виртуальную функцию
- **Если сигнатуры не совпадают**, компилятор выдаст ошибку

### 2. Проблема без override
```cpp
class Base {
public:
    virtual void func(int x);
};

class Derived : public Base {
public:
    virtual void func();  // ОШИБКА: скрывает Base::func(int) вместо переопределения!
};
```

### 3. Решение с override
```cpp
class Base {
public:
    virtual void func(int x);
};

class Derived : public Base {
public:
    virtual void func() override;  // ОШИБКА КОМПИЛЯЦИИ: не переопределяет Base::func(int)
};
```

### 4. Преимущества override

#### A. Безопасность компиляции
- **Предотвращает случайное скрытие** функций вместо переопределения
- **Выявляет ошибки** на этапе компиляции, а не во время выполнения

#### B. Ясность намерений
- **Явно показывает**, что функция предназначена для переопределения
- **Улучшает читаемость** кода

#### C. Безопасность рефакторинга
- **Защищает от ошибок** при изменении сигнатур в базовых классах
- **Автоматически обновляет** все места, где нужно изменить сигнатуру

#### D. Документирование
- **Самодокументирующийся код** - сразу понятно, что функция переопределяет виртуальную

### 5. Правила использования override

#### A. Всегда используйте override
```cpp
// ХОРОШО
class Derived : public Base {
public:
    virtual void func() override;
};

// ПЛОХО (устаревший стиль)
class Derived : public Base {
public:
    virtual void func();
};
```

#### B. Комбинируйте с virtual (опционально в C++11+)
```cpp
// В C++11+ virtual можно опустить с override
class Derived : public Base {
public:
    void func() override;  // virtual подразумевается
};

// Но virtual + override тоже допустимо
class Derived : public Base {
public:
    virtual void func() override;  // явно и понятно
};
```

#### C. Используйте на всех уровнях наследования
```cpp
class Shape {
public:
    virtual void draw() const;
};

class Oval : public Shape {
public:
    virtual void draw() const override;  // первый уровень
};

class Circle : public Oval {
public:
    virtual void draw() const override;  // второй уровень - тоже override!
};
```

## Практические применения
- **Библиотеки и фреймворки** - безопасное расширение функциональности
- **Игровые движки** - переопределение методов рендеринга
- **GUI фреймворки** - кастомизация виджетов
- **Плагинные системы** - безопасная реализация интерфейсов

## Лучшие практики
- **Всегда используйте override** при переопределении виртуальных функций
- **Компилируйте с -Werror** для превращения предупреждений в ошибки
- **Используйте современные стандарты C++** (C++11+)
- **Комбинируйте с final** для предотвращения дальнейшего переопределения
- **Документируйте виртуальные функции** в базовых классах

## Связанные концепции
- **`virtual`** - создание виртуальных функций
- **`final`** - предотвращение переопределения
- **Pure virtual functions** - абстрактные классы
- **Virtual destructors** - корректное уничтожение объектов
- **Polymorphism** - основа объектно-ориентированного программирования
