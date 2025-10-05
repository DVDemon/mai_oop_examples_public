# 07_InheritanceAndDestructors

## Описание
Демонстрирует **порядок вызова конструкторов и деструкторов** при многоуровневом наследовании.

## Классовая диаграмма
```
┌─────────────────┐
│      Person     │
├─────────────────┤
│ + Person()      │ ← конструктор по умолчанию
│ + Person(...)   │ ← конструктор с параметрами
│ + Person(const&)│ ← конструктор копирования
│ + ~Person()     │ ← деструктор
│ + m_full_name   │
│ # m_age         │
│ - m_address     │
└─────────────────┘
         ▲
         │ public inheritance
         │
┌─────────────────┐
│     Engineer    │
├─────────────────┤
│ + Engineer()    │
│ + Engineer(...) │
│ + Engineer(const&)│
│ + ~Engineer()   │
│ + contract_count│
└─────────────────┘
         ▲
         │ public inheritance
         │
┌─────────────────┐
│ CivilEngineer   │
├─────────────────┤
│ + CivilEngineer()│
│ + CivilEngineer(...)│
│ + CivilEngineer(const&)│
│ + ~CivilEngineer()│
│ + m_speciality  │
└─────────────────┘
```

## Ключевые концепции

### 1. Порядок вызова конструкторов
```
Person → Engineer → CivilEngineer
```

```cpp
// При создании CivilEngineer:
CivilEngineer civil_engineer("Daniel", 41, "Address", 12, "Speciality");

// Вызываются конструкторы в порядке:
// 1. Person("Daniel", 41, "Address")
// 2. Engineer("Daniel", 41, "Address", 12)  
// 3. CivilEngineer("Daniel", 41, "Address", 12, "Speciality")
```

### 2. Порядок вызова деструкторов
```
CivilEngineer → Engineer → Person
```

```cpp
// При выходе из main() или уничтожении объекта:
// 1. ~CivilEngineer()
// 2. ~Engineer()  
// 3. ~Person()
```

### 3. Правильные конструкторы в цепочке наследования
```cpp
// Person - базовый класс
Person(std::string_view fullname, int age, std::string_view address);

// Engineer - наследует от Person
Engineer(std::string_view fullname, int age, 
         std::string_view address, int contract_count)
    : Person(fullname, age, address), contract_count(contract_count) {}

// CivilEngineer - наследует от Engineer
CivilEngineer(std::string_view fullname, int age,
              std::string_view address, int contract_count,
              std::string_view speciality)
    : Engineer(fullname, age, address, contract_count), m_speciality(speciality) {}
```

### 4. Конструкторы копирования в иерархии
```cpp
// Person - конструктор копирования
Person(const Person& source)
    : m_full_name(source.m_full_name), m_age(source.m_age), m_address(source.m_address) {}

// Engineer - вызывает конструктор копирования Person
Engineer(const Engineer& source)
    : Person(source), contract_count(source.contract_count) {}

// CivilEngineer - вызывает конструктор копирования Engineer
CivilEngineer(const CivilEngineer& source)
    : Engineer(source), m_speciality(source.m_speciality) {}
```

## Файлы проекта
- `person.h` / `person.cpp` - базовый класс Person
- `engineer.h` / `engineer.cpp` - класс Engineer
- `civilengineer.h` / `civilengineer.cpp` - класс CivilEngineer
- `main.cpp` - демонстрация порядка вызова конструкторов/деструкторов

## Компиляция и запуск
```bash
g++ -o main main.cpp person.cpp engineer.cpp civilengineer.cpp
./main
```

## Ожидаемый вывод
```
=== Creating CivilEngineer object ===
Custom constructor for Person called...
Custom constructor for Engineer called...
Custom constructor called for CivilEngineer...

=== Object created successfully ===
Engineer name: Daniel Gray
Engineer age: 41
Contract count: 12

=== Program ending - destructors will be called ===
Destructor called for CivilEngineer...
Destructor for Engineer called...
Destructor for Person called...
```

## Образовательная цель
Понимание порядка вызова конструкторов и деструкторов при многоуровневом наследовании, а также правильного написания конструкторов копирования в иерархиях классов.

## Важные принципы

### 1. Конструкторы
- Вызываются от **базового класса к производному**
- Каждый конструктор должен правильно инициализировать базовый класс
- Используйте список инициализации для вызова конструктора базового класса

### 2. Деструкторы
- Вызываются от **производного класса к базовому**
- Автоматически вызываются при выходе из области видимости
- Обеспечивают правильную очистку ресурсов

### 3. Конструкторы копирования
- Должны вызывать конструктор копирования базового класса
- Должны копировать все собственные поля класса
- Важны для корректной работы с объектами в иерархии наследования
