#include<bits/stdc++.h>
using namespace std;

class NPC{
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
    }
    void describe(){
        cout<<"Name: "<<name<<" |health: "<<health<<" |power: "<<power<<" |defense: "<<defense<<endl;
    }

};
int main(){
    NPC *alien=new NPC("Alien", 20, 5,2);
    alien->describe();
    NPC *Powerfulalien=new NPC("Powerful Alien", 20, 5,4);
    Powerfulalien->describe();
    return 0;
}