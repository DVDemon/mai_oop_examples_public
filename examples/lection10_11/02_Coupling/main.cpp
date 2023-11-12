#include <iostream>
#include <vector>

struct CartEntry
{
    float Price;
    int Quantity;
    float GetLineItemTotal() { return Price * Quantity; }
};

struct CartContents
{
    std::vector<CartEntry> items;
    float GetCartItemsTotal()
    {
        float cartTotal = 0;
        for (auto item : items)
            cartTotal += item.GetLineItemTotal();
        return cartTotal;
    }
};

class Order
{
private:
    CartContents _cart;
    float _salesTax;

public:
    Order(CartContents cart, float salesTax) : _cart(cart), _salesTax(salesTax) {}
    float OrderTotal() { return _cart.GetCartItemsTotal() * (1.0f + _salesTax); }
};

int main()
{
    return 0;
}