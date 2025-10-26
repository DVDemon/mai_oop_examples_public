#include <iostream>

/**
 * Функция для вывода пары значений
 * Используется как callback в демонстрации функционального программирования
 */
static void printPair(int first_value, int second_value) {
    std::cout << "(" << first_value << ", " << second_value << ")\n";
}

/**
 * Основная функция - демонстрация продвинутых возможностей C++
 * Показывает использование variadic templates, лямбда-функций и функционального программирования
 */
int main() {
    std::cout << "=== ДЕМОНСТРАЦИЯ ПРОДВИНУТЫХ ВОЗМОЖНОСТЕЙ C++ ===" << std::endl;
    
    // ========================================================================
    // ЛЯМБДА-ФУНКЦИЯ ДЛЯ ВЫЗОВА CARTESIAN PRODUCT
    // ========================================================================
    constexpr auto callCartesianProduct =
        // Лямбда с параметрами: функция, условие, первый элемент и остальные элементы
        [](auto function_to_call, auto condition_function, auto first_element, auto... remaining_elements) constexpr {
            // Отладочный вывод (закомментирован для чистоты вывода)
            // std::cout << "call_cart for " << first_element << " with " << sizeof...(remaining_elements) << " elements" << std::endl;
            
            // Используем initializer_list для итерации по параметрам
            // Вызываем функцию для всех пар, где условие истинно
            (void)std::initializer_list<int>{
                ((condition_function(first_element, remaining_elements)
                      ? (void)function_to_call(first_element, remaining_elements)
                      : (void)0),
                 0)...}; 
            std::cout << std::endl;
        };

    // ========================================================================
    // ФУНКЦИЯ ДЛЯ СОЗДАНИЯ CARTESIAN PRODUCT
    // ========================================================================
    constexpr auto createCartesianProduct =
        [=](auto... input_values) constexpr {
            // Возвращаем лямбду, которая принимает функцию и условие
            return [=](auto function_to_call, auto condition_function) constexpr {
                // Используем initializer_list для развертывания функции
                // Первый параметр - функция, которую будем вызывать для пар
                // Второй параметр - функция условия (нужно ли вызывать первую функцию)
                // Перебираем все входные значения и создаем пары
                (void)std::initializer_list<int>{
                    ((void)callCartesianProduct(function_to_call, condition_function, input_values, input_values...), 0)...};
            };
        };

    // ========================================================================
    // ДЕМОНСТРАЦИЯ: СОЗДАНИЕ CARTESIAN PRODUCT ДЛЯ ЧИСЕЛ 1-6
    // ========================================================================
    constexpr auto cartesian_product_1_to_6 = createCartesianProduct(1, 2, 3, 4, 5, 6);
    
    std::cout << "Декартово произведение с условием (первое > второе):" << std::endl;
    cartesian_product_1_to_6(
        [](auto left_hand_value, auto right_hand_value) { 
            std::cout << '(' << left_hand_value << ',' << right_hand_value << ')'; 
        },
        [](auto left_hand_value, auto right_hand_value) { 
            return left_hand_value > right_hand_value; 
        }
    );

    // Альтернативный пример (закомментирован):
    // std::cout << "Декартово произведение без условий:" << std::endl;
    // cartesian_product_1_to_6(
    //     [](auto left_hand_value, auto right_hand_value) { 
    //         std::cout << '(' << left_hand_value << ',' << right_hand_value << ')'; 
    //     },
    //     [](auto left_hand_value, auto right_hand_value) { 
    //         return true; 
    //     }
    // );
}