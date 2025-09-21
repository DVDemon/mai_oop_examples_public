#include <iostream>
#include "cylinder.h"

// Демонстрация управления объектами класса через указатели
// Показывает работу с объектами в стеке и динамически выделенными объектами
int main() {
    // === ОБЪЕКТ В СТЕКЕ ===
    
    // Создание объекта Cylinder в стеке (автоматическое управление памятью)
    Cylinder stackCylinder(10.0, 10.0);
    
    // Вызов метода напрямую через объект
    std::cout << "Объем цилиндра (стек): " << stackCylinder.calculateVolume() << std::endl;
    
    // === УКАЗАТЕЛЬ НА ОБЪЕКТ В СТЕКЕ ===
    
    // Создание указателя на объект в стеке
    Cylinder* pointerToStackObject = &stackCylinder;
    
    // Два способа доступа к методам через указатель:
    // 1. Оператор разыменования и точка: (*pointer).method()
    // 2. Оператор стрелка: pointer->method() (более удобный)
    
    // std::cout << "Объем через разыменование: " << (*pointerToStackObject).calculateVolume() << std::endl;
    std::cout << "Объем через указатель: " << pointerToStackObject->calculateVolume() << std::endl;

    // === ДИНАМИЧЕСКИЙ ОБЪЕКТ В КУЧЕ ===
    
    // Создание объекта в куче через оператор new
    // ВНИМАНИЕ: Необходимо освободить память через delete!
    Cylinder* heapCylinder = new Cylinder(100.0, 2.0);
    
    std::cout << "Объем цилиндра (куча): " << heapCylinder->calculateVolume() << std::endl;
    std::cout << "Радиус цилиндра (куча): " << heapCylinder->getRadius() << std::endl;
    
    // === ОСВОБОЖДЕНИЕ ПАМЯТИ ===
    
    // ОБЯЗАТЕЛЬНО: освобождение динамически выделенной памяти
    // Забыв delete, получим утечку памяти!
    delete heapCylinder;
    
    // После delete указатель становится "висячим" - не используйте его!
    heapCylinder = nullptr;  // Хорошая практика - обнулить указатель
    
    return 0;
}