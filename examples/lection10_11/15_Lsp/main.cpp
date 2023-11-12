#include <iostream>
#include <memory>

struct Figure {
    virtual int GetSquare() = 0;
};

class Rectangle : public Figure {
protected:
    int width;
    int height;
public:

    Rectangle(int w, int h) : width(w), height(h) {
    };

    void SetWidth(int value) {
        width = value;
    }

    void SetHeight(int value) {
        height = value;
    }

    int GetSquare() override {
        return width * height;
    }
};

class Square : public Figure {
protected:
    int size;
public:

    Square(int s) : size(s) {
    };

    void SetSize(int value)  {
        size = value;
    }

    int GetSquare() override {
        return size * size;
    }

};

auto main() -> int {
    std::shared_ptr<Rectangle> rec = std::make_shared<Rectangle>(2, 2);
    rec->SetWidth(3);
    rec->SetHeight(4);
    if (rec->GetSquare() != 12) std::cout << "Oops!" << std::endl;
                          else  std::cout << "Rectangle: ok" << std::endl;

    std::shared_ptr<Square> sqr = std::make_shared<Square>(2);
    sqr->SetSize(4);
    if (sqr->GetSquare() != 16) std::cout << "Oops!" << std::endl;
                          else  std::cout << "Square: ok" << std::endl;
    
    return 0;
}