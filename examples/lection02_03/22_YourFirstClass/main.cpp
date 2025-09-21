#include <iostream>

// Математическая константа π (пи)
const double PI {3.1415926535897932384626433832795};

// Первый класс: Цилиндр
// Демонстрирует основные концепции ООП: инкапсуляцию и методы
class Cylinder {
public:
    // Метод класса - функция, которая работает с данными объекта
    double calculateVolume() const {
        // Формула объема цилиндра: V = π × r² × h
        return PI * baseRadius * baseRadius * height;
    }

    // Данные-члены класса (атрибуты объекта)
    double baseRadius{1.0};  // Радиус основания (по умолчанию 1)
    double height{1.0};      // Высота цилиндра (по умолчанию 1)
};

int main() {
    // Создание объекта класса Cylinder
    Cylinder myCylinder;
    
    // Вызов метода для вычисления объема
    std::cout << "Объем цилиндра по умолчанию: " << myCylinder.calculateVolume() << std::endl;

    // Изменение данных-членов объекта
    myCylinder.baseRadius = 10.0;  // Устанавливаем радиус = 10
    myCylinder.height = 3.0;       // Устанавливаем высоту = 3

    std::cout << "Объем после изменения размеров: " << myCylinder.calculateVolume() << std::endl;

    // Изменение только высоты
    myCylinder.height = 8.0;       // Новая высота = 8

    std::cout << "Объем с новой высотой: " << myCylinder.calculateVolume() << std::endl;
   
    return 0;
}