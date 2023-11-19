#include <iostream>

class PaymentMachine{
    private:
        int balance {0};
        int account_number{0};
    public:
        PaymentMachine() = default;
        PaymentMachine(int b,int a) : balance(b),account_number(a) {}
        int make_payment(int amount){
            balance -= amount;
            if(balance<0) std::cerr << "Balance for account:" << account_number << " below zero" << std::endl;
            return balance;
        };
};

int main() {
    PaymentMachine p(10,100001);

    *((int*)&p)+=10;
    std::cout << "remaining balance:" << p.make_payment(15) << std::endl;;

    return 0;
}