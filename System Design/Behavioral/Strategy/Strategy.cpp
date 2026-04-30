#include<bits/stdc++.h>
using namespace std;

//Strategy Interface
class Strategy{
    public:
    virtual int execute(int data)=0;
};
//Concrete Strategies
class AddStrategy: public Strategy{
    public:
    int execute(int data){
        return data+10;
    }
};
class MultiplyStrategy: public Strategy{
    public:
    int execute(int data){
        return data*10;
    }
};
class DivideStrategy: public Strategy{
    public:
    int execute(int data){
        return data/10;
    }
};
//Context
class Context{
    private:
    Strategy *strategy;
    public:
    void setStrategy(Strategy* s){
        strategy=s;
    }
    int doWork(int data){
        return strategy->execute(data);
    }
};
int main(){
    Context c;
    c.setStrategy(new AddStrategy());
    cout<<c.doWork(100)<<endl;

    c.setStrategy(new MultiplyStrategy());
    cout<<c.doWork(100)<<endl;

    c.setStrategy(new DivideStrategy());
    cout<<c.doWork(100)<<endl;
    return 0;
}