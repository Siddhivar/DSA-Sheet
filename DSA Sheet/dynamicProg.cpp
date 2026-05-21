#include <bits/stdc++.h>
using namespace std;

/*Input: n = 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step

Memeorization Approach (Top-Down)
*/
vector<int>dp;
int solve(int n){
    if(n<0) return 0;
    if(n==0) return 1;
    if(dp[n]!=-1) return dp[n];
    return dp[n]=solve(n-1)+solve(n-2);
}
int climbStairs(int n) {
    dp.resize(n+1,-1);
    return solve(n);
}
// Bottom Up Approach
int climbStairs(int n) {
    if(n<=2) return n;
    int prev1=2;
    int prev2=1;
    for(int i=3;i<=n;i++){
        int curr=prev2+prev1;
        prev2=prev1;
        prev1=curr;
    }
    return prev1;
}

/*Input: nums = [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
Total amount you can rob = 2 + 9 + 1 = 12.

Recursion+Memorization
*/
vector<int>dp;
int solve(vector<int>nums,int i){
    if(i>=nums.size()) return 0;
    if(dp[i]!=-1) return dp[i];
    int steal=nums[i]+solve(nums,i+2);
    int skip=solve(nums,i+1);
    return dp[i]= max(steal,skip);
}
int rob(vector<int>& nums) {
    dp.resize(nums.size()+1,-1);
    return solve(nums,0);
}
//Bottom-Up
int rob(vector<int>& nums) {
    int n=nums.size();
    if(n==1) return nums[0];
    vector<int>dp(n+1,0);
    dp[0]=0;
    dp[1]=nums[0];
    for(int i=2;i<=nums.size();i++){
        int steal=nums[i-1]+dp[i-2];
        int skip=dp[i-1];
        dp[i]=max(skip,steal);
    }
    return dp[n];
}
/*
House Robber 2
Input: nums = [2,3,2]
Output: 3
Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2), because they are adjacent */
vector<int>dp;
int solve(vector<int>& nums, int i, int n){
    if(i>=n) return 0;
    if(dp[i]!=-1) return dp[i];
    int steal=nums[i]+solve(nums,i+2,n);
    int skip=solve(nums,i+1,n);
    return dp[i]=max(steal,skip);
}
int rob(vector<int>& nums) {
    int n=nums.size();
    if(n==1) return nums[0];
    dp.assign(n, -1);
    int choose_first_idx=solve(nums,0,n-1);
    dp.assign(n,-1);
    int skip_first_idx=solve(nums,1,n);
    return max(choose_first_idx, skip_first_idx);
}

//Bottom-Up
int solve(vector<int>& nums, int start, int end){
    int n=end-start+1;
    vector<int>dp(n+1,0);
    dp[0]=0;
    dp[1]=nums[start];
    for(int i=2;i<=n;i++){
        int steal=nums[start+i-1]+dp[i-2];
        int skip=dp[i-1];
        dp[i]=max(steal,skip);
    }
    return dp[n];
}
int rob(vector<int>& nums) {
    int n=nums.size();
    if(n==1) return nums[0];
    if(n==2) return max(nums[0],nums[1]);
    int choose_first_idx=solve(nums,0,n-2);
    int choose_last_idx=solve(nums,1,n-1);
    return max(choose_first_idx, choose_last_idx);
}

/*Input: nums = [4,2,5,3]
Output: 7
Explanation: It is optimal to choose the subsequence [4,2,5] with alternating sum (4 + 5) - 2 = 7.  */
vector<vector<long long>>dp;
long long solve(vector<int>& nums, int idx, bool flag){
    if(idx>=nums.size()) return 0;
    if(dp[idx][flag]!=-1) return dp[idx][flag];
    long long skip=solve(nums,idx+1,flag);
    long long val=nums[idx];
    if(!flag) val=-val;
    long long take=val+solve(nums,idx+1,!flag);
    return dp[idx][flag]=max(skip,take);
}
long long maxAlternatingSum(vector<int>& nums) {
    int n=nums.size();
    dp.assign(n, vector<long long>(2,-1));
    return solve(nums,0,true);
}
//Bottom Up
long long maxAlternatingSum(vector<int>& nums) {
    long long even=0;
    long long odd=0;
    for(int num:nums){
        long long new_even=max(even,odd+num);
        long long new_odd=max(odd, even-num);
        even=new_even;
        odd=new_odd;
    }
    return even;
}
int main(){
}