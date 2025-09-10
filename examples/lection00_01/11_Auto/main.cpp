/*
 * КЛЮЧЕВОЕ СЛОВО AUTO В C++
 * 
 * Этот файл демонстрирует автоматическое выведение типов:
 * - Ключевое слово auto для автоматического определения типа
 * - Выведение типов на основе инициализаторов
 * - Использование суффиксов для явного указания типа
 * - Сравнение размеров автоматически выведенных типов
 * - Преимущества и ограничения использования auto
 */

#include <iostream>  // Для потоков ввода-вывода

/*
 * ПРИМЕР ФУНКЦИИ С AUTO (закомментирован)
 * 
 * auto func(auto a) - это C++20 синтаксис для шаблонных функций
 * В более ранних версиях C++ auto можно использовать только для локальных переменных
 */
// auto func(auto a){
//     return a;
// }

int main(){
    /*
     * АВТОМАТИЧЕСКОЕ ВЫВЕДЕНИЕ ТИПОВ ДЛЯ ОСНОВНЫХ ТИПОВ
     * 
     * auto позволяет компилятору автоматически определить тип переменной
     * на основе значения инициализатора
     */
    std::cout << "=== АВТОМАТИЧЕСКОЕ ВЫВЕДЕНИЕ ОСНОВНЫХ ТИПОВ ===" << std::endl;
    
    auto integer_value {12};      // auto выводится как int
    auto double_value {13.0};     // auto выводится как double
    auto float_value {14.0f};     // auto выводится как float (суффикс f)
    auto long_double_value {15.0l}; // auto выводится как long double (суффикс l)
    auto character_value {'e'};   // auto выводится как char

    /*
     * АВТОМАТИЧЕСКОЕ ВЫВЕДЕНИЕ С МОДИФИКАТОРАМИ ТИПОВ
     * 
     * Использование суффиксов для явного указания типа:
     * - u - unsigned
     * - l - long
     * - ll - long long
     * - ul - unsigned long
     */
    std::cout << "=== АВТОМАТИЧЕСКОЕ ВЫВЕДЕНИЕ С МОДИФИКАТОРАМИ ===" << std::endl;
    
    auto unsigned_value {123u};     // auto выводится как unsigned int
    auto unsigned_long_value {123ul}; // auto выводится как unsigned long
    auto long_long_value {123ll};   // auto выводится как long long

    /*
     * ДЕМОНСТРАЦИЯ РАЗМЕРОВ АВТОМАТИЧЕСКИ ВЫВЕДЕННЫХ ТИПОВ
     * 
     * sizeof() показывает, что auto действительно выводит правильные типы
     */
    std::cout << "=== РАЗМЕРЫ АВТОМАТИЧЕСКИ ВЫВЕДЕННЫХ ТИПОВ ===" << std::endl;
    
    std::cout << "integer_value (int): " << sizeof(integer_value) << " байт" << std::endl;
    std::cout << "double_value (double): " << sizeof(double_value) << " байт" << std::endl;
    std::cout << "float_value (float): " << sizeof(float_value) << " байт" << std::endl;
    std::cout << "long_double_value (long double): " << sizeof(long_double_value) << " байт" << std::endl;
    std::cout << "character_value (char): " << sizeof(character_value) << " байт" << std::endl;
    std::cout << "unsigned_value (unsigned int): " << sizeof(unsigned_value) << " байт" << std::endl;
    std::cout << "unsigned_long_value (unsigned long): " << sizeof(unsigned_long_value) << " байт" << std::endl;
    std::cout << "long_long_value (long long): " << sizeof(long_long_value) << " байт" << std::endl;
    
    /*
     * ДОПОЛНИТЕЛЬНЫЕ ПРИМЕРЫ AUTO
     */
    std::cout << std::endl;
    std::cout << "=== ДОПОЛНИТЕЛЬНЫЕ ПРИМЕРЫ ===" << std::endl;
    
    // auto с различными инициализаторами
    auto boolean_value {true};        // bool
    auto string_literal {"Hello"};    // const char*
    auto number_with_decimal {3.14};  // double
    
    std::cout << "boolean_value (bool): " << sizeof(boolean_value) << " байт" << std::endl;
    std::cout << "string_literal (const char*): " << sizeof(string_literal) << " байт" << std::endl;
    std::cout << "number_with_decimal (double): " << sizeof(number_with_decimal) << " байт" << std::endl;

    return 0;
}

/*
 * РЕЗЮМЕ: КЛЮЧЕВОЕ СЛОВО AUTO В C++
 * 
 * 1. ЧТО ТАКОЕ AUTO:
 *    - Ключевое слово для автоматического выведения типа
 *    - Компилятор определяет тип на основе инициализатора
 *    - Введено в C++11 для упрощения кода
 * 
 * 2. ПРАВИЛА ВЫВЕДЕНИЯ ТИПОВ:
 *    - auto var {12};     → int
 *    - auto var {12.0};   → double
 *    - auto var {12.0f};  → float
 *    - auto var {12u};    → unsigned int
 *    - auto var {'a'};    → char
 *    - auto var {true};   → bool
 * 
 * 3. СУФФИКСЫ ДЛЯ ЯВНОГО УКАЗАНИЯ ТИПА:
 *    - f или F - float
 *    - l или L - long double
 *    - u или U - unsigned
 *    - l или L - long
 *    - ll или LL - long long
 *    - ul или UL - unsigned long
 * 
 * 4. ПРЕИМУЩЕСТВА AUTO:
 *    - Упрощает код (меньше повторений типов)
 *    - Автоматически адаптируется к изменениям типов
 *    - Предотвращает ошибки при изменении типов
 *    - Улучшает читаемость кода
 * 
 * 5. ОГРАНИЧЕНИЯ AUTO:
 *    - Нельзя использовать без инициализатора
 *    - Может выводить неожиданные типы
 *    - Снижает явность типов в коде
 *    - Может усложнить отладку
 * 
 * 6. ПРАКТИЧЕСКИЕ СОВЕТЫ:
 *    - Используйте auto для длинных типов (итераторы, умные указатели)
 *    - Будьте осторожны с auto и ссылками
 *    - Используйте суффиксы для явного указания типа
 *    - Не злоупотребляйте auto - иногда явный тип лучше
 * 
 * 7. СВЯЗЬ С ПРЕДЫДУЩИМИ ТЕМАМИ:
 *    - auto работает со всеми изученными типами (int, double, char, bool)
 *    - sizeof() показывает реальный тип, выведенный auto
 *    - Модификаторы (signed, unsigned, long) влияют на выведение типа
 *    - Инициализация по-прежнему важна для правильного выведения
 */