#include <cassert>
#include <functional>
#include <iostream>
#include <memory>

// ============================================================================
// ДЕМОНСТРАЦИЯ STD::SHARED_PTR - УМНЫЙ УКАЗАТЕЛЬ С РАЗДЕЛЯЕМЫМ ВЛАДЕНИЕМ
// ============================================================================

// ============================================================================
// ВСПОМОГАТЕЛЬНЫЕ ФУНКЦИИ ДЛЯ ДЕМОНСТРАЦИИ
// ============================================================================

// Функция инициализации - создает объект и выводит сообщение
int* initialize_object() {
    std::cout << "Object initialized" << std::endl;
    return new int{13};
}

// Функция деинициализации - освобождает объект и выводит сообщение
void deinitialize_object(int* object_pointer) {
    std::cout << "Object deinitialized" << std::endl;
    delete object_pointer;
}

// ============================================================================
// КАСТОМНЫЙ ДЕЛЕТЕР ДЛЯ ДЕМОНСТРАЦИИ
// ============================================================================

// Структура-делетер для демонстрации кастомного освобождения
struct CustomDeleter {
    void operator()(int* object_pointer) {
        std::cout << "CustomDeleter::operator() called" << std::endl;
        deinitialize_object(object_pointer);
    }
};

// ============================================================================
// ОСНОВНАЯ ФУНКЦИЯ - ДЕМОНСТРАЦИЯ STD::SHARED_PTR
// ============================================================================

int main() {
    std::cout << "=== ДЕМОНСТРАЦИЯ STD::SHARED_PTR ===" << std::endl << std::endl;
    
    // ========================================================================
    // ДЕМОНСТРАЦИЯ 1: БАЗОВОЕ ИСПОЛЬЗОВАНИЕ SHARED_PTR
    // ========================================================================
    std::cout << "1. Базовое использование shared_ptr:" << std::endl;
    
    // Создание shared_ptr с явным new (не рекомендуется)
    std::shared_ptr<int> shared_pointer_1{new int{10}};
    
    // Проверка валидности и значения
    assert(shared_pointer_1);
    assert(*shared_pointer_1 == 10);
    assert(*shared_pointer_1.get() == 10);
    
    // Размер shared_ptr (обычно 16 байт на 64-битных системах)
    std::cout << "   sizeof(shared_ptr) = " << sizeof(shared_pointer_1) << " bytes" << std::endl;
    std::cout << "   Value: " << *shared_pointer_1 << std::endl << std::endl;
    
    // ========================================================================
    // ДЕМОНСТРАЦИЯ 2: ИСПОЛЬЗОВАНИЕ MAKE_SHARED (РЕКОМЕНДУЕМЫЙ СПОСОБ)
    // ========================================================================
    std::cout << "2. Использование std::make_shared (рекомендуемый способ):" << std::endl;
    
    // Создание shared_ptr с помощью make_shared (более эффективно)
    auto shared_pointer_2 = std::make_shared<int>(42);
    
    // Размер shared_ptr (тот же, что и в первом случае)
    std::cout << "   sizeof(shared_ptr) = " << sizeof(shared_pointer_2) << " bytes" << std::endl;
    std::cout << "   Value: " << *shared_pointer_2 << std::endl << std::endl;
    
    // ========================================================================
    // ДЕМОНСТРАЦИЯ 3: КАСТОМНЫЙ ДЕЛЕТЕР - ФУНКЦИЯ
    // ========================================================================
    std::cout << "3. Кастомный делетер - функция:" << std::endl;
    std::cout << "   start" << std::endl;
    
    {
        // Создание shared_ptr с кастомным делетером (функция)
        std::shared_ptr<int> shared_pointer_3{initialize_object(), &deinitialize_object};
        std::cout << "   sizeof(shared_ptr) = " << sizeof(shared_pointer_3) << " bytes" << std::endl;
    }
    std::cout << "   end" << std::endl << std::endl;
    
    // ========================================================================
    // ДЕМОНСТРАЦИЯ 4: КАСТОМНЫЙ ДЕЛЕТЕР - СТРУКТУРА
    // ========================================================================
    std::cout << "4. Кастомный делетер - структура:" << std::endl;
    std::cout << "   start" << std::endl;
    
    {
        // Создание shared_ptr с кастомным делетером (структура)
        std::shared_ptr<int> shared_pointer_4{initialize_object(), CustomDeleter{}};
        std::cout << "   sizeof(shared_ptr) = " << sizeof(shared_pointer_4) << " bytes" << std::endl;
    }
    std::cout << "   end" << std::endl << std::endl;
    
    // ========================================================================
    // ДЕМОНСТРАЦИЯ 5: КАСТОМНЫЙ ДЕЛЕТЕР - STD::FUNCTION
    // ========================================================================
    std::cout << "5. Кастомный делетер - std::function:" << std::endl;
    std::cout << "   start" << std::endl;
    
    {
        // Создание shared_ptr с кастомным делетером (std::function)
        std::shared_ptr<int> shared_pointer_5{
            initialize_object(), 
            std::function<void(int*)>([](int* object_pointer) {deinitialize_object(object_pointer);})
        };
        std::cout << "   sizeof(shared_ptr) = " << sizeof(shared_pointer_5) << " bytes" << std::endl;
        std::cout << "   sizeof(std::function<void()>{}) = " << sizeof(std::function<void()>{}) << " bytes" << std::endl;
    }
    std::cout << "   end" << std::endl << std::endl;
    
    // ========================================================================
    // ДЕМОНСТРАЦИЯ 6: КАСТОМНЫЙ ДЕЛЕТЕР - ЛЯМБДА (БЕЗ ЗАХВАТА)
    // ========================================================================
    std::cout << "6. Кастомный делетер - лямбда (без захвата):" << std::endl;
    std::cout << "   start" << std::endl;
    
    {
        // Создание лямбда-делетера без захвата
        auto lambda_deleter = [](int* object_pointer) { deinitialize_object(object_pointer); };
        std::shared_ptr<int> shared_pointer_6{initialize_object(), lambda_deleter};
        std::cout << "   sizeof(shared_ptr) = " << sizeof(shared_pointer_6) << " bytes" << std::endl;
        std::cout << "   sizeof(lambda_deleter) = " << sizeof(lambda_deleter) << " bytes" << std::endl;
    }
    std::cout << "   end" << std::endl << std::endl;
    
    
    // ========================================================================
    // ДЕМОНСТРАЦИЯ 8: ПРИНЦИПЫ РАБОТЫ SHARED_PTR
    // ========================================================================
    std::cout << "8. Принципы работы shared_ptr:" << std::endl;
    std::cout << "   - Разделяемое владение ресурсом" << std::endl;
    std::cout << "   - Счетчик ссылок (reference counting)" << std::endl;
    std::cout << "   - Автоматическое освобождение при последнем владельце" << std::endl;
    std::cout << "   - Поддержка кастомных делетеров" << std::endl;
    std::cout << "   - Thread-safe счетчик ссылок" << std::endl;
    std::cout << "   - Дополнительные накладные расходы по сравнению с unique_ptr" << std::endl;
    
    return 0;
}