#include <iostream>
#include "dog.h"

// Функция для демонстрации dynamic_cast с указателями
void do_something_with_animal_ptr(Animal* animal_ptr) {
    std::cout << "In function taking base pointer..." << std::endl;
    
    // DYNAMIC_CAST с указателями - возвращает nullptr при неудаче
    Feline* feline_ptr = dynamic_cast<Feline*>(animal_ptr);
    
    if (feline_ptr) {
        // Успешное приведение - можем вызвать специфичные для Feline методы
        feline_ptr->do_some_feline_thingy();
    } else {
        std::cout << "Couldn't cast to Feline pointer, Sorry." << std::endl;
    }
}

// Функция для демонстрации dynamic_cast со ссылками (через указатели)
void do_something_with_animal_ref(Animal& animal_ref) {
    std::cout << "In function taking base reference..." << std::endl;
    
    // DYNAMIC_CAST со ссылками - берем адрес ссылки для приведения
    Feline* feline_ptr = dynamic_cast<Feline*>(&animal_ref);
    
    if (feline_ptr) {
        // Успешное приведение - можем вызвать специфичные для Feline методы
        feline_ptr->do_some_feline_thingy();
    } else {
        std::cout << "Couldn't cast to Feline reference, Sorry." << std::endl;
    }
}

int main() {
    // ДЕМОНСТРАЦИЯ DYNAMIC_CAST В C++
    
    std::cout << "=== Демонстрация dynamic_cast ===" << std::endl;
    
    // Создание объекта Feline через указатель на базовый класс
    Animal* animal_ptr = new Feline("stripes", "feline1");
    
    // НЕПОСРЕДСТВЕННЫЙ вызов специфичного метода НЕ РАБОТАЕТ
    // animal_ptr->do_some_feline_thingy();  // ОШИБКА КОМПИЛЯЦИИ!
    
    std::cout << "-----------" << std::endl;
    
    // ДЕМОНСТРАЦИЯ 1: dynamic_cast с указателями
    std::cout << "--- Dynamic_cast с указателями ---" << std::endl;
    
    // DYNAMIC_CAST: если приведение успешно - получаем валидный указатель,
    // если неудачно - получаем nullptr. Можно проверить перед использованием!
    Feline* feline_ptr = dynamic_cast<Feline*>(animal_ptr);
    
    if (feline_ptr) {
        // Успешное приведение - можем вызвать специфичные для Feline методы
        feline_ptr->do_some_feline_thingy();
    } else {
        std::cout << "Couldn't do the transformation from Animal* to Feline*" << std::endl;
    }
    
    std::cout << "-----------" << std::endl;
    
    // ДЕМОНСТРАЦИЯ 2: dynamic_cast со ссылками
    std::cout << "--- Dynamic_cast со ссылками ---" << std::endl;
    
    // Создание объекта Feline и ссылки на базовый класс
    Feline feline_object("stripes", "feline2");
    Animal& animal_ref = feline_object;
    
    // НЕПОСРЕДСТВЕННЫЙ вызов специфичного метода НЕ РАБОТАЕТ
    // animal_ref.do_some_feline_thingy();  // ОШИБКА КОМПИЛЯЦИИ!
    
    // ПРИМЕР ЗАКОММЕНТИРОВАННОГО КОДА:
    // Попытка приведения к неправильному типу приведет к ошибке
    // Dog& feline_ref = dynamic_cast<Dog&>(animal_ref);  // ОШИБКА!
    // feline_ref.do_some_dog_thingy();
    
    // ПРАВИЛЬНЫЙ способ: проверка через указатели
    Dog* dog_ptr = dynamic_cast<Dog*>(&animal_ref);
    if (dog_ptr) {
        // Успешное приведение к Dog
        dog_ptr->do_some_dog_thingy();
    } else {
        // Неудачное приведение - animal_ref указывает на Feline, а не Dog
        std::cout << "Couldn't cast to Dog reference, Sorry." << std::endl;
    }
    
    std::cout << "---------------" << std::endl;
    
    // ДЕМОНСТРАЦИЯ 3: dynamic_cast в функциях
    std::cout << "--- Dynamic_cast в функциях ---" << std::endl;
    do_something_with_animal_ptr(animal_ptr);
    do_something_with_animal_ref(animal_ref);
    
    std::cout << "----------------" << std::endl;
    
    // ПРИМЕР ЗАКОММЕНТИРОВАННОГО КОДА:
    // dynamic_cast работает только с полиморфными типами!
    /*
    int data{45};
    int* data_ptr = &data;
    
    // ЭТО ВЫЗОВЕТ ОШИБКУ КОМПИЛЯЦИИ - int не полиморфный тип!
    std::string* data_str = dynamic_cast<std::string*>(data_ptr);
    */
    
    std::cout << "=== Важные выводы ===" << std::endl;
    std::cout << "1. dynamic_cast работает только с полиморфными типами" << std::endl;
    std::cout << "2. Для указателей возвращает nullptr при неудаче" << std::endl;
    std::cout << "3. Для ссылок выбрасывает исключение при неудаче" << std::endl;
    std::cout << "4. Всегда проверяйте результат перед использованием" << std::endl;
    std::cout << "5. Позволяет безопасный доступ к специфичным методам" << std::endl;
    
    std::cout << "\n=== Программа завершается ===" << std::endl;
    
    // Освобождение памяти
    delete animal_ptr;
    
    return 0;
}