#include <iostream>
#include <memory>
#include "dog.h"

// ============================================================================
// ДЕМОНСТРАЦИЯ STD::UNIQUE_PTR - УМНЫХ УКАЗАТЕЛЕЙ C++11
// ============================================================================

int main() {
    std::cout << "=== ДЕМОНСТРАЦИЯ STD::UNIQUE_PTR - УМНЫХ УКАЗАТЕЛЕЙ C++11 ===" << std::endl << std::endl;
    
    // ========================================================================
    // ДЕМОНСТРАЦИЯ 1: ОБЪЕКТЫ НА СТЕКЕ (ДЛЯ СРАВНЕНИЯ)
    // ========================================================================
    std::cout << "1. Объекты на стеке (для сравнения):" << std::endl;
    {
        Dog stack_dog("StackDog");
        stack_dog.print_dog();
    }
    std::cout << "   Выход из области видимости - автоматическое уничтожение" << std::endl << std::endl;
    
    // ========================================================================
    // ДЕМОНСТРАЦИЯ 2: СЫРЫЕ УКАЗАТЕЛИ (ПРОБЛЕМЫ)
    // ========================================================================
    std::cout << "2. Сырые указатели (проблемы):" << std::endl;
    std::cout << "   - Необходимо вручную освобождать память" << std::endl;
    std::cout << "   - Риск утечек памяти при забывании delete" << std::endl;
    std::cout << "   - Двойное освобождение памяти" << std::endl;
    std::cout << "   - Висячие указатели" << std::endl << std::endl;
    
    // ========================================================================
    // ДЕМОНСТРАЦИЯ 3: STD::UNIQUE_PTR - ОСНОВЫ
    // ========================================================================
    std::cout << "3. std::unique_ptr - основы:" << std::endl;
    {
        // Создание unique_ptr из сырого указателя
        Dog* raw_pointer = new Dog("RawDog");
        std::unique_ptr<Dog> unique_dog_1{raw_pointer}; // Управление ранее выделенной памятью
        
        // Создание unique_ptr напрямую
        std::unique_ptr<Dog> unique_dog_2{new Dog("UniqueDog")};
        
        // Создание unique_ptr для int
        std::unique_ptr<int> unique_int{new int(200)};
        
        // Инициализация с nullptr
        std::unique_ptr<Dog> unique_dog_3{nullptr};
        
        // Использование как обычного указателя
        unique_dog_2->print_dog();
        
        // Работа с примитивными типами
        *unique_int = 500;
        std::cout << "   Integer value: " << *unique_int << std::endl;
        std::cout << "   Integer address: " << unique_int.get() << std::endl;
    }
    std::cout << "   Выход из области видимости - автоматическое освобождение памяти" << std::endl << std::endl;


    // ========================================================================
    // ДЕМОНСТРАЦИЯ 4: STD::MAKE_UNIQUE (C++14)
    // ========================================================================
    std::cout << "4. std::make_unique (C++14) - более чистый синтаксис:" << std::endl;
    std::unique_ptr<Dog> make_unique_dog = std::make_unique<Dog>("MakeUniqueDog");
    make_unique_dog->print_dog();
    
    std::unique_ptr<int> make_unique_int = std::make_unique<int>(30);
    *make_unique_int = 67;
    std::cout << "   Integer value: " << *make_unique_int << std::endl;
    std::cout << "   Integer address: " << make_unique_int.get() << std::endl << std::endl;
    
    // ========================================================================
    // ДЕМОНСТРАЦИЯ 5: ОГРАНИЧЕНИЯ UNIQUE_PTR
    // ========================================================================
    std::cout << "5. Ограничения unique_ptr:" << std::endl;
    std::unique_ptr<Dog> unique_dog_4 = std::make_unique<Dog>("UniqueDog4");
    unique_dog_4->print_dog();
    std::cout << "   Memory address: " << unique_dog_4.get() << std::endl;
    
    std::cout << "   - Копирование запрещено (copy constructor deleted)" << std::endl;
    std::cout << "   - Присваивание запрещено (assignment operator deleted)" << std::endl;
    std::cout << "   - Только перемещение (move semantics) разрешено" << std::endl << std::endl;
    
    // ========================================================================
    // ДЕМОНСТРАЦИЯ 6: ПЕРЕМЕЩЕНИЕ (MOVE SEMANTICS)
    // ========================================================================
    std::cout << "6. Перемещение (move semantics):" << std::endl;
    std::unique_ptr<Dog> source_dog = std::make_unique<Dog>("SourceDog");
    {
        std::unique_ptr<Dog> destination_dog = std::move(source_dog); // Перемещение владения
        
        destination_dog->print_dog();
        std::cout << "   Destination dog address: " << destination_dog.get() << std::endl;
        
        std::cout << "   Source dog is now nullptr: " << source_dog.get() << std::endl;
        if (source_dog) {
            std::cout << "   Source dog points to something valid" << std::endl;
        } else {
            std::cout << "   Source dog points to nullptr" << std::endl;
        }
    }
    std::cout << "   Выход из области видимости - автоматическое освобождение" << std::endl << std::endl;
    
    // ========================================================================
    // ДЕМОНСТРАЦИЯ 7: МЕТОД RESET()
    // ========================================================================
    std::cout << "7. Метод reset():" << std::endl;
    std::unique_ptr<Dog> reset_dog = std::make_unique<Dog>("ResetDog");
    
    // Проверка до reset
    if (reset_dog) {
        std::cout << "   Before reset - points to: " << reset_dog.get() << std::endl;
    }
    
    reset_dog.reset(); // Освобождение памяти и установка в nullptr
    
    // Проверка после reset
    if (reset_dog) {
        std::cout << "   After reset - points to: " << reset_dog.get() << std::endl;
    } else {
        std::cout << "   After reset - points to nullptr" << std::endl;
    }
    std::cout << std::endl;
    
    // ========================================================================
    // ДЕМОНСТРАЦИЯ 8: ПРЕИМУЩЕСТВА UNIQUE_PTR
    // ========================================================================
    std::cout << "8. Преимущества unique_ptr:" << std::endl;
    std::cout << "   - Автоматическое управление памятью" << std::endl;
    std::cout << "   - Исключение утечек памяти" << std::endl;
    std::cout << "   - Исключение двойного освобождения" << std::endl;
    std::cout << "   - Исключение висячих указателей" << std::endl;
    std::cout << "   - Единоличное владение ресурсом" << std::endl;
    std::cout << "   - Перемещение вместо копирования" << std::endl;
    std::cout << "   - Совместимость с RAII принципом" << std::endl;
    
    return 0;
}