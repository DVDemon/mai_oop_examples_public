#include <memory>
#include <iostream>

// ============================================================================
// ДЕМОНСТРАЦИЯ STD::ENABLE_SHARED_FROM_THIS - БЕЗОПАСНОЕ ПОЛУЧЕНИЕ SHARED_PTR
// ============================================================================

// ============================================================================
// ПРАВИЛЬНАЯ РЕАЛИЗАЦИЯ С STD::ENABLE_SHARED_FROM_THIS
// ============================================================================

// Класс, правильно использующий enable_shared_from_this
struct CorrectImplementation : public std::enable_shared_from_this<CorrectImplementation> {
    // Метод для получения shared_ptr на текущий объект
    std::shared_ptr<CorrectImplementation> get_shared_pointer() {
        return shared_from_this();  // Безопасное получение shared_ptr
    }
    
    // Демонстрационный метод
    void demonstrate_usage() {
        std::cout << "CorrectImplementation::demonstrate_usage() called" << std::endl;
    }
};

// ============================================================================
// НЕПРАВИЛЬНАЯ РЕАЛИЗАЦИЯ БЕЗ STD::ENABLE_SHARED_FROM_THIS
// ============================================================================

// Класс, неправильно пытающийся создать shared_ptr из this
struct IncorrectImplementation {
    // НЕПРАВИЛЬНО: создание shared_ptr из this без enable_shared_from_this
    std::shared_ptr<IncorrectImplementation> get_shared_pointer() {
        return std::shared_ptr<IncorrectImplementation>(this);  // ОПАСНО!
    }
    
    // Демонстрационный метод
    void demonstrate_usage() {
        std::cout << "IncorrectImplementation::demonstrate_usage() called" << std::endl;
    }
    
    // Деструктор для демонстрации проблем
    ~IncorrectImplementation() { 
        std::cout << "IncorrectImplementation::~IncorrectImplementation() called" << std::endl; 
    }
};

// ============================================================================
// ОСНОВНАЯ ФУНКЦИЯ - ДЕМОНСТРАЦИЯ ENABLE_SHARED_FROM_THIS
// ============================================================================

int main() {
    std::cout << "=== ДЕМОНСТРАЦИЯ STD::ENABLE_SHARED_FROM_THIS ===" << std::endl << std::endl;
    
    // ========================================================================
    // ДЕМОНСТРАЦИЯ 1: ПРАВИЛЬНОЕ ИСПОЛЬЗОВАНИЕ ENABLE_SHARED_FROM_THIS
    // ========================================================================
    std::cout << "1. Правильное использование enable_shared_from_this:" << std::endl;
    
    // Создание shared_ptr на объект
    std::shared_ptr<CorrectImplementation> correct_pointer_1 = std::make_shared<CorrectImplementation>();
    
    // Получение еще одного shared_ptr на тот же объект
    std::shared_ptr<CorrectImplementation> correct_pointer_2 = correct_pointer_1->get_shared_pointer();
    
    // Проверка, что оба указателя указывают на один объект
    std::cout << "   correct_pointer_1.use_count() = " << correct_pointer_1.use_count() << std::endl;
    std::cout << "   correct_pointer_2.use_count() = " << correct_pointer_2.use_count() << std::endl;
    std::cout << "   Both pointers point to the same object: " 
              << (correct_pointer_1.get() == correct_pointer_2.get()) << std::endl;
    
    // Демонстрация использования
    correct_pointer_1->demonstrate_usage();
    correct_pointer_2->demonstrate_usage();
    std::cout << std::endl;
    
    // ========================================================================
    // ДЕМОНСТРАЦИЯ 2: НЕПРАВИЛЬНОЕ ИСПОЛЬЗОВАНИЕ (БЕЗ ENABLE_SHARED_FROM_THIS)
    // ========================================================================
    std::cout << "2. Неправильное использование (без enable_shared_from_this):" << std::endl;
    
    try {
        std::cout << "   begin braces" << std::endl;
        
        // Создание shared_ptr на объект
        std::shared_ptr<IncorrectImplementation> incorrect_pointer_1 = std::make_shared<IncorrectImplementation>();
        std::cout << "   middle braces" << std::endl;
        
        // Попытка получить еще один shared_ptr на тот же объект (ОПАСНО!)
        std::shared_ptr<IncorrectImplementation> incorrect_pointer_2 = incorrect_pointer_1->get_shared_pointer();
        std::cout << "   incorrect_pointer_2.use_count() = " << incorrect_pointer_2.use_count() << std::endl;
        std::cout << "   end braces" << std::endl;
        
        // Демонстрация использования
        incorrect_pointer_1->demonstrate_usage();
        incorrect_pointer_2->demonstrate_usage();
        
    } catch(std::exception& exception) {
        std::cout << "   Exception caught: " << exception.what() << std::endl;
    } // UB: double-delete of IncorrectImplementation
    
    std::cout << std::endl;
    
    // ========================================================================
    // ДЕМОНСТРАЦИЯ 3: ПРИНЦИПЫ РАБОТЫ ENABLE_SHARED_FROM_THIS
    // ========================================================================
    std::cout << "3. Принципы работы enable_shared_from_this:" << std::endl;
    std::cout << "   - Безопасное получение shared_ptr из объекта" << std::endl;
    std::cout << "   - Разделение счетчика ссылок между shared_ptr" << std::endl;
    std::cout << "   - Предотвращение двойного освобождения памяти" << std::endl;
    std::cout << "   - Работа только с объектами, управляемыми shared_ptr" << std::endl;
    std::cout << "   - Автоматическое управление жизненным циклом" << std::endl;
    std::cout << "   - Альтернатива небезопасному shared_ptr(this)" << std::endl;
    
    return 0;
} 