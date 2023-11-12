#pragma once
#include <memory>

struct PaymentMachineImpl;
class PaymentMachine{
    private:
        std::aligned_storage_t<sizeof(int)*2,sizeof(int)*2> storage; // в той же памяти что и весь класс
        PaymentMachineImpl* pimpl;
    public:
        PaymentMachine(int balance, int account_number);
        int make_payment(int amount);
        ~PaymentMachine();
};