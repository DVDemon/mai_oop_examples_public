# 05_ConstructorsWithInheritance

## Описание
Демонстрирует **порядок вызова конструкторов и деструкторов** при наследовании.

## Классовая диаграмма
```
┌─────────────────┐
│      Person     │
├─────────────────┤
│ + Person()      │
│ + Person(...)   │
│ + ~Person()     │
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
CivilEngineer civil_engineer("John", 51, "Address", 31, "Speciality");

// Вызываются конструкторы в порядке:
// 1. Person("John", 51, "Address")
// 2. Engineer("John", 51, "Address", 31)  
// 3. CivilEngineer("John", 51, "Address", 31, "Speciality")
```

### 2. Правильный вызов конструктора базового класса
```cpp
// ПРАВИЛЬНО: через список инициализации
CivilEngineer::CivilEngineer(std::string_view fullname, int age,
                             std::string_view address, int contract_count,
                             std::string_view speciality)
    : Engineer(fullname, age, address, contract_count), m_speciality(speciality)
{
    std::cout << "Custom constructor called for CivilEngineer..." << std::endl;
}
```

### 3. НЕПРАВИЛЬНЫЕ способы (с объяснением ошибок)
```cpp
// НЕПРАВИЛЬНО #1: прямая инициализация в теле конструктора
CivilEngineer::CivilEngineer(...) {
    m_full_name = fullname;   // OK - public поле
    m_age = age;              // OK - protected поле (не рекомендуется)
    m_address = address;      // ОШИБКА - private поле Person недоступно!
    m_speciality = speciality;
}

// НЕПРАВИЛЬНО #2: инициализация полей базового класса в списке инициализации
CivilEngineer::CivilEngineer(...)
    : m_full_name(fullname), m_age(age), m_address(address), m_speciality(speciality)  // ОШИБКА!
{
}
```

### 4. Порядок вызова деструкторов
```
CivilEngineer → Engineer → Person
```

```cpp
// При выходе из main() или уничтожении объекта:
// 1. ~CivilEngineer()
// 2. ~Engineer()  
// 3. ~Person()
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
=== Creating Person ===
Custom constructor for Person called...

=== Creating Engineer ===
Custom constructor for Person called...
Custom constructor for Engineer called...

=== Creating CivilEngineer ===
Custom constructor for Person called...
Custom constructor for Engineer called...
Custom constructor called for CivilEnginner ...

=== Program ending (destructors will be called) ===
```

## Образовательная цель
Понимание порядка вызова конструкторов и деструкторов при наследовании, а также правильных способов инициализации в наследующих классах.
