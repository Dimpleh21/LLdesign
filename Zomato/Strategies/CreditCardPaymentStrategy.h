#ifndef CREDIT_CARD_PAYMENT_STRATEGY_H
#define CREDIT_CARD_PAYMENT_STRATEGY_H
#include <iostream>
#include <string>
#include <PaymentStrategy.h>
using namespace std;


class CreditCardStrategy : public PaymentStrategy{
    private:
        string cardNumber;
    public:
        CreditCardStrategy(const string& card){
            cardNumber= card;
        }

        void pay(double amount) override{
            cout << "Paid using credit card with card Number" << cardNumber << endl;
        }
};
#endif   