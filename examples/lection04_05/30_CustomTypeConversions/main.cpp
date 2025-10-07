#include <iostream>
#include "point.h"
#include "number.h"

// Функция для демонстрации преобразования Number -> double
double sum_doubles(double first_value, double second_value) {
    return first_value + second_value;
}

// Функция для демонстрации преобразования Number -> Point
void use_point_function(const Point& point_object) {
    std::cout << "Printing the point from use_point_function: " << point_object << std::endl;
}

int main() {
    // ДЕМОНСТРАЦИЯ ПОЛЬЗОВАТЕЛЬСКИХ ПРЕОБРАЗОВАНИЙ ТИПОВ
    
    std::cout << "=== Демонстрация пользовательских преобразований типов ===" << std::endl;
    
    // Создание объектов Number для демонстрации
    Number first_number(22);
    Number second_number(10);
    
    std::cout << "--- Исходные объекты Number ---" << std::endl;
    std::cout << "First number: " << first_number << std::endl;   // Number: [22]
    std::cout << "Second number: " << second_number << std::endl; // Number: [10]
    
    std::cout << "\n--- Демонстрация преобразующего оператора Number -> double ---" << std::endl;
    
    // ДЕМОНСТРАЦИЯ 1: Явное преобразование Number -> double
    // ВАЖНО: используем static_cast для явного преобразования через explicit оператор
    double conversion_result = sum_doubles(static_cast<double>(first_number), 
                                          static_cast<double>(second_number));
    
    std::cout << "Результат явного преобразования Number -> double: " << conversion_result << std::endl; // 32.0
    
    // ДЕМОНСТРАЦИЯ 2: Попытка неявного преобразования (закомментировано)
    // ВАЖНО: explicit оператор предотвращает неявные преобразования
    // double result2 = sum_doubles(first_number, second_number);  // ОШИБКА КОМПИЛЯЦИИ!
    
    std::cout << "\n--- Демонстрация преобразующего оператора Number -> Point ---" << std::endl;
    
    // ДЕМОНСТРАЦИЯ 3: Явное преобразование Number -> Point
    // ВАЖНО: используем static_cast для явного преобразования через explicit оператор
    std::cout << "Преобразование first_number в Point:" << std::endl;
    use_point_function(static_cast<Point>(first_number));
    
    // ДЕМОНСТРАЦИЯ 4: Попытка неявного преобразования (закомментировано)
    // ВАЖНО: explicit оператор предотвращает неявные преобразования
    // use_point_function(first_number);  // ОШИБКА КОМПИЛЯЦИИ!
    
    std::cout << "\n--- Дополнительные примеры преобразований ---" << std::endl;
    
    // ДЕМОНСТРАЦИЯ 5: Прямое использование преобразующих операторов
    double direct_double_conversion = static_cast<double>(first_number);
    std::cout << "Прямое преобразование Number -> double: " << direct_double_conversion << std::endl; // 22.0
    
    Point direct_point_conversion = static_cast<Point>(second_number);
    std::cout << "Прямое преобразование Number -> Point: " << direct_point_conversion << std::endl; // Point(10, 10)
    
    // ДЕМОНСТРАЦИЯ 6: Использование в выражениях
    double expression_result = static_cast<double>(first_number) + static_cast<double>(second_number);
    std::cout << "Использование в выражении: " << expression_result << std::endl; // 32.0
    
    std::cout << "\n--- Демонстрация арифметических операторов Number ---" << std::endl;
    
    // ДЕМОНСТРАЦИЯ 7: Арифметические операции с Number
    Number sum_result = first_number + second_number;
    Number difference_result = first_number - second_number;
    Number product_result = first_number * second_number;
    Number quotient_result = first_number / second_number;
    Number remainder_result = first_number % second_number;
    
    std::cout << "Number operations:" << std::endl;
    std::cout << first_number << " + " << second_number << " = " << sum_result << std::endl;       // Number: [32]
    std::cout << first_number << " - " << second_number << " = " << difference_result << std::endl; // Number: [12]
    std::cout << first_number << " * " << second_number << " = " << product_result << std::endl;   // Number: [220]
    std::cout << first_number << " / " << second_number << " = " << quotient_result << std::endl;  // Number: [2]
    std::cout << first_number << " % " << second_number << " = " << remainder_result << std::endl; // Number: [2]
    
    std::cout << "\n=== Важные выводы ===" << std::endl;
    std::cout << "1. Преобразующие операторы позволяют преобразование типа объекта" << std::endl;
    std::cout << "2. explicit предотвращает неявные преобразования" << std::endl;
    std::cout << "3. static_cast используется для явного преобразования" << std::endl;
    std::cout << "4. Синтаксис: explicit operator TargetType() const" << std::endl;
    std::cout << "5. Преобразующие операторы являются методами класса" << std::endl;
    
    std::cout << "\n=== Типы пользовательских преобразований ===" << std::endl;
    std::cout << "1. Преобразующие операторы (conversion operators)" << std::endl;
    std::cout << "   - operator TargetType() const" << std::endl;
    std::cout << "   - Позволяют преобразование Source -> Target" << std::endl;
    std::cout << "2. Конструкторы преобразования (converting constructors)" << std::endl;
    std::cout << "   - Target(const Source& source)" << std::endl;
    std::cout << "   - Позволяют преобразование Source -> Target" << std::endl;
    
    std::cout << "\n=== Преимущества explicit ===" << std::endl;
    std::cout << "1. Предотвращает неожиданные неявные преобразования" << std::endl;
    std::cout << "2. Делает код более явным и понятным" << std::endl;
    std::cout << "3. Помогает избежать ошибок компиляции" << std::endl;
    std::cout << "4. Соответствует принципу явности кода" << std::endl;
    
    std::cout << "\n=== Применение пользовательских преобразований ===" << std::endl;
    std::cout << "1. Математические классы - преобразование в базовые типы" << std::endl;
    std::cout << "2. Обертки (wrappers) - преобразование в обернутые типы" << std::endl;
    std::cout << "3. Совместимость с существующими API" << std::endl;
    std::cout << "4. Упрощение интерфейса классов" << std::endl;
    
    std::cout << "\n=== Программа завершается ===" << std::endl;
    
    return 0;
}