#include<bits/stdc++.h>
using namespace std;

// class Car{
//     private:
//     string brand;
//     string model;
//     int speed;
//     public:
//     Car(string brand, string model, int speed)
//     : brand(brand), model(model), speed(speed) {}

//     void accelerate(int increment){
//         speed+=increment;
//     }
//     void displayStatus() {
//         cout << brand << " (" << model << ") has a speed of "
//              << speed << " km/h" << endl;
//     }
// };

//-----------------FUNCTION OVERRIDING--------------
class Base{
    public:
    void show(){
        cout<<"Base class function"<<endl;
    }
};
class Derived:public Base{
    public:
    void show(){
        cout<<"Derived class funcion"<<endl;
    }
};
int main(){
    // Car Toyota("Toyota", "2015", 27);
    // Car Hyundai("Hundai", "2019",40);
    // Toyota.accelerate(4);
    // Hyundai.accelerate(5);

    // Toyota.displayStatus();
    // Hyundai.displayStatus();

    Base *b;
    Derived d;
    b=&d;
    b->show();
    d.show();
    return 0;
}