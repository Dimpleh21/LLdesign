#ifndef DELIVERY_ORDER_H
#define DELIVERY_ORDER_H
#include <iostream>
#include <string>
#include "Order.h"
using namespace std;

class PickupOrder: public Order{
    private:
        string address;
    public:
        PickupOrder(){
            address="";
        }
        string getOrderType() const override{
            return "Pickup";
        }
        string getUserAddress() const{
            return address;
       }

       void setUserAddress(const string& addr){
            address= addr;
       }
};
#endif