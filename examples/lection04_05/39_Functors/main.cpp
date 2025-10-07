#include <iostream>
#include <string>

// Класс-функтор (Functor) - объект, который ведет себя как функция
// Функтор реализуется через перегрузку оператора operator()
class Print
{
public:
    // Перегрузка оператора () для одного параметра
    // Позволяет использовать объект как функцию: print("John")
    void operator()(const std::string& name) const
    {
        std::cout << "The name is : " << name << std::endl;
    }

    // Перегрузка оператора () для двух параметров (перегрузка функций)
    // Позволяет использовать объект как функцию: print("Daniel", "Gray")
    std::string operator()(const std::string& last_name,
                           const std::string& first_name) const
    {
        return (last_name + " " + first_name);
    }
};

// Функция, принимающая функтор как параметр
// ВАЖНО: Функтор передается по константной ссылке
void do_something(const Print& printer)
{
    // Вызываем функтор как обычную функцию
    printer("Snow");
}

int main()
{
    // Создаем объект-функтор
    Print print;

    // Демонстрация функтора с одним параметром
    // Эквивалентно: print.operator()("John")
    print("John");

    // Передача функтора в функцию
    do_something(print);

    // Демонстрация функтора с двумя параметрами
    // Эквивалентно: print.operator()("Daniel", "Gray")
    std::cout << print("Daniel", "Gray") << std::endl;

    return 0;
}