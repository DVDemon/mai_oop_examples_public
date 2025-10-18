# Сложные параметры шаблонов

## Описание
Этот пример демонстрирует работу с шаблонами, имеющими сложные параметры:
- **Параметры-типы** (type parameters)
- **Параметры-значения** (non-type parameters)
- **Параметры по умолчанию** (default template parameters)

## Ключевые концепции

### 1. Сложные параметры шаблона
```cpp
template <class TYPE, TYPE default_value, size_t SIZE = 10>
class Array {
    TYPE array_data[SIZE];
    // ...
};
```

### 2. Параметры-значения
```cpp
// TYPE - тип элементов
// default_value - значение по умолчанию (того же типа, что и TYPE)
// SIZE - размер массива (параметр по умолчанию = 10)
Array<int, 0, 10> array;
```

### 3. Обработка исключений
```cpp
class BadIndexException : public std::exception {
    // Пользовательское исключение для ошибок индексации
};
```

## Особенности

### Параметры по умолчанию
```cpp
template <class TYPE, TYPE default_value, size_t SIZE = 10>
//                                                      ^^^^
//                                              параметр по умолчанию
```

### Итераторы для range-based for
```cpp
TYPE* begin() { return &array_data[0]; }
TYPE* end() { return &array_data[SIZE]; }
```

### Проверка границ с исключениями
```cpp
TYPE& operator[](size_t index) {
    if (index < SIZE) return array_data[index];
    else throw BadIndexException(index, SIZE);
}
```

## Использование

### Создание массива
```cpp
const int my_size = 10;
Array<int, 0, my_size> array;  // int[], значение по умолчанию = 0, размер = 10
```

### Инициализация и изменение
```cpp
// Инициализация
for (int i = 0; i < array.size(); i++) {
    array[i] = i;
}

// Изменение через range-based for
for (auto& element : array) {
    element *= element;  // Возведение в квадрат
}
```

### Обработка исключений
```cpp
try {
    std::cout << array[255] << std::endl;  // Выход за границы
} catch (const std::exception& ex) {
    std::cout << ex.what() << std::endl;
}
```

## Компиляция и запуск
```bash
g++ -std=c++17 -Wall -Wextra main.cpp -o complex_parameters
./complex_parameters
```

## Ожидаемый вывод
```
Original array: 0 1 2 3 4 5 6 7 8 9 
Squared array: 0 1 4 9 16 25 36 49 64 81 
Trying to access array[255]: Exception in runtime
Index:255 is out of bound for array[0..9]
```

## Практические применения
- **Фиксированные массивы**: массивы с известным размером времени компиляции
- **Типобезопасность**: проверка типов на этапе компиляции
- **Оптимизация**: размер массива известен на этапе компиляции
- **Обработка ошибок**: исключения для некорректного доступа
- **STL-совместимость**: поддержка итераторов и range-based for

## Преимущества
- ✅ **Производительность**: нет динамических выделений памяти
- ✅ **Безопасность**: проверка границ с исключениями
- ✅ **Гибкость**: настраиваемый тип и значение по умолчанию
- ✅ **Совместимость**: поддержка современных C++ возможностей
