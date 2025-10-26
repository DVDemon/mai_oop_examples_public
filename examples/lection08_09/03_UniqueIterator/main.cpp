#include "square.h"
#include "list.h"
#include <iostream>
#include <algorithm>

/**
 * Основная функция - демонстрация пользовательского списка с двумя типами итераторов
 * Показывает работу с обычными итераторами и быстрыми итераторами
 */
auto main() -> int {
    std::cout << "=== ДЕМОНСТРАЦИЯ ПОЛЬЗОВАТЕЛЬСКОГО СПИСКА С ИТЕРАТОРАМИ ===" << std::endl;

    // ========================================================================
    // СОЗДАНИЕ И ИНИЦИАЛИЗАЦИЯ СПИСКА КВАДРАТОВ
    // ========================================================================
    List<Square<int>> square_list;

    // Создание квадратов с различными размерами
    Square<int> small_square(std::pair<int,int>(0,0), std::pair<int,int>(10,0), 
                            std::pair<int,int>(10,10), std::pair<int,int>(0,10)),
                medium_square(std::pair<int,int>(0,0), std::pair<int,int>(20,0), 
                              std::pair<int,int>(20,20), std::pair<int,int>(0,20)),
                large_square(std::pair<int,int>(0,0), std::pair<int,int>(30,0), 
                             std::pair<int,int>(30,30), std::pair<int,int>(0,30)),
                extra_large_square(std::pair<int,int>(0,0), std::pair<int,int>(40,0), 
                                  std::pair<int,int>(40,40), std::pair<int,int>(0,40));
    
    // Добавление квадратов в список
    square_list.push_back(small_square);
    square_list.push_back(medium_square);
    square_list.push_back(large_square);
    square_list.push_back(extra_large_square);

    // ========================================================================
    // ДЕМОНСТРАЦИЯ 1: ОБЫЧНАЯ ИТЕРАЦИЯ ПО СПИСКУ
    // ========================================================================
    std::cout << "1. Итерация по списку квадратов:" << std::endl;
    for (auto square : square_list) {
        std::cout << square << std::endl;
    }

    // ========================================================================
    // ДЕМОНСТРАЦИЯ 2: РАБОТА С АЛГОРИТМАМИ STL (ЗАКОММЕНТИРОВАНО)
    // ========================================================================
    // Пример использования алгоритма count_if для подсчета квадратов с площадью >= 400
    // int large_squares_count = std::count_if(square_list.begin(), square_list.end(),
    //                                         [](const auto& square) -> bool {
    //                                             std::pair<int,int> dimensions {
    //                                                 square.c.first - square.a.first,
    //                                                 square.c.second - square.a.second
    //                                             };
    //                                             return (dimensions.first * dimensions.second) >= 400;
    //                                         });
    // std::cout << "Квадратов с площадью >= 400: " << large_squares_count << std::endl;

    // ========================================================================
    // ДЕМОНСТРАЦИЯ 3: ДОСТУП К ЭЛЕМЕНТАМ ЧЕРЕЗ ИТЕРАТОР
    // ========================================================================
    std::cout << "2. Доступ к первому элементу через итератор:" << std::endl;
    std::cout << "X-координата первой вершины первого квадрата: " << square_list.begin()->a.first << std::endl;

    // ========================================================================
    // ДЕМОНСТРАЦИЯ 4: УДАЛЕНИЕ ЭЛЕМЕНТА
    // ========================================================================
    std::cout << "3. Удаление элемента (4-й элемент):" << std::endl;
    square_list.erase(std::next(square_list.begin(), 3));
    for (auto square : square_list) {
        std::cout << square << std::endl;
    }

    // ========================================================================
    // ДЕМОНСТРАЦИЯ 5: ВСТАВКА ЭЛЕМЕНТА
    // ========================================================================
    Square<int> new_square(std::pair<int,int>(10,10),
                          std::pair<int,int>(10,20),
                          std::pair<int,int>(20,20),
                          std::pair<int,int>(20,10));
    
    std::cout << "4. Вставка нового элемента:" << std::endl;
    auto inserted_iterator = square_list.insert(++++square_list.begin(), new_square);
    for (auto square : square_list) {
        std::cout << square << std::endl;
    }

    // ========================================================================
    // ДЕМОНСТРАЦИЯ 6: УДАЛЕНИЕ ВСТАВЛЕННОГО ЭЛЕМЕНТА
    // ========================================================================
    std::cout << "5. Удаление вставленного элемента:" << std::endl;
    square_list.erase(inserted_iterator);
    for (auto square : square_list) {
        std::cout << square << std::endl;
    }

    // ========================================================================
    // ДЕМОНСТРАЦИЯ 7: БЫСТРЫЕ ИТЕРАТОРЫ
    // ========================================================================
    std::cout << "6. Использование быстрых итераторов:" << std::endl;
    for (auto fast_iterator = square_list.begin_fast(); 
         fast_iterator != square_list.end_fast(); ++fast_iterator) {
        std::cout << *fast_iterator << std::endl;
    }
    
    // ========================================================================
    // ДЕМОНСТРАЦИЯ 8: СРАВНЕНИЕ ИТЕРАТОРОВ
    // ========================================================================
    std::cout << "7. Сравнение быстрых итераторов:" << std::endl;
    std::cout << "begin_fast() == begin_fast(): " << (square_list.begin_fast() == square_list.begin_fast()) << std::endl;
    std::cout << "++begin_fast() == begin_fast(): " << (++square_list.begin_fast() == square_list.begin_fast()) << std::endl;

    std::cout << "\n=== ДЕМОНСТРАЦИЯ ЗАВЕРШЕНА ===" << std::endl;
    return 0;
}