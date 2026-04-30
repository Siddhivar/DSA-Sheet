#include<bits/stdc++.h>
using namespace std;

class A{
    public:
    A(){};
    A(const A &obj){
        x=obj.x;
        cout<<"Copy Constructor is called"<<endl;
    }
    int x;
};
int main(){
    A obj1;
    obj1.x=10;
    cout<<"obj1.x-> "<<obj1.x<<endl;

    A obj2(obj1);
    cout<<"obj2.x-> "<<obj2.x<<endl;
    return 0;
}