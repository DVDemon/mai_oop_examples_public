#include <iostream>

namespace MyTemplates
{

    // Шаблон класса с двумя параметрами-типами
    // ВАЖНО: Несколько параметров шаблона разделяются запятыми
    template <class A, class B>
    class Sum
    {
    private:
        A a;  // Первое значение типа A
        B b;  // Второе значение типа B

    public:
        // Конструктор, принимающий значения типов A и B
        Sum(A a_value, B b_value) : a(a_value), b(b_value)
        {
        }

        // Дружественная функция для вывода в поток
        // ВАЖНО: Параметры C и D (а не A, B), поскольку это ссылка на другой шаблон
        // Это позволяет использовать operator<< с любыми типами Sum<C, D>
        template <class C, class D>
        friend std::ostream& operator<<(std::ostream& os, const Sum<C, D>& sum);
    };

    // Шаблон функции operator<< для вывода объекта Sum в поток
    // ВАЖНО: Это внешняя функция-шаблон, которая работает с любыми типами Sum<A, B>
    template <class A, class B>
    std::ostream& operator<<(std::ostream& os, const Sum<A, B>& sum)
    {
        os << sum.a << "," << sum.b << " ";
        return os;
    }
} // namespace MyTemplates

int main(int argc, char **argv)
{

    using namespace MyTemplates;

    // Демонстрация 1: Простой шаблон с двумя параметрами одного типа
    MyTemplates::Sum<int, int> simple_sum(1, 2);
    std::cout << "Simple sum: " << simple_sum << std::endl;

    // Демонстрация 2: Вложенные шаблоны
    // ВАЖНО: Один из параметров - это другой шаблонный тип
    // Создаем Sum<int, Sum<int, int>> - сумма числа и другой суммы
    Sum<int, Sum<int, int>> sum_of_sum(1, Sum<int, int>(2, 3));
    std::cout << "Sum of sum: " << sum_of_sum << std::endl;

    // Демонстрация 3: Глубокая вложенность шаблонов
    // ВАЖНО: Это показывает, как можно создавать сложные типы из шаблонов
    // Тип: Sum<int, Sum<int, Sum<int, Sum<int, int>>>>
    // Это сумма числа и вложенной суммы, которая содержит еще более глубокую вложенность
    Sum<int, Sum<int, Sum<int, Sum<int, int>>>> deep_nesting(
        1, 
        Sum<int, Sum<int, Sum<int, int>>>(
            2, 
            Sum<int, Sum<int, int>>(
                3, 
                Sum<int, int>(4, 5)
            )
        )
    );
    std::cout << "Deep nesting: " << deep_nesting << std::endl;

    return 0;
}
