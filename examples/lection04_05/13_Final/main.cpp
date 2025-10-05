#include <iostream>
#include "animal.h"
#include "feline.h"
#include "dog.h"
#include "cat.h"
#include "bird.h"
#include "crow.h"
#include "pigeon.h"
#include "bulldog.h"
#include "wildcat.h"

// ПРИМЕР 1: final класс - наследование ЗАПРЕЩЕНО
/*
class Plane final {
    Plane() = default;
};

// ЭТО ВЫЗОВЕТ ОШИБКУ КОМПИЛЯЦИИ - нельзя наследоваться от final класса
class FighterJet : public Plane {
    // Ошибка компиляции!
};
*/

int main() {
    // ДЕМОНСТРАЦИЯ ИСПОЛЬЗОВАНИЯ КЛЮЧЕВОГО СЛОВА FINAL
    
    std::cout << "=== Демонстрация final в C++ ===" << std::endl;
    
    // Создание объектов разных типов
    Dog dog_object("short", "Rex");
    Cat cat_object("long", "Whiskers");
    Crow crow_object("black", "Blacky");
    Pigeon pigeon_object("gray", "Dove");
    BullDog bulldog_object;
    
    std::cout << "\n=== Демонстрация final методов ===" << std::endl;
    
    // Демонстрация final метода run() в Dog
    std::cout << "--- Вызов final метода run() ---" << std::endl;
    dog_object.run();        // Dog::run() - final, нельзя переопределить
    
    // Демонстрация переопределения run() в Cat
    cat_object.run();        // Cat::run() - переопределяет Feline::run()
    
    std::cout << "\n--- Вызов final метода fly() ---" << std::endl;
    // Демонстрация final метода fly() в Bird
    crow_object.fly();       // Bird::fly() - final, нельзя переопределить
    pigeon_object.fly();     // Bird::fly() - final, нельзя переопределить
    
    std::cout << "\n--- Вызов собственных методов ---" << std::endl;
    dog_object.bark();       // Dog::bark() - виртуальная функция
    cat_object.miaw();       // Cat::miaw() - виртуальная функция (бесполезна в final классе)
    crow_object.cow();       // Crow::cow() - виртуальная функция
    pigeon_object.coo();     // Pigeon::coo() - виртуальная функция
    
    std::cout << "\n=== Важные выводы ===" << std::endl;
    std::cout << "1. final классы - наследование ЗАПРЕЩЕНО" << std::endl;
    std::cout << "2. final методы - переопределение ЗАПРЕЩЕНО" << std::endl;
    std::cout << "3. virtual final - можно переопределить один раз, дальше запрещено" << std::endl;
    std::cout << "4. Виртуальные функции в final классах технически бесполезны" << std::endl;
    
    std::cout << "\n=== Программа завершается ===" << std::endl;
    // При завершении программы автоматически вызываются деструкторы
    
    return 0;
}