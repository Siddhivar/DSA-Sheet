#include<bits/stdc++.h>
using namespace std;

//Sieve of Eratosthenes
int countPrimes(int n) {
    vector<bool>isPrime(n+1,true);
    isPrime[0]=false;
    isPrime[1]=false;
    for(int i=2;i*i<=n;i++){
        if(isPrime[i]){
            for(int j=2;j*i<=n;j++){
                isPrime[i*j]=false;
            }
        }
    }
    int count=0;
    for(int i=2;i<n;i++){
        if(isPrime[i]){
            count++;
        }
    }
    return count;
}

/*Input: left = 10, right = 19
Output: [11,13]
Explanation: The prime numbers between 10 and 19 are 11, 13, 17, and 19.
The closest gap between any pair is 2, which can be achieved by [11,13] or [17,19].
Since 11 is smaller than 17, we return the first pair.*/
vector<int> closestPrimes(int left, int right) {
    vector<bool>isPrime(right+1,true);
    isPrime[0]=false;
    isPrime[1]=false;
    for(int i=2;i*i<=right;i++){
    if(isPrime[i]){
        for(int j=2;i*j<=right;j++){
            isPrime[i*j]=false;
        }
    }
    }
    vector<int>arr;
    for(int i=left;i<=right;i++){
    if(isPrime[i]){
        arr.push_back(i);
    }
    }
    if(arr.size()<2) return{-1,-1};
    vector<int>ans={arr[0],arr[1]};
    int minDiff=arr[1]-arr[0];
    for(int i=1;i<arr.size();i++){
        int diff=arr[i]-arr[i-1];
        if(minDiff>diff){
            minDiff=diff;
            ans={arr[i-1],arr[i]};
        }
    }
return ans;
}
int main(){
    return 0;
}