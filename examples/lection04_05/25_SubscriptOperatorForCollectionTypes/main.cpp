#include <iostream>
#include "scores.h"

int main() {
    // ДЕМОНСТРАЦИЯ ПЕРЕГРУЗКИ ОПЕРАТОРА [] ДЛЯ КОЛЛЕКЦИЙ
    // с const и не-const версиями
    
    std::cout << "=== Демонстрация оператора [] для коллекций ===" << std::endl;
    
    // Создание объекта Scores
    Scores math_scores("Math");
    
    std::cout << "--- Исходное состояние оценок ---" << std::endl;
    math_scores.print_info();
    
    std::cout << "\n--- Заполнение массива оценок через оператор [] ---" << std::endl;
    
    // ДЕМОНСТРАЦИЯ 1: Заполнение массива через не-const версию оператора []
    // Вызывается не-const версия, возвращающая ссылку для записи
    for (size_t i{}; i < 20; ++i) {
        if (i == 0) {
            // Первая оценка - базовое значение
            math_scores[0] = 73.7;
        } else {
            // Последующие оценки - увеличение на 0.56
            math_scores[i] = math_scores[i - 1] + 0.56;
        }
    }
    
    std::cout << "\n--- Состояние оценок после заполнения ---" << std::endl;
    math_scores.print_info();
    
    std::cout << "\n" << "------" << std::endl;
    
    std::cout << "\n--- Демонстрация const версии оператора [] ---" << std::endl;
    
    // ДЕМОНСТРАЦИЯ 2: Работа с константным объектом
    // Создаем константный объект - может вызывать только const методы
    const Scores geography_scores("Geography");
    
    // При обращении к константному объекту вызывается const версия оператора []
    // Выводится "Calling const operator[] (value version)"
    std::cout << "Reading from const object - geo[3]: " << geography_scores[3] << std::endl;
    
    std::cout << "\n--- Дополнительные примеры использования ---" << std::endl;
    
    // ДЕМОНСТРАЦИЯ 3: Сравнение const и не-const версий
    std::cout << "Reading from non-const object:" << std::endl;
    double math_grade = math_scores[5];  // Вызывается не-const версия
    
    std::cout << "Reading from const object:" << std::endl;
    double geo_grade = geography_scores[5];  // Вызывается const версия
    
    std::cout << "Math grade[5]: " << math_grade << std::endl;
    std::cout << "Geography grade[5]: " << geo_grade << std::endl;
    
    std::cout << "\n--- Демонстрация записи через не-const версию ---" << std::endl;
    
    // ДЕМОНСТРАЦИЯ 4: Изменение значения через не-const версию
    std::cout << "Modifying grade through non-const operator[]:" << std::endl;
    math_scores[10] = 95.5;  // Вызывается не-const версия для записи
    
    std::cout << "Modified math_scores[10]: " << math_scores[10] << std::endl;
    
    std::cout << "\n=== Важные выводы ===" << std::endl;
    std::cout << "1. Две версии оператора []: const и не-const" << std::endl;
    std::cout << "2. Не-const версия возвращает ссылку для записи" << std::endl;
    std::cout << "3. Const версия возвращает значение для только чтения" << std::endl;
    std::cout << "4. Константные объекты могут вызывать только const версии" << std::endl;
    std::cout << "5. Компилятор автоматически выбирает нужную версию" << std::endl;
    
    std::cout << "\n=== Преимущества двойной перегрузки ===" << std::endl;
    std::cout << "1. Безопасность - const объекты защищены от изменения" << std::endl;
    std::cout << "2. Эффективность - const версия может быть оптимизирована" << std::endl;
    std::cout << "3. Гибкость - работа как с изменяемыми, так и с константными объектами" << std::endl;
    std::cout << "4. Совместимость с STL - стандартные контейнеры используют тот же подход" << std::endl;
    
    std::cout << "\n=== Программа завершается ===" << std::endl;
    
    return 0;
}