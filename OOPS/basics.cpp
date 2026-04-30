#include<bits/stdc++.h>
using namespace std;

//----------------Encapsulation-----------
// class Bank {
//     private:
//     int balance;
//     public:
//     Bank(){
//         balance=0;
//     }
//     void deposit(int amount){
//         balance+=amount;
//     }
//     string withdrawl(int amount){
//         if(amount>balance){
//             return "Insufficient Balance";
//         }else{
//             balance-=amount;
//             return "Withdrawl Complete";
//         }
//     }
//     int getBalance(){
//         return balance;
//     }
// };
// int main(){
//     Bank b;
//     b.deposit(1000);
//     cout<<"Balance: "<<b.getBalance()<<endl;
//     cout<<b.withdrawl(300)<<endl;
//     cout<<"Balance after withdrawl: "<<b.getBalance()<<endl;
//     cout<<b.withdrawl(2000)<<endl;
//     return 0;
// }
//---------------------------------Runtime polymorphism
// class Animal{
//     public:
//     virtual void sound(){
//         cout<<"Animal Sound\n";
//     }
// };
// class Dog: public Animal{
//     public:
//     void sound() override{
//         cout<<"Barking\n";
//     }
// };
// /*If we dont have virtual then answer would be "Animal Sound" because it is decided at compile time
// but after adding virtual, now it is decided at run time and now answer is "Barking".*/
// int main(){
// /*a is a pointer to an Animal object
// It can point to:
// Animal object
// Dog object (child class)
// Any derived class*/
//     Animal *a1 = new Dog; //Creates an object at runtime (heap memory)
//     a1->sound();
//     return 0;
// }

//------------------Assosiation----------
// Weak Relationship and object exist independently
class Student{};
class Teacher{
    Student* student;
};  
//---------------------Aggregation----------------
//Has-A , weak, Whole-Part relationship but independent
class Teacher{};
class Department{
    vector<Teacher*>teachers;
};
//--------------------Composition------------------
//Has-A, Strong Ownership
class Room{};
class House{
    vector<Room>rooms;  
};