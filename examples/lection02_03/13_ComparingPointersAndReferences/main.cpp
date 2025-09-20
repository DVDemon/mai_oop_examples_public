#include <iostream>

int main() {
    
    // ==========================================
    // 1. СОЗДАНИЕ ПЕРЕМЕННОЙ, УКАЗАТЕЛЯ И ССЫЛКИ
    // ==========================================
    
    std::cout << "=== Создание переменной, указателя и ссылки ===" << std::endl;
    
    double original_value{12.34};
    double& reference_to_value{original_value};  // Ссылка на original_value
    double* pointer_to_value{&original_value};   // Указатель на original_value
    
    std::cout << "Созданы:" << std::endl;
    std::cout << "- original_value = " << original_value << std::endl;
    std::cout << "- reference_to_value (ссылка на original_value)" << std::endl;
    std::cout << "- pointer_to_value (указатель на original_value)" << std::endl;
    std::cout << std::endl;
    
    // ==========================================
    // 2. ЧТЕНИЕ ЗНАЧЕНИЙ
    // ==========================================
    
    std::cout << "=== Чтение значений ===" << std::endl;
    
    std::cout << "Оригинальная переменная: " << original_value << std::endl;
    std::cout << "Через ссылку: " << reference_to_value << std::endl;
    std::cout << "Адрес в указателе: " << pointer_to_value << std::endl;
    std::cout << "Через указатель (разыменование): " << *pointer_to_value << std::endl;
    
    std::cout << std::endl << "ВАЖНО: Ссылка автоматически разыменовывается!" << std::endl;
    std::cout << "Указатель требует явного разыменования (*pointer)!" << std::endl;
    std::cout << std::endl;
    
    // ==========================================
    // 3. ИЗМЕНЕНИЕ ЗНАЧЕНИЯ ЧЕРЕЗ УКАЗАТЕЛЬ
    // ==========================================
    
    std::cout << "=== Изменение значения через указатель ===" << std::endl;
    
    // Изменяем значение через указатель
    *pointer_to_value = 15.44;
    
    std::cout << "Изменено значение через указатель (*pointer_to_value = 15.44):" << std::endl;
    std::cout << "original_value = " << original_value << std::endl;
    std::cout << "reference_to_value = " << reference_to_value << std::endl;
    std::cout << "pointer_to_value = " << pointer_to_value << std::endl;
    std::cout << "*pointer_to_value = " << *pointer_to_value << std::endl;
    
    std::cout << std::endl << "Все три способа доступа показывают одинаковое значение!" << std::endl;
    std::cout << std::endl;
    
    // ==========================================
    // 4. ИЗМЕНЕНИЕ ЗНАЧЕНИЯ ЧЕРЕЗ ССЫЛКУ
    // ==========================================
    
    std::cout << "=== Изменение значения через ссылку ===" << std::endl;
    
    // Изменяем значение через ссылку
    reference_to_value = 18.44;
    
    std::cout << "Изменено значение через ссылку (reference_to_value = 18.44):" << std::endl;
    std::cout << "original_value = " << original_value << std::endl;
    std::cout << "reference_to_value = " << reference_to_value << std::endl;
    std::cout << "pointer_to_value = " << pointer_to_value << std::endl;
    std::cout << "*pointer_to_value = " << *pointer_to_value << std::endl;
    
    std::cout << std::endl << "Ссылка работает как альтернативное имя переменной!" << std::endl;
    std::cout << std::endl;
    
    // ==========================================
    // 5. КЛЮЧЕВОЕ РАЗЛИЧИЕ: ПЕРЕНАЗНАЧЕНИЕ
    // ==========================================
    
    std::cout << "=== КЛЮЧЕВОЕ РАЗЛИЧИЕ: Переопределение ===" << std::endl;
    
    double another_value{78.45};
    
    std::cout << "Создана новая переменная: another_value = " << another_value << std::endl;
    std::cout << std::endl;
    
    // Попытка "переназначить" ссылку
    std::cout << "Попытка 'переназначить' ссылку:" << std::endl;
    reference_to_value = another_value;  // Это НЕ переназначает ссылку!
    
    std::cout << "После reference_to_value = another_value:" << std::endl;
    std::cout << "original_value = " << original_value << std::endl;
    std::cout << "reference_to_value = " << reference_to_value << std::endl;
    std::cout << "another_value = " << another_value << std::endl;
    
    std::cout << std::endl << "ВАЖНО: Это НЕ переназначает ссылку!" << std::endl;
    std::cout << "Это копирует значение another_value в original_value!" << std::endl;
    std::cout << "Ссылка по-прежнему указывает на original_value!" << std::endl;
    std::cout << std::endl;
    
    // ==========================================
    // 6. ПЕРЕНАЗНАЧЕНИЕ УКАЗАТЕЛЯ
    // ==========================================
    
    std::cout << "=== Переопределение указателя ===" << std::endl;
    
    // Переопределяем указатель на другую переменную
    pointer_to_value = &another_value;
    
    std::cout << "Переопределен указатель (pointer_to_value = &another_value):" << std::endl;
    std::cout << "original_value = " << original_value << std::endl;
    std::cout << "reference_to_value = " << reference_to_value << std::endl;
    std::cout << "another_value = " << another_value << std::endl;
    std::cout << "pointer_to_value = " << pointer_to_value << std::endl;
    std::cout << "*pointer_to_value = " << *pointer_to_value << std::endl;
    
    std::cout << std::endl << "Адреса для сравнения:" << std::endl;
    std::cout << "&original_value = " << &original_value << std::endl;
    std::cout << "&reference_to_value = " << &reference_to_value << std::endl;
    std::cout << "&another_value = " << &another_value << std::endl;
    
    std::cout << std::endl << "ВАЖНО: Указатель теперь указывает на another_value!" << std::endl;
    std::cout << "Ссылка по-прежнему указывает на original_value!" << std::endl;
    std::cout << std::endl;
    
    // ==========================================
    // 7. ИЗМЕНЕНИЕ ЧЕРЕЗ ПЕРЕНАЗНАЧЕННЫЙ УКАЗАТЕЛЬ
    // ==========================================
    
    std::cout << "=== Изменение через переопределенный указатель ===" << std::endl;
    
    // Изменяем значение через переопределенный указатель
    *pointer_to_value = 555.5;
    
    std::cout << "Изменено значение через переопределенный указатель (*pointer_to_value = 555.5):" << std::endl;
    std::cout << "original_value = " << original_value << std::endl;
    std::cout << "reference_to_value = " << reference_to_value << std::endl;
    std::cout << "another_value = " << another_value << std::endl;
    std::cout << "pointer_to_value = " << pointer_to_value << std::endl;
    std::cout << "*pointer_to_value = " << *pointer_to_value << std::endl;
    
    std::cout << std::endl << "Адреса для сравнения:" << std::endl;
    std::cout << "&original_value = " << &original_value << std::endl;
    std::cout << "&reference_to_value = " << &reference_to_value << std::endl;
    std::cout << "&another_value = " << &another_value << std::endl;
    
    std::cout << std::endl << "ВАЖНО: Изменилось значение another_value!" << std::endl;
    std::cout << "original_value и reference_to_value остались неизменными!" << std::endl;
    std::cout << std::endl;
    
    // ==========================================
    // 8. СВОДНАЯ ТАБЛИЦА РАЗЛИЧИЙ
    // ==========================================
    
    std::cout << "=== Сводная таблица различий между указателями и ссылками ===" << std::endl;
    std::cout << std::endl;
    
    std::cout << "| Свойство           | Указатели           | Ссылки              |" << std::endl;
    std::cout << "|--------------------|--------------------|--------------------|" << std::endl;
    std::cout << "| Синтаксис          | int* ptr = &var;   | int& ref = var;    |" << std::endl;
    std::cout << "| Инициализация      | Может быть nullptr | Обязательна        |" << std::endl;
    std::cout << "| Переназначение     | Возможно           | Невозможно          |" << std::endl;
    std::cout << "| Разыменование      | Явное (*ptr)       | Автоматическое     |" << std::endl;
    std::cout << "| Арифметика         | Поддерживается     | Не поддерживается  |" << std::endl;
    std::cout << "| Безопасность       | Менее безопасны    | Более безопасны    |" << std::endl;
    std::cout << "| Размер             | sizeof(ptr)        | sizeof(ref) = sizeof(var) |" << std::endl;
    std::cout << "| nullptr            | Может быть         | Не может быть      |" << std::endl;
    std::cout << std::endl;
    
    // ==========================================
    // 9. ПРАКТИЧЕСКИЕ РЕКОМЕНДАЦИИ
    // ==========================================
    
    std::cout << "=== Практические рекомендации ===" << std::endl;
    std::cout << "Используйте ссылки когда:" << std::endl;
    std::cout << "- Нужна безопасность (нет nullptr)" << std::endl;
    std::cout << "- Не нужна арифметика указателей" << std::endl;
    std::cout << "- Передаете параметры в функции" << std::endl;
    std::cout << "- Создаете псевдонимы для переменных" << std::endl;
    std::cout << std::endl;
    
    std::cout << "Используйте указатели когда:" << std::endl;
    std::cout << "- Нужна арифметика указателей" << std::endl;
    std::cout << "- Работаете с динамической памятью" << std::endl;
    std::cout << "- Нужно переназначать на разные объекты" << std::endl;
    std::cout << "- Работаете с массивами" << std::endl;
    std::cout << "- Нужно явно проверять на nullptr" << std::endl;
    std::cout << std::endl;
    
    std::cout << "Программа завершается корректно" << std::endl;
    return 0;
}