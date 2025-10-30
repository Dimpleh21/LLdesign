#ifndef ORDER_MANAGER_H
#define ORDER_MANAGER_H
#include <iostream>
#include "../models/Order.h"
using namespace std;


class OrderManager{
    private:
        vector<Order*> orderList;
        static OrderManager* instance;
        OrderManager(){

        }
    public:
        static OrderManager* getInstance(){
            if(instance == nullptr){
                instance = new OrderManager();
            }
            return instance;
        }

        void addOrder(Order* order){
            orderList.push_back(order);
        }

        void ListAllOrders(){
            cout << "All Orders" << endl;
            for(auto order: orderList){
                cout << order->getOrderType() << " order for " << order->getUser()->getName() << " | Total : $" << order->getTotal() << " | Scheduled at: " << order->getScheduled();
            }
        }
};

OrderManager* OrderManager::instance = nullptr;
#endif
