#include <iostream>
#include <string>

// Функция для обработки lvalue
std::string& process_lvalue(std::string& value) {
    std::cout << "Обработка lvalue: \"" << value << "\"" << std::endl;
    std::cout << "Адрес lvalue: " << &value << std::endl;
    return value;
}

// Функция для обработки rvalue
std::string&& process_rvalue(std::string&& value) {
    std::cout << "Обработка rvalue: \"" << value << "\"" << std::endl;
    std::cout << "Адрес rvalue: " << &value << std::endl;
    return std::move(value);
}

// Функция для получения строки (возвращает rvalue)
std::string get_string() {
    return "Function Result";
}

int main() {
    
    // ==========================================
    // 1. ОСНОВЫ LVALUE И RVALUE
    // ==========================================
    
    std::cout << "=== Основы lvalue и rvalue в C++ ===" << std::endl;
    
    std::cout << "LVALUE (левое значение):" << std::endl;
    std::cout << "- Имеет имя и адрес в памяти" << std::endl;
    std::cout << "- Может находиться слева от оператора присваивания" << std::endl;
    std::cout << "- Существует продолжительное время" << std::endl;
    std::cout << "- Примеры: переменные, элементы массива, разыменованные указатели" << std::endl;
    std::cout << std::endl;
    
    std::cout << "RVALUE (правое значение):" << std::endl;
    std::cout << "- Не имеет имени или адреса в памяти" << std::endl;
    std::cout << "- Может находиться только справа от оператора присваивания" << std::endl;
    std::cout << "- Временное значение" << std::endl;
    std::cout << "- Примеры: литералы, результаты функций, временные объекты" << std::endl;
    std::cout << std::endl;
    
    // ==========================================
    // 2. ДЕМОНСТРАЦИЯ LVALUE
    // ==========================================
    
    std::cout << "=== Демонстрация lvalue ===" << std::endl;
    
    std::string original_string = "Hello World!";
    std::string another_string = "Another String";
    
    std::cout << "Созданы lvalue переменные:" << std::endl;
    std::cout << "original_string = \"" << original_string << "\"" << std::endl;
    std::cout << "another_string = \"" << another_string << "\"" << std::endl;
    std::cout << "Адрес original_string: " << &original_string << std::endl;
    std::cout << "Адрес another_string: " << &another_string << std::endl;
    std::cout << std::endl;
    
    // Присваивание lvalue
    std::cout << "Присваивание lvalue (original_string = another_string):" << std::endl;
    original_string = another_string;  // lvalue = lvalue
    std::cout << "После присваивания:" << std::endl;
    std::cout << "original_string = \"" << original_string << "\"" << std::endl;
    std::cout << "another_string = \"" << another_string << "\"" << std::endl;
    std::cout << std::endl;
    
    // ==========================================
    // 3. ДЕМОНСТРАЦИЯ RVALUE
    // ==========================================
    
    std::cout << "=== Демонстрация rvalue ===" << std::endl;
    
    std::cout << "Присваивание rvalue (original_string = \"New Value\"):" << std::endl;
    original_string = "New Value";  // lvalue = rvalue
    std::cout << "original_string = \"" << original_string << "\"" << std::endl;
    std::cout << std::endl;
    
    std::cout << "Присваивание результата функции (rvalue):" << std::endl;
    original_string = std::string("Temporary String");  // lvalue = rvalue
    std::cout << "original_string = \"" << original_string << "\"" << std::endl;
    std::cout << std::endl;
    
    // ==========================================
    // 4. ССЫЛКИ НА LVALUE И RVALUE
    // ==========================================
    
    std::cout << "=== Ссылки на lvalue и rvalue ===" << std::endl;
    
    // Ссылка на lvalue
    std::string& reference_to_lvalue = original_string;
    std::cout << "Ссылка на lvalue:" << std::endl;
    std::cout << "reference_to_lvalue = \"" << reference_to_lvalue << "\"" << std::endl;
    std::cout << "Адрес reference_to_lvalue: " << &reference_to_lvalue << std::endl;
    std::cout << "Адрес original_string: " << &original_string << std::endl;
    std::cout << "Адреса одинаковые: " << (&reference_to_lvalue == &original_string ? "Да" : "Нет") << std::endl;
    std::cout << std::endl;
    
    // Const-ссылка на rvalue
    const std::string& const_reference_to_rvalue = "Temporary Rvalue";
    std::cout << "Const-ссылка на rvalue:" << std::endl;
    std::cout << "const_reference_to_rvalue = \"" << const_reference_to_rvalue << "\"" << std::endl;
    std::cout << "Адрес const_reference_to_rvalue: " << &const_reference_to_rvalue << std::endl;
    std::cout << std::endl;
    
    // ==========================================
    // 5. ПЕРЕГРУЗКА ФУНКЦИЙ ДЛЯ LVALUE И RVALUE
    // ==========================================
    
    std::cout << "=== Перегрузка функций для lvalue и rvalue ===" << std::endl;
    
    // Вызов с lvalue
    std::cout << "Вызов с lvalue:" << std::endl;
    std::string& result_lvalue = process_lvalue(original_string);
    std::cout << "Результат: \"" << result_lvalue << "\"" << std::endl;
    std::cout << std::endl;
    
    // Вызов с rvalue
    std::cout << "Вызов с rvalue:" << std::endl;
    std::string&& result_rvalue = process_rvalue(std::string("Temporary Value"));
    std::cout << "Результат: \"" << result_rvalue << "\"" << std::endl;
    std::cout << std::endl;
    
    // ==========================================
    // 6. ПРАКТИЧЕСКИЕ ПРИМЕРЫ
    // ==========================================
    
    std::cout << "=== Практические примеры ===" << std::endl;
    
    // Пример 1: Массивы
    std::cout << "Пример 1: Работа с массивами" << std::endl;
    int numbers[] = {1, 2, 3, 4, 5};
    numbers[0] = 10;  // numbers[0] - lvalue
    std::cout << "numbers[0] = " << numbers[0] << std::endl;
    std::cout << std::endl;
    
    // Пример 2: Указатели
    std::cout << "Пример 2: Работа с указателями" << std::endl;
    int* pointer_to_number = &numbers[0];
    *pointer_to_number = 20;  // *pointer_to_number - lvalue
    std::cout << "*pointer_to_number = " << *pointer_to_number << std::endl;
    std::cout << std::endl;
    
    // Пример 3: Результаты функций
    std::cout << "Пример 3: Результаты функций" << std::endl;
    
    std::string function_result = get_string();  // get_string() - rvalue
    std::cout << "function_result = \"" << function_result << "\"" << std::endl;
    std::cout << std::endl;
    
    // ==========================================
    // 7. СВОДНАЯ ТАБЛИЦА LVALUE И RVALUE
    // ==========================================
    
    std::cout << "=== Сводная таблица lvalue и rvalue ===" << std::endl;
    std::cout << std::endl;
    
    std::cout << "| Свойство        | LVALUE                    | RVALUE                    |" << std::endl;
    std::cout << "|-----------------|---------------------------|---------------------------|" << std::endl;
    std::cout << "| Имя             | Есть                      | Нет                       |" << std::endl;
    std::cout << "| Адрес           | Есть                      | Нет                       |" << std::endl;
    std::cout << "| Время жизни      | Продолжительное          | Временное                 |" << std::endl;
    std::cout << "| Присваивание    | Слева от =                | Справа от =               |" << std::endl;
    std::cout << "| Ссылки          | std::string&              | const std::string&        |" << std::endl;
    std::cout << "| Примеры         | переменные, массивы      | литералы, функции         |" << std::endl;
    std::cout << std::endl;
    
    // ==========================================
    // 8. ПРАВИЛА И РЕКОМЕНДАЦИИ
    // ==========================================
    
    std::cout << "=== Правила и рекомендации ===" << std::endl;
    std::cout << "1. LVALUE может быть присвоено LVALUE или RVALUE" << std::endl;
    std::cout << "2. RVALUE может быть присвоено только LVALUE" << std::endl;
    std::cout << "3. Обычные ссылки могут ссылаться только на LVALUE" << std::endl;
    std::cout << "4. Const-ссылки могут ссылаться на LVALUE и RVALUE" << std::endl;
    std::cout << "5. RVALUE-ссылки могут ссылаться только на RVALUE" << std::endl;
    std::cout << "6. Понимание lvalue/rvalue важно для move-семантики" << std::endl;
    std::cout << "7. Перегрузка функций может различать lvalue и rvalue" << std::endl;
    std::cout << std::endl;
    
    std::cout << "Программа завершается корректно" << std::endl;
    return 0;
}