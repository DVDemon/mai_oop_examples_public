#include <iostream>
#include "point.h"
#include "number.h"

// Функция, принимающая константную ссылку на Point
void do_something_with_point(const Point& point)
{
    std::cout << "point : " << point << std::endl;
}

int main(int argc, char** argv)
{
    // Создаем точку с координатами (10, 10)
    Point p1(10, 10);
    
    // Создаем число со значением 22
    Number n1(22);

    /*
    ДЕМОНСТРАЦИЯ РАЗЛИЧНЫХ СПОСОБОВ ПРЕОБРАЗОВАНИЯ ТИПОВ:
    
    // СПОСОБ 1: Прямое присваивание (раскомментировать для тестирования)
    p1 = n1;
    // Возможные варианты:
    // 1. Copy assignment operator: void operator=(const Number&)
    // 2. Constructor taking Number: Point(const Number&) - если раскомментирован
    // 3. Type conversion operator: operator Point() - НЕ подходит для присваивания
    */

    // СПОСОБ 2: Неявное преобразование при передаче в функцию
    // ВАЖНО: Вызывается operator Point() из класса Number
    // Number автоматически преобразуется в Point
    do_something_with_point(n1);
    
    // Возможные варианты для do_something_with_point(n1):
    // 1. Constructor: Point(const Number&) - если раскомментирован
    // 2. Type conversion operator: operator Point() - ИСПОЛЬЗУЕТСЯ В ДАННОМ СЛУЧАЕ

    return 0;
}
