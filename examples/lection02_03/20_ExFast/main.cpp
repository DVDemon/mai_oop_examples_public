#include <iostream>
#include <chrono>
#include <cstdint>

// Бенчмарк производительности: исключения vs коды ошибок
// Демонстрирует разницу в скорости выполнения между двумя подходами

// Функция с возвратом кода ошибки (быстрый путь для нормального случая)
int calculateWithErrorCode(int inputValue, int& errorCode) {
    switch(inputValue) {
        case 0: 
            ++errorCode;  // Устанавливаем код ошибки
            return 0;       // Возвращаем значение по умолчанию
        default: 
            return inputValue;  // Нормальный случай - просто возвращаем значение
    }
}

// Функция с исключениями (медленный путь при ошибке)
int calculateWithException(int inputValue) {
    switch(inputValue) {
        case 0: 
            throw 1;        // Выбрасываем исключение
        default: 
            return inputValue;  // Нормальный случай - возвращаем значение
    }
}

int main() {
    int accumulatorValue = 0;
    int errorCounter = 0;
    const int ITERATION_COUNT = 1000000;

    std::cout << "=== Производительность: коды ошибок vs исключения ===" << std::endl;
    
    // === Тест 1: Метод с кодами ошибок ===
    std::cout << "1. Тестирование метода с кодами ошибок..." << std::endl;
    accumulatorValue = 0;
    errorCounter = 0;
    
    auto startTime = std::chrono::high_resolution_clock::now();
    for(int iteration = 0; iteration < ITERATION_COUNT; ++iteration) {
        accumulatorValue += calculateWithErrorCode(iteration % 2, errorCounter);
    }
    auto endTime = std::chrono::high_resolution_clock::now();
    
    auto durationMicroseconds = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime).count();
    std::cout << "   Время выполнения: " << durationMicroseconds << " микросекунд" << std::endl;
    std::cout << "   Всего ошибок обработано: " << errorCounter << std::endl;

    // === Тест 2: Метод с исключениями ===
    std::cout << "2. Тестирование метода с исключениями..." << std::endl;
    accumulatorValue = 0;
    errorCounter = 0;
    
    startTime = std::chrono::high_resolution_clock::now();
    for(int iteration = 0; iteration < ITERATION_COUNT; ++iteration) {
        try {
            accumulatorValue += calculateWithException(iteration % 2);
        } catch(...) {
            // Перехватываем любое исключение и увеличиваем счетчик
            ++errorCounter;
        }
    }
    endTime = std::chrono::high_resolution_clock::now();
    
    durationMicroseconds = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime).count();
    std::cout << "   Время выполнения: " << durationMicroseconds << " микросекунд" << std::endl;
    std::cout << "   Исключений обработано: " << errorCounter << std::endl;
    
    std::cout << "\nВывод: исключения значительно медленнее кодов ошибок при частом возникновении!" << std::endl;
    
    return 0;
}