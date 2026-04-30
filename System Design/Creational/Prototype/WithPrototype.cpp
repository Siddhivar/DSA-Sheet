#include<bits/stdc++.h>
using namespace std;

class Prototype{
    public:
    virtual Prototype* clone()=0;
};
class NPC: public Prototype{
    public:
    string name;
    int health;
    int power;
    int defense;
    NPC(const string& name, int health, int power, int defense){
        //Heavy process
        this->name=name;
        this->health=health;
        this->power=power;
        this->defense=defense;
        cout<<"Setting uo the template"<<endl;
    }
    NPC(const NPC &obj){
    name = obj.name;
    health = obj.health;
    power = obj.power;
    defense = obj.defense;
    cout<<"Cloning NPC: "<<name<<endl;
    }
    Prototype* clone()override{
        return new NPC(*this);
    }
    void describe(){
        cout<<"Name: "<<name<<" |health: "<<health<<" |power: "<<power<<" |defense: "<<defense<<endl;
    }
    void setName(const string &n){
        name=n;
    }
    void setHealth(int h){
        health=h;
    }
    void setPower(int p){
        power=p;
    }
    void setDefense(int d){
        defense=d;
    }
};
int main(){
    NPC* alien=new NPC("alien",50,20,4);
    alien->describe();

    NPC* aliencopied1= dynamic_cast<NPC*>(alien->clone());
    aliencopied1->describe();

    NPC* aliencopied2=dynamic_cast<NPC*>(alien->clone());
    aliencopied2->setName("Powerful Alien");
    aliencopied2->setPower(50);
    aliencopied2->describe();
    return 0;
}