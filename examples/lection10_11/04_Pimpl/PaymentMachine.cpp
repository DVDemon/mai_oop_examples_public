#include "PaymentMachine.h"
#include <iostream>

struct PaymentMachineImpl
{
    int balance{0};
    int account_number{0};
};

PaymentMachine::PaymentMachine(int balance, int account_number)
{
    pimpl = new PaymentMachineImpl{balance,account_number}; 
}

int PaymentMachine::make_payment(int amount)
{
    pimpl->balance -= amount;
    if (pimpl->balance < 0)
        std::cerr << "Balance for account:" << pimpl->account_number << " below zero" << std::endl;
    return pimpl->balance;
};

PaymentMachine::~PaymentMachine(){
    delete pimpl;
}