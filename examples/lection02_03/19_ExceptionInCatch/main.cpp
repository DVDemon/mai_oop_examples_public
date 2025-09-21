#include <cstdlib>
#include <iostream>
#include <exception>

// Демонстрация проблемы: исключения, возникающие в catch-блоках
// Показывает, что исключения в catch не перехватываются автоматически

void printReceipt(int amount) {
    if (amount < 0) {
        throw std::exception(); // Исключение при отрицательной сумме
    }
    std::cout << "Receipt total: " << amount << std::endl;
}

// Демонстрация проблемного кода - исключения в catch-блоках
int main(int argc, char **argv) {
    int userAmount = 0;
    
    try {
        std::cout << "Enter amount: ";
        std::cin >> userAmount;
        
        if (userAmount < 0) {
            throw std::exception(); // Отрицательная сумма - ошибка
        }
        if (userAmount == 0) {
            throw 0; // Нулевая сумма - особый случай
        }
        
    } catch (std::exception& exceptionObject) {
        // ПРОБЛЕМА: здесь может возникнуть новое исключение!
        std::cout << "Error: Negative amount entered!" << std::endl;
        printReceipt(userAmount); // Если userAmount < 0, здесь будет исключение
        
    } catch (int zeroAmount) {
        std::cout << "Warning: Zero amount entered!" << std::endl;
    }

    // Этот код выполнится, даже если в catch-блоке произошло исключение
    std::cout << "Final amount processed: " << userAmount << std::endl;

    return 0;
}
