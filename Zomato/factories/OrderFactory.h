#ifndef ORDER_FACTORY_H
#define ORDER_FACTORY_H
#include <iostream>
#include "../models/User.h"
#include "../models/Cart.h"
#include "../models/Restaurant.h"
#include "../models/MenuItem.h"
#include "../strategies/PaymentStrategy.h"
#include "../models/Order.h"
#include <vector>
#include <string>
using namespace std;


class OrderFactory{
    public:
        virtual Order* createOrder(User* user, Cart* cart, Restaurant* res, const vector<MenuItem>& items, PaymentStrategy* paymentMethod, const string& orderType, double total)=0;
        virtual ~OrderFactory(){};

};

#endif