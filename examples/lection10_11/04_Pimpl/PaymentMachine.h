#pragma once

struct PaymentMachineImpl;
class PaymentMachine{
    private:
        PaymentMachineImpl* pimpl; // где-то в куче
    public:
        PaymentMachine(int balance, int account_number);
        int make_payment(int amount);
        ~PaymentMachine();
};