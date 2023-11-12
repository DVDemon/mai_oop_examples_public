#include <iostream>
#include <vector>
#include <memory>

class IItem;

class ISearchItem {
public:

    virtual bool isCookie() {
        return false;
    }

    virtual bool accept(IItem*) {
        return false;
    }
};

class ISearchInterface {
public:
    virtual bool SearchMenu(ISearchItem *item) = 0;
};

class IItem : public ISearchItem {
public:
    virtual void print(ISearchInterface *search) = 0;
};

class ItemBulka : public IItem {
public:

    void print(ISearchInterface *search) override {
        std::cout << "Item bulka" << std::endl;
    }

    bool isCookie() override {
        return true;
    }
};
/*
class ItemBublik : public IItem {
public:

    void print(ISearchInterface *search) override {
        std::cout << "Item bublik" << std::endl;
    }

    bool isCookie() override {
        return true;
    }
};*/

class ItemCoffe : public IItem {
public:
    void print(ISearchInterface *search) override {
        std::cout << "Item coffe ";
        if (search->SearchMenu(this))
            std::cout << " for your cookie";

        std::cout << std::endl;
    }

    bool accept(IItem* ptr) override {
        return ptr->isCookie();
    }
};

class Menu : public ISearchInterface {
private:
    std::vector<std::shared_ptr<IItem>> items;
public:

    bool SearchMenu(ISearchItem *item) override {
        for (auto i : items)
            if (item->accept(i.get())) return true;
        return false;
    }

    void add(std::shared_ptr<IItem> &&i) {
        items.push_back(i);
    }

    void menu() {
        for (auto i : items) i->print(this);
    }

};

auto main() -> int {

    Menu m;
    m.add(std::make_shared<ItemBulka>());
    //m.add(std::make_shared<ItemBublik>());
    m.add(std::make_shared<ItemCoffe>());

    m.menu();

    return 0;
}

