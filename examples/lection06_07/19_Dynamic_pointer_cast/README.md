# 19_Dynamic_pointer_cast - Безопасное приведение типов для умных указателей

## Описание примера

Этот пример демонстрирует **std::dynamic_pointer_cast** - безопасное приведение типов для умных указателей с проверкой во время выполнения. Показывает, как безопасно приводить shared_ptr к производным типам с использованием RTTI (Run-Time Type Information).

## Ключевые концепции

### 1. std::dynamic_pointer_cast - безопасное приведение
```cpp
std::shared_ptr<BaseClass> base_pointer = derived_pointer;
std::shared_ptr<DerivedClass> derived_pointer = std::dynamic_pointer_cast<DerivedClass>(base_pointer);
```

### 2. RTTI (Run-Time Type Information)
- **Проверка типов** - во время выполнения
- **Безопасное приведение** - с проверкой совместимости
- **Возврат nullptr** - при неуспешном приведении
- **Полиморфные типы** - работа только с виртуальными функциями

### 3. Полиморфизм и наследование
```cpp
struct BaseClass {
    virtual void perform_action() = 0;
    virtual ~BaseClass() = default;
};

struct DerivedClass : public BaseClass {
    void perform_action() override { /* implementation */ }
    void specific_function() { /* derived-specific */ }
};
```

## Особенности реализации

### Базовый класс
- **Виртуальные функции** - для полиморфизма
- **Виртуальный деструктор** - для корректного полиморфизма
- **Публичное наследование** - для dynamic_cast

### Производные классы
- **Переопределение виртуальных функций** - override
- **Специфичные функции** - доступные только в производном классе
- **Дополнительные члены** - специфичные для производного класса

### Dynamic pointer cast
- **Безопасное приведение** - с проверкой типов
- **Сохранение счетчика ссылок** - shared_ptr остается валидным
- **Возврат nullptr** - при неуспешном приведении
- **RTTI зависимость** - требует включенного RTTI

## Ожидаемые результаты

```
=== ДЕМОНСТРАЦИЯ STD::DYNAMIC_POINTER_CAST ===

1. Создание и базовое использование:
BaseClass constructor called
   Created shared_ptr<DerivedClassB> and converted to shared_ptr<BaseClass>
   Reference count: 2

2. Успешное приведение к правильному типу:
   Successfully casted to DerivedClassB
DerivedClassB::perform_action() called
DerivedClassB::perform_specific_action_b() called
   Member value: 1

3. Неуспешное приведение к неправильному типу:
   Failed to cast to DerivedClassC (expected behavior)

4. Приведение к правильному типу C:
BaseClass constructor called
   Successfully casted to DerivedClassC
DerivedClassC::perform_action() called
DerivedClassC::perform_specific_action_c() called
   Message: Hello from DerivedClassC!

5. Принципы работы dynamic_pointer_cast:
   - Безопасное приведение типов во время выполнения
   - Проверка совместимости типов через RTTI
   - Возврат nullptr при неуспешном приведении
   - Сохранение счетчика ссылок shared_ptr
   - Работа только с полиморфными типами (виртуальные функции)
   - Альтернатива dynamic_cast для умных указателей
BaseClass destructor called
BaseClass destructor called
```

## Компиляция и запуск

```bash
# Компиляция (RTTI включен по умолчанию)
g++ -std=c++17 -O2 -o dynamic_pointer_cast_program main.cpp

# Запуск
./dynamic_pointer_cast_program
```

## Образовательная ценность

Этот пример демонстрирует:
- **Безопасное приведение типов** - с проверкой во время выполнения
- **RTTI** - Run-Time Type Information
- **Полиморфизм** - виртуальные функции и наследование
- **Умные указатели** - работа с shared_ptr
- **Проверка типов** - безопасное приведение к производным типам

## Практическое применение

### Когда использовать dynamic_pointer_cast
- **Неизвестный тип объекта** - когда тип определяется во время выполнения
- **Безопасное приведение** - с проверкой совместимости типов
- **Полиморфные иерархии** - работа с наследованием
- **Обработка ошибок** - проверка успешности приведения

### Когда НЕ использовать dynamic_pointer_cast
- **Известный тип** - когда тип известен на этапе компиляции
- **Производительность** - накладные расходы на RTTI
- **Простые случаи** - когда static_cast достаточно
- **Не полиморфные типы** - без виртуальных функций

## Сравнение с другими приведениями

### static_pointer_cast
```cpp
std::shared_ptr<DerivedClass> derived = std::static_pointer_cast<DerivedClass>(base);
// Принудительное приведение без проверки
// Быстрее, но небезопасно
```

### dynamic_pointer_cast
```cpp
std::shared_ptr<DerivedClass> derived = std::dynamic_pointer_cast<DerivedClass>(base);
// Безопасное приведение с проверкой
// Медленнее, но безопасно
```

### const_pointer_cast
```cpp
std::shared_ptr<const Class> const_ptr = std::const_pointer_cast<const Class>(ptr);
// Удаление const квалификатора
// Осторожно с const корректностью
```

## Дополнительные возможности

### Проверка типа перед приведением
```cpp
if (std::shared_ptr<DerivedClass> derived = std::dynamic_pointer_cast<DerivedClass>(base)) {
    // Успешное приведение
    derived->specific_function();
} else {
    // Неуспешное приведение
    std::cout << "Cannot cast to DerivedClass" << std::endl;
}
```

### Множественные приведения
```cpp
std::shared_ptr<BaseClass> base = get_object();

if (auto derived_b = std::dynamic_pointer_cast<DerivedClassB>(base)) {
    derived_b->function_b();
} else if (auto derived_c = std::dynamic_pointer_cast<DerivedClassC>(base)) {
    derived_c->function_c();
} else {
    std::cout << "Unknown derived type" << std::endl;
}
```

### Работа с unique_ptr
```cpp
std::unique_ptr<BaseClass> base = std::make_unique<DerivedClass>();
std::unique_ptr<DerivedClass> derived = std::dynamic_pointer_cast<DerivedClass>(base);
// Аналогично для unique_ptr
```

## Ограничения и особенности

### Ограничения dynamic_pointer_cast
- **RTTI зависимость** - требует включенного RTTI
- **Полиморфные типы** - только с виртуальными функциями
- **Производительность** - накладные расходы на проверку типов
- **Размер кода** - увеличение размера исполняемого файла

### Особенности реализации
- **Проверка типов** - во время выполнения
- **Безопасность** - возврат nullptr при неуспешном приведении
- **Счетчик ссылок** - сохранение в shared_ptr
- **Исключения** - не генерирует исключения

## Рекомендации по использованию

### Лучшие практики
1. **Используйте для неизвестных типов** - когда тип определяется во время выполнения
2. **Проверяйте результат** - всегда проверяйте на nullptr
3. **Избегайте избыточного использования** - только когда необходимо
4. **Документируйте намерения** - объясняйте, почему нужно приведение

### Антипаттерны
- **Избыточное использование** - когда тип известен на этапе компиляции
- **Игнорирование результата** - без проверки на nullptr
- **Смешивание с static_cast** - без понимания различий
- **Игнорирование производительности** - в критичных по скорости местах

## Связь с другими примерами

- **18_CustomShared** - пользовательский shared_ptr
- **17_SharedPtr** - стандартный std::shared_ptr
- **16_CustomUniquePointer** - пользовательский unique_ptr
- **15_UniquePointers** - std::unique_ptr

## Дополнительные возможности

### Отладка и профилирование
```cpp
void debug_type_info(std::shared_ptr<BaseClass> ptr) {
    if (auto derived_b = std::dynamic_pointer_cast<DerivedClassB>(ptr)) {
        std::cout << "Type: DerivedClassB" << std::endl;
    } else if (auto derived_c = std::dynamic_pointer_cast<DerivedClassC>(ptr)) {
        std::cout << "Type: DerivedClassC" << std::endl;
    } else {
        std::cout << "Type: BaseClass or unknown" << std::endl;
    }
}
```

### Фабричные методы
```cpp
std::shared_ptr<BaseClass> create_object(const std::string& type) {
    if (type == "B") {
        return std::make_shared<DerivedClassB>();
    } else if (type == "C") {
        return std::make_shared<DerivedClassC>();
    }
    return nullptr;
}

// Использование
auto obj = create_object("B");
if (auto derived = std::dynamic_pointer_cast<DerivedClassB>(obj)) {
    derived->specific_function();
}
```

### Обработка ошибок
```cpp
std::shared_ptr<DerivedClass> safe_cast(std::shared_ptr<BaseClass> base) {
    auto result = std::dynamic_pointer_cast<DerivedClass>(base);
    if (!result) {
        throw std::runtime_error("Cannot cast to DerivedClass");
    }
    return result;
}
```

## Рекомендации по изучению

### Этапы изучения
1. **Понимание полиморфизма** - виртуальные функции, наследование
2. **Изучение RTTI** - Run-Time Type Information
3. **Практика с dynamic_cast** - для сырых указателей
4. **Переход к dynamic_pointer_cast** - для умных указателей
5. **Оптимизация** - понимание накладных расходов

### Практические упражнения
- **Создание иерархии классов** - с виртуальными функциями
- **Реализация фабричных методов** - с dynamic_pointer_cast
- **Обработка ошибок** - проверка результатов приведения
- **Профилирование** - измерение производительности
- **Отладка** - использование для диагностики типов

## Ограничения и предупреждения

### Ограничения RTTI
- **Размер кода** - увеличение размера исполняемого файла
- **Производительность** - накладные расходы на проверку типов
- **Зависимость** - требует включенного RTTI
- **Портабельность** - может не работать на всех платформах

### Предупреждения
- **Не для всех случаев** - только когда необходимо
- **Проверка результата** - всегда проверяйте на nullptr
- **Производительность** - может быть медленнее static_cast
- **Документация** - документируйте необходимость приведения

## Рекомендации по использованию

### Лучшие практики
1. **Используйте для неизвестных типов** - когда тип определяется во время выполнения
2. **Проверяйте результат** - всегда проверяйте на nullptr
3. **Документируйте намерения** - объясняйте, почему нужно приведение
4. **Измеряйте производительность** - в критичных по скорости местах

### Антипаттерны
- **Избыточное использование** - когда тип известен на этапе компиляции
- **Игнорирование результата** - без проверки на nullptr
- **Смешивание с static_cast** - без понимания различий
- **Игнорирование производительности** - в критичных по скорости местах
