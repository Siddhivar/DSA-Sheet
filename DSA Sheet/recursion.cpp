#include<bits/stdc++.h>
using namespace std;

void PrintName(int n){
    if(n==0){
        return;
    }
    cout<<"Siddhi ";
    PrintName(n-1);
}
void PrintNumber(int n){
    if(n==0)  return;
    PrintNumber(n-1);
    cout<<n<<" ";
}
int findSum(int n){
    if(n==0){
        return 0;
    }
    int sum=n+findSum(n-1);
    return sum;
}
int findFactorial(int n){
    if(n==1) return 1;
    int result = n*findFactorial(n-1);
    return result;
}
int main(){
    int n=3;
    PrintName(n);
    cout<<endl;
    PrintNumber(n);
    cout<<endl;
    cout<< "Sum of first "<<6<<" Natural number is: "<<findSum(6)<<endl;
    cout<<"Factorial of "<<5<<": "<<findFactorial(5)<<endl;
    return 0;
}