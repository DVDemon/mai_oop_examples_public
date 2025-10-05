#include <iostream>
#include "person.h"
#include "engineer.h"
#include "civilengineer.h"

int main() {
    // ДЕМОНСТРАЦИЯ ПОРЯДКА ВЫЗОВА КОНСТРУКТОРОВ И ДЕСТРУКТОРОВ
    std::cout << "=== Creating CivilEngineer object ===" << std::endl;
    
    // При создании объекта CivilEngineer вызываются конструкторы в порядке:
    // 1. Person("Daniel Gray", 41, "Green Sky Oh Blue 33St#75")
    // 2. Engineer("Daniel Gray", 41, "Green Sky Oh Blue 33St#75", 12)
    // 3. CivilEngineer("Daniel Gray", 41, "Green Sky Oh Blue 33St#75", 12, "Road Strength")
    CivilEngineer civil_engineer("Daniel Gray", 41, "Green Sky Oh Blue 33St#75", 12, "Road Strength");
    
    std::cout << "\n=== Object created successfully ===" << std::endl;
    std::cout << "Engineer name: " << civil_engineer.get_full_name() << std::endl;
    std::cout << "Engineer age: " << civil_engineer.get_age() << std::endl;
    std::cout << "Contract count: " << civil_engineer.get_contract_count() << std::endl;
    
    std::cout << "\n=== Program ending - destructors will be called ===" << std::endl;
    // При выходе из main() автоматически вызываются деструкторы в обратном порядке:
    // 1. ~CivilEngineer()
    // 2. ~Engineer()
    // 3. ~Person()
    
    return 0;
}