#ifndef USER_H
#define USER_H
#include <iostream>
#include <string>
#include "./Cart.h"
using namespace std;


class User{
    private:
        int userId;
        string userName;
        string address;
        Cart* cart;
    public:
        User(int userId,const string& userName, const string& addr){
            this->userId= userId;
            this->userName= userName;
            this->address= addr;
            cart= new Cart();
        } 

        //getters and setters

        string getName() const{
            return userName;
        }

        void setName(const string& name){
            userName= name;
        }

        string getAddr() const{
            return address;
        }

        void setAddr(const string& addr){
            address= addr;
        }

        Cart* getCart() const{
            return cart;
        }

};
#endif