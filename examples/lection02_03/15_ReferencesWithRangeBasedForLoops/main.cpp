#include <iostream>

int main() {
    
    // ==========================================
    // 1. СОЗДАНИЕ МАССИВА ДЛЯ ДЕМОНСТРАЦИИ
    // ==========================================
    
    std::cout << "=== Range-based for loops с ссылками ===" << std::endl;
    
    int student_scores[]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    const size_t array_size = sizeof(student_scores) / sizeof(student_scores[0]);
    
    std::cout << "Создан массив student_scores с " << array_size << " элементами:" << std::endl;
    std::cout << "Исходные значения: ";
    for (size_t i = 0; i < array_size; ++i) {
        std::cout << student_scores[i] << " ";
    }
    std::cout << std::endl << std::endl;
    
    // ==========================================
    // 2. RANGE-BASED FOR LOOP БЕЗ ССЫЛОК (КОПИРОВАНИЕ)
    // ==========================================
    
    std::cout << "=== Range-based for loop БЕЗ ссылок (копирование) ===" << std::endl;
    
    std::cout << "for (auto score : student_scores) - копирование элементов:" << std::endl;
    std::cout << "Значения: ";
    for (auto score : student_scores) {
        std::cout << score << " ";
    }
    std::cout << std::endl;
    
    std::cout << std::endl << "ВАЖНО: Каждый элемент копируется в переменную score!" << std::endl;
    std::cout << "Изменения в score НЕ влияют на оригинальный массив!" << std::endl;
    std::cout << std::endl;
    
    // ==========================================
    // 3. RANGE-BASED FOR LOOP С ОБЫЧНЫМИ ССЫЛКАМИ (ИЗМЕНЕНИЕ)
    // ==========================================
    
    std::cout << "=== Range-based for loop С обычными ссылками (изменение) ===" << std::endl;
    
    std::cout << "for (auto& score : student_scores) - ссылки на элементы:" << std::endl;
    std::cout << "Умножаем каждый элемент на 10:" << std::endl;
    
    for (auto& score : student_scores) {
        score = score * 10;  // Изменяем оригинальный элемент через ссылку
    }
    
    std::cout << "Результат после изменения: ";
    for (size_t i = 0; i < array_size; ++i) {
        std::cout << student_scores[i] << " ";
    }
    std::cout << std::endl;
    
    std::cout << std::endl << "ВАЖНО: Ссылки позволяют изменять оригинальные элементы!" << std::endl;
    std::cout << "Изменения через ссылку влияют на оригинальный массив!" << std::endl;
    std::cout << std::endl;
    
    // ==========================================
    // 4. RANGE-BASED FOR LOOP С CONST-ССЫЛКАМИ (ТОЛЬКО ЧТЕНИЕ)
    // ==========================================
    
    std::cout << "=== Range-based for loop С const-ссылками (только чтение) ===" << std::endl;
    
    std::cout << "for (const auto& score : student_scores) - const-ссылки на элементы:" << std::endl;
    std::cout << "Значения: ";
    for (const auto& score : student_scores) {
        std::cout << score << " ";
    }
    std::cout << std::endl;
    
    std::cout << std::endl << "ВАЖНО: Const-ссылки обеспечивают read-only доступ!" << std::endl;
    std::cout << "Изменения через const-ссылку НЕВОЗМОЖНЫ!" << std::endl;
    std::cout << std::endl;
    
    // ==========================================
    // 5. ДЕМОНСТРАЦИЯ РАЗЛИЧИЙ В ПРОИЗВОДИТЕЛЬНОСТИ
    // ==========================================
    
    std::cout << "=== Различия в производительности ===" << std::endl;
    
    // Создаем большой массив для демонстрации
    const size_t large_size = 1000;
    int large_array[large_size];
    
    // Инициализируем массив
    for (size_t i = 0; i < large_size; ++i) {
        large_array[i] = static_cast<int>(i);
    }
    
    std::cout << "Создан большой массив с " << large_size << " элементами" << std::endl;
    std::cout << std::endl;
    
    std::cout << "1. Копирование (медленно):" << std::endl;
    std::cout << "   for (auto element : large_array) - каждый элемент копируется" << std::endl;
    std::cout << "   Память: O(n) дополнительной памяти" << std::endl;
    std::cout << "   Время: O(n) времени на копирование" << std::endl;
    std::cout << std::endl;
    
    std::cout << "2. Обычные ссылки (быстро, изменяемо):" << std::endl;
    std::cout << "   for (auto& element : large_array) - ссылки на элементы" << std::endl;
    std::cout << "   Память: O(1) дополнительной памяти" << std::endl;
    std::cout << "   Время: O(1) времени на доступ" << std::endl;
    std::cout << std::endl;
    
    std::cout << "3. Const-ссылки (быстро, read-only):" << std::endl;
    std::cout << "   for (const auto& element : large_array) - const-ссылки на элементы" << std::endl;
    std::cout << "   Память: O(1) дополнительной памяти" << std::endl;
    std::cout << "   Время: O(1) времени на доступ" << std::endl;
    std::cout << "   Безопасность: предотвращает случайные изменения" << std::endl;
    std::cout << std::endl;
    
    // ==========================================
    // 6. ПРАКТИЧЕСКИЕ ПРИМЕРЫ ИСПОЛЬЗОВАНИЯ
    // ==========================================
    
    std::cout << "=== Практические примеры использования ===" << std::endl;
    
    // Пример 1: Поиск максимального элемента
    std::cout << "Пример 1: Поиск максимального элемента" << std::endl;
    int max_score = student_scores[0];
    for (const auto& score : student_scores) {
        if (score > max_score) {
            max_score = score;
        }
    }
    std::cout << "Максимальный балл: " << max_score << std::endl;
    std::cout << std::endl;
    
    // Пример 2: Подсчет суммы
    std::cout << "Пример 2: Подсчет суммы всех баллов" << std::endl;
    int total_score = 0;
    for (const auto& score : student_scores) {
        total_score += score;
    }
    std::cout << "Общая сумма баллов: " << total_score << std::endl;
    std::cout << std::endl;
    
    // Пример 3: Изменение элементов
    std::cout << "Пример 3: Добавление бонуса к каждому баллу" << std::endl;
    std::cout << "До изменения: ";
    for (const auto& score : student_scores) {
        std::cout << score << " ";
    }
    std::cout << std::endl;
    
    for (auto& score : student_scores) {
        score += 5;  // Добавляем бонус
    }
    
    std::cout << "После добавления бонуса (+5): ";
    for (const auto& score : student_scores) {
        std::cout << score << " ";
    }
    std::cout << std::endl << std::endl;
    
    // ==========================================
    // 7. СВОДНАЯ ТАБЛИЦА ТИПОВ RANGE-BASED FOR LOOPS
    // ==========================================
    
    std::cout << "=== Сводная таблица типов range-based for loops ===" << std::endl;
    std::cout << std::endl;
    
    std::cout << "| Тип цикла              | Синтаксис                    | Изменение | Производительность |" << std::endl;
    std::cout << "|------------------------|------------------------------|-----------|--------------------|" << std::endl;
    std::cout << "| Копирование            | for (auto item : array)      | Нет       | Медленно            |" << std::endl;
    std::cout << "| Обычные ссылки          | for (auto& item : array)     | Да        | Быстро              |" << std::endl;
    std::cout << "| Const-ссылки            | for (const auto& item : array)| Нет      | Быстро              |" << std::endl;
    std::cout << std::endl;
    
    // ==========================================
    // 8. РЕКОМЕНДАЦИИ ПО ИСПОЛЬЗОВАНИЮ
    // ==========================================
    
    std::cout << "=== Рекомендации по использованию ===" << std::endl;
    std::cout << "1. Используйте const auto& для read-only доступа" << std::endl;
    std::cout << "2. Используйте auto& только когда нужно изменять элементы" << std::endl;
    std::cout << "3. Избегайте auto (копирование) для больших объектов" << std::endl;
    std::cout << "4. Const-ссылки обеспечивают лучшую производительность и безопасность" << std::endl;
    std::cout << "5. Range-based for loops работают с любыми контейнерами" << std::endl;
    std::cout << std::endl;
    
    std::cout << "Программа завершается корректно" << std::endl;
    return 0;
}