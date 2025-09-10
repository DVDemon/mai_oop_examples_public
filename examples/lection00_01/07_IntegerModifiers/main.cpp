/*
 * МОДИФИКАТОРЫ ЦЕЛОЧИСЛЕННЫХ ТИПОВ В C++
 * 
 * Этот файл демонстрирует различные модификаторы целочисленных типов:
 * - signed/unsigned - знаковые и беззнаковые типы
 * - short/long/long long - различные размеры типов
 * - size_t - специальный тип для размеров
 * - sizeof() - оператор для определения размера типа
 */

#include <iostream>

int main()
{
    /*
     * ЗНАКОВЫЕ ЦЕЛОЧИСЛЕННЫЕ ТИПЫ (SIGNED)
     * 
     * signed - явно указывает, что тип может содержать отрицательные числа
     * По умолчанию int является знаковым типом
     * Диапазон: от -2^(n-1) до 2^(n-1)-1, где n - количество бит
     */
    signed int value1{10};   // Положительное число
    signed int value2{-300}; // Отрицательное число

    std::cout << "value1 : " << value1 << std::endl;
    std::cout << "value2 : " << value2 << std::endl;
    std::cout << "sizeof(value1) : " << sizeof(value1) << std::endl;  // Размер в байтах
    std::cout << "sizeof(value2) : " << sizeof(value2) << std::endl;

    /*
     * БЕЗЗНАКОВЫЕ ЦЕЛОЧИСЛЕННЫЕ ТИПЫ (UNSIGNED)
     * 
     * unsigned - указывает, что тип может содержать только положительные числа и 0
     * Диапазон: от 0 до 2^n-1, где n - количество бит
     * Используется для значений, которые не могут быть отрицательными
     */
    unsigned int value3{4};  // Только положительные числа
    size_t value23 {10};     // size_t - специальный беззнаковый тип для размеров
    
    // unsigned int value4{-5}; // ОШИБКА КОМПИЛЯЦИИ! Нельзя присвоить отрицательное значение

    /*
     * РАЗЛИЧНЫЕ РАЗМЕРЫ ЦЕЛОЧИСЛЕННЫХ ТИПОВ
     * 
     * short - короткие целые числа (обычно 2 байта)
     * int - стандартные целые числа (обычно 4 байта)
     * long - длинные целые числа (4 или 8 байт, зависит от системы)
     * long long - очень длинные целые числа (обычно 8 байт)
     */
    
    // SHORT ТИПЫ (обычно 2 байта)
    short short_var{-32768};                 // 2 байта, диапазон: -32768 до 32767
    short int short_int{455};                // Эквивалентно short
    signed short signed_short{122};          // Явно знаковый short
    signed short int signed_short_int{-456}; // Полная форма
    unsigned short int unsigned_short_int{456}; // Беззнаковый short (0 до 65535)

    // INT ТИПЫ (обычно 4 байта)
    int int_var{55};           // Стандартный int (4 байта)
    signed signed_var{66};     // Эквивалентно signed int
    signed int signed_int{77}; // Явно знаковый int
    unsigned int unsigned_int{77}; // Беззнаковый int (0 до 4294967295)

    // LONG ТИПЫ (4 или 8 байт, зависит от системы)
    long long_var{88}; // 4 или 8 байт (зависит от архитектуры)
    long int long_int{33}; // Эквивалентно long
    signed long signed_long{44}; // Явно знаковый long
    signed long int signed_long_int{44}; // Полная форма
    unsigned long int unsigned_long_int{44}; // Беззнаковый long

    // LONG LONG ТИПЫ (обычно 8 байт)
    long long long_long{888}; // 8 байт, диапазон: ±9.22×10^18
    long long int long_long_int{999}; // Эквивалентно long long
    signed long long signed_long_long{444}; // Явно знаковый long long
    signed long long int signed_long_long_int{1234}; // Полная форма
    unsigned long long int unsigned_long_long_int{1234}; // Беззнаковый long long

    /*
     * ВЫВОД РАЗМЕРОВ И ЗНАЧЕНИЙ SHORT ТИПОВ
     * 
     * sizeof() - оператор, возвращающий размер типа в байтах
     * Полезен для понимания, сколько памяти занимает каждый тип
     */
    std::cout << "Short variable : " << short_var << " , size : "
              << sizeof(short) << " bytes" << std::endl;

    std::cout << "Short Int : " << short_int << " , size : "
              << sizeof(short int) << " bytes" << std::endl;

    std::cout << "Signed short : " << signed_short
              << " , size : " << sizeof(signed short) << " bytes" << std::endl;

    std::cout << "Signed short int :  " << signed_short_int
              << " , size : " << sizeof(signed short int) << " bytes" << std::endl;

    std::cout << "unsigned short int :  " << unsigned_short_int
              << " , size : " << sizeof(unsigned short int) << " bytes" << std::endl;

    std::cout << "---------------------" << std::endl;

    // ВЫВОД РАЗМЕРОВ И ЗНАЧЕНИЙ INT ТИПОВ
    std::cout << "Int variable :  " << int_var << " , size : "
              << sizeof(int) << " bytes" << std::endl;

    std::cout << "Signed variable " << signed_var << " , size : "
              << sizeof(signed) << " bytes" << std::endl;

    std::cout << "Signed int :  " << signed_int << " , size : "
              << sizeof(signed int) << " bytes" << std::endl;

    std::cout << "unsigned int :  " << unsigned_int << " , size : "
              << sizeof(unsigned int) << " bytes" << std::endl;

    std::cout << "---------------------" << std::endl;

    // ВЫВОД РАЗМЕРОВ И ЗНАЧЕНИЙ LONG ТИПОВ
    std::cout << "Long variable :  " << long_var << " , size : "
              << sizeof(long) << " bytes" << std::endl;

    std::cout << "Long int :  " << long_int << " , size : "
              << sizeof(long int) << " bytes" << std::endl;

    std::cout << "Signed long :  " << signed_long << " , size : "
              << sizeof(signed long) << " bytes" << std::endl;

    std::cout << "Signed long int : " << signed_long_int << " , size : "
              << sizeof(signed long int) << " bytes" << std::endl;

    std::cout << "unsigned long int : " << unsigned_long_int << " , size : "
              << sizeof(unsigned long int) << " bytes" << std::endl;

    std::cout << "---------------------" << std::endl;

    // ВЫВОД РАЗМЕРОВ И ЗНАЧЕНИЙ LONG LONG ТИПОВ
    std::cout << "Long long : " << long_long << " , size : "
              << sizeof(long long) << " bytes" << std::endl;

    std::cout << "Long long int : " << long_long_int << " , size : "
              << sizeof(long long int) << " bytes" << std::endl;

    std::cout << "Signed long long : " << signed_long_long << " , size : "
              << sizeof(signed long long) << " bytes" << std::endl;

    std::cout << "Signed long long int : " << signed_long_long_int << " , size : "
              << sizeof(signed long long int) << " bytes" << std::endl;

    std::cout << "unsigned long long int : " << unsigned_long_long_int << " , size : "
              << sizeof(unsigned long long int) << " bytes" << std::endl;

    std::cout << "---------------------" << std::endl;

    return 0;
}

/*
 * РЕЗЮМЕ: МОДИФИКАТОРЫ ЦЕЛОЧИСЛЕННЫХ ТИПОВ
 * 
 * 1. МОДИФИКАТОРЫ ЗНАКА:
 *    - signed - знаковые типы (могут содержать отрицательные числа)
 *    - unsigned - беззнаковые типы (только положительные числа и 0)
 *    - По умолчанию int является знаковым
 * 
 * 2. МОДИФИКАТОРЫ РАЗМЕРА:
 *    - short - короткие целые (обычно 2 байта)
 *    - int - стандартные целые (обычно 4 байта)
 *    - long - длинные целые (4 или 8 байт, зависит от системы)
 *    - long long - очень длинные целые (обычно 8 байт)
 * 
 * 3. ДИАПАЗОНЫ ЗНАЧЕНИЙ:
 *    - short: -32,768 до 32,767 (signed) или 0 до 65,535 (unsigned)
 *    - int: -2,147,483,648 до 2,147,483,647 (signed) или 0 до 4,294,967,295 (unsigned)
 *    - long: зависит от системы (32-бит: как int, 64-бит: как long long)
 *    - long long: ±9.22×10^18 (signed) или 0 до 1.84×10^19 (unsigned)
 * 
 * 4. ОПЕРАТОР sizeof():
 *    - Возвращает размер типа в байтах
 *    - Полезен для понимания использования памяти
 *    - Размеры могут отличаться на разных системах
 * 
 * 5. ПРАКТИЧЕСКИЕ СОВЕТЫ:
 *    - Используйте int для большинства случаев
 *    - Используйте unsigned для значений, которые не могут быть отрицательными
 *    - Используйте long long для очень больших чисел
 *    - Используйте short для экономии памяти в массивах
 *    - size_t - специальный тип для размеров массивов и индексов
 * 
 * 6. ВАЖНЫЕ ЗАМЕЧАНИЯ:
 *    - Размеры типов зависят от архитектуры системы
 *    - Нельзя присвоить отрицательное значение unsigned типу
 *    - Переполнение может привести к неожиданным результатам
 *    - Всегда проверяйте диапазоны при работе с большими числами
 */