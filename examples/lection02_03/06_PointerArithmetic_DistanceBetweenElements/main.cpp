#include <iostream>

int main() {
    
    // ==========================================
    // 1. СОЗДАНИЕ МАССИВА И УКАЗАТЕЛЕЙ
    // ==========================================
    
    // Создаем массив из 10 элементов
    int student_scores[10]{11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    
    // ==========================================
    // 2. РАЗЛИЧНЫЕ СПОСОБЫ СОЗДАНИЯ УКАЗАТЕЛЕЙ
    // ==========================================
    
    std::cout << "=== Различные способы создания указателей ===" << std::endl;
    
    // Способ 1: Индексация массива (закомментировано в оригинале)
    // int* pointer_to_first{&student_scores[0]};
    // int* pointer_to_ninth{&student_scores[8]};
    
    // Способ 2: Арифметика указателей (используется в оригинале)
    int* pointer_to_first{student_scores + 0};   // Указатель на первый элемент (индекс 0)
    int* pointer_to_ninth{student_scores + 8};   // Указатель на девятый элемент (индекс 8)
    
    std::cout << "Указатель на первый элемент: " << pointer_to_first << std::endl;
    std::cout << "Указатель на девятый элемент: " << pointer_to_ninth << std::endl;
    std::cout << "Значение первого элемента: " << *pointer_to_first << std::endl;
    std::cout << "Значение девятого элемента: " << *pointer_to_ninth << std::endl;
    std::cout << std::endl;
    
    // ==========================================
    // 3. ВЫЧИСЛЕНИЕ РАССТОЯНИЯ МЕЖДУ УКАЗАТЕЛЯМИ
    // ==========================================
    
    std::cout << "=== Вычисление расстояния между указателями ===" << std::endl;
    
    // Разность указателей возвращает количество элементов между ними
    std::cout << "Расстояние от первого к девятому элементу: " << (pointer_to_ninth - pointer_to_first) << " элементов" << std::endl;
    std::cout << "Расстояние от девятого к первому элементу: " << (pointer_to_first - pointer_to_ninth) << " элементов" << std::endl;
    std::cout << std::endl;
    
    // ==========================================
    // 4. ИСПОЛЬЗОВАНИЕ std::ptrdiff_t ДЛЯ БЕЗОПАСНОСТИ
    // ==========================================
    
    std::cout << "=== Использование std::ptrdiff_t для безопасности типов ===" << std::endl;
    
    // std::ptrdiff_t - специальный тип для хранения разности указателей
    // Он может быть как положительным, так и отрицательным
    std::ptrdiff_t positive_distance = pointer_to_ninth - pointer_to_first;
    std::ptrdiff_t negative_distance = pointer_to_first - pointer_to_ninth;
    
    std::cout << "Положительное расстояние (ptrdiff_t): " << positive_distance << " элементов" << std::endl;
    std::cout << "Отрицательное расстояние (ptrdiff_t): " << negative_distance << " элементов" << std::endl;
    std::cout << "Размер std::ptrdiff_t: " << sizeof(std::ptrdiff_t) << " байт" << std::endl;
    std::cout << std::endl;
    
    // ==========================================
    // 5. ДОПОЛНИТЕЛЬНЫЕ ПРИМЕРЫ РАССТОЯНИЙ
    // ==========================================
    
    std::cout << "=== Дополнительные примеры расстояний ===" << std::endl;
    
    // Создаем указатели на различные элементы
    int* pointer_to_second{student_scores + 1};   // Второй элемент
    int* pointer_to_fifth{student_scores + 4};   // Пятый элемент
    int* pointer_to_last{student_scores + 9};    // Последний элемент
    
    std::cout << "Расстояние от второго к пятому элементу: " << (pointer_to_fifth - pointer_to_second) << " элементов" << std::endl;
    std::cout << "Расстояние от пятого к последнему элементу: " << (pointer_to_last - pointer_to_fifth) << " элементов" << std::endl;
    std::cout << "Расстояние от последнего к первому элементу: " << (pointer_to_first - pointer_to_last) << " элементов" << std::endl;
    std::cout << std::endl;
    
    // ==========================================
    // 6. ПРОВЕРКА ГРАНИЦ И БЕЗОПАСНОСТЬ
    // ==========================================
    
    std::cout << "=== Проверка границ и безопасность ===" << std::endl;
    
    // Проверяем, что указатели находятся в пределах массива
    std::cout << "Первый элемент массива: " << *pointer_to_first << std::endl;
    std::cout << "Последний элемент массива: " << *pointer_to_last << std::endl;
    
    // Вычисляем общий размер массива через указатели
    std::ptrdiff_t array_size = pointer_to_last - pointer_to_first + 1;
    std::cout << "Размер массива через указатели: " << array_size << " элементов" << std::endl;
    std::cout << "Размер массива через std::size(): " << std::size(student_scores) << " элементов" << std::endl;
    std::cout << std::endl;
    
    // ==========================================
    // 7. ПРАКТИЧЕСКОЕ ПРИМЕНЕНИЕ
    // ==========================================
    
    std::cout << "=== Практическое применение ===" << std::endl;
    
    // Находим средний элемент массива
    int* middle_pointer = pointer_to_first + (array_size / 2);
    std::cout << "Средний элемент массива: " << *middle_pointer << std::endl;
    std::cout << "Индекс среднего элемента: " << (middle_pointer - pointer_to_first) << std::endl;
    
    return 0;
}