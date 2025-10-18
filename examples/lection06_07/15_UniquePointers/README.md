# 15_UniquePointers - std::unique_ptr (Умные указатели) C++11

## Описание примера

Этот пример демонстрирует использование **std::unique_ptr** - умных указателей C++11 для автоматического управления памятью. Показывает, как избежать утечек памяти и других проблем, связанных с ручным управлением памятью.

## Ключевые концепции

### 1. Проблемы сырых указателей
```cpp
Dog* raw_pointer = new Dog("RawDog");
// Необходимо вручную освобождать память
delete raw_pointer;
```
- **Риск утечек памяти** при забывании delete
- **Двойное освобождение** памяти
- **Висячие указатели** после освобождения
- **Сложность управления** в больших проектах

### 2. std::unique_ptr - основы
```cpp
std::unique_ptr<Dog> unique_dog{new Dog("UniqueDog")};
unique_dog->print_dog(); // Использование как обычного указателя
// Автоматическое освобождение при выходе из области видимости
```
- **Автоматическое управление** памятью
- **Единоличное владение** ресурсом
- **Исключение утечек** памяти

### 3. std::make_unique (C++14)
```cpp
auto unique_dog = std::make_unique<Dog>("MakeUniqueDog");
```
- **Более чистый синтаксис** - не нужно new
- **Исключение исключений** - безопасность при создании
- **Автоматический вывод** типов

## Особенности реализации

### Создание unique_ptr
- **Из сырого указателя** - `std::unique_ptr<Dog>{raw_pointer}`
- **Напрямую** - `std::unique_ptr<Dog>{new Dog("Name")}`
- **С make_unique** - `std::make_unique<Dog>("Name")`
- **С nullptr** - `std::unique_ptr<Dog>{nullptr}`

### Ограничения unique_ptr
- **Копирование запрещено** - copy constructor deleted
- **Присваивание запрещено** - assignment operator deleted
- **Только перемещение** - move semantics разрешено

### Перемещение (Move Semantics)
```cpp
std::unique_ptr<Dog> source = std::make_unique<Dog>("Source");
std::unique_ptr<Dog> destination = std::move(source);
// source теперь nullptr, destination владеет объектом
```

### Методы unique_ptr
- **get()** - получение сырого указателя
- **reset()** - освобождение памяти и установка в nullptr
- **operator->** - доступ к методам объекта
- **operator*** - разыменование

## Ожидаемые результаты

```
=== ДЕМОНСТРАЦИЯ STD::UNIQUE_PTR - УМНЫХ УКАЗАТЕЛЕЙ C++11 ===

1. Объекты на стеке (для сравнения):
Constructor for dog StackDog called.
Printing dog : StackDog
Destructor for dog StackDog called
   Выход из области видимости - автоматическое уничтожение

2. Сырые указатели (проблемы):
   - Необходимо вручную освобождать память
   - Риск утечек памяти при забывании delete
   - Двойное освобождение памяти
   - Висячие указатели

3. std::unique_ptr - основы:
Constructor for dog RawDog called.
Constructor for dog UniqueDog called.
Printing dog : UniqueDog
   Integer value: 500
   Integer address: 0x2b758320
Destructor for dog UniqueDog called
Destructor for dog RawDog called
   Выход из области видимости - автоматическое освобождение памяти

4. std::make_unique (C++14) - более чистый синтаксис:
Constructor for dog MakeUniqueDog called.
Printing dog : MakeUniqueDog
   Integer value: 67
   Integer address: 0x2b758320

5. Ограничения unique_ptr:
Constructor for dog UniqueDog4 called.
Printing dog : UniqueDog4
   Memory address: 0x2b7582f0
   - Копирование запрещено (copy constructor deleted)
   - Присваивание запрещено (assignment operator deleted)
   - Только перемещение (move semantics) разрешено

6. Перемещение (move semantics):
Constructor for dog SourceDog called.
Printing dog : SourceDog
   Destination dog address: 0x2b758340
   Source dog is now nullptr: 0
   Source dog points to nullptr
Destructor for dog SourceDog called
   Выход из области видимости - автоматическое освобождение

7. Метод reset():
Constructor for dog ResetDog called.
   Before reset - points to: 0x2b758340
Destructor for dog ResetDog called
   After reset - points to nullptr

8. Преимущества unique_ptr:
   - Автоматическое управление памятью
   - Исключение утечек памяти
   - Исключение двойного освобождения
   - Исключение висячих указателей
   - Единоличное владение ресурсом
   - Перемещение вместо копирования
   - Совместимость с RAII принципом
```

## Компиляция и запуск

```bash
# Компиляция
g++ -std=c++17 -O2 -o unique_pointers_program main.cpp dog.cpp

# Запуск
./unique_pointers_program
```

## Образовательная ценность

Этот пример демонстрирует:
- **std::unique_ptr** - умные указатели C++11
- **Автоматическое управление памятью** - RAII принцип
- **Проблемы сырых указателей** - утечки памяти, двойное освобождение
- **Move semantics** - перемещение владения
- **Практическое применение** в реальном коде

## Практическое применение

### Стандартная библиотека C++
- **std::unique_ptr** - единоличное владение
- **std::shared_ptr** - разделяемое владение
- **std::weak_ptr** - слабые ссылки
- **std::make_unique** - создание unique_ptr

### Библиотеки
- **Boost** - множество умных указателей
- **Собственные библиотеки** - для управления ресурсами
- **API** - для передачи владения

### Когда использовать unique_ptr
- **Единоличное владение** - когда нужен единственный владелец
- **Автоматическое управление** - когда важна безопасность
- **Перемещение владения** - когда нужна передача ресурсов
- **Совместимость с RAII** - когда важны принципы C++

## Связь с другими примерами

- **14_VariadicTemplate** - variadic templates C++11
- **13_DeductionGuide** - deduction guides C++17
- **13_CRTP** - паттерн CRTP
- **12_ConceptsExample2** - сложные концепции C++20

## Дополнительные возможности

### Сравнение с другими умными указателями
```cpp
// unique_ptr - единоличное владение
std::unique_ptr<Dog> unique_dog = std::make_unique<Dog>("Unique");

// shared_ptr - разделяемое владение
std::shared_ptr<Dog> shared_dog = std::make_shared<Dog>("Shared");

// weak_ptr - слабые ссылки
std::weak_ptr<Dog> weak_dog = shared_dog;
```

### Кастомные делетеры
```cpp
// Кастомный делетер для unique_ptr
auto custom_deleter = [](Dog* dog) {
    std::cout << "Custom deleter called" << std::endl;
    delete dog;
};

std::unique_ptr<Dog, decltype(custom_deleter)> custom_dog(
    new Dog("Custom"), custom_deleter);
```

### Массивы с unique_ptr
```cpp
// unique_ptr для массивов
std::unique_ptr<Dog[]> dog_array = std::make_unique<Dog[]>(5);
dog_array[0] = Dog("First");
dog_array[1] = Dog("Second");
```

## Сравнение с сырыми указателями

### Сырые указатели (проблемы)
```cpp
Dog* raw_dog = new Dog("Raw");
// Риск утечки памяти
// Необходимо помнить об освобождении
// Двойное освобождение
// Висячие указатели
delete raw_dog;
```

### unique_ptr (решение)
```cpp
std::unique_ptr<Dog> smart_dog = std::make_unique<Dog>("Smart");
// Автоматическое освобождение
// Исключение утечек
// Безопасность типов
// RAII принцип
```

## Ограничения и особенности

### Ограничения unique_ptr
- **Единоличное владение** - только один владелец
- **Копирование запрещено** - только перемещение
- **Совместимость** - с API, ожидающими сырые указатели

### Особенности использования
- **Перемещение владения** - std::move для передачи
- **Проверка валидности** - if (ptr) для проверки
- **Получение сырого указателя** - get() для совместимости
- **Освобождение памяти** - reset() для явного освобождения
