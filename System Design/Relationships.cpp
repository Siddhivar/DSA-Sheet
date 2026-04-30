#include<bits/stdc++.h>
using namespace std;

//DEPENDENCY
class EmailService{
    public:
    void sendConformation(string email);
};
class OrderService{
    public:
    void placeOrder(string email){
        EmailService service;
        service.sendConformation();
    }
};

// ASSOCIATION
class Teacher{};
class Student{
    Teacher* teacher;
};

//AGGREGATION
class Song{};
class PlayList{
    vector<Song*>songs;
};

//COMPOSITION
class OrderItem {};
class Order {
    vector<OrderItem> items;
};

//INHERITANCE
class Animal{
    void move();
};
class Dog: public Animal{};

//REALIZATION
class Flyable{
    public:
    virtual void fly()=0;
};
class Bird: public Flyable{
    public:
    void fly(){};
};
class Airplane : public Flyable {
public:
    void fly() {}
};
int main(){

}