#ifndef DELIVERY_ORDER_H
#define DELIVERY_ORDER_H
#include <iostream>
#include <string>
#include "Order.h"
using namespace std;

class DeliveryOrder: public Order{
    private:
        string address;
    public:
        DeliveryOrder(){
            address="";
        }
        string getOrderType() const override{
            return "Delivery";
        }
        string getUserAddress() const{
            return address;
       }

       void setUserAddress(const string& addr){
            address= addr;
       }
};
#endif