#ifndef CART_H
#define CART_H
#include <iostream>
#include <vector>
#include "MenuItem.h"
#include "Restaurant.h"
using namespace std;

class Cart{
    private:
        vector<MenuItem> items;
        Restaurant* restaurant;
    public:
        Cart(){
            restaurant = nullptr;
        }
        //getters and setters

        void setRestaurant(Restaurant* res){
            restaurant = res;
        }

        Restaurant* getRestaurant() const{
            return restaurant;
        }

        const vector<MenuItem>& getItems() const{
            return items;
        }

        //rest of the methods

        bool isEmpty() const{
            return items.empty();
        }

        void clearCart(){
            items.clear();
            restaurant = nullptr;
        }


        void addToCart(const MenuItem& item){
            if(!restaurant){
                cout << "Cart is empty. Please select a restaurant first." << endl;
                return;
            }
            items.push_back(item);
        }

        double getTotalCost() const{
            double res=0.0;
            for(const auto& item : items){
                res+=item.getPrice();
            }
            return res;
        }

};

#endif