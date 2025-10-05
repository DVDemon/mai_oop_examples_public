# 06_InheritingBaseConstructors

## Описание
Демонстрирует **наследование конструкторов** через директиву `using` в C++11 и более поздних версиях.

## Классовая диаграмма
```
┌─────────────────┐
│      Person     │
├─────────────────┤
│ + Person()      │ ← конструктор по умолчанию
│ + Person(...)   │ ← конструктор с параметрами
│ + Person(const&)│ ← конструктор копирования
│ + ~Person()     │
│ + m_full_name   │
│ # m_age         │
│ - m_address     │
└─────────────────┘
         ▲
         │ public inheritance + using Person::Person
         │
┌─────────────────┐
│     Engineer    │
├─────────────────┤
│ + contract_count│
│ + Engineer(...) │ ← дополнительный конструктор
│ + ~Engineer()   │
│ + build_something│
└─────────────────┘
```

## Ключевые концепции

### 1. Наследование конструкторов
```cpp
class Engineer : public Person
{
    using Person::Person;  // Наследуем ВСЕ конструкторы Person!
    
public:
    // Дополнительный конструктор Engineer
    Engineer(std::string_view fullname, int age,
             std::string_view address, int contract_count);
};
```

### 2. Что наследуется
Благодаря `using Person::Person` Engineer автоматически получает:
- `Engineer()` - конструктор по умолчанию
- `Engineer(std::string_view, int, std::string_view)` - конструктор с параметрами
- **НЕ наследуется**: `Engineer(const Engineer&)` - конструктор копирования

### 3. Практическое использование
```cpp
int main() {
    // Используем НАСЛЕДОВАННЫЙ конструктор Person для Engineer
    Engineer engineer_inherited("John", 25, "123 Main St");  // Наследованный!
    
    // Используем НАСЛЕДОВАННЫЙ конструктор по умолчанию
    Engineer engineer_default;  // Наследованный!
    
    // Используем собственный конструктор Engineer
    Engineer engineer_custom("Jane", 30, "456 Oak Ave", 5);  // Собственный!
}
```

### 4. Преимущества наследования конструкторов
- **Упрощение кода**: не нужно писать конструкторы-обертки
- **Автоматическая совместимость**: все конструкторы базового класса доступны
- **Гибкость**: можно добавлять дополнительные конструкторы

### 5. Ограничения
```cpp
class Engineer : public Person {
    using Person::Person;  // Наследуем конструкторы
    
public:
    // Конструктор копирования НЕ наследуется автоматически!
    // Нужно писать вручную:
    Engineer(const Engineer& source) 
        : Person(source), contract_count(source.contract_count) {}
};
```

## Файлы проекта
- `person.h` / `person.cpp` - базовый класс Person с несколькими конструкторами
- `engineer.h` / `engineer.cpp` - класс Engineer с наследованием конструкторов
- `main.cpp` - демонстрация использования наследованных конструкторов

## Компиляция и запуск
```bash
g++ -o main main.cpp person.cpp engineer.cpp
./main
```

## Ожидаемый вывод
```
=== Creating Engineer with contract_count ===
Custom constructor for Person called...
Custom constructor for Engineer called...

=== Creating Engineer using inherited Person constructor ===
Custom constructor for Person called...

=== Creating Engineer using inherited default constructor ===
Default constructor for Person called...

=== Testing inherited methods ===
Engineer with contract: 4 contracts
Engineer inherited name: Daniel Gray
Engineer default age: 0
```

## Образовательная цель
Понимание механизма наследования конструкторов в C++11+ и его практического применения для упрощения кода в иерархиях наследования.

## Важные заметки
- Наследование конструкторов доступно с C++11
- Конструкторы копирования НЕ наследуются автоматически
- Можно комбинировать наследованные и собственные конструкторы
- Директива `using` делает конструкторы базового класса доступными для производного класса
