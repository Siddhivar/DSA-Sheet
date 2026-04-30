#include<bits/stdc++.h>
using namespace std;

class Vehicle{
    public:
    string number;
    Vehicle(string n){
        number=n;
    }
};

class ParkingLot{
    vector<Vehicle*>vehicles;
    public:
    void park(Vehicle* v){
        vehicles.push_back(v);
        cout<<"Vehicle "<<v->number<<" is Parked!"<<endl;
    }
    void remove(string num){
        for(auto it=vehicles.begin(); it!=vehicles.end();it++){
            if((*it)->number==num){
                cout<<"Vehicle "<<num<<" is removed from parking!"<<endl;
                delete *it;
                vehicles.erase(it);
                return;
            }
        }
        cout << "Vehicle " << num << " not found!" << endl;
    }
    void count(){
        cout<<"Total vehicles parked: "<<vehicles.size()<<endl;
    }
    void showVehicles(){
        cout<<"Vehicles in Parking: \n";
        for(auto v: vehicles){
            cout<<v->number<<end;
        }
    }
};

int main(){
    ParkingLot pl;
    Vehicle *v1=new Vehicle("UP123");
    Vehicle *v2=new Vehicle("KA123");
    Vehicle *v3=new Vehicle("RJ123");
    Vehicle *v4=new Vehicle("DE123");

    pl.park(v1);
    pl.park(v2);
    pl.count();
    pl.park(v3);
    pl.remove("UP123");
    pl.remove("UP234");
    pl.showVehicles();
    return 0;
}