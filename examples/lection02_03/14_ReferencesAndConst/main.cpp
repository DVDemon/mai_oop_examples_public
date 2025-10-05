#include <iostream>

int main() {
    
    // ==========================================
    // 1. ОБЫЧНЫЕ ССЫЛКИ (НЕ CONST)
    // ==========================================
    
    std::cout << "=== Обычные ссылки (не const) ===" << std::endl;
    
    int original_age{27};
    int& reference_to_age{original_age};  // Обычная ссылка
    
    std::cout << "Созданы:" << std::endl;
    std::cout << "- original_age = " << original_age << std::endl;
    std::cout << "- reference_to_age (обычная ссылка на original_age)" << std::endl;
    std::cout << std::endl;
    
    std::cout << "Чтение значений:" << std::endl;
    std::cout << "original_age = " << original_age << std::endl;
    std::cout << "reference_to_age = " << reference_to_age << std::endl;
    std::cout << std::endl;
    
    // Изменение через оригинальную переменную
    std::cout << "Изменение через оригинальную переменную (original_age++):" << std::endl;
    original_age++;
    std::cout << "original_age = " << original_age << std::endl;
    std::cout << "reference_to_age = " << reference_to_age << std::endl;
    std::cout << std::endl;
    
    // Изменение через ссылку
    std::cout << "Изменение через ссылку (reference_to_age++):" << std::endl;
    reference_to_age++;
    std::cout << "original_age = " << original_age << std::endl;
    std::cout << "reference_to_age = " << reference_to_age << std::endl;
    
    std::cout << std::endl << "ВАЖНО: Обычная ссылка позволяет изменять значение!" << std::endl;
    std::cout << std::endl;
    
    // ==========================================
    // 2. CONST-ССЫЛКИ
    // ==========================================
    
    std::cout << "=== Const-ссылки ===" << std::endl;
    
    int modifiable_value{30};
    const int& const_reference_to_value{modifiable_value};  // Const-ссылка
    
    std::cout << "Созданы:" << std::endl;
    std::cout << "- modifiable_value = " << modifiable_value << std::endl;
    std::cout << "- const_reference_to_value (const-ссылка на modifiable_value)" << std::endl;
    std::cout << std::endl;
    
    std::cout << "Чтение значений:" << std::endl;
    std::cout << "modifiable_value = " << modifiable_value << std::endl;
    std::cout << "const_reference_to_value = " << const_reference_to_value << std::endl;
    std::cout << std::endl;
    
    // Изменение через оригинальную переменную
    std::cout << "Изменение через оригинальную переменную (modifiable_value++):" << std::endl;
    modifiable_value++;
    std::cout << "modifiable_value = " << modifiable_value << std::endl;
    std::cout << "const_reference_to_value = " << const_reference_to_value << std::endl;
    std::cout << std::endl;
    
    // Попытка изменить через const-
    std::cout << "Попытка изменить через const-ссылку:" << std::endl;
    std::cout << "// const_reference_to_value++;  // ОШИБКА КОМПИЛЯЦИИ!" << std::endl;
    std::cout << "const_reference_to_value = " << const_reference_to_value << std::endl;
    
    std::cout << std::endl << "ВАЖНО: Const-ссылка НЕ позволяет изменять значение!" << std::endl;
    std::cout << "Но значение может изменяться через оригинальную переменную!" << std::endl;
    std::cout << std::endl;
    
    // ==========================================
    // 3. CONST-ССЫЛКИ НА CONST-ПЕРЕМЕННЫЕ
    // ==========================================
    
    std::cout << "=== Const-ссылки на const-переменные ===" << std::endl;
    
    const int const_variable{42};
    const int& const_reference_to_const{const_variable};  // Const-ссылка на const-переменную
    
    std::cout << "Созданы:" << std::endl;
    std::cout << "- const_variable = " << const_variable << std::endl;
    std::cout << "- const_reference_to_const (const-ссылка на const-переменную)" << std::endl;
    std::cout << std::endl;
    
    std::cout << "Чтение значений:" << std::endl;
    std::cout << "const_variable = " << const_variable << std::endl;
    std::cout << "const_reference_to_const = " << const_reference_to_const << std::endl;
    std::cout << std::endl;
    
    std::cout << "Попытки изменения:" << std::endl;
    std::cout << "// const_variable++;  // ОШИБКА КОМПИЛЯЦИИ!" << std::endl;
    std::cout << "// const_reference_to_const++;  // ОШИБКА КОМПИЛЯЦИИ!" << std::endl;
    
    std::cout << std::endl << "ВАЖНО: Ни оригинальная переменная, ни ссылка не могут быть изменены!" << std::endl;
    std::cout << std::endl;
    
    // ==========================================
    // 4. СРАВНЕНИЕ С УКАЗАТЕЛЯМИ
    // ==========================================
    
    std::cout << "=== Сравнение с указателями ===" << std::endl;
    
    int pointer_value{50};
    const int* const const_pointer_to_const{&pointer_value};  // Const-указатель на const-данные
    
    std::cout << "Создан const-указатель:" << std::endl;
    std::cout << "- pointer_value = " << pointer_value << std::endl;
    std::cout << "- const_pointer_to_const (const-указатель на const-данные)" << std::endl;
    std::cout << std::endl;
    
    std::cout << "Чтение значений:" << std::endl;
    std::cout << "pointer_value = " << pointer_value << std::endl;
    std::cout << "*const_pointer_to_const = " << *const_pointer_to_const << std::endl;
    std::cout << std::endl;
    
    std::cout << "Попытки изменения:" << std::endl;
    std::cout << "// *const_pointer_to_const = 100;  // ОШИБКА КОМПИЛЯЦИИ!" << std::endl;
    std::cout << "// const_pointer_to_const = &other;  // ОШИБКА КОМПИЛЯЦИИ!" << std::endl;
    
    std::cout << std::endl << "ВАЖНО: Const-указатель на const-данные аналогичен const-ссылке!" << std::endl;
    std::cout << std::endl;
    
    // ==========================================
    // 5. ПРАКТИЧЕСКИЕ ПРИМЕРЫ ИСПОЛЬЗОВАНИЯ
    // ==========================================
    
    std::cout << "=== Практические примеры использования ===" << std::endl;
    
    // Const-ссылки для передачи параметров в функции
    std::cout << "Const-ссылки часто используются для:" << std::endl;
    std::cout << "1. Передачи параметров в функции (избежание копирования)" << std::endl;
    std::cout << "2. Создания read-only доступа к данным" << std::endl;
    std::cout << "3. Работы с временными объектами" << std::endl;
    std::cout << "4. Создания константных псевдонимов" << std::endl;
    std::cout << std::endl;
    
    // Пример с временным объектом
    std::cout << "Пример с временным объектом:" << std::endl;
    const int& temp_reference{100};  // Const-ссылка на временный объект
    std::cout << "temp_reference = " << temp_reference << std::endl;
    std::cout << "// temp_reference++;  // ОШИБКА КОМПИЛЯЦИИ!" << std::endl;
    
    std::cout << std::endl << "ВАЖНО: Const-ссылки могут ссылаться на временные объекты!" << std::endl;
    std::cout << std::endl;
    
    // ==========================================
    // 6. СВОДНАЯ ТАБЛИЦА ТИПОВ ССЫЛОК
    // ==========================================
    
    std::cout << "=== Сводная таблица типов ссылок ===" << std::endl;
    std::cout << std::endl;
    
    std::cout << "| Тип ссылки           | Синтаксис              | Изменение через ссылку |" << std::endl;
    std::cout << "|----------------------|------------------------|------------------------|" << std::endl;
    std::cout << "| Обычная ссылка       | int& ref = var;        | Возможно               |" << std::endl;
    std::cout << "| Const-ссылка         | const int& ref = var;  | Невозможно             |" << std::endl;
    std::cout << "| Const-ссылка на const| const int& ref = cvar; | Невозможно             |" << std::endl;
    std::cout << std::endl;
    
    // ==========================================
    // 7. ПРАВИЛА ИСПОЛЬЗОВАНИЯ CONST-ССЫЛОК
    // ==========================================
    
    std::cout << "=== Правила использования const-ссылок ===" << std::endl;
    std::cout << "1. Const-ссылки обеспечивают read-only доступ" << std::endl;
    std::cout << "2. Значение может изменяться через оригинальную переменную" << std::endl;
    std::cout << "3. Const-ссылки могут ссылаться на временные объекты" << std::endl;
    std::cout << "4. Const-ссылки предотвращают случайные изменения" << std::endl;
    std::cout << "5. Const-ссылки улучшают производительность (избежание копирования)" << std::endl;
    std::cout << "6. Const-ссылки делают код более безопасным" << std::endl;
    std::cout << std::endl;
    
    std::cout << "Программа завершается корректно" << std::endl;
    return 0;
}