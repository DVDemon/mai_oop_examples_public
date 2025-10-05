#include <iostream>
#include "child.h"

int main() {
    // ДЕМОНСТРАЦИЯ ПЕРЕИСПОЛЬЗОВАНИЯ СИМВОЛОВ В НАСЛЕДОВАНИИ
    
    // Создаем объект Child с параметром
    // ВАЖНО: Child(33) инициализирует только Child::m_member_var = 33
    // Parent::m_member_var остается со значением по умолчанию (100)
    Child child_object(33);
    
    std::cout << "=== Method calls ===" << std::endl;
    
    // Вызов переопределенного метода Child::print_var()
    // Показывает значение Child::m_member_var = 33
    child_object.print_var();  // Calls the method in Child
    
    // Вызов метода Parent через квалифицированное имя
    // Показывает значение Parent::m_member_var = 100 (значение по умолчанию)
    child_object.Parent::print_var();  // Calls the method in Parent
    
    std::cout << "\n=== Direct field access ===" << std::endl;
    
    // Демонстрация прямого доступа к полям с одинаковыми именами
    child_object.show_values();
    
    return 0;
}