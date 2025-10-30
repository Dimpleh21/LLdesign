#ifndef ORDER_H
#define ORDER_H
#include <iostream>
#include "./User.h"
#include "./MenuItem.h"
#include "../Strategies/PaymentStrategy.h"
#include "./Restaurant.h"

using namespace std;

class Order{
    protected:
        int orderId;
        static int idCounter;
        User* user;
        Restaurant* restaurant;
        vector<MenuItem> items;
        double total;
        PaymentStrategy* paymentMethod;
        string scheduled;
    public:
        Order() {
            orderId = ++idCounter;
            total = 0.0;
            paymentMethod = nullptr;
            restaurant = nullptr;
            user = nullptr;
            scheduled = "";
        }
        //getters and setters

        int getOrderId() const{
            return orderId;
        }
        double getTotalAmount() const{
            return total;
        }

        void setPaymentMethod(PaymentStrategy* strategy){
            paymentMethod = strategy;
        }

        void setScheduled(const string& time){
            scheduled = time;
        }   

        User* getUser() const{
            return user;
        }

        void setUser(User* u){
            user = u;
        }

        Restaurant* getRestaurant() const{
            return restaurant;
        }

        void setRestaurant(Restaurant* res){
            restaurant = res;
        }

        const vector<MenuItem>& getItems() const{
            return items;
        }

       void setItems(const vector<MenuItem>& itemList){
            items = itemList;
            total = 0.0;
            for(const auto& item : itemList){
                total += item.getPrice();
            }
            
        }

        double getTotal() const{
            return total;
        }

        void setTotal(double amount){
            total = amount;
        }

        string getScheduled() const{
            return scheduled;
        }

        // virtual method for get type

        virtual string getOrderType() const = 0;

        // destructor
        virtual ~Order(){
            delete paymentMethod;
        }

        // other methods can be added as needed

        bool processPayment(){
            if(paymentMethod){
                paymentMethod->pay(total);
                return true;
            }else{
                cout << "Payment method not set!" << endl;
                return false;
            }
           
        }


};

int Order::idCounter = 0;
#endif

// we cant make the order Id private as we have to implement strategies to pay, so those extended strategies should have access to orderId to increment it