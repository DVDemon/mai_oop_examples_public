#include <iostream>
#include <string>
#include <unordered_set>
#include <random>

/**
 * Демонстрация уникальности элементов в std::unordered_set
 * Показывает, что unordered_set не позволяет дубликаты и использует хеширование
 */
void testElementUniqueness() {
    std::cout << "\n=== ТЕСТ УНИКАЛЬНОСТИ ЭЛЕМЕНТОВ В STD::UNORDERED_SET ===" << std::endl;

    std::unordered_set<int> integer_hash_set;

    // ========================================================================
    // ПЕРВАЯ ПОПЫТКА ВСТАВКИ ЭЛЕМЕНТА
    // ========================================================================
    std::cout << "1. Первая попытка вставки элемента 42:" << std::endl;
    auto insertion_result = integer_hash_set.insert(42);
    std::cout << "   Элемент: " << *insertion_result.first 
              << ", Вставлен: " << (insertion_result.second ? "ДА" : "НЕТ") << std::endl;

    // ========================================================================
    // ВТОРАЯ ПОПЫТКА ВСТАВКИ ТОГО ЖЕ ЭЛЕМЕНТА
    // ========================================================================
    std::cout << "2. Вторая попытка вставки элемента 42:" << std::endl;
    insertion_result = integer_hash_set.insert(42);
    std::cout << "   Элемент: " << *insertion_result.first 
              << ", Вставлен: " << (insertion_result.second ? "ДА" : "НЕТ") << std::endl;
    
    std::cout << "   ВЫВОД: std::unordered_set не позволяет дубликаты!" << std::endl;
    std::cout << "   ВЫВОД: Использует хеширование для быстрого поиска!" << std::endl;
}

/**
 * Демонстрация отсутствия сортировки в std::unordered_set
 * Показывает, что элементы не упорядочиваются и выводятся в произвольном порядке
 */
void testNoAutomaticSorting() {
    std::cout << "\n=== ТЕСТ ОТСУТСТВИЯ АВТОМАТИЧЕСКОЙ СОРТИРОВКИ В STD::UNORDERED_SET ===" << std::endl;

    // ========================================================================
    // ГЕНЕРАЦИЯ СЛУЧАЙНЫХ ЧИСЕЛ
    // ========================================================================
    std::cout << "1. Генерация случайных чисел:" << std::endl;
    std::unordered_set<int> random_integer_set;
    
    // Инициализация генератора случайных чисел
    std::random_device random_device;
    std::mt19937 random_generator(random_device());
    std::uniform_int_distribution<int> distribution(0, 99);
    
    for (int generation_index = 0; generation_index < 10; ++generation_index) {
        int random_number = distribution(random_generator);
        random_integer_set.insert(random_number);
    }

    std::cout << "   Сгенерированные числа (в порядке вставки): ";
    for (int generation_index = 0; generation_index < 10; ++generation_index) {
        int random_number = distribution(random_generator);
        std::cout << random_number << " ";
    }
    std::cout << std::endl;

    // ========================================================================
    // ВЫВОД ЭЛЕМЕНТОВ В ПРОИЗВОЛЬНОМ ПОРЯДКЕ
    // ========================================================================
    std::cout << "2. Элементы в unordered_set (произвольный порядок):" << std::endl;
    std::cout << "   ";
    for (const auto& element : random_integer_set) {
        std::cout << element << " ";
    }
    std::cout << std::endl;
    std::cout << "   ВЫВОД: Порядок элементов НЕ соответствует порядку вставки!" << std::endl;

    // ========================================================================
    // ДЕМОНСТРАЦИЯ С СТРОКАМИ
    // ========================================================================
    std::cout << "3. Демонстрация со строками:" << std::endl;
    std::unordered_set<std::string> string_hash_set = {"AAA", "CCC", "BBB", "DDDD"};
    
    std::cout << "   Исходный порядок: AAA, CCC, BBB, DDDD" << std::endl;
    std::cout << "   Порядок в unordered_set: ";
    for (const auto& string_element : string_hash_set) {
        std::cout << string_element << " ";
    }
    std::cout << std::endl;
    std::cout << "   ВЫВОД: std::unordered_set НЕ сортирует элементы!" << std::endl;
    std::cout << "   ВЫВОД: Порядок зависит от хеш-функции и внутренней структуры!" << std::endl;
}

/**
 * Основная функция - демонстрация std::unordered_set
 * Показывает уникальность элементов и отсутствие сортировки
 */
int main() {
    std::cout << "=== ДЕМОНСТРАЦИЯ STD::UNORDERED_SET ===" << std::endl;

    // Тест 1: Уникальность элементов
    testElementUniqueness();
    
    // Тест 2: Отсутствие автоматической сортировки
    testNoAutomaticSorting();

    std::cout << "\n=== ДЕМОНСТРАЦИЯ ЗАВЕРШЕНА ===" << std::endl;
    return 0;
}