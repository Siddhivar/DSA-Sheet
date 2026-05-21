#include <bits/stdc++.h>
using namespace std;

int myAtoi(string s) {
    int i=0;
    int n=s.length();
    while(i<n && s[i]==' '){
        i++;
    }
    if(i==n){
        return 0;
    }
    int sign=1;
    if(s[i]=='-'){
        sign=-1;
        i++;
    }else if(s[i]=='+'){
        i++;
    }
    long long num=0;
    while(i<n && isdigit(s[i])){
        int digit=s[i]-'0';
        if(num>(INT_MAX - digit)/10){
            if (sign==-1){
                return INT_MIN;
            }else{
                return INT_MAX;
            }
        }
        num=num*10+digit;
        i++;
    }
    return sign*num;

}
double myPow(double x, int n) {
    long long N=n;
    double ans = 1.0;
    if(N<0){
        x=1/x;
        N=-N;
    }
    while(N>0){
        if(N%2==1){
            ans=ans*x;
        }
        x=x*x;
        N=N/2;
    }
    return ans;
}
const long long mod= 1e9+7;
long long power(long long n, long long x){
    long long ans=1;
    while(x>0){
    if(x%2==1){
        ans=(ans*n)%mod;
    }
    n=(n*n)%mod;
    x=x/2;
    }
    return ans;
}
int countGoodNumbers(long long n) {
    long long even_count=(n+1)/2;
    long long odd_count=n/2;
    long long part1= power(5,even_count);
    long long part2=power(4,odd_count);
    return (part1*part2)%mod;
}

void insertStack(stack<int>&st, int x){
    if(st.empty() || st.top()<=x){
        st.push(x);
        return;
    }
    int temp= st.top();
    st.pop();
    insertStack(st,x);
    st.push(temp);
}
void sortStack(stack<int>&st){
    if(st.empty()) return;
    int temp=st.top();
    st.pop();
    sortStack(st);
    insertStack(st, temp);
}
void InsertStack(stack<int>&st, int x){
    if(st.empty()){
        st.push(x);
        return;
    }
    int temp=st.top();
    st.pop();
    InsertStack(st,x);
    st.push(temp);
}
void ReverseStack(stack<int>&st){
    if(st.empty()) return;
    int temp=st.top();
    st.pop();
    ReverseStack(st);
    InsertStack(st, temp);
}
int main(){
    stack<int>st;
    st.push(2);
    st.push(3);
    st.push(1);
    st.push(4);
    // sortStack(st);
    // cout<<"Before Reversing: ";
    // while(!st.empty()){
    //     cout<<st.top()<<" ";
    //     st.pop();
    // }cout<<endl;
    ReverseStack(st);
    cout<<"After Reversing: ";
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }cout<<endl;
    return 0;
}