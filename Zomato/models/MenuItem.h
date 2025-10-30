#ifndef MENUITEM_H
#define MENUITEM_H
#include <string>
#include <iostream>
using namespace std;

class MenuItem{
    private:
        string itemId;
        string itemName;
        double price;
    public:
        MenuItem(const string& id, const string& name, double pr): itemId(id), itemName(name), price(pr) {}
        
        //getters and setters

        string getItemId() const{
            return itemId;
        }

        void setItemId(const string& id){
            itemId = id;
        }

        string getItemName() const{
            return itemName;
        }

        void setItemName(const string& name){
            itemName = name;
        }

        double getPrice() const{
            return price;
        }

        void setPrice(double pr){
            price = pr;
        }
};
#endif