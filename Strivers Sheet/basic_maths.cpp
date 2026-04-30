#include<bits/stdc++.h>
using namespace std;

int countDigits(int n){
    int rem=0;
    while(n>0){
        n=n/10;
        rem+=1;
    }
    return rem;
}
int reverseDigit(int n){
    int rem=0;
    while(n>0){
        rem= rem*10+(n%10);
        n=n/10;
    }
    return rem;
}
bool checkPalindrome(int num){
    int reverseNum= reverseDigit(num);
    if(num==reverseNum){
        return true;
    }
    return false;
}

//Euclidean Algorithm, Time Complexity = O(log(min(a,b)))​
int findGCD(int num1, int num2){
    while(num2!=0){
        int temp=num2;
        num2=num1%num2;
        num1=temp;
    }
    return num1;
}
int power(int base, int exp){
    int result = 1;
    while(exp--){
        result *= base;
    }
    return result;
}

bool checkArmstrong(int num){
    // int digits=countDigits(num);
    int digits= to_string(num).length();
    int rem=0;
    int copy=num;
    while(copy>0){
        int lastDigit=copy%10;
        rem += power(lastDigit, digits);
        copy=copy/10;
    }
    return rem==num;
}
vector<int>PrintDivisor(int num){
    vector<int>result;
    for(int i=1;i*i<=num;i++){
        if(num%i==0){
            result.push_back(i);
            if(i!=num/i){
                result.push_back(num/i);
            }
        }
    }
    return result;
}
bool checkPrime(int num){
    if(num<=1) return false;
    for(int i=2;i*i<=num;i++){
        if(num%i==0){
            return false;
        }
    }
    return true;
}
int main(){
    // int num=4558;
    // cout<<"Total no. of digits in "<<num<<": "<<countDigits(num)<<endl;
    // cout<<"Reverse digit of "<<num<<" : "<< reverseDigit(num)<<endl;
    // cout<<"Check Palindrome "<<num<<" : "<< checkPalindrome(num)<<endl;
    // int num1=48;
    // int num2=18;
    // cout<<"GDC of "<<num1<<" and "<<num2<<": "<<findGCD(num1,num2)<<endl;
    // int number=153;
    // cout<<"Check Armstrong: "<<checkArmstrong(153)<<endl;
    int num=27;
    vector<int>res=PrintDivisor(num);
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<" ";
    }cout<<endl;

    cout<<" Check Prime "<< checkPrime(num);
    return 0;
}