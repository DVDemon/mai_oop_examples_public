#include <cstdlib>
#include <iostream>
#include <exception>

// Демонстрация проблемы с noexcept спецификатором
// Показывает, что происходит при нарушении noexcept контракта

// ОПАСНО: функция помечена как noexcept, но выбрасывает исключение!
void validateAmount(int amount) noexcept {
    if (amount < 0) {
        throw std::exception(); // Нарушение noexcept контракта!
    }
}

// Демонстрация проблемного кода - нарушение noexcept контракта
int main(int argc, char** argv) {
    try {
        // Вызываем функцию с отрицательным значением
        validateAmount(-1);
        
    } catch(...) {
        // Этот catch может НЕ сработать из-за noexcept!
        std::cout << "Исключение перехвачено в main" << std::endl;
    }
    
    std::cout << "Программа завершена" << std::endl;
    
    return 0;
}

