#include <iostream>

int main() {
    
    // ==========================================
    // 1. УКАЗАТЕЛЬ НА КОНСТАНТНУЮ СТРОКУ
    // ==========================================
    
    // Указатель на константную строку - содержимое нельзя изменить
    const char* constant_string_pointer = "Hello World!";
    
    std::cout << "=== Работа с указателем на константную строку ===" << std::endl;
    std::cout << "Строка через указатель: " << constant_string_pointer << std::endl;
    std::cout << "Адрес строки: " << static_cast<const void*>(constant_string_pointer) << std::endl;
    
    // Попытка изменить содержимое через указатель вызовет ошибку компиляции:
    // *constant_string_pointer = 'B';  // ОШИБКА: нельзя изменить константную строку
    
    // Но можно читать отдельные символы
    std::cout << "Четвертый символ (индекс 3): " << constant_string_pointer[3] << std::endl;
    std::cout << "Первый символ через разыменование: " << *constant_string_pointer << std::endl;
    std::cout << std::endl;
    
    // ==========================================
    // 2. МОДИФИЦИРУЕМЫЙ МАССИВ СИМВОЛОВ
    // ==========================================
    
    // Массив символов - содержимое можно изменять
    char modifiable_string[]{"Hello World!"};
    
    std::cout << "=== Работа с модифицируемым массивом символов ===" << std::endl;
    std::cout << "Исходная строка: " << modifiable_string << std::endl;
    
    // Изменяем символ в позиции 7 (8-й символ, считая с 0)
    modifiable_string[7] = 'B';  // 'o' заменяется на 'B'
    
    std::cout << "Строка после изменения: " << modifiable_string << std::endl;
    std::cout << "Адрес массива: " << static_cast<void*>(modifiable_string) << std::endl;
    std::cout << std::endl;
    
    // ==========================================
    // 3. ДОПОЛНИТЕЛЬНЫЕ ПРИМЕРЫ РАБОТЫ С УКАЗАТЕЛЯМИ НА СИМВОЛЫ
    // ==========================================
    
    // Указатель на модифицируемый массив
    char* pointer_to_modifiable = modifiable_string;
    
    std::cout << "=== Дополнительные примеры ===" << std::endl;
    std::cout << "Строка через указатель на массив: " << pointer_to_modifiable << std::endl;
    
    // Изменение через указатель
    pointer_to_modifiable[0] = 'h';  // Заменяем 'H' на 'h'
    std::cout << "После изменения через указатель: " << modifiable_string << std::endl;
    
    // Перемещение указателя
    pointer_to_modifiable += 6;  // Перемещаемся к слову "World"
    std::cout << "Строка с позиции 6: " << pointer_to_modifiable << std::endl;
    
    return 0;
}