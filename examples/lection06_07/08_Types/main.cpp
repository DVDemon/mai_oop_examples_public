#include <iostream>

// ============================================================================
// ТИП КАК ПАРАМЕТР: ПРОВЕРКА ТИПА
// ============================================================================

// Базовый шаблон для проверки типа
// По умолчанию возвращает false для всех типов
template <class T>
struct is_int {
    static const bool value = false;
};

// Специализация для типа int
// Возвращает true только для типа int
template <>
struct is_int<int> {
    static const bool value = true;
};

// ============================================================================
// ТИП КАК РЕЗУЛЬТАТ: УДАЛЕНИЕ УКАЗАТЕЛЯ
// ============================================================================

// Базовый шаблон для удаления указателя
// Если тип не является указателем, возвращает сам тип
template<class T>
struct remove_pointer {
    using type = T;
};

// Специализация для указателей
// Удаляет один уровень указателя
template<class T>
struct remove_pointer<T*> {
    using type = T;
};

// ============================================================================
// ОСНОВНАЯ ФУНКЦИЯ - ДЕМОНСТРАЦИЯ РАБОТЫ С ТИПАМИ
// ============================================================================

int main() {
    std::cout << "=== ДЕМОНСТРАЦИЯ РАБОТЫ С ТИПАМИ В ШАБЛОНАХ ===" << std::endl << std::endl;
    
    // ========================================================================
    // ДЕМОНСТРАЦИЯ 1: ПРОВЕРКА ТИПА (ТИП КАК ПАРАМЕТР)
    // ========================================================================
    std::cout << "1. Проверка типа (тип как параметр):" << std::endl;
    std::cout << "   is_int<bool>::value = " << is_int<bool>::value << std::endl;
    std::cout << "   is_int<int>::value  = " << is_int<int>::value << std::endl;
    std::cout << "   is_int<double>::value = " << is_int<double>::value << std::endl;
    std::cout << "   is_int<char>::value = " << is_int<char>::value << std::endl << std::endl;
    
    // ========================================================================
    // ДЕМОНСТРАЦИЯ 2: УДАЛЕНИЕ УКАЗАТЕЛЯ (ТИП КАК РЕЗУЛЬТАТ)
    // ========================================================================
    std::cout << "2. Удаление указателя (тип как результат):" << std::endl;
    
    // Создаем указатель на int
    int* int_pointer = nullptr;
    
    // Используем remove_pointer для получения типа без указателя
    // decltype(int_pointer) = int*, remove_pointer<int*>::type = int
    remove_pointer<decltype(int_pointer)>::type int_value{42};
    
    std::cout << "   Исходный тип: int*" << std::endl;
    std::cout << "   Тип после remove_pointer: int" << std::endl;
    std::cout << "   Значение переменной: " << int_value << std::endl << std::endl;
    
    // ========================================================================
    // ДЕМОНСТРАЦИЯ 3: РАБОТА С РАЗНЫМИ ТИПАМИ УКАЗАТЕЛЕЙ
    // ========================================================================
    std::cout << "3. Работа с разными типами указателей:" << std::endl;
    
    // Указатель на double
    double* double_pointer = nullptr;
    remove_pointer<decltype(double_pointer)>::type double_value{3.14};
    std::cout << "   double* -> " << typeid(remove_pointer<decltype(double_pointer)>::type).name() 
              << " = " << double_value << std::endl;
    
    // Указатель на char
    char* char_pointer = nullptr;
    remove_pointer<decltype(char_pointer)>::type char_value{'A'};
    std::cout << "   char* -> " << typeid(remove_pointer<decltype(char_pointer)>::type).name() 
              << " = " << char_value << std::endl;
    
    // Обычный тип (не указатель)
    int regular_int = 100;
    remove_pointer<decltype(regular_int)>::type regular_value{200};
    std::cout << "   int -> " << typeid(remove_pointer<decltype(regular_int)>::type).name() 
              << " = " << regular_value << std::endl << std::endl;
    
    // ========================================================================
    // ДЕМОНСТРАЦИЯ 4: ПРАКТИЧЕСКОЕ ПРИМЕНЕНИЕ
    // ========================================================================
    std::cout << "4. Практическое применение:" << std::endl;
    std::cout << "   - Проверка типов на этапе компиляции" << std::endl;
    std::cout << "   - Метапрограммирование с типами" << std::endl;
    std::cout << "   - Создание type traits для библиотек" << std::endl;
    std::cout << "   - Удаление указателей для безопасной работы с типами" << std::endl;
    
    return 0;
}