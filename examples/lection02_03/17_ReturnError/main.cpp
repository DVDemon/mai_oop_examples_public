#include <iostream>
#include <exception>
#include <stdexcept>

// ==========================================
// 1. МЕТОД 1: ВОЗВРАТ BOOL (УСПЕХ/НЕУДАЧА)
// ==========================================

bool print_division(int dividend, int divisor) {
    if (divisor != 0) {
        std::cout << "Результат деления: " << (dividend / divisor) << std::endl;
        return true;  // Успех
    } else {
        return false;  // Неудача
    }
}

// ==========================================
// 2. МЕТОД 2: ВОЗВРАТ ЗНАЧЕНИЯ + ССЫЛКА НА РЕЗУЛЬТАТ
// ==========================================

int calculate_division_with_result(int dividend, int divisor, bool& success_flag) {
    if (divisor != 0) {
        success_flag = true;   // Успех
        return (dividend / divisor);
    } else {
        success_flag = false;  // Неудача
        return 0;  // Возвращаем 0 как "некорректное" значение
    }
}

// ==========================================
// 3. МЕТОД 3: ИСКЛЮЧЕНИЯ (EXCEPTIONS)
// ==========================================

int calculate_division_with_exception(int dividend, int divisor) {
    // Проверка входных данных
    if (divisor == 0) {
        throw std::logic_error("Делитель не может быть равен нулю!");
    }
    
    // Основной алгоритм
    return dividend / divisor;
}

int main() {
    
    // ==========================================
    // ДЕМОНСТРАЦИЯ РАЗЛИЧНЫХ МЕТОДОВ ОБРАБОТКИ ОШИБОК
    // ==========================================
    
    std::cout << "=== Различные методы обработки ошибок в C++ ===" << std::endl;
    std::cout << std::endl;
    
    // ==========================================
    // МЕТОД 1: BOOL-ФУНКЦИИ
    // ==========================================
    
    std::cout << "=== Метод 1: Bool-функции (возврат успех/неудача) ===" << std::endl;
    
    std::cout << "Тест 1: Деление 4 на 2" << std::endl;
    if (!print_division(4, 2)) {
        std::cout << "ОШИБКА: Не удалось выполнить деление!" << std::endl;
    }
    std::cout << std::endl;
    
    std::cout << "Тест 2: Деление 4 на 0" << std::endl;
    if (!print_division(4, 0)) {
        std::cout << "ОШИБКА: Не удалось выполнить деление!" << std::endl;
    }
    std::cout << std::endl;
    
    std::cout << "ПРЕИМУЩЕСТВА bool-функций:" << std::endl;
    std::cout << "- Простота использования" << std::endl;
    std::cout << "- Нет исключений" << std::endl;
    std::cout << "- Легко проверять результат" << std::endl;
    std::cout << std::endl;
    
    std::cout << "НЕДОСТАТКИ bool-функций:" << std::endl;
    std::cout << "- Не возвращают полезное значение при ошибке" << std::endl;
    std::cout << "- Легко забыть проверить результат" << std::endl;
    std::cout << "- Нет информации о типе ошибки" << std::endl;
    std::cout << std::endl;
    
    // ==========================================
    // МЕТОД 2: ССЫЛКА НА РЕЗУЛЬТАТ
    // ==========================================
    
    std::cout << "=== Метод 2: Ссылка на результат (success flag) ===" << std::endl;
    
    bool operation_success{};
    int division_result{};
    
    std::cout << "Тест 1: Деление 4 на 2" << std::endl;
    division_result = calculate_division_with_result(4, 2, operation_success);
    if (operation_success) {
        std::cout << "4/2 = " << division_result << std::endl;
    } else {
        std::cout << "ОШИБКА: Не удалось выполнить деление!" << std::endl;
    }
    std::cout << std::endl;
    
    std::cout << "Тест 2: Деление 4 на 0" << std::endl;
    division_result = calculate_division_with_result(4, 0, operation_success);
    if (!operation_success) {
        std::cout << "ОШИБКА: Деление на ноль невозможно!" << std::endl;
        std::cout << "Возвращенное значение: " << division_result << " (некорректно)" << std::endl;
    }
    std::cout << std::endl;
    
    std::cout << "ПРЕИМУЩЕСТВА метода с success flag:" << std::endl;
    std::cout << "- Возвращает и значение, и статус" << std::endl;
    std::cout << "- Нет исключений" << std::endl;
    std::cout << "- Более информативен" << std::endl;
    std::cout << std::endl;
    
    std::cout << "НЕДОСТАТКИ метода с success flag:" << std::endl;
    std::cout << "- Нужно помнить о проверке флага" << std::endl;
    std::cout << "- Возвращаемое значение при ошибке может быть некорректным" << std::endl;
    std::cout << "- Дополнительный параметр в функции" << std::endl;
    std::cout << std::endl;
    
    // ==========================================
    // МЕТОД 3: ИСКЛЮЧЕНИЯ
    // ==========================================
    
    std::cout << "=== Метод 3: Исключения (exceptions) ===" << std::endl;
    
    std::cout << "Тест 1: Деление 4 на 2 (без ошибок)" << std::endl;
    try {
        int result = calculate_division_with_exception(4, 2);
        std::cout << "4/2 = " << result << std::endl;
    } catch (const std::exception& ex) {
        std::cout << "ИСКЛЮЧЕНИЕ: " << ex.what() << std::endl;
    }
    std::cout << std::endl;
    
    std::cout << "Тест 2: Деление 4 на 0 (с исключением)" << std::endl;
    try {
        int result = calculate_division_with_exception(4, 0);
        std::cout << "4/0 = " << result << std::endl;
    } catch (const std::exception& ex) {
        std::cout << "ИСКЛЮЧЕНИЕ: " << ex.what() << std::endl;
    }
    std::cout << std::endl;
    
    std::cout << "ПРЕИМУЩЕСТВА исключений:" << std::endl;
    std::cout << "- Автоматическая обработка ошибок" << std::endl;
    std::cout << "- Подробная информация об ошибке" << std::endl;
    std::cout << "- Нельзя забыть обработать ошибку" << std::endl;
    std::cout << "- Чистый код без постоянных проверок" << std::endl;
    std::cout << std::endl;
    
    std::cout << "НЕДОСТАТКИ исключений:" << std::endl;
    std::cout << "- Медленнее обычных проверок" << std::endl;
    std::cout << "- Могут прервать выполнение программы" << std::endl;
    std::cout << "- Требуют понимания механизма исключений" << std::endl;
    std::cout << std::endl;
    
    // ==========================================
    // СРАВНЕНИЕ МЕТОДОВ
    // ==========================================
    
    std::cout << "=== Сравнение методов обработки ошибок ===" << std::endl;
    std::cout << std::endl;
    
    std::cout << "| Критерий           | Bool-функции | Success flag | Исключения |" << std::endl;
    std::cout << "|--------------------|--------------|--------------|------------|" << std::endl;
    std::cout << "| Простота           | Высокая      | Средняя      | Низкая     |" << std::endl;
    std::cout << "| Производительность | Высокая      | Высокая      | Низкая     |" << std::endl;
    std::cout << "| Информативность    | Низкая       | Средняя      | Высокая    |" << std::endl;
    std::cout << "| Безопасность       | Низкая       | Средняя      | Высокая    |" << std::endl;
    std::cout << "| Читаемость кода    | Средняя      | Низкая       | Высокая    |" << std::endl;
    std::cout << std::endl;
    
    // ==========================================
    // РЕКОМЕНДАЦИИ ПО ВЫБОРУ МЕТОДА
    // ==========================================
    
    std::cout << "=== Рекомендации по выбору метода ===" << std::endl;
    std::cout << "1. Используйте bool-функции для:" << std::endl;
    std::cout << "   - Простых операций" << std::endl;
    std::cout << "   - Когда производительность критична" << std::endl;
    std::cout << "   - Для простых проверок" << std::endl;
    std::cout << std::endl;
    
    std::cout << "2. Используйте success flag для:" << std::endl;
    std::cout << "   - Когда нужно и значение, и статус" << std::endl;
    std::cout << "   - Когда исключения нежелательны" << std::endl;
    std::cout << "   - Для совместимости с C-кодом" << std::endl;
    std::cout << std::endl;
    
    std::cout << "3. Используйте исключения для:" << std::endl;
    std::cout << "   - Критических ошибок" << std::endl;
    std::cout << "   - Когда нужна подробная информация об ошибке" << std::endl;
    std::cout << "   - Для чистого и читаемого кода" << std::endl;
    std::cout << "   - Когда ошибки редки, но серьезны" << std::endl;
    std::cout << std::endl;
    
    // ==========================================
    // ДОПОЛНИТЕЛЬНЫЕ ПРИМЕРЫ
    // ==========================================
    
    std::cout << "=== Дополнительные примеры ===" << std::endl;
    
    // Пример с разными типами исключений
    std::cout << "Пример с разными типами исключений:" << std::endl;
    try {
        // Попытка деления на ноль
        int result = calculate_division_with_exception(10, 0);
        std::cout << "Результат: " << result << std::endl;
    } catch (const std::logic_error& ex) {
        std::cout << "Логическая ошибка: " << ex.what() << std::endl;
    } catch (const std::exception& ex) {
        std::cout << "Общее исключение: " << ex.what() << std::endl;
    } catch (...) {
        std::cout << "Неизвестное исключение!" << std::endl;
    }
    std::cout << std::endl;
    
    std::cout << "Программа завершается корректно" << std::endl;
    return 0;
}