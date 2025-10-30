#ifndef RESTAURANT_H
#define RESTAURANT_H
#include <iostream>
#include <string>
#include <vector>
#include "./MenuItem.h"
using namespace std;

class Restaurant{
    private:
        static int idCounter;
        int restaurantId;
        string restaurantName;
        string location;
        vector<MenuItem*> menuItems;
    public:
        Restaurant(const string& name, const string& loc) : restaurantName(name), location(loc) {
            restaurantId = ++idCounter;
        }

        //getters and setters
        int getRestaurantId() const{
            return restaurantId;
        }
        void setRestaurantName(const string& name){
            restaurantName = name;
        }
        string getRestaurantName() const{
            return restaurantName;
        }
        void setLocation(const string& loc){
            location = loc;
        }
        string getLocation() const{
            return location;
        }

        const vector<MenuItem*>& getMenu() const{
            return menuItems;
        }

        void addMenuItem(MenuItem* item) {
            menuItems.push_back(item);
        }

};

int Restaurant::idCounter = 0;
#endif