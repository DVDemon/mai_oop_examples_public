#include <iostream>
#include <memory>

class Rectangle {
protected:
    int width;
    int height;
public:

    Rectangle(int w, int h) : width(w), height(h) {
    };

    virtual void SetWidth(int value) {
        width = value;
    }

    virtual void SetHeight(int value) {
        height = value;
    }

    virtual int GetSquare() {
        return width * height;
    }
};

struct Square :  Rectangle {
    Square(int w, int h) : Rectangle(w, w) {
    };

    void SetWidth(int value) override {
        width = value;
        height = value;
    }

    void SetHeight(int value) override {
        width = value;
        height = value;
    }

};

void foo(std::shared_ptr<Rectangle> &rec){
    //if(std::dynamic_pointer_cast<Square>(rec)) throw std::logic_error("Don't use square!");

    rec->SetWidth(3);
    rec->SetHeight(4); // rec->width=4;rec->height=4;
    if (rec->GetSquare() != 12) std::cout << "Oops!" << std::endl;
                           else std::cout << "Ok!" << std::endl;
}

auto main() -> int {
    std::shared_ptr<Rectangle> rec = 
            std::make_shared<Square>(2, 2); //std::shared_ptr<Square>
            
    foo(rec); //std::shared_ptr<Rectangle>
    
    return 0;
}