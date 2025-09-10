/*
 * КОНСТАНТНЫЕ ВЫРАЖЕНИЯ В C++ (constexpr)
 * 
 * Этот файл демонстрирует использование constexpr для создания
 * константных выражений времени компиляции:
 * - Различие между const и constexpr
 * - Вычисление значений во время компиляции
 * - Ограничения constexpr
 * - Практические примеры применения
 * - static_assert для проверки констант времени компиляции
 */

#include <iostream>  // Для потоков ввода-вывода

int main() {
    /*
     * ОСНОВНЫЕ КОНСТАНТНЫЕ ВЫРАЖЕНИЯ
     * 
     * constexpr - ключевое слово, которое указывает, что значение
     * должно быть вычислено во время компиляции.
     * 
     * Различие между const и constexpr:
     * - const: значение не изменяется во время выполнения
     * - constexpr: значение вычисляется во время компиляции
     */
    constexpr int library_major_version {1237};  // Версия библиотеки (известна при компиляции)
    constexpr int human_eye_count {2};           // Количество глаз у человека
    constexpr double pi_approximation {3.14};    // Приближенное значение π
    
    /*
     * ПОПЫТКА ИЗМЕНЕНИЯ constexpr (ЗАКОММЕНТИРОВАНО)
     * 
     * constexpr переменные нельзя изменять, как и обычные константы
     */
    // human_eye_count = 4;  // ОШИБКА: нельзя изменить constexpr
    
    std::cout << "=== ОСНОВНЫЕ КОНСТАНТНЫЕ ВЫРАЖЕНИЯ ===" << std::endl;
    std::cout << "Количество глаз у человека: " << human_eye_count << std::endl;
    std::cout << "Приближенное значение π: " << pi_approximation << std::endl;
    std::cout << "Версия библиотеки: " << library_major_version << std::endl;
    std::cout << std::endl;

    /*
     * ОГРАНИЧЕНИЯ constexpr
     * 
     * constexpr переменные могут быть инициализированы только
     * другими constexpr значениями или константами времени компиляции
     */
    std::cout << "=== ОГРАНИЧЕНИЯ constexpr ===" << std::endl;
    
    // Этот код закомментирован, потому что вызывает ошибку компиляции
    // int leg_count {2};                    // Обычная переменная (не constexpr)
    // constexpr int arm_count{leg_count};   // ОШИБКА: leg_count не известна при компиляции
    
    std::cout << "constexpr может быть инициализирована только константами времени компиляции" << std::endl;
    std::cout << std::endl;

    /*
     * ПРАВИЛЬНОЕ ИСПОЛЬЗОВАНИЕ constexpr
     * 
     * constexpr переменные могут быть инициализированы другими constexpr значениями
     * и результатами вычислений, которые можно выполнить во время компиляции
     */
    std::cout << "=== ПРАВИЛЬНОЕ ИСПОЛЬЗОВАНИЕ constexpr ===" << std::endl;
    
    constexpr int room_count{10};                    // Количество комнат
    constexpr int door_count{room_count};            // Количество дверей (равно количеству комнат)
    
    const int table_count{5};                        // Обычная константа
    constexpr int chair_count{ table_count * 5};     // Количество стульев (вычисляется при компиляции)
    
    std::cout << "Количество комнат: " << room_count << std::endl;
    std::cout << "Количество дверей: " << door_count << std::endl;
    std::cout << "Количество столов: " << table_count << std::endl;
    std::cout << "Количество стульев: " << chair_count << std::endl;
    std::cout << std::endl;

    /*
     * ПРАКТИЧЕСКИЕ ПРИМЕРЫ constexpr
     * 
     * Демонстрация различных способов использования constexpr
     * в реальных программах
     */
    std::cout << "=== ПРАКТИЧЕСКИЕ ПРИМЕРЫ ===" << std::endl;
    
    // Математические константы
    constexpr double euler_number = 2.71828182846;
    constexpr double golden_ratio = 1.61803398875;
    
    // Константы для вычислений
    constexpr int seconds_per_minute = 60;
    constexpr int minutes_per_hour = 60;
    constexpr int hours_per_day = 24;
    constexpr int days_per_year = 365;
    
    // Вычисленные константы
    constexpr int seconds_per_hour = seconds_per_minute * minutes_per_hour;
    constexpr int seconds_per_day = seconds_per_hour * hours_per_day;
    constexpr int seconds_per_year = seconds_per_day * days_per_year;
    
    std::cout << "Математические константы:" << std::endl;
    std::cout << "Число Эйлера (e): " << euler_number << std::endl;
    std::cout << "Золотое сечение: " << golden_ratio << std::endl;
    std::cout << std::endl;
    
    std::cout << "Временные константы:" << std::endl;
    std::cout << "Секунд в минуте: " << seconds_per_minute << std::endl;
    std::cout << "Секунд в часе: " << seconds_per_hour << std::endl;
    std::cout << "Секунд в дне: " << seconds_per_day << std::endl;
    std::cout << "Секунд в году: " << seconds_per_year << std::endl;
    std::cout << std::endl;

    /*
     * static_assert - ПРОВЕРКА КОНСТАНТ ВРЕМЕНИ КОМПИЛЯЦИИ
     * 
     * static_assert позволяет проверять условия во время компиляции.
     * Если условие ложно, компиляция завершится с ошибкой.
     * 
     * Это полезно для проверки констант и предотвращения ошибок.
     */
    std::cout << "=== static_assert - ПРОВЕРКА КОНСТАНТ ===" << std::endl;
    
    // Проверка версии библиотеки
    // static_assert(library_major_version == 1237, "Неверная версия библиотеки!");
    
    // Проверка математических констант
    // static_assert(seconds_per_year == 31536000, "Неверное количество секунд в году!");
    
    // Проверка логических условий
    // static_assert(human_eye_count == 2, "У человека должно быть 2 глаза!");
    
    std::cout << "static_assert позволяет проверять условия во время компиляции" << std::endl;
    std::cout << "Раскомментируйте строки выше, чтобы увидеть проверки в действии" << std::endl;
    std::cout << std::endl;

    /*
     * ДЕМОНСТРАЦИЯ ПРЕИМУЩЕСТВ constexpr
     * 
     * constexpr обеспечивает лучшую производительность и безопасность
     */
    std::cout << "=== ПРЕИМУЩЕСТВА constexpr ===" << std::endl;
    
    // Вычисления во время компиляции
    constexpr int array_size = 100;
    constexpr int buffer_size = array_size * 2;
    constexpr int max_elements = buffer_size / sizeof(int);
    
    std::cout << "Размер массива: " << array_size << std::endl;
    std::cout << "Размер буфера: " << buffer_size << std::endl;
    std::cout << "Максимальное количество элементов: " << max_elements << std::endl;
    std::cout << std::endl;
    
    std::cout << "Программа выполняет свои задачи..." << std::endl;
    
    return 0;
}

/*
 * РЕЗЮМЕ: КОНСТАНТНЫЕ ВЫРАЖЕНИЯ В C++ (constexpr)
 * 
 * 1. ОСНОВНЫЕ ПОНЯТИЯ:
 *    - constexpr - значение вычисляется во время компиляции
 *    - const - значение не изменяется во время выполнения
 *    - constexpr более строгий, чем const
 * 
 * 2. ОГРАНИЧЕНИЯ constexpr:
 *    - Может быть инициализирована только константами времени компиляции
 *    - Не может использовать значения, неизвестные при компиляции
 *    - Все вычисления должны быть выполнимы во время компиляции
 * 
 * 3. ПРАВИЛЬНОЕ ИСПОЛЬЗОВАНИЕ:
 *    - Инициализация другими constexpr значениями
 *    - Вычисления с константами времени компиляции
 *    - Математические операции с известными значениями
 * 
 * 4. static_assert:
 *    - Проверка условий во время компиляции
 *    - Предотвращение ошибок на этапе компиляции
 *    - Работает только с константами времени компиляции
 * 
 * 5. ПРЕИМУЩЕСТВА constexpr:
 *    - Лучшая производительность (вычисления при компиляции)
 *    - Безопасность типов
 *    - Оптимизация компилятора
 *    - Проверка ошибок во время компиляции
 * 
 * 6. ПРАКТИЧЕСКИЕ ПРИМЕНЕНИЯ:
 *    - Математические константы
 *    - Размеры массивов и буферов
 *    - Конфигурационные параметры
 *    - Проверка версий и совместимости
 * 
 * 7. ВАЖНЫЕ ЗАМЕЧАНИЯ:
 *    - Используйте constexpr для значений, известных при компиляции
 *    - constexpr обеспечивает лучшую производительность
 *    - static_assert помогает отлавливать ошибки раньше
 *    - constexpr - это основа для метапрограммирования в C++
 * 
 * 8. ДОПОЛНИТЕЛЬНЫЕ ВОЗМОЖНОСТИ:
 *    - constexpr функции (C++11)
 *    - constexpr конструкторы (C++11)
 *    - if constexpr (C++17)
 *    - consteval функции (C++20)
 */