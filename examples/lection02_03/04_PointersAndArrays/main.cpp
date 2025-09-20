#include <iostream>

int main() {
    
    // ==========================================
    // 1. СОЗДАНИЕ МАССИВА И УКАЗАТЕЛЯ НА НЕГО
    // ==========================================
    
    // Создаем массив из 10 элементов
    int student_scores[10]{11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    
    // Создаем указатель на массив (имя массива автоматически преобразуется в указатель)
    int* pointer_to_scores{student_scores};
    
    // ==========================================
    // 2. АДРЕСА МАССИВА И УКАЗАТЕЛЯ
    // ==========================================
    
    std::cout << "=== Адреса массива и указателя ===" << std::endl;
    std::cout << "Адрес массива (student_scores): " << student_scores << std::endl;
    std::cout << "Адрес в указателе (pointer_to_scores): " << pointer_to_scores << std::endl;
    std::cout << "Адрес первого элемента (&student_scores[0]): " << &student_scores[0] << std::endl;
    std::cout << std::endl;
    
    // ==========================================
    // 3. ДОСТУП К ДАННЫМ ЧЕРЕЗ МАССИВ И УКАЗАТЕЛЬ
    // ==========================================
    
    std::cout << "=== Доступ к данным через массив и указатель ===" << std::endl;
    std::cout << "Первый элемент через разыменование массива (*student_scores): " << *student_scores << std::endl;
    std::cout << "Первый элемент через индексацию (student_scores[0]): " << student_scores[0] << std::endl;
    std::cout << "Первый элемент через разыменование указателя (*pointer_to_scores): " << *pointer_to_scores << std::endl;
    std::cout << "Первый элемент через индексацию указателя (pointer_to_scores[0]): " << pointer_to_scores[0] << std::endl;
    std::cout << std::endl;
    
    // ==========================================
    // 4. ДОСТУП К РАЗЛИЧНЫМ ЭЛЕМЕНТАМ МАССИВА
    // ==========================================
    
    std::cout << "=== Доступ к различным элементам массива ===" << std::endl;
    std::cout << "Элементы массива через индексацию:" << std::endl;
    for (int i = 0; i < 5; ++i) {
        std::cout << "student_scores[" << i << "] = " << student_scores[i] << std::endl;
    }
    
    std::cout << std::endl << "Элементы массива через указатель:" << std::endl;
    for (int i = 0; i < 5; ++i) {
        std::cout << "*(pointer_to_scores + " << i << ") = " << *(pointer_to_scores + i) << std::endl;
    }
    std::cout << std::endl;
    
    // ==========================================
    // 5. РАЗЛИЧИЯ МЕЖДУ МАССИВОМ И УКАЗАТЕЛЕМ
    // ==========================================
    
    std::cout << "=== Различия между массивом и указателем ===" << std::endl;
    
    int single_number{21};
    pointer_to_scores = &single_number;  // Указатель можно перенаправить на другую переменную
    
    std::cout << "После перенаправления указателя:" << std::endl;
    std::cout << "Адрес в указателе: " << pointer_to_scores << std::endl;
    std::cout << "Значение через указатель: " << *pointer_to_scores << std::endl;
    std::cout << std::endl;
    
    // Попытка перенаправить имя массива вызовет ошибку компиляции:
    std::cout << "Попытка перенаправить имя массива (ОШИБКА КОМПИЛЯЦИИ):" << std::endl;
    // student_scores = &single_number;  // ОШИБКА: несовместимые типы в присваивании
    std::cout << "Имя массива - это специальный указатель, который идентифицирует весь массив" << std::endl;
    std::cout << "Его нельзя перенаправить на другую переменную" << std::endl;
    std::cout << std::endl;
    
    // ==========================================
    // 6. РАЗМЕР МАССИВА И УКАЗАТЕЛЯ
    // ==========================================
    
    std::cout << "=== Размер массива и указателя ===" << std::endl;
    
    // std::size() работает только с массивами, но не с указателями
    std::cout << "Размер массива (std::size(student_scores)): " << std::size(student_scores) << std::endl;
    
    // Попытка использовать std::size() с указателем вызовет ошибку компиляции:
    std::cout << "Попытка получить размер указателя (ОШИБКА КОМПИЛЯЦИИ):" << std::endl;
    // std::cout << "Размер указателя: " << std::size(pointer_to_scores) << std::endl;  // ОШИБКА
    std::cout << "std::size() не работает с обычными указателями" << std::endl;
    std::cout << std::endl;
    
    // ==========================================
    // 7. ДОПОЛНИТЕЛЬНЫЕ ПРИМЕРЫ АРИФМЕТИКИ УКАЗАТЕЛЕЙ
    // ==========================================
    
    std::cout << "=== Арифметика указателей ===" << std::endl;
    
    // Возвращаем указатель на массив для демонстрации
    pointer_to_scores = student_scores;
    
    std::cout << "Демонстрация арифметики указателей:" << std::endl;
    std::cout << "pointer_to_scores[0] = " << pointer_to_scores[0] << std::endl;
    std::cout << "pointer_to_scores[1] = " << pointer_to_scores[1] << std::endl;
    std::cout << "pointer_to_scores[2] = " << pointer_to_scores[2] << std::endl;
    
    // Инкремент указателя
    ++pointer_to_scores;
    std::cout << "После ++pointer_to_scores:" << std::endl;
    std::cout << "*pointer_to_scores = " << *pointer_to_scores << std::endl;
    
    return 0;
}