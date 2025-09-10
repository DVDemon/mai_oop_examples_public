/*
 * ОПЕРАТОРЫ break И continue В C++
 * 
 * Этот файл демонстрирует использование операторов break и continue:
 * - Оператор break - принудительный выход из цикла
 * - Оператор continue - пропуск текущей итерации
 * - Использование в различных типах циклов
 * - Практические примеры и рекомендации
 */

#include <iostream>  // Для потоков ввода-вывода

int main() {
    /*
     * ПОДГОТОВКА КОНСТАНТ ДЛЯ ДЕМОНСТРАЦИИ
     * 
     * Определяем константы для демонстрации работы break и continue
     */
    const size_t LOOP_ITERATIONS{20};  // Общее количество итераций
    const size_t SKIP_VALUE{5};        // Значение для пропуска (continue)
    const size_t BREAK_VALUE{11};      // Значение для выхода (break)
    
    std::cout << "=== ОПЕРАТОРЫ break И continue В C++ ===" << std::endl;
    std::cout << "Демонстрация управления выполнением циклов" << std::endl;
    std::cout << "Пропускаем значение: " << SKIP_VALUE << ", выходим при значении: " << BREAK_VALUE << std::endl;
    std::cout << std::endl;

    /*
     * ПРИМЕР 1: break И continue В ЦИКЛЕ FOR
     * 
     * Демонстрация использования break и continue в цикле for.
     * 
     * Особенности:
     * - continue пропускает текущую итерацию и переходит к следующей
     * - break полностью выходит из цикла
     * - В цикле for обновление переменной происходит автоматически
     */
    std::cout << "=== ПРИМЕР 1: break И continue В ЦИКЛЕ FOR ===" << std::endl;
    std::cout << "Цикл for с операторами break и continue:" << std::endl;
    
    for (size_t counter{0}; counter < LOOP_ITERATIONS; ++counter) {
        if (counter == SKIP_VALUE) {
            std::cout << "Пропускаем итерацию " << counter << " (continue)" << std::endl;
            continue;  // Пропускаем текущую итерацию, переходим к следующей
        }

        if (counter == BREAK_VALUE) {
            std::cout << "Выходим из цикла при значении " << counter << " (break)" << std::endl;
            break;  // Полностью выходим из цикла
        }
        
        std::cout << "Обрабатываем значение: " << counter << std::endl;
    }
    std::cout << "Цикл for завершен!" << std::endl;
    std::cout << std::endl;

    /*
     * ПРИМЕР 2: break И continue В ЦИКЛЕ WHILE
     * 
     * Демонстрация использования break и continue в цикле while.
     * 
     * ВАЖНО: В цикле while при использовании continue необходимо
     * вручную обновлять переменную цикла, иначе возможен бесконечный цикл!
     */
    std::cout << "=== ПРИМЕР 2: break И continue В ЦИКЛЕ WHILE ===" << std::endl;
    std::cout << "Цикл while с операторами break и continue:" << std::endl;
    
    size_t while_counter{0};
    while (while_counter < LOOP_ITERATIONS) {
        if (while_counter == SKIP_VALUE) {
            std::cout << "Пропускаем итерацию " << while_counter << " (continue)" << std::endl;
            ++while_counter;  // ВАЖНО! Обновляем переменную перед continue
            continue;  // Пропускаем текущую итерацию
        }

        if (while_counter == BREAK_VALUE) {
            std::cout << "Выходим из цикла при значении " << while_counter << " (break)" << std::endl;
            break;  // Полностью выходим из цикла
        }

        std::cout << "Обрабатываем значение: " << while_counter << std::endl;
        ++while_counter;  // Обновление переменной цикла
    }
    std::cout << "Цикл while завершен!" << std::endl;
    std::cout << std::endl;

    /*
     * ПРИМЕР 3: break И continue В ЦИКЛЕ DO-WHILE
     * 
     * Демонстрация использования break и continue в цикле do-while.
     * 
     * ВАЖНО: В цикле do-while при использовании continue также необходимо
     * вручную обновлять переменную цикла!
     */
    std::cout << "=== ПРИМЕР 3: break И continue В ЦИКЛЕ DO-WHILE ===" << std::endl;
    std::cout << "Цикл do-while с операторами break и continue:" << std::endl;
    
    size_t dowhile_counter{0};
    do {
        if (dowhile_counter == SKIP_VALUE) {
            std::cout << "Пропускаем итерацию " << dowhile_counter << " (continue)" << std::endl;
            ++dowhile_counter;  // ВАЖНО! Обновляем переменную перед continue
            continue;  // Пропускаем текущую итерацию
        }

        if (dowhile_counter == BREAK_VALUE) {
            std::cout << "Выходим из цикла при значении " << dowhile_counter << " (break)" << std::endl;
            break;  // Полностью выходим из цикла
        }

        std::cout << "Обрабатываем значение: " << dowhile_counter << std::endl;
        ++dowhile_counter;  // Обновление переменной цикла
    } while (dowhile_counter < LOOP_ITERATIONS);
    
    std::cout << "Цикл do-while завершен!" << std::endl;
    std::cout << std::endl;

    /*
     * ПРИМЕР 4: ПРАКТИЧЕСКОЕ ПРИМЕНЕНИЕ - ПОИСК В МАССИВЕ
     * 
     * Демонстрация практического использования break для поиска элемента
     */
    std::cout << "=== ПРИМЕР 4: ПОИСК В МАССИВЕ ===" << std::endl;
    std::cout << "Поиск элемента в массиве с использованием break:" << std::endl;
    
    int numbers[] = {10, 25, 7, 42, 15, 8, 33, 19};
    const size_t array_size = sizeof(numbers) / sizeof(numbers[0]);
    int target_value = 42;
    bool found = false;
    size_t found_index = 0;
    
    std::cout << "Ищем значение " << target_value << " в массиве: ";
    for (size_t i = 0; i < array_size; ++i) {
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl;
    
    for (size_t search_index = 0; search_index < array_size; ++search_index) {
        if (numbers[search_index] == target_value) {
            found = true;
            found_index = search_index;
            break;  // Найден элемент, выходим из цикла
        }
    }
    
    if (found) {
        std::cout << "Элемент " << target_value << " найден на позиции " << found_index << std::endl;
    } else {
        std::cout << "Элемент " << target_value << " не найден в массиве" << std::endl;
    }
    std::cout << std::endl;

    /*
     * ПРИМЕР 5: ПРАКТИЧЕСКОЕ ПРИМЕНЕНИЕ - ФИЛЬТРАЦИЯ ДАННЫХ
     * 
     * Демонстрация практического использования continue для фильтрации
     */
    std::cout << "=== ПРИМЕР 5: ФИЛЬТРАЦИЯ ДАННЫХ ===" << std::endl;
    std::cout << "Фильтрация четных чисел с использованием continue:" << std::endl;
    
    const size_t filter_range = 15;
    std::cout << "Нечетные числа от 1 до " << filter_range << ":" << std::endl;
    
    for (size_t filter_counter = 1; filter_counter <= filter_range; ++filter_counter) {
        if (filter_counter % 2 == 0) {
            continue;  // Пропускаем четные числа
        }
        std::cout << filter_counter << " ";
    }
    std::cout << std::endl;
    std::cout << std::endl;

    /*
     * ПРИМЕР 6: ВЛОЖЕННЫЕ ЦИКЛЫ И break
     * 
     * Демонстрация работы break во вложенных циклах
     */
    std::cout << "=== ПРИМЕР 6: ВЛОЖЕННЫЕ ЦИКЛЫ И break ===" << std::endl;
    std::cout << "Демонстрация break во вложенных циклах:" << std::endl;
    
    const size_t outer_limit = 3;
    const size_t inner_limit = 5;
    const size_t break_condition = 2;
    
    for (size_t outer = 0; outer < outer_limit; ++outer) {
        std::cout << "Внешний цикл: " << outer << std::endl;
        
        for (size_t inner = 0; inner < inner_limit; ++inner) {
            if (inner == break_condition) {
                std::cout << "  Выходим из внутреннего цикла при inner = " << inner << std::endl;
                break;  // Выходим только из внутреннего цикла
            }
            std::cout << "  Внутренний цикл: " << inner << std::endl;
        }
    }
    std::cout << std::endl;

    /*
     * ПРИМЕР 7: ОШИБКА - БЕСКОНЕЧНЫЙ ЦИКЛ С continue
     * 
     * Демонстрация типичной ошибки при использовании continue в while
     */
    std::cout << "=== ПРИМЕР 7: ПРЕДУПРЕЖДЕНИЕ О БЕСКОНЕЧНОМ ЦИКЛЕ ===" << std::endl;
    std::cout << "Демонстрация правильного использования continue в while:" << std::endl;
    
    size_t correct_counter = 0;
    while (correct_counter < 5) {
        if (correct_counter == 2) {
            std::cout << "Пропускаем " << correct_counter << " (правильно)" << std::endl;
            ++correct_counter;  // ПРАВИЛЬНО: обновляем перед continue
            continue;
        }
        std::cout << "Обрабатываем: " << correct_counter << std::endl;
        ++correct_counter;
    }
    
    std::cout << "Если бы мы не обновили переменную перед continue," << std::endl;
    std::cout << "цикл стал бы бесконечным!" << std::endl;
    std::cout << std::endl;

    /*
     * РЕКОМЕНДАЦИИ ПО ИСПОЛЬЗОВАНИЮ break И continue
     * 
     * Практические советы для эффективного использования
     */
    std::cout << "=== РЕКОМЕНДАЦИИ ===" << std::endl;
    std::cout << "1. Используйте break для досрочного выхода из цикла" << std::endl;
    std::cout << "2. Используйте continue для пропуска текущей итерации" << std::endl;
    std::cout << "3. В циклах while и do-while обновляйте переменные перед continue" << std::endl;
    std::cout << "4. break выходит только из ближайшего цикла (не из вложенных)" << std::endl;
    std::cout << "5. Избегайте чрезмерного использования break и continue" << std::endl;
    std::cout << "6. Рассмотрите альтернативы (флаги, условия) для лучшей читаемости" << std::endl;
    std::cout << "7. Тестируйте код с break и continue тщательно" << std::endl;
    std::cout << std::endl;
    
    return 0;
}

/*
 * РЕЗЮМЕ: ОПЕРАТОРЫ break И continue В C++
 * 
 * 1. ОСНОВНЫЕ ПОНЯТИЯ:
 *    - break - принудительный выход из цикла
 *    - continue - пропуск текущей итерации
 *    - Работают во всех типах циклов (for, while, do-while)
 *    - Улучшают контроль над выполнением циклов
 * 
 * 2. ОПЕРАТОР break:
 *    - Полностью завершает выполнение цикла
 *    - Передает управление следующему оператору после цикла
 *    - Выходит только из ближайшего цикла (не из вложенных)
 *    - Полезен для досрочного завершения при выполнении условия
 * 
 * 3. ОПЕРАТОР continue:
 *    - Пропускает оставшуюся часть текущей итерации
 *    - Переходит к следующей итерации цикла
 *    - В циклах while/do-while требует обновления переменных
 *    - Полезен для пропуска определенных значений
 * 
 * 4. ОСОБЕННОСТИ В РАЗНЫХ ЦИКЛАХ:
 *    - for: автоматическое обновление переменной
 *    - while: требует ручного обновления перед continue
 *    - do-while: требует ручного обновления перед continue
 * 
 * 5. ПРАКТИЧЕСКИЕ ПРИМЕНЕНИЯ:
 *    - Поиск элементов в массивах (break)
 *    - Фильтрация данных (continue)
 *    - Валидация входных данных
 *    - Обработка ошибок
 *    - Оптимизация производительности
 * 
 * 6. ПРЕИМУЩЕСТВА:
 *    - Гибкий контроль над циклами
 *    - Улучшение производительности
 *    - Более читаемый код в некоторых случаях
 *    - Возможность досрочного завершения
 * 
 * 7. НЕДОСТАТКИ:
 *    - Может снижать читаемость кода
 *    - Риск бесконечных циклов с continue
 *    - Сложность отладки
 *    - Нарушение структурированного программирования
 * 
 * 8. РЕКОМЕНДАЦИИ:
 *    - Используйте осторожно и осознанно
 *    - Обновляйте переменные перед continue в while/do-while
 *    - Рассмотрите альтернативы для лучшей читаемости
 *    - Тестируйте код тщательно
 *    - Документируйте сложную логику
 * 
 * 9. ВАЖНЫЕ ЗАМЕЧАНИЯ:
 *    - break выходит только из одного уровня вложенности
 *    - continue может вызвать бесконечный цикл в while/do-while
 *    - Не работают в switch (кроме break)
 *    - Могут усложнить понимание логики программы
 * 
 * 10. АЛЬТЕРНАТИВЫ:
 *     - Флаги и условия вместо break/continue
 *     - Функции для инкапсуляции логики
 *     - Алгоритмы STL для стандартных операций
 *     - Структурированное программирование
 * 
 * 11. ДОПОЛНИТЕЛЬНЫЕ ВОЗМОЖНОСТИ:
 *     - Метки для выхода из вложенных циклов (goto)
 *     - Исключения для обработки ошибок
 *     - RAII для управления ресурсами
 *     - Функциональное программирование
 */