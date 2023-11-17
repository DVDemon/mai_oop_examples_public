#include <vector>
#include <memory>
#include <iostream>

// Forward declaration of Visitor
class Visitor;

// Abstract Element class
class Element {
public:
    virtual void accept(Visitor& visitor) = 0; // делает вызов visit не с родительским классом, а с дочерним
};

// Concrete Element classes
class ConcreteElementA : public Element {
public:
    void accept(Visitor& visitor) override; 
    void operationA() {
        std::cout << "ConcreteElementA operationA" << std::endl;
    }
};

class ConcreteElementB : public Element {
public:
    void accept(Visitor& visitor) override;
    void operationB() {
        std::cout << "ConcreteElementB operationB" << std::endl;
    }
};

// Abstract Visitor class
class Visitor {
public:
    virtual void visit(ConcreteElementA& element) = 0;
    virtual void visit(ConcreteElementB& element) = 0;
};

// Concrete Visitor classes
class ConcreteVisitor1 : public Visitor {
public:
    void visit(ConcreteElementA& element) override {
        std::cout << "ConcreteVisitor1 visits ";
        element.operationA();
    }

    void visit(ConcreteElementB& element) override {
        std::cout << "ConcreteVisitor1 visits ";
        element.operationB();
    }
};

class ConcreteVisitor2 : public Visitor {
public:
    void visit(ConcreteElementA& element) override {
        std::cout << "ConcreteVisitor2 visits ";
        element.operationA();
    }

    void visit(ConcreteElementB& element) override {
        std::cout << "ConcreteVisitor2 visits ";
        element.operationB();
    }
};

// Implement accept methods
void ConcreteElementA::accept(Visitor& visitor) {
    visitor.visit(*this);
}

void ConcreteElementB::accept(Visitor& visitor) {
    visitor.visit(*this);
}

int main() {
    std::vector<std::shared_ptr<Element>> elements;
    elements.emplace_back(std::make_unique<ConcreteElementA>());
    elements.emplace_back(std::make_unique<ConcreteElementB>());

    ConcreteVisitor1 visitor1;
    ConcreteVisitor2 visitor2;

    for (auto& element : elements) {
        element->accept(visitor1);
    }

    for (auto& element : elements) {
        element->accept(visitor2);
    }

    return 0;
}