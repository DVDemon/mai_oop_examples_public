#pragma once
#include <string>

class Shape {
public:
    Shape(const std::string& name) : name(name) {}

    virtual ~Shape() = default;

    virtual double area() const = 0;
    virtual double perimeter() const = 0;

    std::string getName() const {
        return name;
    }

protected:
    std::string name;
};
