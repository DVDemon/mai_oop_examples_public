#include <iostream>

// Математическая константа π (пи)
const double PI {3.1415926535897932384626433832795};

class Cylinder {
public:
    // === КОНСТРУКТОРЫ ===
    
    // Defaulted конструктор
    Cylinder() = default;
    
    // Параметризованный конструктор
    Cylinder(double radiusValue, double heightValue) {
        baseRadius = radiusValue;
        height = heightValue;
    }
    
    // === ОСНОВНЫЕ МЕТОДЫ ===
    
    // Метод для вычисления объема цилиндра
    double calculateVolume() const {
        // Формула объема: V = π × r² × h
        return PI * baseRadius * baseRadius * height;
    }
    
    // === ГЕТТЕРЫ (GETTERS) ===
    
    // Геттер для радиуса - возвращает копию значения
    double getRadius() const {
        return baseRadius;
    }

    // Геттер для высоты - возвращает копию значения
    double getHeight() const {
        return height;
    }

    // === ОПАСНЫЙ МЕТОД - ВОЗВРАТ ССЫЛКИ ===
    
    // ВНИМАНИЕ: Этот метод нарушает инкапсуляцию!
    // Возвращает ссылку, позволяя напрямую изменять приватные данные
    double& getRadiusReference() {
        return baseRadius;  // Опасный подход!
    }

    // === СЕТТЕРЫ (SETTERS) ===
    
    // Сеттер для радиуса с проверкой (правильный подход)
    void setRadius(double newRadius) {
        if (newRadius >= 0) {  // Простая валидация
            baseRadius = newRadius;
        }
        // Можно добавить обработку ошибок для отрицательных значений
    }

    // Сеттер для высоты с проверкой
    void setHeight(double newHeight) {
        if (newHeight >= 0) {  // Простая валидация
            height = newHeight;
        }
    }

private:
    // === ДАННЫЕ-ЧЛЕНЫ ===
    
    double baseRadius{1.0};  // Радиус основания (по умолчанию 1.0)
    double height{1.0};      // Высота цилиндра (по умолчанию 1.0)
};

int main() {
    // Создание объекта с параметрами
    Cylinder myCylinder(10.0, 10.0);
    std::cout << "Объем цилиндра (начальный): " << myCylinder.calculateVolume() << std::endl;

    // === ДЕМОНСТРАЦИЯ РАЗЛИЧНЫХ СПОСОБОВ ДОСТУПА ===
    
    // Способ 1: Использование сеттеров (рекомендуемый подход)
    myCylinder.setRadius(100.0);
    myCylinder.setHeight(10.0);
    
    // Способ 2: Опасный способ через ссылку (НЕ рекомендуется!)
    // myCylinder.getRadiusReference() = 100.0;  // Нарушает инкапсуляцию
    
    std::cout << "Объем цилиндра (после изменения): " << myCylinder.calculateVolume() << std::endl;
    
    // Демонстрация геттеров
    std::cout << "Текущий радиус: " << myCylinder.getRadius() << std::endl;
    std::cout << "Текущая высота: " << myCylinder.getHeight() << std::endl;

    return 0;
}