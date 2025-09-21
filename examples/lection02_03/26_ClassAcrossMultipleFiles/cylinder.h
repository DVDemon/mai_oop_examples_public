#ifndef CYLINDER_H
#define CYLINDER_H

#include "constants.h"

// Класс Cylinder - демонстрация разделения на заголовочный файл и реализацию
// Представляет геометрическую фигуру цилиндр с методами для вычисления объема
class Cylinder {
public:
    // === КОНСТРУКТОРЫ ===
    
    // Конструктор по умолчанию (автоматически генерируется компилятором)
    Cylinder() = default;
    
    // Параметризованный конструктор
    // Объявление в заголовочном файле, реализация в .cpp файле
    Cylinder(double radiusValue, double heightValue);
    
    // === ОСНОВНЫЕ МЕТОДЫ ===
    
    // Метод для вычисления объема цилиндра
    // Объявление в заголовочном файле, реализация в .cpp файле
    double calculateVolume();
    
    // === ГЕТТЕРЫ (GETTERS) ===
    
    // Геттер для радиуса основания
    double getRadius();
    
    // Геттер для высоты цилиндра
    double getHeight();
    
    // === СЕТТЕРЫ (SETTERS) ===
    
    // Сеттер для радиуса основания
    void setRadius(double radiusValue);
    
    // Сеттер для высоты цилиндра
    void setHeight(double heightValue);

private:
    // === ДАННЫЕ-ЧЛЕНЫ ===
    
    double baseRadius{1.0};  // Радиус основания цилиндра (по умолчанию 1.0)
    double height{1.0};      // Высота цилиндра (по умолчанию 1.0)
};

#endif // CYLINDER_H
