#include <iostream>

int main() {
    
    // ==========================================
    // 1. РАЗЛИЧНЫЕ СПОСОБЫ СОЗДАНИЯ ДИНАМИЧЕСКИХ МАССИВОВ
    // ==========================================
    
    const size_t array_size{10};
    
    std::cout << "=== Различные способы создания динамических массивов ===" << std::endl;
    
    // Способ 1: Массив без инициализации (содержит мусор)
    double* salaries_array{new double[array_size]};  // Массив будет содержать случайные значения
    
    // Способ 2: Массив с инициализацией нулями
    int* students_array{new int[array_size]{}};  // Все значения инициализированы нулями
    
    // Способ 3: Массив с частичной инициализацией
    double* scores_array{new double[array_size]{1, 2, 3, 4, 5}};  // Первые 5 элементов инициализированы, остальные - нули
    
    std::cout << "Созданы три динамических массива размером " << array_size << " элементов" << std::endl;
    std::cout << std::endl;
    
    // ==========================================
    // 2. ПРОВЕРКА НА nullptr И ИСПОЛЬЗОВАНИЕ МАССИВА
    // ==========================================
    
    std::cout << "=== Проверка на nullptr и использование массива ===" << std::endl;
    
    if (scores_array != nullptr) {
        std::cout << "Размер указателя (не массива!): " << sizeof(scores_array) << " байт" << std::endl;
        std::cout << "Память для массива scores успешно выделена" << std::endl;
        std::cout << std::endl;
        
        // Выводим элементы массива двумя способами
        std::cout << "Элементы массива scores:" << std::endl;
        for (size_t i{0}; i < array_size; ++i) {
            std::cout << "Индекс " << i << ": " << scores_array[i] 
                      << " (через индексацию) = " << *(scores_array + i) 
                      << " (через арифметику указателей)" << std::endl;
        }
        std::cout << std::endl;
    }
    
    // ==========================================
    // 3. ДЕМОНСТРАЦИЯ РАЗЛИЧНЫХ МАССИВОВ
    // ==========================================
    
    std::cout << "=== Демонстрация различных массивов ===" << std::endl;
    
    // Массив с мусором
    std::cout << "Массив salaries (содержит мусор):" << std::endl;
    for (size_t i{0}; i < 5; ++i) {  // Показываем только первые 5 элементов
        std::cout << "salaries[" << i << "] = " << salaries_array[i] << std::endl;
    }
    std::cout << std::endl;
    
    // Массив с нулями
    std::cout << "Массив students (инициализирован нулями):" << std::endl;
    for (size_t i{0}; i < 5; ++i) {
        std::cout << "students[" << i << "] = " << students_array[i] << std::endl;
    }
    std::cout << std::endl;
    
    // ==========================================
    // 4. ОСВОБОЖДЕНИЕ ПАМЯТИ
    // ==========================================
    
    std::cout << "=== Освобождение памяти ===" << std::endl;
    
    // ВАЖНО: Используем delete[] для массивов, а не delete
    delete[] salaries_array;
    salaries_array = nullptr;
    std::cout << "Память для salaries_array освобождена" << std::endl;
    
    delete[] students_array;
    students_array = nullptr;
    std::cout << "Память для students_array освобождена" << std::endl;
    
    delete[] scores_array;
    scores_array = nullptr;
    std::cout << "Память для scores_array освобождена" << std::endl;
    std::cout << std::endl;
    
    // ==========================================
    // 5. СРАВНЕНИЕ СТАТИЧЕСКИХ И ДИНАМИЧЕСКИХ МАССИВОВ
    // ==========================================
    
    std::cout << "=== Сравнение статических и динамических массивов ===" << std::endl;
    
    // Статический массив (живет в стеке)
    int static_scores[10]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    std::cout << "Статический массив (стек):" << std::endl;
    std::cout << "Размер массива: " << std::size(static_scores) << " элементов" << std::endl;
    std::cout << "Размер в памяти: " << sizeof(static_scores) << " байт" << std::endl;
    
    std::cout << "Элементы статического массива:" << std::endl;
    for (auto score : static_scores) {
        std::cout << "Значение: " << score << std::endl;
    }
    std::cout << std::endl;
    
    // Динамический массив (живет в куче)
    int* dynamic_scores{new int[10]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}};
    
    std::cout << "Динамический массив (куча):" << std::endl;
    std::cout << "Размер указателя: " << sizeof(dynamic_scores) << " байт" << std::endl;
    std::cout << "Размер массива: НЕ МОЖЕМ УЗНАТЬ через std::size()!" << std::endl;
    
    std::cout << "Элементы динамического массива:" << std::endl;
    for (size_t i{0}; i < 10; ++i) {
        std::cout << "Значение: " << dynamic_scores[i] << std::endl;
    }
    std::cout << std::endl;
    
    // ==========================================
    // 6. ДОПОЛНИТЕЛЬНЫЕ ПРИМЕРЫ РАБОТЫ С ДИНАМИЧЕСКИМИ МАССИВАМИ
    // ==========================================
    
    std::cout << "=== Дополнительные примеры работы с динамическими массивами ===" << std::endl;
    
    // Создаем массив с пользовательским размером
    size_t custom_size{5};
    int* custom_array{new int[custom_size]{10, 20, 30, 40, 50}};
    
    std::cout << "Пользовательский массив размером " << custom_size << ":" << std::endl;
    for (size_t i{0}; i < custom_size; ++i) {
        std::cout << "custom_array[" << i << "] = " << custom_array[i] << std::endl;
    }
    
    // Изменяем элементы массива
    std::cout << std::endl << "Изменяем элементы массива:" << std::endl;
    for (size_t i{0}; i < custom_size; ++i) {
        custom_array[i] *= 2;  // Удваиваем каждый элемент
        std::cout << "custom_array[" << i << "] = " << custom_array[i] << std::endl;
    }
    
    // Освобождаем память
    delete[] custom_array;
    custom_array = nullptr;
    std::cout << "Память для custom_array освобождена" << std::endl;
    std::cout << std::endl;
    
    // ==========================================
    // 7. ПРАВИЛА РАБОТЫ С ДИНАМИЧЕСКИМИ МАССИВАМИ
    // ==========================================
    
    std::cout << "=== Правила работы с динамическими массивами ===" << std::endl;
    std::cout << "1. ВСЕГДА используйте delete[] для освобождения массивов" << std::endl;
    std::cout << "2. НИКОГДА не используйте delete для массивов" << std::endl;
    std::cout << "3. ВСЕГДА устанавливайте указатель в nullptr после освобождения" << std::endl;
    std::cout << "4. ВСЕГДА проверяйте на nullptr перед использованием" << std::endl;
    std::cout << "5. Помните, что std::size() не работает с динамическими массивами" << std::endl;
    std::cout << "6. Храните размер массива отдельно" << std::endl;
    std::cout << "7. Предпочитайте std::vector вместо сырых динамических массивов" << std::endl;
    std::cout << std::endl;
    
    // ==========================================
    // 8. ОСВОБОЖДЕНИЕ ОСТАВШЕЙСЯ ПАМЯТИ
    // ==========================================
    
    std::cout << "=== Освобождение оставшейся памяти ===" << std::endl;
    
    // Освобождаем память для динамического массива
    delete[] dynamic_scores;
    dynamic_scores = nullptr;
    std::cout << "Память для dynamic_scores освобождена" << std::endl;
    
    std::cout << "Программа завершается корректно" << std::endl;
    return 0;
}