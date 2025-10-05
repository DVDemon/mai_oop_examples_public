#include <iostream>

// Базовый класс Animal (Животное) - демонстрирует множественное наследование
struct Animal {
    // Общий метод для всех животных
    void wow() {
        std::cout << "Wow!!!" << std::endl;
    }
};

// Первый производный класс Duck (Утка) наследуется от Animal
struct Duck : Animal {
    // Специфичный метод для уток
    void swim() {
        std::cout << "swim" << std::endl;
    }
};

// Второй производный класс Bobr (Бобр) наследуется от Animal
struct Bobr : Animal {
    // Специфичный метод для бобров
    void make_a_dam() {
        std::cout << "dam!!!" << std::endl;
    }
};

// Класс Platypus (Утконос) демонстрирует МНОЖЕСТВЕННОЕ НАСЛЕДОВАНИЕ
// Наследуется от Duck И от Bobr одновременно
struct Platypus : Duck, Bobr {
    // Platypus получает все методы от Duck и Bobr
    // ВАЖНО: у Platypus есть ДВА экземпляра Animal (один через Duck, один через Bobr)
    // Это создает проблему неоднозначности при вызове wow()
};

int main() {
    // ДЕМОНСТРАЦИЯ МНОЖЕСТВЕННОГО НАСЛЕДОВАНИЯ
    
    std::cout << "=== Демонстрация множественного наследования ===" << std::endl;
    
    // Создание объектов отдельных классов
    Duck duck_object;
    Bobr bobr_object;
    
    // Создание объекта с множественным наследованием
    Platypus platypus_object;
    
    std::cout << "--- Методы, унаследованные от Duck ---" << std::endl;
    platypus_object.swim();  // Метод от Duck
    
    std::cout << "--- Методы, унаследованные от Bobr ---" << std::endl;
    platypus_object.make_a_dam();  // Метод от Bobr
    
    std::cout << "--- Решение проблемы неоднозначности ---" << std::endl;
    
    // ПРОБЛЕМА МНОЖЕСТВЕННОГО НАСЛЕДОВАНИЯ:
    // platypus_object.wow();  // ОШИБКА КОМПИЛЯЦИИ - неоднозначность!
    // Компилятор не знает, какой wow() вызвать - от Duck::Animal или от Bobr::Animal
    
    // РЕШЕНИЕ: Квалифицированные имена
    std::cout << "Вызов wow() через Bobr::Animal:" << std::endl;
    platypus_object.Bobr::wow();  // Явно указываем путь наследования
    
    std::cout << "Вызов wow() через Duck::Animal:" << std::endl;
    platypus_object.Duck::wow();  // Явно указываем путь наследования
    
    std::cout << "\n=== Важные выводы ===" << std::endl;
    std::cout << "1. Множественное наследование позволяет наследоваться от нескольких базовых классов" << std::endl;
    std::cout << "2. Объект получает все методы от всех базовых классов" << std::endl;
    std::cout << "3. Возникает проблема неоднозначности при одинаковых именах методов" << std::endl;
    std::cout << "4. Решение: использование квалифицированных имен (Class::method)" << std::endl;
    std::cout << "5. У объекта может быть несколько экземпляров одного базового класса" << std::endl;
    
    return 0;
}
