#include <iostream>

// Базовый шаблон класса (Primary Template)
// ВАЖНО: Это общая реализация для всех типов T
template <class T>
class MyContainer
{
    T element;  // Элемент типа T

public:
    // Конструктор, принимающий значение типа T
    MyContainer(T argument) : element(argument)
    {
    }

    // Метод увеличения значения (работает для числовых типов)
    T increase()
    {
        return ++element;
    }

    // Метод уменьшения значения (работает для числовых типов)
    T decrease()
    {
        return --element;
    }
};

// Специализация шаблона для типа char (Template Specialization)
// ВАЖНО: Это специальная реализация только для типа char
// template <> означает полную специализацию шаблона
template <>
class MyContainer<char>
{
    char element;  // Элемент типа char

public:
    // Конструктор для char
    MyContainer(char argument) : element(argument)
    {
    }

    // Специальный метод для char - преобразование в верхний регистр
    char uppercase()
    {
        if ((element >= 'a') && (element <= 'z')) {
            element += 'A' - 'a';  // Преобразование в верхний регистр
        }
        return element;
    }

    // Переопределение метода increase для char
    // ВАЖНО: Для char "увеличение" означает преобразование в верхний регистр
    char increase()
    {
        if ((element >= 'a') && (element <= 'z')) {
            element += 'A' - 'a';  // Преобразование в верхний регистр
        }
        return element;
    }

    // Переопределение метода decrease для char
    // ВАЖНО: Для char "уменьшение" означает преобразование в нижний регистр
    char decrease()
    {
        if ((element >= 'A') && (element <= 'Z')) {
            element -= 'A' - 'a';  // Преобразование в нижний регистр
        }
        return element;
    }
};

int main(int argc, char** argv)
{
    // Демонстрация базового шаблона для типа int
    MyContainer<int> int_container(7);
    std::cout << "int increase(): " << int_container.increase() << std::endl;

    // Демонстрация специализации шаблона для типа char
    MyContainer<char> char_container('j');
    
    // Использование специального метода uppercase (только для char)
    std::cout << "char uppercase(): " << char_container.uppercase() << std::endl;
    
    // Использование переопределенного метода increase (для char = uppercase)
    std::cout << "char increase(): " << char_container.increase() << std::endl;
    
    // Использование переопределенного метода decrease (для char = lowercase)
    std::cout << "char decrease(): " << char_container.decrease() << std::endl;

    return 0;
}

