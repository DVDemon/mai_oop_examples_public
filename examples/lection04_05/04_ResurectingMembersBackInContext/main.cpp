#include <iostream>
#include "person.h"
#include "engineer.h"
#include "civilengineer.h"

int main() {
    // ДЕМОНСТРАЦИЯ 1: Создание константного объекта Person
    const Person person;
    std::cout << "Person address: " << person.get_address() << std::endl;
    
    // ДЕМОНСТРАЦИЯ 2: Engineer с private наследованием
    Engineer engineer;
    
    // Метод add() был "воскрешен" как public через using в Engineer
    int sum1 = engineer.add(5, 3);         // OK - метод add доступен благодаря "using Person::add"
    int sum2 = engineer.add(5, 3, 2);      // OK - перегруженная версия
    std::cout << "Engineer add(5,3): " << sum1 << std::endl;
    std::cout << "Engineer add(5,3,2): " << sum2 << std::endl;
    
    // НО: геттеры НЕ доступны извне, т.к. они protected в Engineer
    // engineer.get_full_name();  // ОШИБКА - метод protected в Engineer
    
    // ДЕМОНСТРАЦИЯ 3: CivilEngineer
    CivilEngineer civil_engineer;
    civil_engineer.build_road();  // Метод использует "воскрешенные" члены
    
    // Метод add доступен и для CivilEngineer (public в Engineer)
    int result = civil_engineer.add(10, 20);
    std::cout << "CivilEngineer add(10,20): " << result << std::endl;
    
    return 0;
}