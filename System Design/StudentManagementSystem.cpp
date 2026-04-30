#include<bits/stdc++.h>
using namespace std;

class StudentSystem{
    string name;
    int marks;

    public:
    StudentSystem(string a , int b){
        name=a;
        marks=b;
    }
    void setMarks(int m){
        marks=m;
    }
    int getMarks(){
        return marks;
    }
    string getResult(){
        if(marks>=33){
            return "Passed";
        }
        return "Failed";
    }
    string getName(){
        return name;
    }
};
int main(){
    StudentSystem s("Siddhi", 60);
    s.setMarks(50);
    cout<<"Marks: "<<s.getMarks()<<endl;
    cout<<"Name: "<<s.getName()<<endl;
    cout<<s.getResult()<<endl;
    return 0;
}