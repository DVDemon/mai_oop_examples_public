#include <iostream>

// Базовый шаблон класса Foo с тремя параметрами-типами
// ВАЖНО: Складывает второе и третье "число" и приводит результат к типу первого
template <class A, class B, class C>
struct Foo
{
    // Метод сложения с приведением типа
    A add(B first_value, C second_value)
    {
        return static_cast<A>(first_value + second_value);
    }
};

// Частичная специализация шаблона Foo
// ВАЖНО: Специализация для случаев, когда B=char и C=char
// template <class A> означает, что A остается параметром шаблона
template <class A>
struct Foo<A, char, char>
{
    // Специальная реализация для char + char
    // ВАЖНО: Вычитаем '0' для корректного преобразования символов в числа
    A add(char first_char, char second_char)
    {
        // std::cout << "char" << std::endl;  // Для отладки
        return static_cast<A>(first_char + second_char - '0' - '0');
    }
};

// Шаблон функции add (для сравнения с классом)
template <class A, class B, class C>
A add(B first_value, C second_value)
{
    return static_cast<A>(first_value + second_value);
}

/*
ВАЖНОЕ ОГРАНИЧЕНИЕ: Частичная специализация НЕ разрешена для функций!

// Это НЕ разрешено в C++:
template <class A>
A add<A, char, char>(char b, char c) {
    return static_cast<A>(b + c - '0' - '0');
}

Для функций можно использовать только полную специализацию:
template <>
int add<int, char, char>(char b, char c) {
    return b + c - '0' - '0';
}
*/

int main()
{
    // Демонстрация базового шаблона: Foo<int, int, int>
    // Обычное арифметическое сложение: 5 + 3 = 8
    std::cout << "Foo<int,int,int>().add(5,3) = " 
              << Foo<int, int, int>().add(5, 3) << std::endl;

    // Демонстрация частичной специализации: Foo<int, char, char>
    // Специальная логика для char: '2' + '2' - '0' - '0' = 2 + 2 = 4
    std::cout << "Foo<int,char,char>().add('2','2') = " 
              << Foo<int, char, char>().add('2', '2') << std::endl;

    // Демонстрация частичной специализации: Foo<char, char, char>
    // Результат приводится к char: '0' + 1 - '0' - '0' = 1, затем static_cast<char>(1)
    std::cout << "Foo<char,char,char>().add('0',1) = " 
              << Foo<char, char, char>().add('0', 1) << std::endl;

    // Демонстрация шаблона функции (без специализации)
    std::cout << "add<int,int,int>(1,2) = " 
              << add<int, int, int>(1, 2) << std::endl;

    // Демонстрация шаблона функции (без специализации для char)
    // Обычное сложение ASCII кодов: '1' + '2' = 49 + 50 = 99
    std::cout << "add<int,char,char>('1','2') = " 
              << add<int, char, char>('1', '2') << std::endl;

    return 0;
}