#include <iostream>

int main() {
    
    // ==========================================
    // 1. ОБЫЧНАЯ ПЕРЕМЕННАЯ (БЕЗ CONST)
    // ==========================================
    
    std::cout << "=== Обычная переменная (можно изменять) ===" << std::endl;
    
    int modifiable_variable{5};  // Обычная переменная - можно изменять любым способом
    std::cout << "Значение переменной: " << modifiable_variable << std::endl;
    std::cout << "Адрес переменной: " << &modifiable_variable << std::endl;
    
    // Изменяем значение
    modifiable_variable = 12;
    modifiable_variable += 7;
    
    std::cout << "После изменений:" << std::endl;
    std::cout << "Значение переменной: " << modifiable_variable << std::endl;
    std::cout << "Адрес переменной: " << &modifiable_variable << std::endl;
    std::cout << std::endl;
    
    // ==========================================
    // 2. ОБЫЧНЫЙ УКАЗАТЕЛЬ (БЕЗ CONST)
    // ==========================================
    
    std::cout << "=== Обычный указатель (можно изменять и указатель, и данные) ===" << std::endl;
    
    int* modifiable_pointer{nullptr};
    int target_variable1{23};
    
    modifiable_pointer = &target_variable1;
    std::cout << "Адрес в указателе: " << modifiable_pointer << std::endl;
    std::cout << "Значение через указатель: " << *modifiable_pointer << std::endl;
    std::cout << "Значение переменной напрямую: " << target_variable1 << std::endl;
    
    // Изменяем значение через указатель
    std::cout << std::endl << "Изменяем значение через указатель:" << std::endl;
    *modifiable_pointer = 432;
    std::cout << "Адрес в указателе: " << modifiable_pointer << std::endl;
    std::cout << "Значение через указатель: " << *modifiable_pointer << std::endl;
    std::cout << "Значение переменной напрямую: " << target_variable1 << std::endl;
    
    // Изменяем сам указатель (заставляем указывать на другую переменную)
    std::cout << std::endl << "Изменяем сам указатель:" << std::endl;
    int target_variable2{56};
    modifiable_pointer = &target_variable2;
    std::cout << "Адрес в указателе: " << modifiable_pointer << std::endl;
    std::cout << "Значение через указатель: " << *modifiable_pointer << std::endl;
    std::cout << "Первая переменная: " << target_variable1 << std::endl;
    std::cout << "Вторая переменная: " << target_variable2 << std::endl;
    std::cout << std::endl;
    
    // ==========================================
    // 3. УКАЗАТЕЛЬ НА КОНСТАНТНЫЕ ДАННЫЕ (const int*)
    // ==========================================
    
    std::cout << "=== Указатель на константные данные (указатель можно изменять, данные - нет) ===" << std::endl;
    
    int source_variable{632};  // Рекомендуется явно указывать const для ясности намерений
    const int* pointer_to_const_data{&source_variable};  // Нельзя изменять данные через этот указатель
    
    std::cout << "Адрес в указателе: " << pointer_to_const_data << std::endl;
    std::cout << "Значение через указатель: " << *pointer_to_const_data << std::endl;
    
    // Попытка изменить данные через указатель вызовет ошибку компиляции:
    std::cout << std::endl << "Попытка изменить данные через указатель (ОШИБКА КОМПИЛЯЦИИ):" << std::endl;
    // *pointer_to_const_data = 444;  // ОШИБКА: нельзя изменять константные данные
    
    // Но можно изменить сам указатель (заставить указывать на другую переменную)
    std::cout << std::endl << "Изменяем адрес в указателе:" << std::endl;
    int another_variable{872};
    pointer_to_const_data = &another_variable;
    std::cout << "Адрес в указателе: " << pointer_to_const_data << std::endl;
    std::cout << "Значение через указатель: " << *pointer_to_const_data << std::endl;
    std::cout << std::endl;
    
    // ==========================================
    // 4. КЛЮЧЕВОЕ СЛОВО CONST ПРИМЕНЯЕТСЯ К ИМЕНИ ПЕРЕМЕННОЙ
    // ==========================================
    
    std::cout << "=== const применяется к имени переменной ===" << std::endl;
    
    int regular_variable{10};  // Можно сделать const для защиты, если нужно
    
    // pointer_to_protected_data - это указатель на константные данные
    // Мы не можем изменять данные через этот указатель, независимо от того,
    // объявлены ли сами данные как const или нет
    const int* pointer_to_protected_data{&regular_variable};
    
    // *pointer_to_protected_data = 55;  // ОШИБКА: нельзя изменять через указатель на const
    regular_variable = 66;  // Но можно изменять напрямую
    std::cout << "Значение переменной напрямую: " << regular_variable << std::endl;
    std::cout << "Адрес в указателе: " << pointer_to_protected_data << std::endl;
    std::cout << "Значение через указатель: " << *pointer_to_protected_data << std::endl;
    std::cout << std::endl;
    
    // Нельзя создать модифицируемый указатель на константные данные
    std::cout << "Попытка создать модифицируемый указатель на const данные (ОШИБКА КОМПИЛЯЦИИ):" << std::endl;
    const int const_data{55};
    // int* modifiable_pointer_to_const{&const_data};  // ОШИБКА: недопустимое преобразование
    // *modifiable_pointer_to_const = 66;
    
    // ==========================================
    // 5. КОНСТАНТНЫЙ УКАЗАТЕЛЬ НА КОНСТАНТНЫЕ ДАННЫЕ (const int* const)
    // ==========================================
    
    std::cout << "=== Константный указатель на константные данные (ничего нельзя изменить) ===" << std::endl;
    
    const int const_value{459};
    const int* const const_pointer_to_const{&const_value};
    
    std::cout << "Адрес в указателе: " << const_pointer_to_const << std::endl;
    std::cout << "Значение через указатель: " << *const_pointer_to_const << std::endl;
    
    // Нельзя изменить данные через указатель
    std::cout << std::endl << "Попытка изменить данные через указатель (ОШИБКА КОМПИЛЯЦИИ):" << std::endl;
    // *const_pointer_to_const = 222;  // ОШИБКА: попытка записи в read-only память
    
    // Нельзя изменить адрес в указателе
    std::cout << "Попытка изменить адрес в указателе (ОШИБКА КОМПИЛЯЦИИ):" << std::endl;
    int different_variable{333};
    // const_pointer_to_const = &different_variable;  // ОШИБКА: попытка записи в read-only память
    std::cout << std::endl;
    
    // ==========================================
    // 6. КОНСТАНТНЫЙ УКАЗАТЕЛЬ НА МОДИФИЦИРУЕМЫЕ ДАННЫЕ (int* const)
    // ==========================================
    
    std::cout << "=== Константный указатель на модифицируемые данные (указатель нельзя изменить, данные - можно) ===" << std::endl;
    
    int modifiable_target{982};
    int* const const_pointer_to_modifiable{&modifiable_target};
    
    std::cout << "Адрес в указателе: " << const_pointer_to_modifiable << std::endl;
    std::cout << "Значение через указатель: " << *const_pointer_to_modifiable << std::endl;
    
    // Можно изменить данные через указатель
    std::cout << std::endl << "Изменяем данные через указатель:" << std::endl;
    // const_pointer_to_modifiable++;  // ОШИБКА: нельзя изменять константный указатель
    *const_pointer_to_modifiable = 456;
    std::cout << "Новое значение через указатель: " << *const_pointer_to_modifiable << std::endl;
    
    // Нельзя изменить адрес в указателе
    std::cout << std::endl << "Попытка изменить адрес в указателе (ОШИБКА КОМПИЛЯЦИИ):" << std::endl;
    int another_target{2928};
    // const_pointer_to_modifiable = &another_target;  // ОШИБКА: нельзя изменять константный указатель
    
    return 0;
}