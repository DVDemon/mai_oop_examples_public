#include <iostream>
#include "PaymentMachine.h"


int main() {
    PaymentMachine p(10,100001);

    //*((int*)&p)+=10;
    std::cout << "remaining balance:" << p.make_payment(15) << std::endl;;

    return 0;
}