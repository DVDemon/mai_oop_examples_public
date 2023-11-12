// Посетитель (Visitor)

#include <iostream>
#include <vector>

class DrawPrimitive {
public:
    virtual void save_to_file(class Export *) = 0;
};

class Circle : public DrawPrimitive {
public:
    int radius;

    Circle(int radius_) : radius(radius_) {};

    void save_to_file(class Export *) override;
};

class Box : public DrawPrimitive {
public:
    int w;
    int h;

    Box(int w_, int h_) : w(w_), h(h_) {};

    void save_to_file(class Export *) override;
};

class Export {
public:
    virtual void save_to(Circle *) = 0;

    virtual void save_to(Box *) = 0;
};

class JsonExport : public Export {
public:
    void save_to(Circle *c) override {
        std::cout << "{type:circle,radius:" << c->radius << "}" << std::endl;
    }

    void save_to(Box *b) override {
        std::cout << "{type:box,width:" << b->w << ",height:" << b->h << "}" << std::endl;
    }
};

class XmlExport : public Export {
public:
    void save_to(Circle *c) override {
        std::cout << "<circle radius=>" << c->radius << "</circle>" << std::endl;
    }

    void save_to(Box *b) override {
        std::cout << "<box w=" << b->w << " height=" << b->h << "></box>" << std::endl;
    }
};

void Circle::save_to_file(Export *v) {
    v->save_to(this);
}

void Box::save_to_file(Export *v) {
    v->save_to(this);
}

int main(int, char *[]) {
    std::vector<DrawPrimitive *> doc = {new Circle{100}, new Box{4, 3}, new Box{16, 9}, new Circle{13}, new Circle{2}};

    Export *exporter = new JsonExport{};
    for (auto obj : doc) {
        obj->save_to_file(exporter);
    }

    exporter = new XmlExport{};
    for (auto obj : doc) {
        obj->save_to_file(exporter);
    }

    return 0;
}
