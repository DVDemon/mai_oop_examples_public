# 07_ConstIterator - Пользовательский контейнер с обычными и константными итераторами

## Описание

Этот пример демонстрирует создание полнофункционального пользовательского контейнера с поддержкой как обычных, так и константных итераторов. Показывает современные возможности C++20, включая concepts, и полную STL-совместимость.

## Ключевые концепции

### 1. Пользовательский контейнер (BoxContainer)
- **Назначение**: Динамический контейнер с автоматическим расширением
- **Особенности**: Поддержка копирования, присваивания, добавления/удаления элементов
- **STL-совместимость**: Полная интеграция с алгоритмами стандартной библиотеки
- **Управление памятью**: Автоматическое расширение при необходимости

### 2. Обычные итераторы (Iterator)
- **Назначение**: Позволяют модифицировать элементы контейнера
- **Тип**: Random Access Iterator
- **Операции**: Полный набор операций для навигации и модификации
- **Применение**: Когда нужно изменять элементы контейнера

### 3. Константные итераторы (ConstIterator)
- **Назначение**: Только чтение элементов контейнера
- **Тип**: Random Access Iterator с константными ссылками
- **Операции**: Все операции навигации, но без возможности модификации
- **Применение**: Для константных контейнеров и безопасного доступа

### 4. C++20 Concepts
- **std::is_default_constructible_v**: Проверка наличия конструктора по умолчанию
- **std::copyable**: Проверка возможности копирования
- **requires**: Ограничения на типы шаблонов
- **static_assert**: Проверка требований на этапе компиляции

## Структура кода

### Основной класс BoxContainer
```cpp
template <typename T>
requires std::is_default_constructible_v<T>
class BoxContainer {
    // Конструкторы, деструктор
    // Методы доступа к данным
    // Методы модификации контейнера
    // Операторы
    // Итераторы
};
```

### Обычный итератор
```cpp
class Iterator {
    using iterator_category = std::random_access_iterator_tag;
    using value_type        = T;
    using pointer_type      = T*;
    using reference_type    = T&;
    
    // Полный набор операций итератора
};
```

### Константный итератор
```cpp
class ConstIterator {
    using iterator_category = std::random_access_iterator_tag;
    using value_type        = T;
    using pointer_type      = const T*;
    using reference_type    = const T&;
    
    // Полный набор операций итератора (только чтение)
};
```

## Демонстрационные возможности

### 1. Создание и заполнение контейнера
```cpp
BoxContainer<int> integer_container;
integer_container.add(5);
integer_container.add(1);
integer_container.add(7);
// ... добавление элементов
```

### 2. Работа с константным контейнером
```cpp
const BoxContainer<int> const_copy(integer_container);
for (auto const_iterator = const_copy.begin(); 
     const_iterator != const_copy.end(); ++const_iterator) {
    std::cout << (*const_iterator) << " ";
}
```

### 3. Автоматический выбор типа итератора
```cpp
// Обычный контейнер - обычные итераторы
BoxContainer<int> mutable_container;
auto mutable_iterator = mutable_container.begin();  // Iterator

// Константный контейнер - константные итераторы
const BoxContainer<int> const_container;
auto const_iterator = const_container.begin();     // ConstIterator
```

## Образовательные цели

1. **Понимание итераторов**: Различия между обычными и константными итераторами
2. **STL-совместимость**: Создание контейнеров, совместимых со стандартной библиотекой
3. **C++20 Concepts**: Использование современных возможностей языка
4. **Управление памятью**: Автоматическое расширение контейнеров
5. **Шаблонное программирование**: Создание универсальных классов

## Ключевые улучшения в коде

### Имена переменных
- `vi` → `integer_container` (более описательное)
- `copy` → `const_copy` (ясно указывает на константность)
- `it` → `const_iterator` (более описательное)
- `i` → `element_index` (в циклах)

### Комментарии
- Подробные Doxygen-комментарии для всех методов
- Объяснение назначения каждого типа итератора
- Комментарии к демонстрационным шагам
- Образовательные комментарии для студентов

### Форматирование
- Единообразные отступы
- Логическая группировка кода
- Четкие разделители между секциями

## Требования

- C++20 или новее (для concepts и requires)
- Компилятор с поддержкой современных возможностей C++

## Сборка и запуск

```bash
# Компиляция
g++ -std=c++20 -o const_iterator main.cpp

# Запуск
./const_iterator
```

## Ожидаемый вывод

```
=== ДЕМОНСТРАЦИЯ КОНСТАНТНЫХ ИТЕРАТОРОВ ===
1. Создание и заполнение контейнера:
   Исходный контейнер: BoxContainer : [ size :  9, capacity : 10, items : 5 1 7 2 5 3 7 9 6 ]
2. Создание константной копии контейнера:
3. Итерация по константному контейнеру (только чтение):
   Элементы константного контейнера: 5 1 7 2 5 3 7 9 6 
4. Различия между типами итераторов:
   - Обычные итераторы: позволяют модифицировать элементы
   - Константные итераторы: только чтение элементов
   - Константный контейнер автоматически использует константные итераторы

=== ДЕМОНСТРАЦИЯ ЗАВЕРШЕНА ===
```

## Сравнение типов итераторов

### Обычные итераторы (Iterator)
```cpp
BoxContainer<int> container;
auto iterator = container.begin();
*iterator = 42;  // Можно модифицировать
```

### Константные итераторы (ConstIterator)
```cpp
const BoxContainer<int> const_container;
auto const_iterator = const_container.begin();
// *const_iterator = 42;  // ОШИБКА КОМПИЛЯЦИИ!
int value = *const_iterator;  // Только чтение
```

## Ключевые особенности реализации

### 1. Автоматический выбор типа итератора
```cpp
// Обычные методы
Iterator begin() { return Iterator(&m_items[0]); }
Iterator end()   { return Iterator(&m_items[m_size]); }

// Константные методы
ConstIterator begin() const { return ConstIterator(&m_items[0]); }
ConstIterator end() const   { return ConstIterator(&m_items[m_size]); }
```

### 2. C++20 Concepts
```cpp
template <typename T>
requires std::is_default_constructible_v<T>
class BoxContainer {
    static_assert(std::is_default_constructible_v<T>, 
                  "Types must have default constructor");
};
```

### 3. STL-совместимость
```cpp
// Поддержка алгоритмов STL
std::sort(container.begin(), container.end());
std::find(container.begin(), container.end(), value);
std::copy(container.begin(), container.end(), output_iterator);
```

## Дополнительные возможности для изучения

1. **Обратные итераторы**: Реализация `rbegin()` и `rend()`
2. **Алгоритмы STL**: Интеграция с `std::sort`, `std::find`, `std::transform`
3. **Исключения**: Обработка ошибок при работе с итераторами
4. **Производительность**: Оптимизация для различных типов операций
5. **Move-семантика**: Поддержка перемещения элементов

## Практические применения

### 1. Безопасная итерация
```cpp
void processContainer(const BoxContainer<int>& container) {
    // Автоматически используются константные итераторы
    for (auto it = container.begin(); it != container.end(); ++it) {
        std::cout << *it << " ";  // Только чтение
    }
}
```

### 2. Модификация элементов
```cpp
void modifyContainer(BoxContainer<int>& container) {
    // Используются обычные итераторы
    for (auto it = container.begin(); it != container.end(); ++it) {
        *it *= 2;  // Модификация элементов
    }
}
```

### 3. Интеграция с алгоритмами
```cpp
BoxContainer<int> container = {1, 2, 3, 4, 5};
std::sort(container.begin(), container.end());
std::reverse(container.begin(), container.end());
```

Этот пример отлично демонстрирует создание полнофункциональных контейнеров с современными возможностями C++20 и показывает важность правильного использования константных итераторов для безопасности кода.
