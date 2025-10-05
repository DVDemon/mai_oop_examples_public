#include <iostream>

// Математическая константа π (пи)
const double PI {3.1415926535897932384626433832795};

class Cylinder {
public:
    // === КОНСТРУКТОРЫ ===
    
    // Конструктор по умолчанию (без параметров)
    Cylinder() {
        baseRadius = 2.0;  // Устанавливаем радиус по умолчанию
        height = 2.0;      // Устанавливаем высоту по умолчанию
    }

    // Параметризованный конструктор (с параметрами)
    Cylinder(double radiusValue, double heightValue) {
        baseRadius = radiusValue;   // Инициализируем радиус переданным значением
        height = heightValue;       // Инициализируем высоту переданным значением
    }
   
    // === МЕТОДЫ ===
    
    // Метод для вычисления объема цилиндра
    double calculateVolume() const {
        // Формула объема: V = π × r² × h
        return PI * baseRadius * baseRadius * height;
    }

private:
    // === ДАННЫЕ-ЧЛЕНЫ ===
    
    double baseRadius{};  // Радиус основания цилиндра
    double height{};      // Высота цилиндра
};

int main() {
    // Демонстрация различных способов создания объектов
    
    // Создание объекта с помощью конструктора по умолчанию
    Cylinder defaultCylinder;

    std::cout << "Объем цилиндра (конструктор по умолчанию): " 
              << defaultCylinder.calculateVolume() << std::endl;

    // Создание объекта с помощью параметризованного конструктора
    Cylinder customCylinder(10.0, 4.0);  // Раскомментируйте для демонстрации
    std::cout << "Объем цилиндра (параметризованный конструктор): " 
              << customCylinder.calculateVolume() << std::endl;

    return 0;
}