/*
 * ЧИСЛОВЫЕ ПРЕДЕЛЫ В C++
 * 
 * Этот файл демонстрирует использование std::numeric_limits для получения
 * информации о числовых типах данных:
 * - Минимальные и максимальные значения типов
 * - Различие между min() и lowest() для вещественных чисел
 * - Дополнительные свойства типов (знаковость, количество цифр)
 * - Практическое применение для проверки переполнения
 */

#include <iostream>  // Для потоков ввода-вывода
#include <limits>    // Для std::numeric_limits

int main() {
    /*
     * ЧИСЛОВЫЕ ПРЕДЕЛЫ ДЛЯ ЦЕЛЫХ ТИПОВ
     * 
     * std::numeric_limits<T>::min() - минимальное значение типа T
     * std::numeric_limits<T>::max() - максимальное значение типа T
     * 
     * Для целых типов min() возвращает наименьшее возможное значение
     */
    std::cout << "=== ПРЕДЕЛЫ ЦЕЛЫХ ТИПОВ ===" << std::endl;
    
    std::cout << "Диапазон short: от " << std::numeric_limits<short>::min() 
              << " до " << std::numeric_limits<short>::max() << std::endl;
    
    std::cout << "Диапазон unsigned short: от " << std::numeric_limits<unsigned short>::min() 
              << " до " << std::numeric_limits<unsigned short>::max() << std::endl;
    
    std::cout << "Диапазон int: от " << std::numeric_limits<int>::min() 
              << " до " << std::numeric_limits<int>::max() << std::endl;
    
    std::cout << "Диапазон unsigned int: от " << std::numeric_limits<unsigned int>::min() 
              << " до " << std::numeric_limits<unsigned int>::max() << std::endl;
    
    std::cout << "Диапазон long: от " << std::numeric_limits<long>::min() 
              << " до " << std::numeric_limits<long>::max() << std::endl;
    std::cout << std::endl;

    /*
     * ЧИСЛОВЫЕ ПРЕДЕЛЫ ДЛЯ ВЕЩЕСТВЕННЫХ ТИПОВ
     * 
     * Для вещественных типов есть важное различие:
     * - min() - наименьшее положительное нормализованное значение
     * - lowest() - наименьшее возможное значение (включая отрицательные)
     * - max() - наибольшее возможное значение
     * 
     * Это различие критично для понимания диапазонов вещественных чисел!
     */
    std::cout << "=== ПРЕДЕЛЫ ВЕЩЕСТВЕННЫХ ТИПОВ ===" << std::endl;
    
    std::cout << "Диапазон float (min): от " << std::numeric_limits<float>::min() 
              << " до " << std::numeric_limits<float>::max() << std::endl;
    
    std::cout << "Диапазон float (lowest): от " << std::numeric_limits<float>::lowest() 
              << " до " << std::numeric_limits<float>::max() << std::endl;
    
    std::cout << "Диапазон double (lowest): от " << std::numeric_limits<double>::lowest() 
              << " до " << std::numeric_limits<double>::max() << std::endl;
    
    std::cout << "Диапазон long double (lowest): от " << std::numeric_limits<long double>::lowest() 
              << " до " << std::numeric_limits<long double>::max() << std::endl;
    std::cout << std::endl;

    /*
     * ДОПОЛНИТЕЛЬНЫЕ СВОЙСТВА ТИПОВ
     * 
     * std::numeric_limits предоставляет множество полезной информации
     * о числовых типах, которая может быть полезна при программировании
     */
    std::cout << "=== ДОПОЛНИТЕЛЬНЫЕ СВОЙСТВА ТИПОВ ===" << std::endl;
    
    // Проверка знаковости типа
    std::cout << "int является знаковым: " << std::boolalpha 
              << std::numeric_limits<int>::is_signed << std::endl;
    
    // Количество цифр (битов) в мантиссе
    std::cout << "Количество цифр в int: " << std::numeric_limits<int>::digits << std::endl;
    
    // Дополнительные полезные свойства
    std::cout << "int имеет бесконечность: " << std::boolalpha 
              << std::numeric_limits<int>::has_infinity << std::endl;
    
    std::cout << "float имеет бесконечность: " << std::boolalpha 
              << std::numeric_limits<float>::has_infinity << std::endl;
    
    std::cout << "float имеет NaN: " << std::boolalpha 
              << std::numeric_limits<float>::has_quiet_NaN << std::endl;
    std::cout << std::endl;

    /*
     * ПРАКТИЧЕСКОЕ ПРИМЕНЕНИЕ
     * 
     * Демонстрация того, как можно использовать numeric_limits
     * для проверки переполнения и других практических задач
     */
    std::cout << "=== ПРАКТИЧЕСКОЕ ПРИМЕНЕНИЕ ===" << std::endl;
    
    // Пример проверки переполнения
    int max_int_value = std::numeric_limits<int>::max();
    int min_int_value = std::numeric_limits<int>::min();
    
    std::cout << "Максимальное значение int: " << max_int_value << std::endl;
    std::cout << "Минимальное значение int: " << min_int_value << std::endl;
    
    // Предупреждение о переполнении
    std::cout << "ВНИМАНИЕ: Попытка увеличить максимальное значение int приведет к переполнению!" << std::endl;
    std::cout << "max_int + 1 = " << (max_int_value + 1) << " (переполнение!)" << std::endl;
    std::cout << std::endl;
    
    return 0;
}

/*
 * РЕЗЮМЕ: ЧИСЛОВЫЕ ПРЕДЕЛЫ В C++
 * 
 * 1. ОСНОВНЫЕ ФУНКЦИИ std::numeric_limits:
 *    - min() - минимальное значение типа
 *    - max() - максимальное значение типа
 *    - lowest() - наименьшее значение (важно для вещественных типов)
 * 
 * 2. РАЗЛИЧИЕ МЕЖДУ min() И lowest():
 *    - Для целых типов: min() = lowest()
 *    - Для вещественных типов: min() > 0, lowest() < 0
 * 
 * 3. ДОПОЛНИТЕЛЬНЫЕ СВОЙСТВА:
 *    - is_signed - проверка знаковости типа
 *    - digits - количество цифр в представлении
 *    - has_infinity - поддержка бесконечности
 *    - has_quiet_NaN - поддержка NaN
 * 
 * 4. ПРАКТИЧЕСКОЕ ПРИМЕНЕНИЕ:
 *    - Проверка переполнения при арифметических операциях
 *    - Валидация входных данных
 *    - Оптимизация алгоритмов
 *    - Отладка числовых вычислений
 * 
 * 5. ВАЖНЫЕ ЗАМЕЧАНИЯ:
 *    - Значения могут отличаться на разных платформах
 *    - Вещественные типы имеют специальные значения (Infinity, NaN)
 *    - Используйте numeric_limits для написания переносимого кода
 *    - Всегда проверяйте переполнение при работе с граничными значениями
 * 
 * 6. ДОПОЛНИТЕЛЬНАЯ ИНФОРМАЦИЯ:
 *    - Полная документация: https://en.cppreference.com/w/cpp/types/numeric_limits
 *    - Множество других полезных свойств доступно в std::numeric_limits
 */