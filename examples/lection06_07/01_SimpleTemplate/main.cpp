#include <iostream>
#include <string>

// Шаблон класса с параметром-типом
// ВАЖНО: template <class T> - это устаревший синтаксис, современный: template <typename T>
// Но оба варианта эквивалентны и работают одинаково
template <class T>
struct Container
{
    T payload;  // Поле типа T для хранения данных
    
    // Конструктор, принимающий значение типа T
    Container(const T& value) : payload(value) {}
};

// Шаблон функции с параметром-типом
// ВАЖНО: Компилятор может автоматически вывести тип T из аргумента
template <class T>
T print(T value)
{
    std::cout << "Value: " << value << " size: " << sizeof(T) << std::endl;
    return value;
}

// Шаблон класса с параметром-константой (non-type template parameter)
// ВАЖНО: Параметр V должен быть константой времени компиляции
template <int V>
struct foo
{
    static const int value = V;  // Статическая константа
};

int main(int argc, char** argv)
{
    // Демонстрация шаблонов функций
    
    // Явное указание типа шаблона
    print("Hello world!");
    print<std::string>("Hello world!");
    
    // Автоматический вывод типа (type deduction)
    // Компилятор сам определит тип из аргумента
    print(std::string("Hello world!"));

    /*
    ДОПОЛНИТЕЛЬНЫЕ ПРИМЕРЫ (закомментированы для краткости):
    
    // Явное указание типов
    print<int>(10);
    print<double>(0.5);
    print<char>(48);
    
    // Автоматический вывод типов
    print(10);        // int
    print(0.5);       // double
    print('A');       // char
    
    // Создание объектов шаблонного класса
    Container<int> container_int(10);
    Container<std::string> container_string("Hello");
    
    // Вложенные шаблоны (template nesting)
    Container<Container<const char*>> nested_container(
        Container<const char*>("Hi there!")
    );
    std::cout << nested_container.payload.payload << std::endl;
    */

    // Демонстрация шаблона с параметром-константой
    constexpr int A = 10;  // constexpr необходимо для параметра шаблона
    std::cout << "foo<" << A << ">::value = " << foo<A>::value << std::endl;

    return 0;
}


