#include <iostream>
#include <exception>

// Демонстрация сложной обработки исключений с различными типами ошибок
// Показывает порядок перехвата исключений и проброс (rethrow)

void functionWithExceptions() {
    try {
        std::cout << "FunctionWithExceptions called" << std::endl;
        
        // Попытка доступа к несуществующему элементу строки
        // Это вызовет std::out_of_range исключение
        char invalidCharacter = std::string().at(1);
        
        // Эта строка не выполнится из-за исключения выше
        throw 42; // Пользовательское исключение типа int

    } catch (int errorCode) {
        // Перехватываем пользовательское исключение типа int
        std::cout << "Caught integer exception in FunctionWithExceptions: " << errorCode << std::endl;

    } catch (const std::exception& standardException) {
        // Перехватываем стандартные исключения (включая std::out_of_range)
        std::cout << "Caught standard exception: " << standardException.what() << std::endl;
        
        // Пробрасываем исключение дальше по стеку вызовов
        throw;
    }
}

void callingFunction() {
    try {
        std::cout << "CallingFunction called" << std::endl;
        functionWithExceptions();
    } catch (const std::exception& caughtException) {
        // Обрабатываем исключение, проброшенное из functionWithExceptions
        std::cout << "Exception caught in CallingFunction: " << caughtException.what() << std::endl;
    }
}

int main() {
    // Запускаем цепочку вызовов функций с обработкой исключений
    callingFunction();
    return 0;
}

