#include <iostream>
#include "person.h"
#include "engineer.h"
#include "civilengineer.h"

int main() {
    // ДЕМОНСТРАЦИЯ 1: Создание объекта Person
    // Вызывается конструктор Person(fullname, age, address)
    std::cout << "=== Creating Person ===" << std::endl;
    Person person("John Snow", 27, "Winterfell Cold 33St#75");
    
    // ДЕМОНСТРАЦИЯ 2: Создание объекта Engineer
    // Порядок вызова конструкторов: Person → Engineer
    std::cout << "\n=== Creating Engineer ===" << std::endl;
    Engineer engineer("Daniel Gray", 41, "Green Sky Oh Blue 33St#75", 12);
    
    // ДЕМОНСТРАЦИЯ 3: Создание объекта CivilEngineer
    // Порядок вызова конструкторов: Person → Engineer → CivilEngineer
    std::cout << "\n=== Creating CivilEngineer ===" << std::endl;
    CivilEngineer civil_engineer("John Travolta", 51, "Tiny Dog 42St#89", 31, "Road Strength");
    
    std::cout << "\n=== Program ending (destructors will be called) ===" << std::endl;
    // При выходе из main() автоматически вызываются деструкторы в обратном порядке:
    // ~CivilEngineer → ~Engineer → ~Person (для civil_engineer)
    // ~Engineer → ~Person (для engineer)
    // ~Person (для person)
    
    return 0;
}