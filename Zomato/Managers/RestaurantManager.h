#ifndef RESTAURANT_MANAGER_H
#define RESTAURANT_MANAGER_H
#include <iostream>
#include <vector>
#include <algorithm>
#include "../models/Restaurant.h"
using namespace std;

class RestaurantManager{
    private:
        vector<Restaurant*> restaurants;
        static RestaurantManager* instance;
        RestaurantManager() {
            //private constructor for singleton
        }
    public:

        static RestaurantManager* getInstance() {
            if(!instance) {
                instance = new RestaurantManager();
            }
            return instance;
        }

        void addRestaurant(Restaurant* res){
            restaurants.push_back(res);
        }

        const vector<Restaurant*>& getRestaurants() const{
            return restaurants;
        }



        vector<Restaurant*> browseByLocation(const string& loc) const{
            vector<Restaurant*> resList;
            transform(loc.begin(), loc.end(), loc.begin(), ::tolower);
            for(const auto& res : restaurants){
                string resLoc = res->getLocation();
                transform(resLoc.begin(), resLoc.end(), resLoc.begin(), ::tolower);
                if(resLoc == loc){
                    resList.push_back(res);
                }
            }
            return resList;
        }
        
};

RestaurantManager* RestaurantManager::instance = nullptr;
#endif






//this is a singleton class