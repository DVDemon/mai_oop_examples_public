#include <cstdlib>
#include <iostream>
#include <memory>

// ============================================================================
// ДЕМОНСТРАЦИЯ STD::DYNAMIC_POINTER_CAST - БЕЗОПАСНОЕ ПРИВЕДЕНИЕ ТИПОВ
// ============================================================================

// ============================================================================
// БАЗОВЫЙ КЛАСС ДЛЯ ДЕМОНСТРАЦИИ ПОЛИМОРФИЗМА
// ============================================================================

// Базовый класс с виртуальной функцией
struct BaseClass {
    BaseClass() {
        std::cout << "BaseClass constructor called" << std::endl;
    }
    
    // Виртуальная функция для демонстрации полиморфизма
    virtual void perform_action() {
        std::cout << "BaseClass::perform_action() called" << std::endl;
    }
    
    // Виртуальный деструктор для корректного полиморфизма
    virtual ~BaseClass() {
        std::cout << "BaseClass destructor called" << std::endl;
    }
};

// ============================================================================
// ПРОИЗВОДНЫЙ КЛАСС B
// ============================================================================

// Производный класс B с дополнительной функциональностью
struct DerivedClassB : public BaseClass {
    const int member_value = 1;

    // Переопределение виртуальной функции
    void perform_action() override {
        std::cout << "DerivedClassB::perform_action() called" << std::endl;
    }
    
    // Специфичная функция класса B
    void perform_specific_action_b() {
        std::cout << "DerivedClassB::perform_specific_action_b() called" << std::endl;
    }
};

// ============================================================================
// ПРОИЗВОДНЫЙ КЛАСС C
// ============================================================================

// Производный класс C с дополнительной функциональностью
struct DerivedClassC : public BaseClass {
    const char* message = "Hello from DerivedClassC!";
    
    // Переопределение виртуальной функции
    void perform_action() override {
        std::cout << "DerivedClassC::perform_action() called" << std::endl;
    }
    
    // Специфичная функция класса C
    void perform_specific_action_c() {
        std::cout << "DerivedClassC::perform_specific_action_c() called" << std::endl;
    }
};

// ============================================================================
// ОСНОВНАЯ ФУНКЦИЯ - ДЕМОНСТРАЦИЯ DYNAMIC_POINTER_CAST
// ============================================================================

auto main() -> int {
    std::cout << "=== ДЕМОНСТРАЦИЯ STD::DYNAMIC_POINTER_CAST ===" << std::endl << std::endl;
    
    // ========================================================================
    // ДЕМОНСТРАЦИЯ 1: СОЗДАНИЕ И БАЗОВОЕ ИСПОЛЬЗОВАНИЕ
    // ========================================================================
    std::cout << "1. Создание и базовое использование:" << std::endl;
    
    // Создание shared_ptr на производный класс B
    std::shared_ptr<DerivedClassB> derived_pointer_b(new DerivedClassB());
    
    // Приведение к базовому классу (неявное приведение)
    std::shared_ptr<BaseClass> base_pointer = derived_pointer_b;
    
    std::cout << "   Created shared_ptr<DerivedClassB> and converted to shared_ptr<BaseClass>" << std::endl;
    std::cout << "   Reference count: " << base_pointer.use_count() << std::endl << std::endl;
    
    // ========================================================================
    // ДЕМОНСТРАЦИЯ 2: УСПЕШНОЕ ПРИВЕДЕНИЕ К ПРАВИЛЬНОМУ ТИПУ
    // ========================================================================
    std::cout << "2. Успешное приведение к правильному типу:" << std::endl;
    
    // Попытка приведения к типу B (должно быть успешным)
    if (std::shared_ptr<DerivedClassB> casted_pointer_b = std::dynamic_pointer_cast<DerivedClassB>(base_pointer)) {
        std::cout << "   Successfully casted to DerivedClassB" << std::endl;
        casted_pointer_b->perform_action();
        casted_pointer_b->perform_specific_action_b();
        std::cout << "   Member value: " << casted_pointer_b->member_value << std::endl;
    } else {
        std::cout << "   Failed to cast to DerivedClassB" << std::endl;
    }
    std::cout << std::endl;
    
    // ========================================================================
    // ДЕМОНСТРАЦИЯ 3: НЕУСПЕШНОЕ ПРИВЕДЕНИЕ К НЕПРАВИЛЬНОМУ ТИПУ
    // ========================================================================
    std::cout << "3. Неуспешное приведение к неправильному типу:" << std::endl;
    
    // Попытка приведения к типу C (должно быть неуспешным)
    if (std::shared_ptr<DerivedClassC> casted_pointer_c = std::dynamic_pointer_cast<DerivedClassC>(base_pointer)) {
        std::cout << "   Successfully casted to DerivedClassC" << std::endl;
        casted_pointer_c->perform_action();
        casted_pointer_c->perform_specific_action_c();
    } else {
        std::cout << "   Failed to cast to DerivedClassC (expected behavior)" << std::endl;
    }
    std::cout << std::endl;
    
    // ========================================================================
    // ДЕМОНСТРАЦИЯ 4: ПРИВЕДЕНИЕ К ПРАВИЛЬНОМУ ТИПУ C
    // ========================================================================
    std::cout << "4. Приведение к правильному типу C:" << std::endl;
    
    // Создание нового объекта типа C
    std::shared_ptr<DerivedClassC> derived_pointer_c(new DerivedClassC());
    std::shared_ptr<BaseClass> base_pointer_c = derived_pointer_c;
    
    // Попытка приведения к типу C (должно быть успешным)
    if (std::shared_ptr<DerivedClassC> casted_pointer_c_success = std::dynamic_pointer_cast<DerivedClassC>(base_pointer_c)) {
        std::cout << "   Successfully casted to DerivedClassC" << std::endl;
        casted_pointer_c_success->perform_action();
        casted_pointer_c_success->perform_specific_action_c();
        std::cout << "   Message: " << casted_pointer_c_success->message << std::endl;
    } else {
        std::cout << "   Failed to cast to DerivedClassC" << std::endl;
    }
    std::cout << std::endl;
    
    // ========================================================================
    // ДЕМОНСТРАЦИЯ 5: ПРИНЦИПЫ РАБОТЫ DYNAMIC_POINTER_CAST
    // ========================================================================
    std::cout << "5. Принципы работы dynamic_pointer_cast:" << std::endl;
    std::cout << "   - Безопасное приведение типов во время выполнения" << std::endl;
    std::cout << "   - Проверка совместимости типов через RTTI" << std::endl;
    std::cout << "   - Возврат nullptr при неуспешном приведении" << std::endl;
    std::cout << "   - Сохранение счетчика ссылок shared_ptr" << std::endl;
    std::cout << "   - Работа только с полиморфными типами (виртуальные функции)" << std::endl;
    std::cout << "   - Альтернатива dynamic_cast для умных указателей" << std::endl;
    
    return 0;
}
