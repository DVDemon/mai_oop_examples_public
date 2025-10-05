# 16_DynamicCasts

## Описание
Демонстрирует использование **`dynamic_cast`** в C++ для безопасного приведения типов в полиморфной иерархии. Показывает, как получить доступ к специфичным методам производных классов через указатели и ссылки на базовый класс.

## Классовая диаграмма
```
┌─────────────────┐
│     Animal      │
├─────────────────┤
│ + virtual breathe() │ ← виртуальная функция (ОБЯЗАТЕЛЬНА для dynamic_cast!)
│ + virtual ~Animal   │ ← виртуальный деструктор (ОБЯЗАТЕЛЬНЫЙ для dynamic_cast!)
│ # m_description     │
└─────────────────┘
         ▲
         │ public inheritance
         │
┌─────────────────┐
│     Feline      │
├─────────────────┤
│ + virtual run()    │ ← виртуальная функция
│ + virtual ~Feline  │ ← виртуальный деструктор
│ + do_some_feline_thingy() │ ← специфичный метод (не виртуальный)
│ + m_fur_style      │
└─────────────────┘
         ▲
         │ public inheritance
         │
┌─────────────────┐
│      Dog        │
├─────────────────┤
│ + virtual bark()   │ ← виртуальная функция
│ + virtual ~Dog     │ ← виртуальный деструктор
│ + do_some_dog_thingy() │ ← специфичный метод (не виртуальный)
│ - m_speed          │
└─────────────────┘
```

## Ключевые концепции

### 1. Требования для dynamic_cast
```cpp
// ОБЯЗАТЕЛЬНО: хотя бы одна виртуальная функция в базовом классе
class Animal {
public:
    virtual ~Animal();  // Виртуальный деструктор - МИНИМУМ!
    virtual void breathe() const;  // Дополнительная виртуальная функция
};
```

### 2. dynamic_cast с указателями
```cpp
Animal* animal_ptr = new Feline("stripes", "feline1");

// Безопасное приведение - возвращает nullptr при неудаче
Feline* feline_ptr = dynamic_cast<Feline*>(animal_ptr);

if (feline_ptr) {
    // Успешное приведение - можем вызывать специфичные методы
    feline_ptr->do_some_feline_thingy();
} else {
    // Неудачное приведение - animal_ptr не указывает на Feline
    std::cout << "Couldn't cast to Feline" << std::endl;
}
```

### 3. dynamic_cast со ссылками
```cpp
Feline feline_object("stripes", "feline2");
Animal& animal_ref = feline_object;

// Безопасное приведение через указатели (рекомендуемый способ)
Dog* dog_ptr = dynamic_cast<Dog*>(&animal_ref);
if (dog_ptr) {
    dog_ptr->do_some_dog_thingy();
} else {
    std::cout << "Couldn't cast to Dog" << std::endl;
}

// ПРЯМОЕ приведение ссылок (НЕ рекомендуется - выбрасывает исключение!)
// Dog& dog_ref = dynamic_cast<Dog&>(animal_ref);  // std::bad_cast при неудаче
```

### 4. Доступ к специфичным методам
```cpp
// НЕ РАБОТАЕТ - нет доступа к специфичным методам через базовый указатель
Animal* animal_ptr = new Feline("stripes", "feline1");
// animal_ptr->do_some_feline_thingy();  // ОШИБКА КОМПИЛЯЦИИ!

// РАБОТАЕТ - через dynamic_cast
Feline* feline_ptr = dynamic_cast<Feline*>(animal_ptr);
if (feline_ptr) {
    feline_ptr->do_some_feline_thingy();  // OK!
}
```

## Файлы проекта
- `animal.h` / `animal.cpp` - базовый класс Animal с виртуальными функциями
- `feline.h` / `feline.cpp` - класс Feline с специфичным методом
- `dog.h` / `dog.cpp` - класс Dog с собственным специфичным методом
- `main.cpp` - демонстрация различных способов использования dynamic_cast

## Компиляция и запуск
```bash
g++ -std=c++11 -o main main.cpp animal.cpp feline.cpp dog.cpp
./main
```

## Ожидаемый вывод
```
=== Демонстрация dynamic_cast ===
-----------
--- Dynamic_cast с указателями ---
Doing some feline thingy...
-----------
--- Dynamic_cast со ссылками ---
Couldn't cast to Dog reference, Sorry.
---------------
--- Dynamic_cast в функциях ---
In function taking base pointer...
Doing some feline thingy...
In function taking base reference...
Doing some feline thingy...
----------------
=== Важные выводы ===
1. dynamic_cast работает только с полиморфными типами
2. Для указателей возвращает nullptr при неудаче
3. Для ссылок выбрасывает исключение при неудаче
4. Всегда проверяйте результат перед использованием
5. Позволяет безопасный доступ к специфичным методам

=== Программа завершается ===
Dog destructor called
Feline destructor called
Animal destructor called
Feline destructor called
Animal destructor called
```

## Образовательная цель
Понимание использования `dynamic_cast` для безопасного приведения типов в полиморфной иерархии и доступа к специфичным методам производных классов.

## Важные принципы

### 1. Обязательные требования
- **Хотя бы одна виртуальная функция** в базовом классе (обычно виртуальный деструктор)
- **Полиморфная иерархия** - классы должны быть связаны наследованием
- **Виртуальные функции** должны быть доступны во время выполнения

### 2. Поведение с указателями
```cpp
Derived* derived_ptr = dynamic_cast<Derived*>(base_ptr);

if (derived_ptr) {
    // Успешное приведение - base_ptr действительно указывает на Derived
    derived_ptr->specific_method();
} else {
    // Неудачное приведение - base_ptr НЕ указывает на Derived
    // derived_ptr равен nullptr
}
```

### 3. Поведение со ссылками
```cpp
// РЕКОМЕНДУЕМЫЙ способ - через указатели
Derived* derived_ptr = dynamic_cast<Derived*>(&base_ref);
if (derived_ptr) {
    derived_ptr->specific_method();
}

// НЕ РЕКОМЕНДУЕМЫЙ способ - прямое приведение ссылок
try {
    Derived& derived_ref = dynamic_cast<Derived&>(base_ref);
    derived_ref.specific_method();
} catch (const std::bad_cast& e) {
    // Обработка неудачного приведения
}
```

### 4. Преимущества dynamic_cast
- **Безопасность** - проверка типов во время выполнения
- **Гибкость** - работа с полиморфными иерархиями
- **Доступ к специфичным методам** - вызов методов, недоступных через базовый класс
- **Предотвращение ошибок** - защита от неправильных приведений

### 5. Ограничения dynamic_cast
- **Только полиморфные типы** - требует виртуальных функций
- **Накладные расходы** - проверка типов во время выполнения
- **Не работает с примитивными типами** - только с классами
- **Требует RTTI** - Runtime Type Information должна быть включена

## Практические применения

### 1. Обработка различных типов в коллекциях
```cpp
std::vector<Animal*> animals;
// ... заполнение коллекции

for (Animal* animal : animals) {
    // Полиморфный вызов
    animal->breathe();
    
    // Специфичные действия для разных типов
    if (Feline* feline = dynamic_cast<Feline*>(animal)) {
        feline->do_some_feline_thingy();
    } else if (Dog* dog = dynamic_cast<Dog*>(animal)) {
        dog->do_some_dog_thingy();
    }
}
```

### 2. Фабричные паттерны
```cpp
Animal* createAnimal(const std::string& type) {
    if (type == "feline") {
        return new Feline("short", "Cat");
    } else if (type == "dog") {
        return new Dog("long", "Dog");
    }
    return nullptr;
}

void processAnimal(Animal* animal) {
    // Общая обработка
    animal->breathe();
    
    // Специфичная обработка
    if (Feline* feline = dynamic_cast<Feline*>(animal)) {
        feline->run();
    }
}
```

### 3. Валидация типов
```cpp
bool isFeline(Animal* animal) {
    return dynamic_cast<Feline*>(animal) != nullptr;
}

bool isDog(Animal* animal) {
    return dynamic_cast<Dog*>(animal) != nullptr;
}
```

## Лучшие практики

### 1. Всегда проверяйте результат
```cpp
// ХОРОШО
Derived* derived_ptr = dynamic_cast<Derived*>(base_ptr);
if (derived_ptr) {
    derived_ptr->method();
}

// ПЛОХО
Derived* derived_ptr = dynamic_cast<Derived*>(base_ptr);
derived_ptr->method();  // Может быть nullptr!
```

### 2. Используйте виртуальные функции когда возможно
```cpp
// ХОРОШО - полиморфизм
class Animal {
public:
    virtual void makeSound() = 0;
};

// ПЛОХО - злоупотребление dynamic_cast
void makeSound(Animal* animal) {
    if (Dog* dog = dynamic_cast<Dog*>(animal)) {
        dog->bark();
    } else if (Cat* cat = dynamic_cast<Cat*>(animal)) {
        cat->meow();
    }
}
```

### 3. Предпочитайте указатели ссылкам для dynamic_cast
```cpp
// ХОРОШО - безопасно
Derived* derived_ptr = dynamic_cast<Derived*>(&base_ref);
if (derived_ptr) {
    derived_ptr->method();
}

// ПЛОХО - может выбросить исключение
Derived& derived_ref = dynamic_cast<Derived&>(base_ref);
derived_ref.method();
```

### 4. Документируйте использование dynamic_cast
```cpp
// Объясните, почему нужен dynamic_cast
Animal* animal = getAnimal();
// Нужен dynamic_cast, так как метод специфичен для Feline
if (Feline* feline = dynamic_cast<Feline*>(animal)) {
    feline->purr();  // Метод доступен только для Feline
}
```

## Частые ошибки

### 1. Использование без виртуальных функций
```cpp
// ОШИБКА: Нет виртуальных функций
class Base { };
class Derived : public Base { };

Base* base_ptr = new Derived();
Derived* derived_ptr = dynamic_cast<Derived*>(base_ptr);  // Неопределенное поведение!
```

### 2. Игнорирование проверки результата
```cpp
// ОШИБКА: Не проверяется результат
Derived* derived_ptr = dynamic_cast<Derived*>(base_ptr);
derived_ptr->method();  // Может быть nullptr!
```

### 3. Злоупотребление dynamic_cast
```cpp
// ПЛОХО: Слишком много dynamic_cast
void process(Animal* animal) {
    if (Feline* f = dynamic_cast<Feline*>(animal)) {
        f->run();
    } else if (Dog* d = dynamic_cast<Dog*>(animal)) {
        d->run();
    }
    // Лучше использовать виртуальные функции!
}
```

### 4. Использование с примитивными типами
```cpp
// ОШИБКА: dynamic_cast не работает с примитивными типами
int data = 42;
std::string* str_ptr = dynamic_cast<std::string*>(&data);  // Ошибка компиляции!
```

## Связанные концепции
- **Polymorphism** - полиморфизм с виртуальными функциями
- **Virtual functions** - виртуальные функции
- **Inheritance** - наследование в C++
- **RTTI** - Runtime Type Information
- **Type casting** - приведение типов в C++
- **static_cast** - статическое приведение типов
- **const_cast** - приведение константности
- **reinterpret_cast** - низкоуровневое приведение типов
