# Лабораторная работа 01: Google Test Framework

## Цель

* Изучение системы сборки на языке C++ с использованием CMake
* Изучение систем контроля версий Git
* Изучение работы с памятью в C++
* Изучение работы с вводом/выводом в стандартный поток
* **Изучение unit-тестирования с использованием Google Test Framework**

## Задание

* Установить компилятор C++
* Установить систему сборки CMake
* Установить систему управления версиями Git
* Установить систему unit-тестирования Google Test
* Установить и настроить Visual Studio Code
* Написать программу согласно варианту задания
* Написать unit-тесты согласно варианту задания
* Завести аккаунт на GitHub (если нет) и опубликовать репозиторий
* Отправить ссылку на репозиторий в lms.mai.ru

## Структура проекта

```
06_GTest/
├── CMakeLists.txt          # Файл конфигурации CMake
├── main.cpp                # Основная программа
├── include/
│   └── calculator.h        # Заголовочный файл с объявлениями функций
├── src/
│   └── calculator.cpp      # Реализация функций
├── test/
│   └── tests01.cpp         # Unit-тесты с использованием Google Test
└── readme.md               # Данный файл
```

## Инструкции по установке

### Установка компилятора C++

Скачайте и установите актуальную версию C++:

* **Windows**: рекомендуется использовать [MinGW-w64](https://www.mingw-w64.org/downloads/) или Visual Studio Community
* **macOS**: рекомендуется установка "Xcode" и "Xcode Command Line Tools" с [developer.apple.com](https://developer.apple.com/xcode/)
* **Linux** (рекомендуется версия gcc 12 и выше):
  ```bash
  sudo apt update
  sudo apt install build-essential
  ```

### Установка CMake

Скачайте и установите актуальную версию CMake с [cmake.org](https://cmake.org/download/)

### Установка Git

Скачайте и установите актуальную версию Git под вашу операционную систему с [git-scm.com](https://git-scm.com/downloads)

### Установка Google Test

**Способ 1: Автоматическая установка (рекомендуется)**
Проект настроен на автоматическую загрузку Google Test через CMake. Никаких дополнительных действий не требуется.

**Способ 2: Ручная установка**
```bash
git clone https://github.com/google/googletest.git
cd googletest
mkdir build
cd build
cmake ..
make
make install
```

### Установка Visual Studio Code

* Скачайте и установите актуальную версию Visual Studio Code с [code.visualstudio.com](https://code.visualstudio.com/download)
* Установите расширение "C/C++ Extension Pack" (ms-vscode.cpptools-extension-pack)

## Сборка и запуск проекта

### Сборка проекта

```bash
# Создание директории для сборки
mkdir build
cd build

# Конфигурация проекта
cmake ..

# Сборка проекта
cmake --build .
```

### Запуск основной программы

```bash
# Из директории build
./gtest_exe
```

### Запуск тестов

```bash
# Из директории build
./tests

# Или через CTest
ctest --verbose
```

## Пример использования Google Test

### Основные макросы для тестирования

#### ASSERT макросы (прерывают выполнение при ошибке)
```cpp
ASSERT_TRUE(condition);      // Проверяет, что условие истинно
ASSERT_FALSE(condition);     // Проверяет, что условие ложно
ASSERT_EQ(expected, actual); // Проверяет равенство
ASSERT_NE(val1, val2);       // Проверяет неравенство
ASSERT_LT(val1, val2);       // Проверяет, что val1 < val2
ASSERT_LE(val1, val2);       // Проверяет, что val1 <= val2
ASSERT_GT(val1, val2);       // Проверяет, что val1 > val2
ASSERT_GE(val1, val2);       // Проверяет, что val1 >= val2
```

#### EXPECT макросы (продолжают выполнение при ошибке)
```cpp
EXPECT_TRUE(condition);      // Проверяет, что условие истинно
EXPECT_FALSE(condition);     // Проверяет, что условие ложно
EXPECT_EQ(expected, actual); // Проверяет равенство
EXPECT_NE(val1, val2);       // Проверяет неравенство
EXPECT_LT(val1, val2);       // Проверяет, что val1 < val2
EXPECT_LE(val1, val2);       // Проверяет, что val1 <= val2
EXPECT_GT(val1, val2);       // Проверяет, что val1 > val2
EXPECT_GE(val1, val2);       // Проверяет, что val1 >= val2
```

### Пример тестового файла

```cpp
#include <gtest/gtest.h>
#include "../include/calculator.h"

// Тест для проверки сложения положительных чисел
TEST(CalculatorTest, AdditionPositiveNumbers) {
    EXPECT_EQ(calculator(5, 3), 8);
    EXPECT_EQ(calculator(10, 20), 30);
}

// Тест для проверки сложения отрицательных чисел
TEST(CalculatorTest, AdditionNegativeNumbers) {
    EXPECT_EQ(calculator(-5, -3), -8);
    EXPECT_EQ(calculator(-10, 5), -5);
}

// Тест для проверки граничных случаев
TEST(CalculatorTest, EdgeCases) {
    EXPECT_EQ(calculator(0, 0), 0);
    EXPECT_EQ(calculator(100, 0), 100);
    EXPECT_EQ(calculator(0, 100), 100);
}

// Тест для проверки больших чисел
TEST(CalculatorTest, LargeNumbers) {
    EXPECT_EQ(calculator(1000000, 2000000), 3000000);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
```

## Варианты заданий

Напишите программу "калькулятор", которая будет:
* Вводить из стандартного ввода `std::cin` числа и символы, означающие действия с ними
* Выводить в стандартный вывод `std::cout` результат работы
* Быть оформлена в виде **функции**, вызываемой из `main`
* Unit-тесты должны проверять корректность работы программы, вызывая **функцию** с правильными и неправильными аргументами

### Шаблон программы

```cpp
#include <iostream>
#include <string>

// Объявление функции в заголовочном файле
std::string calculator(const std::string& lhv, const std::string& rhv);

int main() {
    std::string value1, value2;
    
    // Считываем значения переменных value1 и value2 из стандартного ввода
    std::cout << "Введите первое значение: ";
    std::cin >> value1;
    std::cout << "Введите второе значение: ";
    std::cin >> value2;
    
    std::string result = calculator(value1, value2);
    
    // Выводим значение result в стандартный вывод
    std::cout << "Результат: " << result << std::endl;
    
    return 0;
}
```

### Варианты операций

| № | Действие | Описание |
|---|----------|----------|
| 1 | Сложение целых чисел | `calculator("5", "3")` → `"8"` |
| 2 | Вычитание целых чисел | `calculator("10", "3")` → `"7"` |
| 3 | Умножение целых чисел | `calculator("4", "5")` → `"20"` |
| 4 | Деление целых чисел | `calculator("15", "3")` → `"5"` |
| 5 | Сложение вещественных чисел | `calculator("2.5", "3.7")` → `"6.2"` |
| 6 | Умножение вещественных чисел | `calculator("2.5", "4.0")` → `"10.0"` |
| 7 | Вычитание вещественных чисел | `calculator("10.5", "3.2")` → `"7.3"` |
| 8 | Деление вещественных чисел | `calculator("15.0", "3.0")` → `"5.0"` |
| 9 | Конкатенация двух строк | `calculator("Hello", "World")` → `"HelloWorld"` |
| 10 | Повторение строки | `calculator("Hi", "3")` → `"HiHiHi"` |

## Примеры тестов для различных вариантов

### Для арифметических операций (варианты 1-8)

```cpp
#include <gtest/gtest.h>
#include "../include/calculator.h"

TEST(CalculatorTest, Addition) {
    EXPECT_EQ(calculator("5", "3"), "8");
    EXPECT_EQ(calculator("-5", "3"), "-2");
    EXPECT_EQ(calculator("0", "0"), "0");
}

TEST(CalculatorTest, Division) {
    EXPECT_EQ(calculator("15", "3"), "5");
    EXPECT_EQ(calculator("10", "2"), "5");
    // Тест на деление на ноль
    EXPECT_EQ(calculator("10", "0"), "Error: Division by zero");
}
```

### Для строковых операций (варианты 9-10)

```cpp
TEST(CalculatorTest, StringConcatenation) {
    EXPECT_EQ(calculator("Hello", "World"), "HelloWorld");
    EXPECT_EQ(calculator("", "Test"), "Test");
    EXPECT_EQ(calculator("Test", ""), "Test");
}

TEST(CalculatorTest, StringRepetition) {
    EXPECT_EQ(calculator("Hi", "3"), "HiHiHi");
    EXPECT_EQ(calculator("A", "5"), "AAAAA");
    EXPECT_EQ(calculator("Test", "0"), "");
}
```

## Рекомендации по написанию тестов

1. **Покрытие граничных случаев**: тестируйте с нулевыми значениями, отрицательными числами, пустыми строками
2. **Тестирование ошибок**: проверяйте обработку некорректных входных данных
3. **Группировка тестов**: используйте осмысленные имена для тестовых групп
4. **Читаемость**: пишите понятные имена тестов и используйте комментарии
5. **Независимость**: каждый тест должен быть независимым от других

## Полезные ссылки

* [Google Test Documentation](https://google.github.io/googletest/)
* [CMake Tutorial](https://cmake.org/cmake/help/latest/guide/tutorial/)
* [Git Documentation](https://git-scm.com/doc)
* [C++ Reference](https://en.cppreference.com/)
