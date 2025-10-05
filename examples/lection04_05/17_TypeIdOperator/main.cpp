#include <iostream>
#include "polymorphic.h"
#include "nonpolymorphic.h"

int main() {
    // ДЕМОНСТРАЦИЯ ОПЕРАТОРА TYPEID В C++
    
    std::cout << "=== Демонстрация typeid operator ===" << std::endl;
    
    // ДЕМОНСТРАЦИЯ 1: typeid с фундаментальными типами
    std::cout << "--- typeid с фундаментальными типами ---" << std::endl;
    
    // typeid с типами возвращает статическую информацию о типе
    std::cout << "typeid(int): " << typeid(int).name() << std::endl;
    
    // typeid с литералами - проверка типа во время компиляции
    if (typeid(22.2f) == typeid(float)) {
        std::cout << "22.2f is a float" << std::endl;
    } else {
        std::cout << "22.2f is not float" << std::endl;
    }
    
    std::cout << "----------------" << std::endl;
    
    // ДЕМОНСТРАЦИЯ 2: typeid с полиморфными ссылками
    std::cout << "--- typeid с полиморфными ссылками ---" << std::endl;
    
    // Создание объекта производного класса
    DynamicDerived dynamic_derived_object;
    
    // Ссылка на базовый класс, указывающая на объект производного класса
    DynamicBase& base_reference = dynamic_derived_object;
    
    // typeid с объектом - возвращает реальный тип объекта
    std::cout << "Type of dynamic_derived_object: " << typeid(dynamic_derived_object).name() << std::endl;
    
    // typeid с полиморфной ссылкой - возвращает ДИНАМИЧЕСКИЙ тип объекта!
    std::cout << "Type of base_reference: " << typeid(base_reference).name() << std::endl;
    
    std::cout << "----------------" << std::endl;
    
    // ДЕМОНСТРАЦИЯ 3: typeid с полиморфными указателями
    std::cout << "--- typeid с полиморфными указателями ---" << std::endl;
    
    // Указатель на базовый класс, указывающий на объект производного класса
    DynamicBase* base_pointer = new DynamicDerived;
    
    // ВАЖНО: typeid с указателем возвращает СТАТИЧЕСКИЙ тип указателя
    std::cout << "Type of base_pointer: " << typeid(base_pointer).name() << std::endl;
    
    // ВАЖНО: Для получения динамического типа нужно разыменовать указатель!
    std::cout << "Type of *base_pointer: " << typeid(*base_pointer).name() << std::endl;
    
    std::cout << "----------------" << std::endl;
    
    // ДЕМОНСТРАЦИЯ 4: typeid с НЕ полиморфными указателями и ссылками
    std::cout << "--- typeid с НЕ полиморфными типами ---" << std::endl;
    
    // НЕ полиморфные классы - без виртуальных функций
    StaticBase* static_base_pointer = new StaticDerived;
    StaticDerived static_derived_object;
    StaticBase& static_base_reference{static_derived_object};
    
    // ВАЖНО: Для НЕ полиморфных типов typeid всегда возвращает СТАТИЧЕСКИЙ тип
    std::cout << "Type of *static_base_pointer: " << typeid(*static_base_pointer).name() << std::endl;
    std::cout << "Type of static_base_reference: " << typeid(static_base_reference).name() << std::endl;
    std::cout << "Type of static_derived_object: " << typeid(static_derived_object).name() << std::endl;
    
    std::cout << "\n=== Важные выводы ===" << std::endl;
    std::cout << "1. typeid с полиморфными ссылками возвращает ДИНАМИЧЕСКИЙ тип" << std::endl;
    std::cout << "2. typeid с полиморфными указателями требует разыменования (*ptr)" << std::endl;
    std::cout << "3. typeid с НЕ полиморфными типами всегда возвращает СТАТИЧЕСКИЙ тип" << std::endl;
    std::cout << "4. Полиморфизм работает только при наличии виртуальных функций" << std::endl;
    std::cout << "5. typeid.name() возвращает имя типа (может быть нечитаемым)" << std::endl;
    
    std::cout << "\n=== Программа завершается ===" << std::endl;
    
    // Освобождение памяти
    delete base_pointer;
    delete static_base_pointer;
    
    return 0;
}