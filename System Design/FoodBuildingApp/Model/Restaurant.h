#ifndef RESTAURANT_H
#define RESTAURANT_H

#include <bits/stdc++.h>
#include "MenuItem.h"
using namespace std;

class Resaturant{
    private:
    static int nextRestaurantId;
    int restaurantId;
    string name;
    string location;
    vector<MenuItem>menu;

    public:
    Resaturant(const string& name, const string& location){
        this->name=name;
        this->location=location;
        this->restaurantId=++nextRestaurantId;
    }
    void setName(const string& n){
        name=n;
    }
    string getName(){
        return name;
    }
    void setLoc(const string& loc){
        location=loc;
    }
    string getLoc(){
        return location;
    }
    void addMenuItem(const MenuItem &item){
        menu.push_back(item);
    }

};