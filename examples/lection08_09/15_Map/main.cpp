#include <iostream>
#include <map>
#include <string>

/**
 * Демонстрация уникальности ключей в std::map
 * Показывает, что map не позволяет дубликаты ключей и различные способы вставки
 */
void testKeyUniqueness() {
    std::cout << "\n=== ТЕСТ УНИКАЛЬНОСТИ КЛЮЧЕЙ В STD::MAP ===" << std::endl;

    std::map<int, std::string> person_map;

    // ========================================================================
    // ПЕРВАЯ ПОПЫТКА ВСТАВКИ ПАРЫ КЛЮЧ-ЗНАЧЕНИЕ
    // ========================================================================
    std::cout << "1. Первая попытка вставки пары (42, \"Petia\"):" << std::endl;
    auto insertion_result = person_map.insert(std::make_pair(42, "Petia"));
    std::cout << "   Ключ: " << insertion_result.first->first 
              << ", Значение: " << insertion_result.first->second 
              << ", Вставлен: " << (insertion_result.second ? "ДА" : "НЕТ") << std::endl;

    // ========================================================================
    // ВТОРАЯ ПОПЫТКА ВСТАВКИ С ТЕМ ЖЕ КЛЮЧОМ
    // ========================================================================
    std::cout << "2. Вторая попытка вставки пары (42, \"Vasia\"):" << std::endl;
    insertion_result = person_map.insert(std::make_pair(42, "Vasia"));
    std::cout << "   Ключ: " << insertion_result.first->first 
              << ", Значение: " << insertion_result.first->second 
              << ", Вставлен: " << (insertion_result.second ? "ДА" : "НЕТ") << std::endl;
    
    std::cout << "   ВЫВОД: std::map не позволяет дубликаты ключей!" << std::endl;

    // ========================================================================
    // ПЕРЕЗАПИСЬ ЗНАЧЕНИЯ ЧЕРЕЗ ОПЕРАТОР []
    // ========================================================================
    std::cout << "3. Перезапись значения через оператор []:" << std::endl;
    person_map[42] = "Kuzia";
    std::cout << "   Ключ 42 теперь имеет значение: " << person_map[42] << std::endl;
    std::cout << "   ВЫВОД: Оператор [] перезаписывает существующие значения!" << std::endl;
}

/**
 * Демонстрация автоматической сортировки в std::map
 * Показывает, что элементы автоматически упорядочиваются по ключам
 */
void testAutomaticSorting() {
    std::cout << "\n=== ТЕСТ АВТОМАТИЧЕСКОЙ СОРТИРОВКИ В STD::MAP ===" << std::endl;

    std::map<std::string, int> person_age_map = {
        {"Vasia", 10},
        {"Petia", 42},
        {"Marina", 17},
        {"Mike", 22},
        {"Alex", 1}
    };

    // ========================================================================
    // ВЫВОД ТОЛЬКО КЛЮЧЕЙ В ОТСОРТИРОВАННОМ ПОРЯДКЕ
    // ========================================================================
    std::cout << "1. Ключи в отсортированном порядке:" << std::endl;
    for (auto& key_value_pair : person_age_map) {
        std::cout << "   " << key_value_pair.first << std::endl;
    }

    // ========================================================================
    // ВЫВОД КЛЮЧЕЙ И ЗНАЧЕНИЙ С ИСПОЛЬЗОВАНИЕМ STRUCTURED BINDING (C++17)
    // ========================================================================
    std::cout << "2. Пары ключ-значение в отсортированном порядке:" << std::endl;
    for (auto& [key, value] : person_age_map) {
        std::cout << "   " << key << " -> " << value << std::endl;
    }
    
    std::cout << "   ВЫВОД: std::map автоматически сортирует элементы по ключам!" << std::endl;
}

/**
 * Демонстрация работы с итераторами std::map
 * Показывает поиск элементов, двунаправленные итераторы и лямбда-функции
 */
void testIteratorOperations() {
    std::cout << "\n=== ТЕСТ ОПЕРАЦИЙ С ИТЕРАТОРАМИ STD::MAP ===" << std::endl;

    std::map<std::string, int> word_number_map = {
        {"Alpha", 1},
        {"Bravo", 2},
        {"Charlie", 3},
        {"Delta", 4},
        {"Echo", 5}
    };

    // ========================================================================
    // ЛЯМБДА-ФУНКЦИЯ ДЛЯ БЕЗОПАСНОГО ПОЛУЧЕНИЯ ЗНАЧЕНИЙ
    // ========================================================================
    std::cout << "1. Безопасное получение значений через лямбда-функцию:" << std::endl;
    auto get_from_map = [&word_number_map](const auto& key) {
        auto iterator = word_number_map.find(key);
        return iterator == std::end(word_number_map) ? 0 : iterator->second;
    };

    std::cout << "   Поиск \"Alph\": " << get_from_map("Alph") << std::endl;
    std::cout << "   Поиск \"Alpha\": " << get_from_map("Alpha") << std::endl;

    // ========================================================================
    // ОСНОВНЫЕ ОПЕРАЦИИ С ДВУНАПРАВЛЕННЫМИ ИТЕРАТОРАМИ
    // ========================================================================
    std::cout << "2. Базовые операции с двунаправленными итераторами:" << std::endl;
    auto current_iterator = word_number_map.begin();
    std::cout << "   Первый элемент: " << current_iterator->first 
              << " -> " << current_iterator->second << std::endl;

    // Перемещение вперед
    ++current_iterator;
    std::cout << "   Следующий элемент: " << current_iterator->first 
              << " -> " << current_iterator->second << std::endl;

    // Перемещение назад (двунаправленные итераторы)
    --current_iterator;
    std::cout << "   Предыдущий элемент: " << current_iterator->first 
              << " -> " << current_iterator->second << std::endl;

    // ========================================================================
    // ПОИСК ЭЛЕМЕНТОВ В MAP
    // ========================================================================
    std::cout << "3. Поиск элементов в map:" << std::endl;
    auto search_iterator = word_number_map.find("Alpha");
    if (search_iterator != std::end(word_number_map)) {
        std::cout << "   Найден: " << search_iterator->first 
                  << " -> " << search_iterator->second << std::endl;
    } else {
        std::cout << "   Элемент не найден" << std::endl;
    }

    // ========================================================================
    // ОГРАНИЧЕНИЯ ДВУНАПРАВЛЕННЫХ ИТЕРАТОРОВ
    // ========================================================================
    std::cout << "4. Ограничения двунаправленных итераторов:" << std::endl;
    std::cout << "   - НЕТ оператора += (прямое перемещение)" << std::endl;
    std::cout << "   - ЕСТЬ операторы ++ и -- (пошаговое перемещение)" << std::endl;
    
    // Закомментированная операция, которая НЕ РАБОТАЕТ:
    // current_iterator += 3;  // ОШИБКА КОМПИЛЯЦИИ!
    
    // Альтернатива для перемещения на несколько позиций
    std::advance(current_iterator, 2);
    std::cout << "   Элемент через 2 позиции (std::advance): " 
              << current_iterator->first << " -> " << current_iterator->second << std::endl;
}

/**
 * Основная функция - демонстрация std::map
 * Показывает уникальность ключей, автоматическую сортировку и работу с итераторами
 */
int main() {
    std::cout << "=== ДЕМОНСТРАЦИЯ STD::MAP ===" << std::endl;

    // Тест 1: Уникальность ключей
    testKeyUniqueness();
    
    // Тест 2: Автоматическая сортировка
    testAutomaticSorting();
    
    // Тест 3: Операции с итераторами
    testIteratorOperations();

    std::cout << "\n=== ДЕМОНСТРАЦИЯ ЗАВЕРШЕНА ===" << std::endl;
    return 0;
}