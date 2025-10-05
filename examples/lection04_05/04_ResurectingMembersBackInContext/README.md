# 04_ResurectingMembersBackInContext

## Описание
Демонстрирует **приватное наследование** и технику "воскрешения" членов базового класса через директиву `using`.

## Классовая диаграмма
```
┌─────────────────┐
│      Person     │
├─────────────────┤
│ + m_full_name   │
│ # m_age         │
│ # m_address     │
│ + add()         │
│ + do_something()│
└─────────────────┘
         ▲
         │ PRIVATE inheritance
         │
┌─────────────────┐
│     Engineer    │
├─────────────────┤
│ + contract_count│
│ + build_something│
│ + add()         │ ← "воскрешен" как public
│ # m_age         │ ← "воскрешен" как protected
│ # m_address     │ ← "воскрешен" как protected
└─────────────────┘
         ▲
         │ public inheritance
         │
┌─────────────────┐
│ CivilEngineer   │
├─────────────────┤
│ + m_speciality  │
│ + build_road()  │
└─────────────────┘
```

## Ключевые концепции

### 1. Приватное наследование
```cpp
class Engineer : private Person  // Person становится private базовым классом
{
    // ВСЕ public и protected члены Person становятся private в Engineer
};
```

### 2. "Воскрешение" членов
```cpp
class Engineer : private Person {
public:
    // Делаем метод add снова public для внешнего использования
    using Person::add;

protected:
    // Делаем методы и поля доступными для наследников Engineer
    using Person::get_full_name;
    using Person::get_age;
    using Person::get_address;
    using Person::m_address;
    using Person::m_age;
};
```

### 3. Ограничения для наследников
```cpp
class CivilEngineer : public Engineer {
    void build_road() {
        // МОЖЕМ использовать "воскрешенные" члены
        m_age = 45;        // OK - был "воскрешен" как protected
        m_address = "";    // OK - был "воскрешен" как protected
        add(10, 2);        // OK - был "воскрешен" как public
        
        // НЕ МОЖЕМ обратиться к Person напрямую
        // using Person::do_something;  // ОШИБКА - Person недоступен
    }
};
```

## Файлы проекта
- `person.h` / `person.cpp` - базовый класс Person
- `engineer.h` / `engineer.cpp` - класс Engineer с private наследованием
- `civilengineer.h` / `civilengineer.cpp` - класс CivilEngineer
- `main.cpp` - демонстрация "воскрешения" членов

## Компиляция и запуск
```bash
g++ -o main main.cpp person.cpp engineer.cpp civilengineer.cpp
./main
```

## Ожидаемый вывод
```
Person address: None
Engineer add(5,3): 8
Engineer add(5,3,2): 10
CivilEngineer add(10,20): 30
```

## Образовательная цель
Понимание приватного наследования и техники "воскрешения" членов базового класса через директиву `using`.
