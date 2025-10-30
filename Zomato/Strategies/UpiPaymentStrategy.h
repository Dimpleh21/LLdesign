#ifndef UPI_PAYMENT_STRATEGY_H
#define UPI_PAYMENT_STRATEGY_H
#include <string>
#include "PaymentStrategy.h"
using namespace std;

class UpiPaymentStrategy : public PaymentStrategy{
    private:
        string mobile;
    public:
        UpiPaymentStrategy(const string& mob){
            mobile = mob;
        }

        void pay(double amount) override{
            cout << "paid using upi payment gateway an amount of " << amount << endl;
        }
};
#endif