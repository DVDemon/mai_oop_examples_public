#include <cstdlib>
#include <iostream>

// Демонстрация константных методов и константных объектов
// Показывает использование const для обеспечения неизменяемости

struct MyClass {
    // === ДАННЫЕ-ЧЛЕНЫ ===
    
    // mutable int counter{};  // Раскомментируйте для демонстрации mutable
    int counter{};            // Счетчик (обычное поле)
 
    // === КОНСТАНТНЫЕ МЕТОДЫ ===
    
    // Константный геттер - не изменяет состояние объекта
    int getValue() const {
        return counter;
    }

    // Константный метод с константным параметром
    int calculateSum(const int additionalValue) const {
        // ++counter;  // ОШИБКА: нельзя изменять поля в константном методе
        return getValue() + additionalValue;  // Можно вызывать другие константные методы
    }
};

int main(int argc, char** argv) {
    std::cout << "=== Демонстрация константных методов и объектов ===" << std::endl;
    
    // === ПРИМЕРЫ С УКАЗАТЕЛЯМИ (закомментированы для простоты) ===
    /*
    int a = 100;
    int b = 222;
    
    // Константный указатель (указатель нельзя изменить)
    int *const constantPointer = &a;
    *constantPointer = 987;  // Можно изменить значение
    // constantPointer = &b;  // ОШИБКА: нельзя изменить указатель
    
    // Указатель на константу (значение нельзя изменить)
    const int *pointerToConstant = &a;
    // *pointerToConstant = 110;  // ОШИБКА: нельзя изменить значение
    pointerToConstant = &b;      // Можно изменить указатель
    
    // Константный указатель на константу
    const int *const constantPointerToConstant = &a;
    // *constantPointerToConstant = 155;  // ОШИБКА: нельзя изменить значение
    // constantPointerToConstant = &b;    // ОШИБКА: нельзя изменить указатель
    */

    // === РАБОТА С КОНСТАНТНЫМ ОБЪЕКТОМ ===
    
    const MyClass constantObject;  // Константный объект
    
    // Можно вызывать только константные методы
    int currentValue = constantObject.getValue();
    std::cout << "Текущее значение: " << currentValue << std::endl;
    
    // Вызов константного метода с параметром
    int result = constantObject.calculateSum(10);
    std::cout << "Результат вычисления (0 + 10): " << result << std::endl;
    
    // === ОБЪЯСНЕНИЕ ПРАВИЛ ===
    
    std::cout << "\n=== Правила константных методов ===" << std::endl;
    std::cout << "- Константные методы НЕ МОГУТ изменять поля объекта" << std::endl;
    std::cout << "- Константные методы МОГУТ вызывать другие константные методы" << std::endl;
    std::cout << "- Константные объекты могут вызывать ТОЛЬКО константные методы" << std::endl;
    std::cout << "- mutable поля можно изменять даже в константных методах" << std::endl;
    
    std::cout << "\n=== Программа завершена ===" << std::endl;
    
    return 0;
}