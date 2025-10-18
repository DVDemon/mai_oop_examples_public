#include <iostream>

namespace example
{
    // Метафункция для вычисления абсолютного значения
    // ВАЖНО: Метафункция - это шаблон, который выполняет вычисления на этапе компиляции
    // Результат вычисляется компилятором и становится константой
    template <int value>
    struct abs
    {
        // Статическая константа, вычисляемая на этапе компиляции
        static const int result = value < 0 ? -value : value;
    };
}

// Функция, возвращающая константу времени компиляции
// ВАЖНО: constexpr позволяет использовать функцию в константных выражениях
constexpr int get_value()
{
    return -99;
}

int main()
{
    // Демонстрация метафункции - создание объекта
    example::abs<10> abs_instance;
    std::cout << "abs_instance.result = " << abs_instance.result << std::endl;

    // Демонстрация прямого доступа к результату метафункции
    // ВАЖНО: Все вычисления происходят на этапе компиляции
    std::cout << "example::abs<10>::result = " << example::abs<10>::result << std::endl;
    std::cout << "example::abs<-20>::result = " << example::abs<-20>::result << std::endl;
    
    // Демонстрация использования constexpr функции в метафункции
    // ВАЖНО: get_value() вычисляется на этапе компиляции благодаря constexpr
    std::cout << "example::abs<get_value()>::result = " 
              << example::abs<get_value()>::result << std::endl;

    return 0;
}