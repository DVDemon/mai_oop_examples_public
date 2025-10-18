#include <cassert>
#include <iostream>
#include <memory>
#include <vector>

// ============================================================================
// ДЕМОНСТРАЦИЯ STD::WEAK_PTR - СЛАБЫЕ ССЫЛКИ ДЛЯ БЕЗОПАСНОГО ДОСТУПА
// ============================================================================

// ============================================================================
// ПАТТЕРН OBSERVER С ИСПОЛЬЗОВАНИЕМ WEAK_PTR
// ============================================================================

// Класс-наблюдатель для демонстрации паттерна Observer
struct Observer {
public:
    // Конструктор с инициализацией значения
    explicit Observer(int observer_value)
        : m_value(observer_value) {
    }

    // Метод уведомления наблюдателя
    void notify() {
        std::cout << "Observer notified: " << m_value << std::endl;
    }
    
private:
    int m_value;  // Значение наблюдателя
};

// Класс-наблюдаемый объект с использованием weak_ptr
struct Observable {
    // Регистрация наблюдателя (слабая ссылка)
    void registerObserver(const std::shared_ptr<Observer>& observer) {
        m_observers.emplace_back(observer);  // Добавление weak_ptr
    }

    // Уведомление всех наблюдателей
    void notify() {
        for (auto& weak_observer : m_observers) {
            // Попытка получить shared_ptr из weak_ptr
            auto shared_observer = weak_observer.lock();
            if (shared_observer) {
                // Наблюдатель еще жив, уведомляем его
                shared_observer->notify();
            }
            // Если shared_observer == nullptr, наблюдатель уже уничтожен
        }
    }
    
private:
    // Контейнер слабых ссылок на наблюдателей
    std::vector<std::weak_ptr<Observer>> m_observers;
};

// ============================================================================
// ДЕМОНСТРАЦИЯ ПАТТЕРНА OBSERVER
// ============================================================================

void demonstrateObserverPattern() {
    std::cout << "=== ДЕМОНСТРАЦИЯ ПАТТЕРНА OBSERVER ===" << std::endl;
    
    Observable observable;

    // Создание и регистрация наблюдателей
    auto observer_1 = std::make_shared<Observer>(1);
    observable.registerObserver(observer_1);

    auto observer_2 = std::make_shared<Observer>(2);
    observable.registerObserver(observer_2);

    auto observer_3 = std::make_shared<Observer>(3);
    observable.registerObserver(observer_3);

    // Создание временного наблюдателя (будет уничтожен в конце блока)
    {
        auto temporary_observer = std::make_shared<Observer>(4);
        observable.registerObserver(temporary_observer);
    }  // temporary_observer уничтожается здесь

    // Уведомление всех наблюдателей (включая уже уничтоженного)
    std::cout << "Notifying all observers:" << std::endl;
    observable.notify();
}

// ============================================================================
// ОСНОВНАЯ ФУНКЦИЯ - ДЕМОНСТРАЦИЯ WEAK_PTR
// ============================================================================

int main() {
    std::cout << "=== ДЕМОНСТРАЦИЯ STD::WEAK_PTR ===" << std::endl << std::endl;
    
    // ========================================================================
    // ДЕМОНСТРАЦИЯ 1: БАЗОВОЕ ИСПОЛЬЗОВАНИЕ WEAK_PTR
    // ========================================================================
    std::cout << "1. Базовое использование weak_ptr:" << std::endl;
    
    // Создание shared_ptr
    auto shared_pointer = std::make_shared<int>(42);
    std::cout << "   Created shared_ptr with value: " << *shared_pointer << std::endl;
    std::cout << "   Reference count: " << shared_pointer.use_count() << std::endl;

    // Создание weak_ptr
    std::weak_ptr<int> weak_pointer;
    std::cout << "   Created empty weak_ptr" << std::endl;
    
    // ========================================================================
    // ДЕМОНСТРАЦИЯ 2: РАБОТА С WEAK_PTR В РАЗНЫХ ОБЛАСТЯХ ВИДИМОСТИ
    // ========================================================================
    std::cout << "2. Работа с weak_ptr в разных областях видимости:" << std::endl;
    
    {
        // Создание shared_ptr в локальной области видимости
        auto local_shared_pointer = std::make_shared<int>(42);
        std::cout << "   Created local shared_ptr" << std::endl;
        std::cout << "   Local reference count: " << local_shared_pointer.use_count() << std::endl;

        // Присвоение weak_ptr
        weak_pointer = local_shared_pointer;
        std::cout << "   Assigned weak_ptr to local shared_ptr" << std::endl;
        std::cout << "   Reference count after weak_ptr assignment: " << local_shared_pointer.use_count() << std::endl;

        // Проверка валидности weak_ptr
        auto locked_pointer = weak_pointer.lock();
        if (locked_pointer) {
            std::cout << "   weak_ptr is valid, value: " << *locked_pointer << std::endl;
        } else {
            std::cout << "   weak_ptr is invalid" << std::endl;
        }
    }  // local_shared_pointer уничтожается здесь
    
    // Проверка weak_ptr после уничтожения shared_ptr
    auto locked_pointer_after_destruction = weak_pointer.lock();
    if (locked_pointer_after_destruction) {
        std::cout << "   weak_ptr is still valid after shared_ptr destruction" << std::endl;
    } else {
        std::cout << "   weak_ptr is invalid after shared_ptr destruction (expected)" << std::endl;
    }
    std::cout << std::endl;
    
    // ========================================================================
    // ДЕМОНСТРАЦИЯ 3: ПАТТЕРН OBSERVER
    // ========================================================================
    std::cout << "3. Паттерн Observer с weak_ptr:" << std::endl;
    demonstrateObserverPattern();
    std::cout << std::endl;
    
    // ========================================================================
    // ДЕМОНСТРАЦИЯ 4: ПРИНЦИПЫ РАБОТЫ WEAK_PTR
    // ========================================================================
    std::cout << "4. Принципы работы weak_ptr:" << std::endl;
    std::cout << "   - weak_ptr не увеличивает счетчик ссылок shared_ptr" << std::endl;
    std::cout << "   - weak_ptr не препятствует освобождению объекта" << std::endl;
    std::cout << "   - weak_ptr можно проверить на валидность с помощью lock()" << std::endl;
    std::cout << "   - weak_ptr автоматически становится невалидным при освобождении объекта" << std::endl;
    std::cout << "   - weak_ptr предотвращает циклические ссылки" << std::endl;
    std::cout << "   - weak_ptr обеспечивает безопасный доступ к объекту" << std::endl;
    std::cout << "   - weak_ptr идеален для паттерна Observer" << std::endl;
    
    return 0;
}