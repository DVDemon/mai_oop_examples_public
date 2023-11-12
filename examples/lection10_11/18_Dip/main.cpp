#include <iostream>
#include <vector>
#include <memory>

class Menu;

// нехорошая ссылка на массив IItem*
class IItem {
protected:
    std::vector<std::shared_ptr<IItem>>* items;
public:
    virtual void print() = 0;

    void SetMenu(std::vector<std::shared_ptr<IItem>> *items) {
        this->items = items;
    }

};

class ItemBulka : public IItem {
public:

    void print() override {
        std::cout << "Item bulka" << std::endl;
    }
};

// тут есть зависимость от реализации!
class ItemCoffe : public IItem {
public:

    void print() override {
        std::cout << "Item coffe ";

        bool hasBulka = false;
        for (auto i : *items) {
            if (std::dynamic_pointer_cast<ItemBulka> (i)) {
                std::cout << " for your cookie" << std::endl;
                return;
            }
        }

        std::cout << std::endl;
    }
};



// Меню использует только абстрактный класс!
class Menu {
private:
    std::vector<std::shared_ptr<IItem>> items;
public:

    void add(std::shared_ptr<IItem> &&i) {
        items.push_back(i);
        i->SetMenu(&items);
    }

    void menu() {
        for (auto i : items) i->print();
    }

};

auto main() -> int{

    Menu m;
    
    m.add(std::make_shared<ItemBulka>());
    m.add(std::make_shared<ItemBulka>());
    m.add(std::make_shared<ItemCoffe>());
    m.add(std::make_shared<ItemCoffe>());

    m.menu();

    return 0;
}

