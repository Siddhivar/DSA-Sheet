#include <iostream>
#include <mutex>
using namespace std;

// class Singleton{
// private:
//     static Singleton* instance;
//     static mutex mtx;

//     Singleton(){
//         cout<<"Constructor is being called."<<endl;
//     }

// public:
//     static Singleton* getInstance(){
//         if(instance==nullptr){
//             lock_guard<mutex> lock(mtx);
//             if(instance==nullptr){
//                 instance = new Singleton();
//             }
//         }
//         return instance;
//     }
// };

// Singleton* Singleton::instance = nullptr;
// mutex Singleton::mtx;

//---------------------------Eager Initialization
// class Singleton{
// private:
//     static Singleton* instance;

//     Singleton(){
//         cout<<"Constructor is being called."<<endl;
//     }

// public:
//     static Singleton* getInstance(){
//         return instance;
//     }
// };

// Singleton* Singleton::instance = new Singleton();
// int main(){
//     Singleton *s1 = Singleton::getInstance();
//     Singleton *s2 = Singleton::getInstance();
//     cout << (s1 == s2) << endl;
//     return 0;
// }

//-------------------------------------

class Counter{
    private:
    static Counter* instance;
    // static mutex mtx;
    int count;
    
    Counter(){
        count=0;
    };

    public:
    void increament(){
        // lock_guard<mutex>lock(mtx);
        count++;
    }
    int getCount(){
        // lock_guard<mutex>lock(mtx);
        return count;
    }

    static Counter* getInstance(){
        if(instance==nullptr){
            // lock_guard<mutex>lock(mtx);
            if(instance==nullptr){
                instance= new Counter();
            }
            return instance;
        }
    }
};

Counter* Counter::instance=nullptr;
// mutex Counter::mtx;

int main(){
    Counter* c1=Counter::getInstance();
    Counter* c2=Counter::getInstance();
    cout<<c1->getCount()<<endl;
    cout<<c2->getCount()<<endl;;
    c1->increament();
    cout<<c2->getCount()<<endl;
}