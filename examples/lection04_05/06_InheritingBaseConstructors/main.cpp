#include <iostream>
#include "person.h"
#include "engineer.h"

int main() {
    // ДЕМОНСТРАЦИЯ 1: Использование дополнительного конструктора Engineer
    // Вызывается Engineer(std::string_view, int, std::string_view, int)
    std::cout << "=== Creating Engineer with contract_count ===" << std::endl;
    Engineer engineer_with_contract("Daniel Gray", 23, "123 Main Street", 4);
    
    // ДЕМОНСТРАЦИЯ 2: Наследование конструктора Person
    // Благодаря "using Person::Person" можем использовать конструктор Person для Engineer!
    // Вызывается Person(std::string_view, int, std::string_view) - НАСЛЕДОВАННЫЙ
    std::cout << "\n=== Creating Engineer using inherited Person constructor ===" << std::endl;
    Engineer engineer_inherited("Daniel Gray", 23, "456 Oak Avenue");  // Наследованный конструктор
    
    // ДЕМОНСТРАЦИЯ 3: Наследование конструктора по умолчанию
    // Вызывается Person() - НАСЛЕДОВАННЫЙ
    std::cout << "\n=== Creating Engineer using inherited default constructor ===" << std::endl;
    Engineer engineer_default;  // Наследованный конструктор по умолчанию
    
    // ДЕМОНСТРАЦИЯ 4: Проверка доступа к методам
    std::cout << "\n=== Testing inherited methods ===" << std::endl;
    std::cout << "Engineer with contract: " << engineer_with_contract.get_contract_count() << " contracts" << std::endl;
    std::cout << "Engineer inherited name: " << engineer_inherited.get_full_name() << std::endl;
    std::cout << "Engineer default age: " << engineer_default.get_age() << std::endl;
    
    return 0;
}