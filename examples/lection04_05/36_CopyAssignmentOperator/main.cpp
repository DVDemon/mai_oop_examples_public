#include <iostream>
#include "point.h"

int main()
{
    std::cout << "Copy Assignment Operator Demo" << std::endl;
    
    // Создаем три точки с разными координатами и данными
    Point p1(10, 10, 10);
    Point p2(20, 20, 20);
    Point p77(3, 3, 3);

    std::cout << "p1 : " << p1 << std::endl;
    std::cout << "p2 : " << p2 << std::endl;

    std::cout << "-----" << std::endl;

    // Демонстрация цепочки присваиваний
    // Эквивалентные способы записи:
    // p1 = p2 = p77;                    // Обычный синтаксис
    // p1.operator=(p2).operator=(p77);  // Явный вызов методов
    p1.operator=(p2.operator=(p77));    // Явный вызов с правильным порядком

    std::cout << "p1 : " << p1 << std::endl;
    std::cout << "p2 : " << p2 << std::endl;

    // Изменяем данные в p1
    // ВАЖНО: Это НЕ влияет на p2, так как у каждого объекта своя копия данных
    p1.set_data(55);

    std::cout << "-----------" << std::endl;
    std::cout << "p1 : " << p1 << std::endl;  // data = 55
    std::cout << "p2 : " << p2 << std::endl;  // data = 3 (не изменилось)

    // Демонстрация оператора присваивания перемещением
    std::cout << "-----------" << std::endl;
    Point p3;

    // Временный объект Point(1,1,1) будет перемещен в p3
    // Это вызовет move assignment operator, а не copy assignment operator
    p3 = Point(1, 1, 1);
    std::cout << "p3 : " << p3 << std::endl;

    /*
    ЗАКОММЕНТИРОВАННЫЙ КОД - демонстрация конструктора копирования:
    
    Point p3(30, 30, 30);
    Point p4 = p3;  // Вызов конструктора копирования, НЕ оператора присваивания

    std::cout << "p3 : " << p3 << std::endl;
    std::cout << "p4 : " << p4 << std::endl;

    p3.set_data(77);

    std::cout << "-----" << std::endl;
    std::cout << "p3 : " << p3 << std::endl;  // data = 77
    std::cout << "p4 : " << p4 << std::endl;  // data = 30 (не изменилось)

    std::cout << "Done!" << std::endl;
    */

    return 0;
}