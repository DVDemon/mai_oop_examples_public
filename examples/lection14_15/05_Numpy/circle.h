#pragma once

#include "shape.h"

class Circle : public Shape {
public:
    Circle(double radius) : Shape("Circle"), radius(radius) {}

    double area() const override {
        return 3.14159265358979323846 * radius * radius;
    }

    double perimeter() const override {
        return 2 * 3.14159265358979323846 * radius;
    }

private:
    double radius;
};


