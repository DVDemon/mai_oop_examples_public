/*
 * ЛОГИЧЕСКИЕ ОПЕРАТОРЫ В C++
 * 
 * Этот файл демонстрирует работу с логическими операторами:
 * - Логическое И (&&)
 * - Логическое ИЛИ (||)
 * - Логическое НЕ (!)
 * - Комбинирование логических операторов
 * - Использование с операторами сравнения
 */

#include <iostream>  // Для потоков ввода-вывода

int main() {
    /*
     * ОБЪЯВЛЕНИЕ ЛОГИЧЕСКИХ ПЕРЕМЕННЫХ
     * 
     * Создаем три булевы переменные для демонстрации логических операций
     * Используем мнемонические имена для лучшего понимания
     */
    bool is_condition_a_true {true};   // Первое условие - истинно
    bool is_condition_b_false {false}; // Второе условие - ложно
    bool is_condition_c_true {true};   // Третье условие - истинно
    
    /*
     * НАСТРОЙКА ВЫВОДА БУЛЕВЫХ ЗНАЧЕНИЙ
     * 
     * std::boolalpha заставляет cout выводить true/false вместо 1/0
     * Это делает вывод более читаемым для логических операций
     */
    std::cout << std::boolalpha; // Выводить true/false вместо 1/0
    
    std::cout << "=== ИСХОДНЫЕ ЗНАЧЕНИЯ ===" << std::endl;
    std::cout << "is_condition_a_true : " << is_condition_a_true << std::endl;
    std::cout << "is_condition_b_false : " << is_condition_b_false << std::endl;
    std::cout << "is_condition_c_true : " << is_condition_c_true << std::endl;
    std::cout << std::endl;

    /*
     * ЛОГИЧЕСКОЕ И (&&)
     * 
     * Оператор && возвращает true только когда ВСЕ операнды истинны.
     * Если хотя бы один операнд ложен, результат будет false.
     * 
     * Это как цепь: если одно звено сломано, вся цепь не работает.
     */
    std::cout << "=== ЛОГИЧЕСКОЕ И (&&) ===" << std::endl;
    std::cout << "is_condition_a_true && is_condition_b_false : " 
              << (is_condition_a_true && is_condition_b_false) << std::endl; // false
    std::cout << "is_condition_a_true && is_condition_c_true : " 
              << (is_condition_a_true && is_condition_c_true) << std::endl;  // true
    std::cout << "is_condition_a_true && is_condition_b_false && is_condition_c_true : " 
              << (is_condition_a_true && is_condition_b_false && is_condition_c_true) << std::endl; // false
    std::cout << std::endl;

    /*
     * ЛОГИЧЕСКОЕ ИЛИ (||)
     * 
     * Оператор || возвращает true если ХОТЯ БЫ ОДИН операнд истинен.
     * Только если все операнды ложны, результат будет false.
     * 
     * Это как параллельные пути: если хотя бы один путь открыт, можно пройти.
     */
    std::cout << "=== ЛОГИЧЕСКОЕ ИЛИ (||) ===" << std::endl;
    std::cout << "is_condition_a_true || is_condition_b_false : " 
              << (is_condition_a_true || is_condition_b_false) << std::endl; // true
    std::cout << "is_condition_a_true || is_condition_c_true : " 
              << (is_condition_a_true || is_condition_c_true) << std::endl;  // true
    std::cout << "is_condition_a_true || is_condition_b_false || is_condition_c_true : " 
              << (is_condition_a_true || is_condition_b_false || is_condition_c_true) << std::endl; // true
    std::cout << std::endl;

    /*
     * ЛОГИЧЕСКОЕ НЕ (!)
     * 
     * Оператор ! инвертирует значение операнда:
     * - !true = false
     * - !false = true
     * 
     * Это как переключатель: включенное становится выключенным и наоборот.
     */
    std::cout << "=== ЛОГИЧЕСКОЕ НЕ (!) ===" << std::endl;
    std::cout << "!is_condition_a_true : " << !is_condition_a_true << std::endl;     // false
    std::cout << "!is_condition_b_false : " << !is_condition_b_false << std::endl;   // true
    std::cout << "!is_condition_c_true : " << !is_condition_c_true << std::endl;     // false
    std::cout << std::endl;

    /*
     * КОМБИНИРОВАНИЕ ЛОГИЧЕСКИХ ОПЕРАТОРОВ
     * 
     * Можно комбинировать несколько логических операторов в одном выражении.
     * Важно помнить о приоритете операций и использовать скобки для ясности.
     * 
     * Приоритет: ! > && > ||
     */
    std::cout << "=== КОМБИНИРОВАНИЕ ОПЕРАТОРОВ ===" << std::endl;
    std::cout << "!(is_condition_a_true && is_condition_b_false) || is_condition_c_true : " 
              << (!(is_condition_a_true && is_condition_b_false) || is_condition_c_true) << std::endl; // true
    std::cout << std::endl;

    /*
     * ЛОГИЧЕСКИЕ ОПЕРАТОРЫ С ОПЕРАТОРАМИ СРАВНЕНИЯ
     * 
     * Логические операторы часто используются с операторами сравнения
     * для создания сложных условий.
     * 
     * Операторы сравнения возвращают bool, поэтому их можно комбинировать
     * с логическими операторами.
     */
    int first_number {45};
    int second_number {20};
    int third_number {11};
    
    std::cout << "=== ЛОГИЧЕСКИЕ ОПЕРАЦИИ С ЧИСЛАМИ ===" << std::endl;
    std::cout << "first_number : " << first_number << std::endl;
    std::cout << "second_number : " << second_number << std::endl;
    std::cout << "third_number : " << third_number << std::endl;
    std::cout << std::endl;
    
    /*
     * ДЕМОНСТРАЦИЯ РАЗЛИЧНЫХ КОМБИНАЦИЙ
     * 
     * Каждое выражение показывает, как логические операторы
     * работают с результатами операций сравнения.
     */
    std::cout << "(first_number > second_number) && (first_number > third_number) : " 
              << ((first_number > second_number) && (first_number > third_number)) << std::endl; // true
    std::cout << "(first_number == second_number) || (second_number <= third_number) : " 
              << ((first_number == second_number) || (second_number <= third_number)) << std::endl; // false
    std::cout << "(first_number < second_number) || (first_number > third_number) : " 
              << ((first_number < second_number) || (first_number > third_number)) << std::endl; // true
    std::cout << "(third_number > second_number) || (first_number < third_number) : " 
              << ((third_number > second_number) || (first_number < third_number)) << std::endl; // false
    std::cout << "(first_number > third_number) && (third_number <= first_number) : " 
              << ((first_number > third_number) && (third_number <= first_number)) << std::endl; // true
    std::cout << "(first_number > second_number) && (first_number <= third_number) : " 
              << ((first_number > second_number) && (first_number <= third_number)) << std::endl; // false
    std::cout << "(!is_condition_a_true) && (first_number == second_number) : " 
              << ((!is_condition_a_true) && (first_number == second_number)) << std::endl; // false
    std::cout << std::endl;
    
    return 0;
}

/*
 * РЕЗЮМЕ: ЛОГИЧЕСКИЕ ОПЕРАТОРЫ В C++
 * 
 * 1. ОСНОВНЫЕ ЛОГИЧЕСКИЕ ОПЕРАТОРЫ:
 *    - && (И) - true только если все операнды true
 *    - || (ИЛИ) - true если хотя бы один операнд true
 *    - ! (НЕ) - инвертирует значение операнда
 * 
 * 2. ПРИОРИТЕТ ОПЕРАЦИЙ:
 *    - ! (высший приоритет)
 *    - &&
 *    - || (низший приоритет)
 * 
 * 3. КОМБИНИРОВАНИЕ С ОПЕРАТОРАМИ СРАВНЕНИЯ:
 *    - Операторы сравнения возвращают bool
 *    - Их результаты можно комбинировать с логическими операторами
 *    - Используйте скобки для ясности сложных выражений
 * 
 * 4. ПРАКТИЧЕСКИЕ СОВЕТЫ:
 *    - Используйте мнемонические имена для булевых переменных
 *    - Применяйте std::boolalpha для читаемого вывода
 *    - Не забывайте о скобках в сложных выражениях
 *    - Логические операторы часто используются в условиях if/else
 * 
 * 5. ВАЖНЫЕ ЗАМЕЧАНИЯ:
 *    - Логические операторы работают с булевыми значениями
 *    - Операторы сравнения автоматически преобразуются в bool
 *    - Короткое замыкание: && и || не вычисляют правую часть, если результат уже определен
 *    - Используйте логические операторы для создания сложных условий в программах
 */