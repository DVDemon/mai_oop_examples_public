#include <iostream>

// Глобальные переменные для демонстрации (не рекомендуется в реальном коде)
int global_variable;

namespace example_namespace {
    int namespace_variable;
}

int main() {
    
    // ==========================================
    // 1. ИНИЦИАЛИЗАЦИЯ ГЛОБАЛЬНЫХ ПЕРЕМЕННЫХ
    // ==========================================
    
    std::cout << "=== Инициализация глобальных переменных ===" << std::endl;
    
    global_variable = 0;
    example_namespace::namespace_variable = 0;
    
    std::cout << "Глобальная переменная: " << global_variable << std::endl;
    std::cout << "Переменная в namespace: " << example_namespace::namespace_variable << std::endl;
    std::cout << std::endl;
    
    // ==========================================
    // 2. СЛУЧАЙ 1: ОПАСНОЕ ВЫДЕЛЕНИЕ ПАМЯТИ БЕЗ ОБРАБОТКИ ОШИБОК
    // ==========================================
    
    std::cout << "=== СЛУЧАЙ 1: Опасное выделение памяти без обработки ошибок ===" << std::endl;
    std::cout << "Следующий код ЗАКОММЕНТИРОВАН, так как он ОПАСЕН и может вызвать КРАШ:" << std::endl;
    
    // ОПАСНЫЙ КОД - ЗАКОММЕНТИРОВАН ДЛЯ БЕЗОПАСНОСТИ:
    /*
    // Попытка выделить огромный массив - может вызвать краш
    int* dangerous_allocation = new int[10000000000000000];
    
    // Цикл с множественными попытками выделения памяти
    for (size_t i{0}; i < 10000000; ++i) {
        int* data = new int[1000000000000000];  // ОПАСНО: может вызвать краш!
        // Память не освобождается - утечка памяти!
    }
    //*/
    
    std::cout << "Когда new не может выделить память, программа может крашиться!" << std::endl;
    std::cout << "Этот код демонстрирует НЕПРАВИЛЬНЫЙ подход!" << std::endl;
    std::cout << std::endl;
    
    // ==========================================
    // 3. СЛУЧАЙ 2: ОБРАБОТКА ОШИБОК ЧЕРЕЗ ИСКЛЮЧЕНИЯ
    // ==========================================
    
    std::cout << "=== СЛУЧАЙ 2: Обработка ошибок через исключения ===" << std::endl;
    std::cout << "Следующий код ЗАКОММЕНТИРОВАН, так как он может вызвать исключения:" << std::endl;
    
    // КОД С ИСКЛЮЧЕНИЯМИ - ЗАКОММЕНТИРОВАН ДЛЯ БЕЗОПАСНОСТИ:
    //*
    for (size_t i{0}; i < 10; ++i) {
        try {
            // Попытка выделить огромный массив
            int* data_with_exception = new int[1000000000000000];
            std::cout << "Память успешно выделена!" << std::endl;
            delete[] data_with_exception;  // Освобождаем память
        } catch (std::exception& ex) {
            std::cout << "Ошибка выделения памяти: " << ex.what() << std::endl;
        }
    }
   // */
    
    std::cout << "Исключения позволяют корректно обработать ошибки выделения памяти!" << std::endl;
    std::cout << "Это ПРАВИЛЬНЫЙ подход для обработки ошибок!" << std::endl;
    std::cout << std::endl;
    
    // ==========================================
    // 4. СЛУЧАЙ 3: БЕЗОПАСНОЕ ВЫДЕЛЕНИЕ ПАМЯТИ С std::nothrow
    // ==========================================
    
    std::cout << "=== СЛУЧАЙ 3: Безопасное выделение памяти с std::nothrow ===" << std::endl;
    
    // Безопасное выделение памяти с проверкой на nullptr
    for (size_t i{0}; i < 10; ++i) {
        
        // std::nothrow предотвращает выброс исключений
        // Вместо этого new возвращает nullptr при неудаче
        int* safe_allocation = new(std::nothrow) int[100000000000000L];
        
        if (safe_allocation != nullptr) {
            std::cout << "Попытка " << (i + 1) << ": Память успешно выделена!" << std::endl;
            std::cout << "Адрес выделенной памяти: " << safe_allocation << std::endl;
            
            // Освобождаем память
            delete[] safe_allocation;
            safe_allocation = nullptr;
            
            std::cout << "Память освобождена" << std::endl;
        } else {
            std::cout << "Попытка " << (i + 1) << ": Выделение памяти не удалось!" << std::endl;
            std::cout << "Оператор new вернул nullptr" << std::endl;
        }
        std::cout << std::endl;
    }
    
    // ==========================================
    // 5. ДОПОЛНИТЕЛЬНЫЕ ПРИМЕРЫ БЕЗОПАСНОГО ВЫДЕЛЕНИЯ ПАМЯТИ
    // ==========================================
    
    std::cout << "=== Дополнительные примеры безопасного выделения памяти ===" << std::endl;
    
    // Пример 1: Выделение одного элемента
    std::cout << "Пример 1: Выделение одного элемента" << std::endl;
    int* single_element = new(std::nothrow) int{42};
    
    if (single_element != nullptr) {
        std::cout << "Один элемент выделен: " << *single_element << std::endl;
        delete single_element;
        single_element = nullptr;
    } else {
        std::cout << "Не удалось выделить один элемент" << std::endl;
    }
    std::cout << std::endl;
    
    // Пример 2: Выделение небольшого массива
    std::cout << "Пример 2: Выделение небольшого массива" << std::endl;
    const size_t small_array_size = 1000;
    int* small_array = new(std::nothrow) int[small_array_size];
    
    if (small_array != nullptr) {
        std::cout << "Массив из " << small_array_size << " элементов выделен" << std::endl;
        
        // Инициализируем массив
        for (size_t i = 0; i < small_array_size; ++i) {
            small_array[i] = static_cast<int>(i);
        }
        
        std::cout << "Первые 5 элементов: ";
        for (size_t i = 0; i < 5; ++i) {
            std::cout << small_array[i] << " ";
        }
        std::cout << std::endl;
        
        delete[] small_array;
        small_array = nullptr;
    } else {
        std::cout << "Не удалось выделить массив" << std::endl;
    }
    std::cout << std::endl;
    
    // ==========================================
    // 6. ПРАВИЛА БЕЗОПАСНОГО ВЫДЕЛЕНИЯ ПАМЯТИ
    // ==========================================
    
    std::cout << "=== Правила безопасного выделения памяти ===" << std::endl;
    std::cout << "1. ВСЕГДА проверяйте результат new на nullptr" << std::endl;
    std::cout << "2. Используйте std::nothrow для предотвращения исключений" << std::endl;
    std::cout << "3. ВСЕГДА освобождайте выделенную память с помощью delete/delete[]" << std::endl;
    std::cout << "4. ВСЕГДА устанавливайте указатель в nullptr после освобождения" << std::endl;
    std::cout << "5. Используйте try-catch для обработки исключений при необходимости" << std::endl;
    std::cout << "6. Предпочитайте умные указатели (smart pointers) в современном C++" << std::endl;
    std::cout << std::endl;
    
    // ==========================================
    // 7. СРАВНЕНИЕ ПОДХОДОВ
    // ==========================================
    
    std::cout << "=== Сравнение подходов к обработке ошибок выделения памяти ===" << std::endl;
    std::cout << "Обычный new:" << std::endl;
    std::cout << "  - Выбрасывает std::bad_alloc при неудаче" << std::endl;
    std::cout << "  - Требует обработки исключений" << std::endl;
    std::cout << "  - Может вызвать краш программы при необработанном исключении" << std::endl;
    std::cout << std::endl;
    
    std::cout << "new(std::nothrow):" << std::endl;
    std::cout << "  - Возвращает nullptr при неудаче" << std::endl;
    std::cout << "  - Не выбрасывает исключений" << std::endl;
    std::cout << "  - Требует проверки на nullptr" << std::endl;
    std::cout << "  - Более предсказуемое поведение" << std::endl;
    std::cout << std::endl;
    
    std::cout << "Программа завершается корректно" << std::endl;
    return 0;
}