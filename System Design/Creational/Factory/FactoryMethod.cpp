#include<bits/stdc++.h>
using namespace std;

class Notification{
    public:
    virtual void send()=0;
};

class SMSNotification : public Notification{
    public:
    void send() override{
        cout<<"SMS Notification"<<endl;
    }
};
class EmailNotification : public Notification{
    public:
    void send() override{
        cout<<"Email Notification"<<endl;
    }
};
class Creator{
    public:
    virtual Notification* create()=0;
    void notify(){
        Notification* n =create();
        n->send();
    }
};
class SMSCreator: public Creator{
    public:
    Notification* create(){
        return new SMSNotification;
    }
};
class EmailCreator: public Creator{
    public:
    Notification* create(){
        return new EmailNotification;
    }
};
int main(){
    Creator* c= new EmailCreator();
    c->notify();
    return 0;
}