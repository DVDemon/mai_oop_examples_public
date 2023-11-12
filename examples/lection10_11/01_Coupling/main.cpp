#include <iostream>
#include <vector>

struct CartEntry
{
    float Price;
    int Quantity;
};
struct CartContents
{
    std::vector<CartEntry> items;
};
class Order
{
private:
    CartContents _cart;
    float _salesTax;

public:
    Order(CartContents cart, float salesTax) : _cart(cart), _salesTax(salesTax) {}
    float OrderTotal()
    {
        float cartTotal = 0;
        for (auto item : _cart.items)
            cartTotal += item.Price * item.Quantity;
        cartTotal += cartTotal * _salesTax;
        return cartTotal;
    }
};

int main()
{
    return 0;
}