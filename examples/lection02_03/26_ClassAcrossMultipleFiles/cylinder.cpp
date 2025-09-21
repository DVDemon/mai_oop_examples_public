#include "cylinder.h"

// === РЕАЛИЗАЦИЯ КОНСТРУКТОРОВ ===

// Реализация параметризованного конструктора
// Инициализирует объект Cylinder с заданными значениями радиуса и высоты
Cylinder::Cylinder(double radiusValue, double heightValue) {
    baseRadius = radiusValue;   // Устанавливаем радиус основания
    height = heightValue;       // Устанавливаем высоту цилиндра
}

// === РЕАЛИЗАЦИЯ ОСНОВНЫХ МЕТОДОВ ===

// Реализация метода для вычисления объема цилиндра
// Использует формулу: V = π × r² × h
double Cylinder::calculateVolume() {
    return PI * baseRadius * baseRadius * height;
}

// === РЕАЛИЗАЦИЯ ГЕТТЕРОВ ===

// Реализация геттера для радиуса основания
// Возвращает копию значения радиуса
double Cylinder::getRadius() {
    return baseRadius;
}

// Реализация геттера для высоты цилиндра
// Возвращает копию значения высоты
double Cylinder::getHeight() {
    return height;
}

// === РЕАЛИЗАЦИЯ СЕТТЕРОВ ===

// Реализация сеттера для радиуса основания
// Устанавливает новое значение радиуса (без валидации в этом примере)
void Cylinder::setRadius(double radiusValue) {
    baseRadius = radiusValue;
}

// Реализация сеттера для высоты цилиндра
// Устанавливает новое значение высоты (без валидации в этом примере)
void Cylinder::setHeight(double heightValue) {
    height = heightValue;
}