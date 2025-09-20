#include <iostream>

int main() {
    
    // ==========================================
    // 1. ОБЪЯВЛЕНИЕ И ИНИЦИАЛИЗАЦИЯ УКАЗАТЕЛЕЙ
    // ==========================================
    
    // Автоматическая инициализация указателей nullptr
    int* pointer_to_integer{};           // Автоматически инициализируется nullptr
    double* pointer_to_double{};         // Автоматически инициализируется nullptr
    
    // Явная инициализация указателей nullptr
    int* explicit_null_pointer{nullptr};
    double* explicit_null_double_pointer{nullptr};
    
    // ==========================================
    // 2. РАЗМЕРЫ УКАЗАТЕЛЕЙ В ПАМЯТИ
    // ==========================================
    
    std::cout << "=== Размеры типов данных и указателей ===" << std::endl;
    std::cout << "sizeof(int): " << sizeof(int) << " байт" << std::endl;           // 4 байта
    std::cout << "sizeof(double): " << sizeof(double) << " байт" << std::endl;     // 8 байт
    std::cout << "sizeof(int*): " << sizeof(int*) << " байт" << std::endl;         // 8 байт (на 64-битной системе)
    std::cout << "sizeof(double*): " << sizeof(double*) << " байт" << std::endl;   // 8 байт (на 64-битной системе)
    std::cout << "sizeof(pointer_to_integer): " << sizeof(pointer_to_integer) << " байт" << std::endl;
    std::cout << "sizeof(explicit_null_double_pointer): " << sizeof(explicit_null_double_pointer) << " байт" << std::endl;
    std::cout << std::endl;
    
    // ==========================================
    // 3. РАЗЛИЧНЫЕ СПОСОБЫ РАЗМЕЩЕНИЯ ЗВЕЗДОЧКИ
    // ==========================================
    
    // Все эти объявления эквивалентны - звездочка может быть рядом с типом или именем
    int* pointer_style1{nullptr};        // Рекомендуемый стиль
    int *pointer_style2{nullptr};        // Альтернативный стиль
    int  *pointer_style3{nullptr};       // Еще один вариант
    
    // ==========================================
    // 4. ОСТОРОЖНОСТЬ ПРИ ОБЪЯВЛЕНИИ НЕСКОЛЬКИХ ПЕРЕМЕННЫХ
    // ==========================================
    
    // Потенциально запутанное объявление
    int *pointer_and_variable{}, regular_variable{};
    int* another_pointer{}, another_regular_variable{};  // ВАЖНО: another_regular_variable НЕ является указателем!
    
    std::cout << "=== Размеры переменных в смешанных объявлениях ===" << std::endl;
    std::cout << "sizeof(pointer_and_variable): " << sizeof(pointer_and_variable) << " байт" << std::endl;
    std::cout << "sizeof(regular_variable): " << sizeof(regular_variable) << " байт" << std::endl;
    std::cout << "sizeof(another_pointer): " << sizeof(another_pointer) << " байт" << std::endl;
    std::cout << "sizeof(another_regular_variable): " << sizeof(another_regular_variable) << " байт" << std::endl;
    std::cout << std::endl;
    
    // Рекомендуемый подход - раздельные объявления
    int* clear_pointer{};
    int clear_regular_variable{};        // Никакой путаницы!
    
    // ==========================================
    // 5. ИНИЦИАЛИЗАЦИЯ УКАЗАТЕЛЕЙ АДРЕСАМИ ПЕРЕМЕННЫХ
    // ==========================================
    
    int source_integer{43};
    int* pointer_to_source{&source_integer};  // Оператор взятия адреса (&)
    
    std::cout << "=== Работа с адресами переменных ===" << std::endl;
    std::cout << "Значение переменной source_integer: " << source_integer << std::endl;
    std::cout << "Адрес переменной source_integer: " << pointer_to_source << std::endl;
    
    // Изменение адреса, хранящегося в указателе
    int another_integer{65};
    pointer_to_source = &another_integer;    // Присваиваем указателю новый адрес
    std::cout << "Новый адрес в указателе: " << pointer_to_source << std::endl;
    std::cout << std::endl;
    
    // ==========================================
    // 6. НЕСОВМЕСТИМОСТЬ ТИПОВ УКАЗАТЕЛЕЙ
    // ==========================================
    
    int* integer_pointer{nullptr};
    double double_value{33.0};
    
    // Следующая строка вызовет ошибку компиляции:
    // integer_pointer = &double_value;  // ОШИБКА: нельзя присвоить адрес double указателю на int
    
    // ==========================================
    // 7. РАЗЫМЕНОВАНИЕ УКАЗАТЕЛЕЙ (DEREFERENCING)
    // ==========================================
    
    int* dereference_pointer{nullptr};
    int data_value{56};
    dereference_pointer = &data_value;
    
    std::cout << "=== Разыменование указателей ===" << std::endl;
    std::cout << "Значение через разыменование: " << *dereference_pointer << std::endl;
    std::cout << "Прямое значение переменной: " << data_value << std::endl;
    
    return 0;
}