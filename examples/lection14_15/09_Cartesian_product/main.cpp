#include <iostream>

static void print(int x, int y)
{
    std::cout << "(" << x << ", " << y << ")\n";
}

int main()
{
    constexpr auto call_cart =
        // лямбда с первым параметром-функцией, параметром-условием и ее параметрами x и множеством rest
        [](auto func, auto cond, auto x, auto... rest) constexpr
    {
        //std::cout << "call_cart for " << x << " with " << sizeof...(rest) << " elements" << std::endl;
        
        // используем initializer list для итерации по параметрам
        // вызываем func для всех параметров, для которых cond(x,rest) истина

        (void)std::initializer_list<int>{
            ((cond(x, rest)
                  ? (void)func(x, rest)
                  : (void)0),
             0)...}; 
        std::cout << std::endl;
    };

    constexpr auto cartesian =
        [=](auto... xs) constexpr
    {
        // вернем лямбду с одним параметром - то же лямбдой f
        return [=](auto f, auto cond) constexpr
        {
            // с помощью initializer_list развертываем функцию
            // первый параметр функция, которую будем вызывать к парам
            // второй параметр функция, которая будет определять условие (нужно ли вызывать первую функцию)
            // первый параметр переберает все параметры функции - xs
            // второй параметр передает все параметры в функцию - xs ...
            (void)std::initializer_list<int>{
                ((void)call_cart(f, cond, xs, xs...), 0)...};
        };
    };

    constexpr auto print_cart = cartesian(1, 2, 3, 4, 5, 6);
/*
    print_cart([](auto lhv, auto rhv) { std::cout << '(' << lhv << ',' << rhv << ')'; },
               [](auto lhv, auto rhv) { return lhv < rhv; });
*/

    print_cart([](auto lhv, auto rhv) { std::cout << '(' << lhv << ',' << rhv << ')'; },
               [](auto lhv, auto rhv) { return true; });
}
