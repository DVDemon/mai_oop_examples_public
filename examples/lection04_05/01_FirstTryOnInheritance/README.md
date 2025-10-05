# 01_FirstTryOnInheritance

## Описание
Демонстрирует базовое публичное наследование и проблему **Object Slicing** (срезки объектов).

## Классовая диаграмма
```
┌─────────────────┐
│      Person     │
├─────────────────┤
│ + first_name    │
│ + last_name     │
│ + print()       │
└─────────────────┘
         ▲
         │ public inheritance
         │
┌─────────────────┐
│     Player      │
├─────────────────┤
│ + m_game        │
│ + print()       │ (переопределенный)
└─────────────────┘
```

## Ключевые концепции

### 1. Публичное наследование
```cpp
class Player : public Person  // Player наследует от Person
```

### 2. Проблема Object Slicing
```cpp
Player basketball_player("Basketball");
basketball_player.set_first_name("John");
basketball_player.set_last_name("Snow");

// ПРОБЛЕМА: При приведении Player к Person теряется информация о Player!
static_cast<Person>(basketball_player).print(std::cout);
```

**Что происходит:**
- Создается **КОПИЯ** только базовой части объекта (Person)
- Информация о Player (m_game) **ТЕРЯЕТСЯ**
- Вызывается метод `print()` класса Person, а не Player

## Файлы проекта
- `person.h` / `person.cpp` - базовый класс Person
- `player.h` / `player.cpp` - производный класс Player
- `main.cpp` - демонстрация проблемы object slicing

## Компиляция и запуск
```bash
g++ -o main main.cpp person.cpp player.cpp
./main
```

## Ожидаемый вывод
```
Player : [ game : Basketball names : John Snow]
Person : John Snow]
```

## Образовательная цель
Понимание проблемы object slicing при приведении объектов производного класса к базовому классу по значению.
