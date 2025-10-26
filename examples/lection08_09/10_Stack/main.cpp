#include <iostream>
#include <stack>

/**
 * Демонстрация базовых операций со стеком
 * Показывает принцип LIFO (Last In, First Out) и основные операции
 */
void demonstrateBasicStackOperations() {
    std::cout << "\n=== ДЕМОНСТРАЦИЯ БАЗОВЫХ ОПЕРАЦИЙ СО СТЕКОМ ===" << std::endl;

    // ========================================================================
    // ВАЖНО: std::stack НЕ ИМЕЕТ КОНСТРУКТОРА ИНИЦИАЛИЗАЦИИ
    // ========================================================================
    // std::stack<int> values = {0, 1, 2, 3, 4, 5, 6};  // ОШИБКА КОМПИЛЯЦИИ!
    std::stack<int> integer_stack;

    // ========================================================================
    // ДОБАВЛЕНИЕ ЭЛЕМЕНТОВ В СТЕК
    // ========================================================================
    std::cout << "1. Добавление элементов в стек:" << std::endl;
    for (int element_index = 0; element_index < 10; ++element_index) {
        integer_stack.push(element_index);
        std::cout << "   Добавлен элемент: " << element_index << std::endl;
    }

    // ========================================================================
    // ИЗВЛЕЧЕНИЕ ЭЛЕМЕНТОВ ИЗ СТЕКА (ПРИНЦИП LIFO)
    // ========================================================================
    std::cout << "2. Извлечение элементов из стека (LIFO - Last In, First Out):" << std::endl;
    while (!integer_stack.empty()) {
        std::cout << "   Размер стека: " << integer_stack.size() 
                  << ", Верхний элемент: " << integer_stack.top() << std::endl;
        integer_stack.pop();
    }
    std::cout << "   Стек пуст!" << std::endl;
}

/**
 * Демонстрация ограничений std::stack
 * Показывает, что stack не поддерживает итераторы
 */
void demonstrateStackLimitations() {
    std::cout << "\n=== ОГРАНИЧЕНИЯ STD::STACK ===" << std::endl;
    
    std::cout << "1. std::stack НЕ ПОДДЕРЖИВАЕТ ИТЕРАТОРЫ:" << std::endl;
    std::cout << "   - Нет методов begin() и end()" << std::endl;
    std::cout << "   - Нет поддержки range-based for loop" << std::endl;
    std::cout << "   - Нет доступа к элементам по индексу" << std::endl;
    std::cout << "   - Только операции: push(), pop(), top(), empty(), size()" << std::endl;
    
    std::cout << "2. ПРИЧИНЫ ОГРАНИЧЕНИЙ:" << std::endl;
    std::cout << "   - Стек - это адаптер контейнера, а не полноценный контейнер" << std::endl;
    std::cout << "   - Принцип LIFO не требует итерации по всем элементам" << std::endl;
    std::cout << "   - Безопасность: предотвращение случайного доступа к внутренним элементам" << std::endl;
    
    std::cout << "3. АЛЬТЕРНАТИВЫ ДЛЯ ИТЕРАЦИИ:" << std::endl;
    std::cout << "   - Использование базового контейнера (deque, vector, list)" << std::endl;
    std::cout << "   - Временное копирование элементов в другой контейнер" << std::endl;
    std::cout << "   - Рекурсивный обход стека" << std::endl;
}

/**
 * Основная функция - демонстрация std::stack
 * Показывает принцип работы стека и его ограничения
 */
int main() {
    std::cout << "=== ДЕМОНСТРАЦИЯ STD::STACK ===" << std::endl;

    // Демонстрация базовых операций
    demonstrateBasicStackOperations();
    
    // Демонстрация ограничений
    demonstrateStackLimitations();

    std::cout << "\n=== ДЕМОНСТРАЦИЯ ЗАВЕРШЕНА ===" << std::endl;
    return 0;
}