#include <cstdlib>
#include <iostream>
#include <memory>

// ============================================================================
// ДЕМОНСТРАЦИЯ РЕШЕНИЯ ПРОБЛЕМЫ ЦИКЛИЧЕСКИХ ССЫЛОК С WEAK_PTR
// ============================================================================

// ============================================================================
// ПРАВИЛЬНОЕ РЕШЕНИЕ: ИСПОЛЬЗОВАНИЕ WEAK_PTR ДЛЯ ПРЕДОТВРАЩЕНИЯ ЦИКЛОВ
// ============================================================================

// Forward declaration для класса B
class ClassB;

// Класс A с правильным использованием weak_ptr
class ClassA {
private:
    std::weak_ptr<ClassB> weak_reference_to_b;  // Слабая ссылка на объект B
    
public:
    // Конструктор
    ClassA() {
        std::cout << "Constructor: ClassA" << std::endl; 
    }
    
    // Установка слабой ссылки на объект B
    void set_weak_reference_to_b(std::shared_ptr<ClassB> object_b) {
        weak_reference_to_b = object_b;
    }

    // Метод для демонстрации работы
    void print_information() {
        std::cout << "Print: ClassA" << std::endl;
    }

    // Деструктор
    ~ClassA() {
        std::cout << "Destructor: ClassA" << std::endl;
    }
};

// Класс B с правильным использованием weak_ptr
class ClassB {
private:
    std::weak_ptr<ClassA> weak_reference_to_a;  // Слабая ссылка на объект A
    
public:
    // Конструктор
    ClassB() {
        std::cout << "Constructor: ClassB" << std::endl;    
    }
    
    // Установка слабой ссылки на объект A
    void set_weak_reference_to_a(std::shared_ptr<ClassA> object_a) {
        weak_reference_to_a = object_a;
    }

    // Метод для демонстрации работы с weak_ptr
    void print_information() {
        std::cout << "Print: ClassB" << std::endl;
        
        // Попытка получить shared_ptr из weak_ptr
        std::shared_ptr<ClassA> shared_pointer_to_a = weak_reference_to_a.lock();
        
        if (shared_pointer_to_a) {
            // Объект A еще жив, можно вызвать его метод
            shared_pointer_to_a->print_information();
        } else {
            // Объект A уже уничтожен
            std::cout << "Object A is deleted (expected behavior)" << std::endl;     
        }
    }

    // Деструктор
    ~ClassB() {
        std::cout << "Destructor: ClassB" << std::endl;
    }
};

// ============================================================================
// ОСНОВНАЯ ФУНКЦИЯ - ДЕМОНСТРАЦИЯ РЕШЕНИЯ ЦИКЛИЧЕСКИХ ССЫЛОК
// ============================================================================

int main(int argc, char** argv) {
    std::cout << "=== ДЕМОНСТРАЦИЯ РЕШЕНИЯ ЦИКЛИЧЕСКИХ ССЫЛОК С WEAK_PTR ===" << std::endl << std::endl;
    
    // ========================================================================
    // ДЕМОНСТРАЦИЯ: СОЗДАНИЕ ОБЪЕКТОВ С WEAK_PTR
    // ========================================================================
    std::cout << "1. Создание объектов с weak_ptr:" << std::endl;
    
    // Создание объекта B
    std::shared_ptr<ClassB> object_b(new ClassB());
    std::cout << "   Created shared_ptr<ClassB>, reference count: " << object_b.use_count() << std::endl;
    
    {
        // Создание объекта A в локальной области видимости
        std::shared_ptr<ClassA> object_a(new ClassA());
        std::cout << "   Created shared_ptr<ClassA>, reference count: " << object_a.use_count() << std::endl;
        
        // Установка слабых ссылок (не создают циклических зависимостей)
        object_a->set_weak_reference_to_b(object_b);
        object_b->set_weak_reference_to_a(object_a);
        
        std::cout << "   Set weak references between objects" << std::endl;
        std::cout << "   Reference counts after weak_ptr assignment:" << std::endl;
        std::cout << "     object_a.use_count() = " << object_a.use_count() << std::endl;
        std::cout << "     object_b.use_count() = " << object_b.use_count() << std::endl;
        std::cout << "   Note: weak_ptr does not increase reference count!" << std::endl;
        
    }  // object_a уничтожается здесь, так как weak_ptr не препятствует освобождению
    
    std::cout << "   object_a destroyed, object_b.use_count() = " << object_b.use_count() << std::endl;
    std::cout << "   Result: No memory leak! Objects can be properly destroyed." << std::endl;
    std::cout << std::endl;
    
    // ========================================================================
    // ДЕМОНСТРАЦИЯ: РАБОТА С WEAK_PTR ПОСЛЕ УНИЧТОЖЕНИЯ ОБЪЕКТА
    // ========================================================================
    std::cout << "2. Работа с weak_ptr после уничтожения объекта:" << std::endl;
    std::cout << "   Start printing ..." << std::endl;
    
    // Вызов метода, который использует weak_ptr
    object_b->print_information();
    
    std::cout << std::endl;
    
    // ========================================================================
    // ДЕМОНСТРАЦИЯ: ПРИНЦИПЫ РАБОТЫ WEAK_PTR
    // ========================================================================
    std::cout << "3. Принципы работы weak_ptr:" << std::endl;
    std::cout << "   - weak_ptr не увеличивает счетчик ссылок shared_ptr" << std::endl;
    std::cout << "   - weak_ptr не препятствует освобождению объекта" << std::endl;
    std::cout << "   - weak_ptr можно проверить на валидность с помощью lock()" << std::endl;
    std::cout << "   - weak_ptr автоматически становится невалидным при освобождении объекта" << std::endl;
    std::cout << "   - weak_ptr предотвращает циклические ссылки" << std::endl;
    std::cout << "   - weak_ptr обеспечивает безопасный доступ к объекту" << std::endl;
    std::cout << "   - weak_ptr решает проблему утечек памяти" << std::endl;
    
    return 0;
}

