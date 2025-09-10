/*
 * ФОРМАТИРОВАНИЕ ВЫВОДА В C++
 * 
 * Этот файл демонстрирует различные манипуляторы для форматирования вывода:
 * - Управление переносами строк
 * - Управление шириной полей
 * - Выравнивание текста
 * - Заполнители
 * - Форматы чисел (десятичный, шестнадцатеричный, восьмеричный)
 * - Форматы вещественных чисел
 * - Точность вывода
 */

#include <iostream>  // Для потоков ввода-вывода
#include <iomanip>   // Для манипуляторов форматирования (setw, setfill, setprecision и др.)

int main(){
    /*
     * УПРАВЛЕНИЕ ПЕРЕНОСАМИ СТРОК
     * 
     * std::endl vs '\n':
     * - std::endl - добавляет символ новой строки И сбрасывает буфер
     * - '\n' - только добавляет символ новой строки
     */
    
    // Демонстрация: без переносов строк текст слипается
    std::cout << "Hello";
    std::cout << "World";  // Результат: HelloWorld
    
    std::cout << std::endl;  // Принудительный перенос строки
    
    std::cout << "-------------" << std::endl;
    
    // Использование std::endl для переноса строк
    std::cout << "Hello" << std::endl;
    std::cout << "World" << std::endl;
    
    std::cout << std::endl;
    
    // Использование '\n' для переноса строк (только символ, без сброса буфера)
    std::cout << "Hello\n";
    std::cout << "World\n";
    
    
    //===================================================================
    std::cout << std::endl;

    /*
     * УПРАВЛЕНИЕ БУФЕРИЗАЦИЕЙ - std::flush
     * 
     * std::flush принудительно сбрасывает буфер вывода
     * Это гарантирует, что данные будут отправлены в поток немедленно
     * Полезно для отладки и критически важных сообщений
     */
    std::cout << "This is a nice message...." << std::endl << std::flush;
    // После std::flush мы уверены, что сообщение было отправлено в поток
    // Это может быть важно в некоторых приложениях (например, логирование)
    
    //===================================================================
    std::cout << std::endl;


    /*
     * УПРАВЛЕНИЕ ШИРИНОЙ ПОЛЕЙ - std::setw()
     * 
     * std::setw() устанавливает минимальную ширину поля для следующего выводимого значения
     * ВАЖНО: setw() действует только на СЛЕДУЮЩЕЕ значение!
     * Если текст короче указанной ширины, он дополняется пробелами
     */
    
    // Неформатированная таблица - неровные колонки
    std::cout << "Unformatted table : " << std::endl;
    std::cout << "Daniel" << " " << "Gray" << " 25" << std::endl;
    std::cout << "Stanley" <<" "  << "Woods" << " 33" << std::endl;
    std::cout << "Jordan" << " "  << "Parker" << " 45" << std::endl;
    std::cout << "Joe" << " " << "Ball" << " 21" << std::endl;
    std::cout << "Josh" << " " << "Carr" << " 27" << std::endl;
    std::cout << "Izaiah" << " " << "Robinson" << " 29" << std::endl;
    
    std::cout << std::endl;
    std::cout << "Formatted table : " << std::endl;
    
    // Форматированная таблица с фиксированной шириной колонок
    std::cout << std::setw(10) <<  "Lastname"  << std::setw(10) << "Firstname" << std::setw(5) << "Age" << std::endl;
    std::cout << std::setw(10) << "Daniel"  << std::setw(10) << "Gray" << std::setw(5) << "25" << std::endl;
    std::cout << std::setw(10) << "Stanley" << std::setw(10)  << "Woods" << std::setw(5) <<  "33" << std::endl;
    std::cout << std::setw(10) <<  "Jordan" << std::setw(10)  << "Parker" << std::setw(5) << "45" << std::endl;
    std::cout << std::setw(10) <<  "Joe" << std::setw(10) << "Ball" << std::setw(5) << "21" << std::endl;
    std::cout << std::setw(10) << "Josh" << std::setw(10) << "Carr" << std::setw(5) <<"27" << std::endl;
    std::cout << std::setw(10) << "Izaiah" << std::setw(10) << "Robinson" << std::setw(5) << "29" << std::endl;
    
    std::cout << std::endl;
    std::cout << "Formatted table with variables: " << std::endl;
    
    // Использование переменных для управления шириной колонок
    int col_width{14};  // Ширина колонки для имени и фамилии
    
    // Более гибкий подход - ширина колонок задается переменными
    std::cout << std::setw(col_width) <<  "Lastname"  << std::setw(col_width) << "Firstname" << std::setw(col_width/2) << "Age" << std::endl;
    std::cout << std::setw(col_width) << "Daniel"  << std::setw(col_width) << "Gray" << std::setw(col_width/2) << "25" << std::endl;
    std::cout << std::setw(col_width) << "Stanley" << std::setw(col_width)  << "Woods" << std::setw(col_width/2) <<  "33" << std::endl;
    std::cout << std::setw(col_width) <<  "Jordan" << std::setw(col_width)  << "Parker" << std::setw(col_width/2) << "45" << std::endl;
    std::cout << std::setw(col_width) <<  "Joe" << std::setw(col_width) << "Ball" << std::setw(col_width/2) << "21" << std::endl;
    std::cout << std::setw(col_width) << "Josh" << std::setw(col_width) << "Carr" << std::setw(col_width/2) <<"27" << std::endl;
    std::cout << std::setw(col_width) << "Izaiah" << std::setw(col_width) << "Robinson" << std::setw(col_width/2) << "29" << std::endl;
    
    
    
    //===================================================================
    std::cout << std::endl;

    //Justify : Values can be justified in their fields. There are three manipulators
    //          for adjusting the justification: left, right, and internal. 
    
    //right justified
    std::cout << std::endl;
    std::cout << "Right justified table(default) :  " << std::endl;
    
    col_width = 20;
    
    std::cout << std::right;
    std::cout << std::setw(col_width) <<  "Lastname"  << std::setw(col_width) << "Firstname" << std::setw(col_width/2) << "Age" << std::endl;
    std::cout << std::setw(col_width) << "Daniel"  << std::setw(col_width) << "Gray" << std::setw(col_width/2) << "25" << std::endl;
    std::cout << std::setw(col_width) << "Stanley" << std::setw(col_width)  << "Woods" << std::setw(col_width/2) <<  "33" << std::endl;
    std::cout << std::setw(col_width) <<  "Jordan" << std::setw(col_width)  << "Parker" << std::setw(col_width/2) << "45" << std::endl;
    std::cout << std::setw(col_width) <<  "Joe" << std::setw(col_width) << "Ball" << std::setw(col_width/2) << "21" << std::endl;
    std::cout << std::setw(col_width) << "Josh" << std::setw(col_width) << "Carr" << std::setw(col_width/2) <<"27" << std::endl;
    std::cout << std::setw(col_width) << "Izaiah" << std::setw(col_width) << "Robinson" << std::setw(col_width/2) << "29" << std::endl;
    


    //Left justified
    std::cout << std::endl;
    std::cout << "Left justified table :  " << std::endl;
    
    col_width = 20;
    
    std::cout << std::left;
    std::cout << std::setw(col_width) <<  "Lastname"  << std::setw(col_width) << "Firstname" << std::setw(col_width/2) << "Age" << std::endl;
    std::cout << std::setw(col_width) << "Daniel"  << std::setw(col_width) << "Gray" << std::setw(col_width/2) << "25" << std::endl;
    std::cout << std::setw(col_width) << "Stanley" << std::setw(col_width)  << "Woods" << std::setw(col_width/2) <<  "33" << std::endl;
    std::cout << std::setw(col_width) <<  "Jordan" << std::setw(col_width)  << "Parker" << std::setw(col_width/2) << "45" << std::endl;
    std::cout << std::setw(col_width) <<  "Joe" << std::setw(col_width) << "Ball" << std::setw(col_width/2) << "21" << std::endl;
    std::cout << std::setw(col_width) << "Josh" << std::setw(col_width) << "Carr" << std::setw(col_width/2) <<"27" << std::endl;
    std::cout << std::setw(col_width) << "Izaiah" << std::setw(col_width) << "Robinson" << std::setw(col_width/2) << "29" << std::endl;
    

    //Internal justified : sign is left justified , data is right justified
    std::cout << std::endl;
    std::cout << "Internal justified : " << std::endl;
    std::cout << std::right;
    std::cout << std::setw(10) << -123.45 << std::endl;
    std::cout << std::internal;
    std::cout << std::setw(10) << -123.45 << std::endl;
    
    //===================================================================
    std::cout << std::endl;

    /*
     * ЗАПОЛНИТЕЛИ - std::setfill()
     * 
     * std::setfill() устанавливает символ-заполнитель для пустых мест в полях
     * По умолчанию используется пробел
     * Действует до следующего изменения заполнителя
     */
    
    std::cout << std::endl;
    std::cout << "Table with fill characters :  " << std::endl;
    
    
    col_width = 20;
    
    std::cout << std::left;
    std::cout << std::setfill('_'); // Устанавливаем символ подчеркивания как заполнитель
    std::cout << std::setw(col_width) <<  "Lastname"  << std::setw(col_width) << "Firstname" << std::setw(col_width/2) << "Age" << std::endl;
    std::cout << std::setw(col_width) << "Daniel"  << std::setw(col_width) << "Gray" << std::setw(col_width/2) << "25" << std::endl;
    std::cout << std::setw(col_width) << "Stanley" << std::setw(col_width)  << "Woods" << std::setw(col_width/2) <<  "33" << std::endl;
    std::cout << std::setw(col_width) <<  "Jordan" << std::setw(col_width)  << "Parker" << std::setw(col_width/2) << "45" << std::endl;
    std::cout << std::setw(col_width) <<  "Joe" << std::setw(col_width) << "Ball" << std::setw(col_width/2) << "21" << std::endl;
    std::cout << std::setw(col_width) << "Josh" << std::setw(col_width) << "Carr" << std::setw(col_width/2) <<"27" << std::endl;
    std::cout << std::setw(col_width) << "Izaiah" << std::setw(col_width) << "Robinson" << std::setw(col_width/2) << "29" << std::endl;
    
    //===================================================================
    std::cout << std::endl;

    /*
     * ФОРМАТ ВЫВОДА ЛОГИЧЕСКИХ ЗНАЧЕНИЙ
     * 
     * std::boolalpha - выводит true/false вместо 1/0
     * std::noboolalpha - выводит 1/0 вместо true/false (по умолчанию)
     */
    
    bool condition {true};
    bool other_condition {false};
    
    // Вывод в числовом формате (по умолчанию)
    std::cout << "condition : " << condition << std::endl;  // 1
    std::cout << "other_condition : " << other_condition << std::endl;  // 0
    
    std::cout << std::endl;
    std::cout << std::boolalpha;  // Включаем текстовый формат
    std::cout << "condition : " << condition << std::endl;  // true
    std::cout << "other_condition : " << other_condition << std::endl;  // false
    
    std::cout << std::endl;
    std::cout << std::noboolalpha;  // Возвращаемся к числовому формату
    std::cout << "condition : " << condition << std::endl;  // 1
    std::cout << "other_condition : " << other_condition << std::endl;  // 0
    
    //===================================================================
    std::cout << std::endl;

    /*
     * ОТОБРАЖЕНИЕ ЗНАКА ПЛЮС ДЛЯ ПОЛОЖИТЕЛЬНЫХ ЧИСЕЛ
     * 
     * std::showpos - показывает знак + для положительных чисел
     * std::noshowpos - скрывает знак + для положительных чисел (по умолчанию)
     */
    
    int pos_num {34};
    int neg_num {-45};
    
    // Обычный вывод (без знака +)
    std::cout << "pos_num : " << pos_num << std::endl;  // 34
    std::cout << "neg_num : " << neg_num << std::endl;  // -45
    
    std::cout << std::endl;
    std::cout << std::showpos;  // Включаем отображение знака +
    std::cout << "pos_num : " << pos_num << std::endl;  // +34
    std::cout << "neg_num : " << neg_num << std::endl;  // -45

    std::cout << std::endl;
    std::cout << std::noshowpos;  // Отключаем отображение знака +
    std::cout << "pos_num : " << pos_num << std::endl;  // 34
    std::cout << "neg_num : " << neg_num << std::endl;  // -45   


    //===================================================================
    std::cout << std::endl;


    /*
     * СИСТЕМЫ СЧИСЛЕНИЯ
     * 
     * std::dec - десятичная система (по умолчанию)
     * std::hex - шестнадцатеричная система
     * std::oct - восьмеричная система
     * 
     * ВАЖНО: Для вещественных чисел системы счисления работают только для целой части!
     */
    
    int pos_int {717171};
    int neg_int {-47347};
    double double_var {498.32};
    
    std::cout << std::endl;
    std::cout << "default base format : " << std::endl;
    std::cout << "pos_int : " << pos_int << std::endl;
    std::cout << "neg_int : " << neg_int << std::endl;
    std::cout << "double_var : " << double_var << std::endl;
    
    std::cout << std::endl;
    std::cout << "pos_int in different bases : " << std::endl;
    std::cout << "pos_int (dec) : " << std::dec << pos_int << std::endl;  // 717171
    std::cout << "pos_int (hex) : " << std::hex << pos_int << std::endl;  // af173
    std::cout << "pos_int (oct) : " << std::oct << pos_int << std::endl;  // 2564563
    
    std::cout << std::endl;
    std::cout << "neg_int in different bases : " << std::endl;
    std::cout << "neg_int (dec) : " << std::dec << neg_int << std::endl;  // -47347
    std::cout << "neg_int (hex) : " << std::hex << neg_int << std::endl;  // ffffffffffff4a8d
    std::cout << "neg_int (oct) : " << std::oct << neg_int << std::endl;  // 177777777777777452215
    
    std::cout << std::endl;
    std::cout << "double_var in different bases : " << std::endl;
    std::cout << "double_var (dec) : " << std::dec << double_var << std::endl;  // 498.32
    std::cout << "double_var (hex) : " << std::hex << double_var << std::endl;  // 1f2.51eb851eb852
    std::cout << "double_var (oct) : " << std::oct << double_var << std::endl;  // 762.2436560512346
    
    
    //===================================================================
    std::cout << std::endl;


    /*
     * РЕГИСТР БУКВ В ШЕСТНАДЦАТЕРИЧНОЙ СИСТЕМЕ
     * 
     * std::uppercase - использует заглавные буквы (A-F) в hex
     * std::nouppercase - использует строчные буквы (a-f) в hex (по умолчанию)
     * 
     * Влияет только на шестнадцатеричные числа и научную нотацию
     */
    
    pos_int = 717171;
    
    std::cout << "pos_int (nouppercase : default) : " << std::endl;
    std::cout << "pos_int (dec) : " << std::dec << pos_int << std::endl;  // 717171
    std::cout << "pos_int (hex) : " << std::hex << pos_int << std::endl;  // af173 (строчные)
    std::cout << "pos_int (oct) : " << std::oct << pos_int << std::endl;  // 2564563
    
    std::cout << std::endl;
    std::cout << "pos_int (uppercase) : " << std::endl;
    std::cout << std::uppercase;  // Включаем заглавные буквы
    std::cout << "pos_int (dec) : " << std::dec << pos_int << std::endl;  // 717171
    std::cout << "pos_int (hex) : " << std::hex << pos_int << std::endl;  // AF173 (заглавные)
    std::cout << "pos_int (oct) : " << std::oct << pos_int << std::endl;  // 2564563
    
    
    //===================================================================
    std::cout << std::endl;


    /*
     * ФОРМАТЫ ВЕЩЕСТВЕННЫХ ЧИСЕЛ
     * 
     * std::fixed - фиксированная точка (всегда показывает десятичную точку)
     * std::scientific - научная нотация (например, 1.23e+02)
     * По умолчанию - автоматический выбор формата
     */
    
    double a{ 3.1415926535897932384626433832795 };
    double b{ 2006.0 };
    double c{ 1.34e-10 };
    
    std::cout << std::endl;
    std::cout << "double values (default : use scientific where necessary) : " << std::endl;
    std::cout << "a : " << a << std::endl;  // 3.14159
    std::cout << "b : " << b << std::endl;  // 2006
    std::cout << "c : " << c << std::endl;  // 1.34e-10
    
    std::cout << std::endl;
    std::cout << "double values (fixed) : " << std::endl;
    std::cout << std::fixed;  // Включаем фиксированную точку
    std::cout << "a : " << a << std::endl;  // 3.141593
    std::cout << "b : " << b << std::endl;  // 2006.000000
    std::cout << "c : " << c << std::endl;  // 0.000000
    
    std::cout << std::endl;
    std::cout << "double values (scientific) : " << std::endl;
    std::cout << std::scientific;  // Включаем научную нотацию
    std::cout << "a : " << a << std::endl;  // 3.141593e+00
    std::cout << "b : " << b << std::endl;  // 2.006000e+03
    std::cout << "c : " << c << std::endl;  // 1.340000e-10

    std::cout << std::endl;
    std::cout << "double values (back to defaults) : " << std::endl;
    std::cout.unsetf(std::ios::scientific | std::ios::fixed); // Возвращаемся к автоматическому формату
    std::cout << "a : " << a << std::endl;  // 3.14159
    std::cout << "b : " << b << std::endl;  // 2006
    std::cout << "c : " << c << std::endl;  // 1.34e-10
    
    
    //===================================================================
    std::cout << std::endl;

    /*
     * ТОЧНОСТЬ ВЫВОДА ВЕЩЕСТВЕННЫХ ЧИСЕЛ - std::setprecision()
     * 
     * std::setprecision(n) - устанавливает количество значащих цифр
     * По умолчанию точность = 6 значащих цифр
     * ВАЖНО: Если точность больше поддерживаемой типом, выводятся "мусорные" цифры
     */
    
    a = 3.1415926535897932384626433832795;
    
    std::cout << std::endl;
    std::cout << "a (default precision(6)) : " << a <<  std::endl;  // 3.14159
    std::cout << std::setprecision(10);  // Устанавливаем точность 10 значащих цифр
    std::cout << "a (precision(10)) : " << a << std::endl;  // 3.141592654
    std::cout << std::setprecision(20);  // Устанавливаем точность 20 значащих цифр
    std::cout << "a (precision(20)) : " << a << std::endl;  // 3.141592653589793116
    
    // Если точность больше поддерживаемой типом, выводятся "мусорные" цифры
    
    //===================================================================
    std::cout << std::endl;

    /*
     * ОТОБРАЖЕНИЕ ДЕСЯТИЧНОЙ ТОЧКИ - std::showpoint
     * 
     * std::showpoint - принудительно показывает десятичную точку и нули
     * std::noshowpoint - скрывает десятичную точку для целых чисел (по умолчанию)
     */
    
    double d {34.1};
    double e {101.99};
    double f {12.0};
    int    g {45};
    
    std::cout << std::endl;
    std::cout << "noshowpoint (default) : " << std::endl;
    std::cout << "d : " << d << std::endl;  // 34.1
    std::cout << "e : " << e << std::endl;  // 101.99
    std::cout << "f : " << f << std::endl;  // 12 (без .0)
    std::cout << "g : " << g << std::endl;  // 45
    
    std::cout << std::endl;
    std::cout << "showpoint: " << std::endl;
    std::cout << std::showpoint;  // Включаем принудительное отображение точки
    std::cout << "d : " << d << std::endl;  // 34.1000
    std::cout << "e : " << e << std::endl;  // 101.9900
    std::cout << "f : " << f << std::endl;  // 12.0000 (с .0)
    std::cout << "g : " << g << std::endl;  // 45.0000

    return 0;
}

/*
 * РЕЗЮМЕ: МАНИПУЛЯТОРЫ ФОРМАТИРОВАНИЯ В C++
 * 
 * 1. УПРАВЛЕНИЕ ПЕРЕНОСАМИ СТРОК:
 *    - std::endl - перенос строки + сброс буфера
 *    - '\n' - только перенос строки
 *    - std::flush - принудительный сброс буфера
 * 
 * 2. УПРАВЛЕНИЕ ШИРИНОЙ ПОЛЕЙ:
 *    - std::setw(n) - минимальная ширина поля (действует только на следующее значение)
 * 
 * 3. ВЫРАВНИВАНИЕ:
 *    - std::left - по левому краю
 *    - std::right - по правому краю (по умолчанию для чисел)
 *    - std::internal - знак слева, число справа
 * 
 * 4. ЗАПОЛНИТЕЛИ:
 *    - std::setfill(c) - символ-заполнитель для пустых мест
 * 
 * 5. ЛОГИЧЕСКИЕ ЗНАЧЕНИЯ:
 *    - std::boolalpha - true/false
 *    - std::noboolalpha - 1/0 (по умолчанию)
 * 
 * 6. ЗНАКИ ЧИСЕЛ:
 *    - std::showpos - показывать + для положительных
 *    - std::noshowpos - скрывать + (по умолчанию)
 * 
 * 7. СИСТЕМЫ СЧИСЛЕНИЯ:
 *    - std::dec - десятичная (по умолчанию)
 *    - std::hex - шестнадцатеричная
 *    - std::oct - восьмеричная
 *    - std::uppercase - заглавные буквы в hex
 * 
 * 8. ФОРМАТЫ ВЕЩЕСТВЕННЫХ ЧИСЕЛ:
 *    - std::fixed - фиксированная точка
 *    - std::scientific - научная нотация
 *    - std::setprecision(n) - количество значащих цифр
 *    - std::showpoint - принудительно показывать десятичную точку
 * 
 * ПРАКТИЧЕСКИЕ СОВЕТЫ:
 * - Манипуляторы действуют до следующего изменения
 * - setw() действует только на следующее значение
 * - Для вещественных чисел системы счисления работают только с целой частью
 * - Не устанавливайте точность больше поддерживаемой типом
 * - Используйте unsetf() для сброса флагов форматирования
 */