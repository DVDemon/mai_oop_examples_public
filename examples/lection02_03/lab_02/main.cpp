#include <iostream>
#include "dasharray.h"

// Лабораторная работа 2: Демонстрация класса DashArray
// Показывает различные конструкторы, включая перемещающий конструктор
// Демонстрирует Правило пяти (Rule of Five) для управления ресурсами

int main() {
    std::cout << "=== Лабораторная работа 2: Класс DashArray ===" << std::endl;
    
    // === ДЕМОНСТРАЦИЯ РАЗЛИЧНЫХ КОНСТРУКТОРОВ ===
    
    std::cout << "\n--- Создание объектов с помощью различных конструкторов ---" << std::endl;
    
    // Конструктор из списка инициализации
    DashArray firstArray{'1', '1', '1', '1', '1', '1', '1'};
    std::cout << "Первый массив: ";
    firstArray.print(std::cout) << std::endl;

    // Конструктор из списка инициализации (короткий массив)
    DashArray secondArray{'1', '1', '1'};
    std::cout << "Второй массив: ";
    secondArray.print(std::cout) << std::endl;

    // === ДЕМОНСТРАЦИЯ ОПЕРАЦИЙ ===
    
    std::cout << "\n--- Операции с массивами ---" << std::endl;
    
    // Сложение массивов (создает новый массив)
    DashArray thirdArray(firstArray.add(secondArray));
    std::cout << "Результат сложения: ";
    thirdArray.print(std::cout) << std::endl;

    // === ДЕМОНСТРАЦИЯ ПЕРЕМЕЩАЮЩЕГО КОНСТРУКТОРА ===
    
    std::cout << "\n--- Перемещающий конструктор ---" << std::endl;
    
    // Перемещающий конструктор - "крадет" ресурсы у thirdArray
    DashArray fourthArray(std::move(thirdArray));
    std::cout << "Четвертый массив (после перемещения): ";
    fourthArray.print(std::cout) << std::endl;
    
    // thirdArray теперь в неопределенном состоянии (но безопасном)

    // Временный объект для демонстрации
    DashArray tempArray(DashArray{'1', '1', '1', '1', '1', '1', '1'});

    // === ДЕМОНСТРАЦИЯ ОБРАБОТКИ ИСКЛЮЧЕНИЙ ===
    
    std::cout << "\n--- Обработка исключений ---" << std::endl;

    try {
        // Успешное вычитание
        DashArray fifthArray = fourthArray.remove(secondArray);
        std::cout << "Результат вычитания (успешно): ";
        fifthArray.print(std::cout) << std::endl;

        // Попытка вычитания, которое приведет к исключению
        DashArray sixthArray = secondArray.remove(fourthArray);
        std::cout << "Результат вычитания (не должно выполниться): ";
        sixthArray.print(std::cout) << std::endl;

    } catch (std::exception& exception) {
        std::cerr << "Перехвачено исключение: " << exception.what() << std::endl;
    }

    std::cout << "\n--- Выход из main() - вызов деструкторов ---" << std::endl;
    
    // Деструкторы вызываются в обратном порядке создания:
    // tempArray → fourthArray → secondArray → firstArray
    
    std::cout << "\n=== Лабораторная работа завершена ===" << std::endl;
    
    return 0;  // Исправлено: возвращаем 0 вместо 1
}