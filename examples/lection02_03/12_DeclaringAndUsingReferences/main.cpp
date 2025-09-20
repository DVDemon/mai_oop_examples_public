#include <iostream>

int main() {
    
    // ==========================================
    // 1. СОЗДАНИЕ ОРИГИНАЛЬНЫХ ПЕРЕМЕННЫХ
    // ==========================================
    
    std::cout << "=== Создание оригинальных переменных ===" << std::endl;
    
    int original_integer{33};
    double original_double{55};
    
    std::cout << "Созданы оригинальные переменные:" << std::endl;
    std::cout << "original_integer = " << original_integer << std::endl;
    std::cout << "original_double = " << original_double << std::endl;
    std::cout << std::endl;
    
    // ==========================================
    // 2. СОЗДАНИЕ ССЫЛОК НА ПЕРЕМЕННЫЕ
    // ==========================================
    
    std::cout << "=== Создание ссылок на переменные ===" << std::endl;
    
    // Ссылки - это альтернативные имена для существующих переменных
    int& reference_to_integer{original_integer};
    double& reference_to_double{original_double};
    
    std::cout << "Созданы ссылки на переменные:" << std::endl;
    std::cout << "reference_to_integer ссылается на original_integer" << std::endl;
    std::cout << "reference_to_double ссылается на original_double" << std::endl;
    std::cout << std::endl;
    
    // ==========================================
    // 3. ДЕМОНСТРАЦИЯ ТОЖДЕСТВЕННОСТИ АДРЕСОВ
    // ==========================================
    
    std::cout << "=== Демонстрация тождественности адресов ===" << std::endl;
    
    std::cout << "Оригинальные переменные:" << std::endl;
    std::cout << "original_integer = " << original_integer << std::endl;
    std::cout << "Адрес original_integer: " << &original_integer << std::endl;
    std::cout << "original_double = " << original_double << std::endl;
    std::cout << "Адрес original_double: " << &original_double << std::endl;
    
    std::cout << std::endl << "Ссылки:" << std::endl;
    std::cout << "reference_to_integer = " << reference_to_integer << std::endl;
    std::cout << "Адрес reference_to_integer: " << &reference_to_integer << std::endl;
    std::cout << "reference_to_double = " << reference_to_double << std::endl;
    std::cout << "Адрес reference_to_double: " << &reference_to_double << std::endl;
    
    std::cout << std::endl << "ВАЖНО: Адреса оригинальных переменных и ссылок ОДИНАКОВЫЕ!" << std::endl;
    std::cout << "Ссылка - это просто другое имя для той же переменной!" << std::endl;
    std::cout << std::endl;
    
    // ==========================================
    // 4. ИЗМЕНЕНИЕ ЗНАЧЕНИЙ ЧЕРЕЗ ОРИГИНАЛЬНЫЕ ПЕРЕМЕННЫЕ
    // ==========================================
    
    std::cout << "=== Изменение значений через оригинальные переменные ===" << std::endl;
    
    // Изменяем значения через оригинальные переменные
    original_integer = 111;
    original_double = 67.2;
    
    std::cout << "Изменены значения через оригинальные переменные:" << std::endl;
    std::cout << "original_integer = " << original_integer << std::endl;
    std::cout << "original_double = " << original_double << std::endl;
    
    std::cout << std::endl << "Ссылки автоматически отражают изменения:" << std::endl;
    std::cout << "reference_to_integer = " << reference_to_integer << std::endl;
    std::cout << "reference_to_double = " << reference_to_double << std::endl;
    
    std::cout << std::endl << "Адреса остаются неизменными:" << std::endl;
    std::cout << "Адрес original_integer: " << &original_integer << std::endl;
    std::cout << "Адрес reference_to_integer: " << &reference_to_integer << std::endl;
    std::cout << "Адрес original_double: " << &original_double << std::endl;
    std::cout << "Адрес reference_to_double: " << &reference_to_double << std::endl;
    std::cout << std::endl;
    
    // ==========================================
    // 5. ИЗМЕНЕНИЕ ЗНАЧЕНИЙ ЧЕРЕЗ ССЫЛКИ
    // ==========================================
    
    std::cout << "=== Изменение значений через ссылки ===" << std::endl;
    
    // Изменяем значения через ссылки
    reference_to_integer = 1012;
    reference_to_double = 1000.45;
    
    std::cout << "Изменены значения через ссылки:" << std::endl;
    std::cout << "reference_to_integer = " << reference_to_integer << std::endl;
    std::cout << "reference_to_double = " << reference_to_double << std::endl;
    
    std::cout << std::endl << "Оригинальные переменные автоматически отражают изменения:" << std::endl;
    std::cout << "original_integer = " << original_integer << std::endl;
    std::cout << "original_double = " << original_double << std::endl;
    
    std::cout << std::endl << "Адреса по-прежнему остаются неизменными:" << std::endl;
    std::cout << "Адрес original_integer: " << &original_integer << std::endl;
    std::cout << "Адрес reference_to_integer: " << &reference_to_integer << std::endl;
    std::cout << "Адрес original_double: " << &original_double << std::endl;
    std::cout << "Адрес reference_to_double: " << &reference_to_double << std::endl;
    std::cout << std::endl;
    
    // ==========================================
    // 6. ДОПОЛНИТЕЛЬНЫЕ ПРИМЕРЫ РАБОТЫ СО ССЫЛКАМИ
    // ==========================================
    
    std::cout << "=== Дополнительные примеры работы со ссылками ===" << std::endl;
    
    // Пример 1: Ссылка на константу
    const int const_value{42};
    const int& reference_to_const{const_value};
    
    std::cout << "Константная ссылка:" << std::endl;
    std::cout << "const_value = " << const_value << std::endl;
    std::cout << "reference_to_const = " << reference_to_const << std::endl;
    std::cout << "Адреса одинаковые: " << &const_value << " = " << &reference_to_const << std::endl;
    std::cout << std::endl;
    
    // Пример 2: Ссылка на элемент массива
    int array[5]{10, 20, 30, 40, 50};
    int& reference_to_array_element{array[2]};  // Ссылка на третий элемент
    
    std::cout << "Ссылка на элемент массива:" << std::endl;
    std::cout << "array[2] = " << array[2] << std::endl;
    std::cout << "reference_to_array_element = " << reference_to_array_element << std::endl;
    
    // Изменяем через ссылку
    reference_to_array_element = 999;
    std::cout << "После изменения через ссылку:" << std::endl;
    std::cout << "array[2] = " << array[2] << std::endl;
    std::cout << "reference_to_array_element = " << reference_to_array_element << std::endl;
    std::cout << std::endl;
    
    // ==========================================
    // 7. ОСНОВНЫЕ СВОЙСТВА ССЫЛОК
    // ==========================================
    
    std::cout << "=== Основные свойства ссылок ===" << std::endl;
    std::cout << "1. Ссылка должна быть инициализирована при создании" << std::endl;
    std::cout << "2. Ссылка не может быть переназначена на другую переменную" << std::endl;
    std::cout << "3. Ссылка и оригинальная переменная имеют одинаковый адрес" << std::endl;
    std::cout << "4. Изменения через ссылку влияют на оригинальную переменную" << std::endl;
    std::cout << "5. Ссылка не может быть nullptr (в отличие от указателей)" << std::endl;
    std::cout << "6. Ссылки безопаснее указателей" << std::endl;
    std::cout << std::endl;
    
    // ==========================================
    // 8. СРАВНЕНИЕ ССЫЛОК И УКАЗАТЕЛЕЙ
    // ==========================================
    
    std::cout << "=== Сравнение ссылок и указателей ===" << std::endl;
    std::cout << "Ссылки:" << std::endl;
    std::cout << "  - Синтаксис: int& ref = var;" << std::endl;
    std::cout << "  - Не могут быть nullptr" << std::endl;
    std::cout << "  - Не могут быть переназначены" << std::endl;
    std::cout << "  - Автоматически разыменовываются" << std::endl;
    std::cout << "  - Безопаснее указателей" << std::endl;
    std::cout << std::endl;
    
    std::cout << "Указатели:" << std::endl;
    std::cout << "  - Синтаксис: int* ptr = &var;" << std::endl;
    std::cout << "  - Могут быть nullptr" << std::endl;
    std::cout << "  - Могут быть переназначены" << std::endl;
    std::cout << "  - Требуют явного разыменования (*ptr)" << std::endl;
    std::cout << "  - Более гибкие, но менее безопасные" << std::endl;
    std::cout << std::endl;
    
    std::cout << "Программа завершается корректно" << std::endl;
    return 0;
}