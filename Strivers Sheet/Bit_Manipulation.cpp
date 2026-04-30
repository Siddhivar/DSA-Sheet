#include<bits/stdc++.h>
using namespace std;

bool isBitSet(int num, int i){
    return ((num>>i)&1)==1;
}
bool isPowerOfTwo(int num){
    return ((num & (num-1))==0);
}
int countSetBit(int num){
    int count=0;
    while(num){
        num=num&(num-1); // remove the lowest set bit
        count++;
    }
    return count;
}
int setRightMostBit(int num){
    if((num &(num+1))==0){
        return num;
    }
    return (num | (num+1));
}
void Swap(int a, int b){
    a=a^b;
    b=a^b;
    a=a^b;
    cout<<"a: "<<a<<endl;
    cout<<"b: "<<b<<endl;
}
int divide(int dividend, int divisor) {
    if(dividend==INT_MIN && divisor==-1){
        return INT_MAX;
    }
    long long dvd=dividend;
    long long dvs=divisor;
    dvd=llabs(dvd);
    dvs=llabs(dvs);
    long long result=0;
    while(dvd>=dvs){
        long long temp=dvs;
        long long multiple=1;
        while(dvd>=(temp<<1)){
            temp<<=1;
            multiple<<=1;
        }
        dvd-=temp;
        result+=multiple;
    }
    if((dividend<0)^(divisor<0)){
        result=-result;
    }
    return result;
}
int minBitFlips(int start, int goal) {
    int diff=start^goal;
    int count=0;
    while(diff){
        diff=diff & (diff-1);
        count++;
    }
    return count;
}
int singleNumber(vector<int>& nums) {
    int ans=0;
    for(int i=0;i<nums.size();i++){
        ans=ans^nums[i];
    }
    return ans;
}
int findTillX(int n){
    if(n%4==1){
        return 1;
    }else if(n%4==2){
        return n+1;
    }else if(n%4==3){
        return 0;
    }else{
        return n;
    }
}
int findRangeXOR(int l, int r){
    return findTillX(l-1) ^ findTillX(r);
}
int main(){
    int num=7;
    // int i=0;
    // cout<<"Is ith bit set? "<<isBitSet(num,i)<<endl;
    // cout<<"Is power of two? "<<isPowerOfTwo(16)<<endl;
    // cout<<"total set bits: "<<countSetBit(num)<<endl;
    // cout<<"Set rightmost bit: "<<setRightMostBit(num)<<endl;
    int a =5;
    int b=10;
    cout<<"Before swapping-> a: "<<a<<" b: "<<b<<endl;
    cout<<"after swapping ->";
    Swap(a,b);
    return 0;
}