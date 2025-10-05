# 10_PolymorphicObjectsStoredInCollections

## Описание
Демонстрирует **хранение полиморфных объектов в коллекциях** и проблему **Object Slicing** при неправильном хранении объектов в массивах.

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

### 1. Проблема Object Slicing в коллекциях
```cpp
// ПРОБЛЕМА: Хранение объектов по значению в массиве базового класса
Circle circle1(7.2, "circle1");
Oval oval1(13.3, 1.2, "Oval1");

// ОШИБКА: Object Slicing - все объекты становятся Shape!
Shape shapes_by_value[]{circle1, oval1, circle2, oval2, circle3, oval3};

for (Shape& shape_ref : shapes_by_value) {
    shape_ref.draw();  // Всегда вызывается Shape::draw()!
}
```

### 2. Решение через указатели
```cpp
// РЕШЕНИЕ: Использование указателей на базовый класс
Shape* shapes_by_pointer[]{&circle1, &oval1, &circle2, &oval2, &circle3, &oval3};

for (Shape* shape_ptr : shapes_by_pointer) {
    shape_ptr->draw();  // Вызывается правильная версия draw()!
}
```

### 3. Почему ссылки не работают в массивах
```cpp
// ОШИБКА КОМПИЛЯЦИИ: Ссылки не являются assignable
// const Shape& shapes_refs[]{circle1, oval1, circle2, oval2, circle3, oval3};

// Ссылки не могут быть присвоены повторно (не lvalue-assignable)
```

### 4. Сравнение размеров объектов
```cpp
Circle circle1(7.2, "circle1");
std::cout << "Size of Circle object: " << sizeof(circle1) << " bytes" << std::endl;
std::cout << "Size of Shape object: " << sizeof(Shape{}) << " bytes" << std::endl;

// При object slicing объекты "срезаются" до размера базового класса
```

## Файлы проекта
- `shape.h` / `shape.cpp` - базовый класс Shape с виртуальными функциями
- `oval.h` / `oval.cpp` - класс Oval с переопределением виртуальных функций
- `circle.h` / `circle.cpp` - класс Circle с переопределением на третьем уровне
- `main.cpp` - демонстрация object slicing и его решения

## Компиляция и запуск
```bash
g++ -o main main.cpp shape.cpp oval.cpp circle.cpp
./main
```

## Ожидаемый вывод
```
=== PROBLEM: Object Slicing in Arrays ===
Size of Circle object: 56 bytes
Size of Shape object: 32 bytes

--- Object slicing demonstration ---
Size of sliced object: 32 bytes
Shape::draw() called. Drawing circle1
Size of sliced object: 32 bytes
Shape::draw() called. Drawing Oval1
Size of sliced object: 32 bytes
Shape::draw() called. Drawing circle2
Size of sliced object: 32 bytes
Shape::draw() called. Drawing Oval2
Size of sliced object: 32 bytes
Shape::draw() called. Drawing circle3
Size of sliced object: 32 bytes
Shape::draw() called. Drawing Oval3

=== SOLUTION: Using Pointers ===
--- Polymorphism preserved with pointers ---
Size of actual object: 56 bytes
Circle::draw() called. Drawing circle1 with radius: 7.2

Size of actual object: 56 bytes
Oval::draw() called. Drawing Oval1 with m_x_radius: 13.3 and m_y_radius: 1.2

Size of actual object: 56 bytes
Circle::draw() called. Drawing circle2 with radius: 11.2

Size of actual object: 56 bytes
Oval::draw() called. Drawing Oval2 with m_x_radius: 31.3 and m_y_radius: 15.2

Size of actual object: 56 bytes
Circle::draw() called. Drawing circle3 with radius: 12.2

Size of actual object: 56 bytes
Oval::draw() called. Drawing Oval3 with m_x_radius: 53.3 and m_y_radius: 9.2

=== Why References Don't Work in Arrays ===
References cannot be stored in arrays because they are not assignable.
Use pointers instead for polymorphic collections.
```

## Образовательная цель
Понимание проблемы object slicing при хранении полиморфных объектов в коллекциях и правильных способов их хранения.

## Важные принципы

### 1. Object Slicing в коллекциях
- При хранении **объектов по значению** в массиве базового класса происходит срезка
- Все объекты **превращаются в объекты базового класса**
- **Теряется полиморфизм** - всегда вызываются методы базового класса
- **Теряются данные** производных классов

### 2. Правильное хранение полиморфных объектов
- Используйте **указатели на базовый класс** в коллекциях
- Указатели сохраняют **полную информацию** об объектах
- **Полиморфизм работает** корректно
- **Виртуальные функции** вызываются правильно

### 3. Почему ссылки не подходят
- **Ссылки не являются assignable** - их нельзя присвоить повторно
- **Нельзя создать массив ссылок** в C++
- Для полиморфных коллекций используйте **указатели или умные указатели**

### 4. Альтернативные решения
```cpp
// Умные указатели (современный подход)
std::vector<std::unique_ptr<Shape>> shapes;
shapes.push_back(std::make_unique<Circle>(7.2, "circle1"));
shapes.push_back(std::make_unique<Oval>(13.3, 1.2, "Oval1"));

// Контейнеры STL с указателями
std::vector<Shape*> shape_pointers{&circle1, &oval1, &circle2};
```

## Практические применения
- **Графические редакторы** - коллекция различных фигур
- **Игровые движки** - коллекция различных объектов игры
- **UI фреймворки** - коллекция различных виджетов
- **Системы управления** - коллекция различных устройств

## Лучшие практики
- **Никогда не храните полиморфные объекты по значению** в коллекциях
- **Всегда используйте указатели или умные указатели**
- **Предпочитайте умные указатели** (std::unique_ptr, std::shared_ptr) сырым указателям
- **Используйте виртуальные деструкторы** для корректной очистки памяти
