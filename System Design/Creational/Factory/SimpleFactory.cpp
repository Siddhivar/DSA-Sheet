#include<bits/stdc++.h>
using namespace std;

/*This is a Simple Factory Pattern
because-
One class (BurgerFactory) decides everything
Uses if-else to create objects*/
class Burger{
    public:
    virtual void prepare()=0;
};
class BasicBurger: public Burger{
    public:
    void prepare()override{
        cout<<"Preparing Basic Burger"<<endl;
    }
};
class StandardBurger: public Burger{
    public:
    void prepare()override{
        cout<<"Preparing Standard Burger"<<endl;
    }
};
class PremiumBurger: public Burger{
    public:
    void prepare()override{
        cout<<"Preparing Premium Burger"<<endl;
    }
};
class BurgerFactory{
    public:
    Burger* createBurger(string &type){
        if(type=="BasicBurger"){
            return new BasicBurger;
        }else if(type=="StandardBurger"){
            return new StandardBurger;
        }else if(type=="PremiumBurger"){
            return new PremiumBurger;
        }else{
            cout<<"Invalid Burger"<<endl;
            return nullptr;
        }
    }
};
int main(){
    string type = "PremiumBurger";
    BurgerFactory bf;
    Burger* burger = bf.createBurger(type);
    if (burger) {
        burger->prepare();
        delete burger;
    }
    return 0;
}
