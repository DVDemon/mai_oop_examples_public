#include <iostream>

// Математическая константа π (пи)
const double PI {3.1415926535897932384626433832795};

class Cylinder {
public:
    // === КОНСТРУКТОРЫ ===
    
    // Defaulted конструктор - компилятор генерирует реализацию автоматически
    // Использует значения инициализации данных-членов: {} означает 0.0
    Cylinder() = default;

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
    
    double baseRadius{};  // Инициализация {} означает 0.0
    double height{};      // Инициализация {} означает 0.0
};

int main() {
    // Создание объекта с помощью defaulted конструктора
    // Данные-члены будут инициализированы значением 0.0
    Cylinder defaultCylinder;
    
    std::cout << "Объем цилиндра (defaulted конструктор): " 
              << defaultCylinder.calculateVolume() << std::endl;
   
    return 0;
}