#include <bits/stdc++.h>
using namespace std;


//295. Find Median from Data Stream
priority_queue<int>left_max_heap;
priority_queue<int, vector<int>, greater<int>>right_min_heap;
MedianFinder() {
    
}
void addNum(int num) {
    if(left_max_heap.empty() || num<=left_max_heap.top()){
        left_max_heap.push(num);
    }else{
        right_min_heap.push(num);
    }
    if(left_max_heap.size()>right_min_heap.size()+1){
        right_min_heap.push(left_max_heap.top());
        left_max_heap.pop();
    }
    else if(left_max_heap.size()<right_min_heap.size()){
        left_max_heap.push(right_min_heap.top());
        right_min_heap.pop();
    }
}
double findMedian() {
    if(left_max_heap.size()==right_min_heap.size()){
        return (right_min_heap.top()+left_max_heap.top())/2.0;
    }
    return left_max_heap.top();
}

//451. Sort Characters By Frequency
typedef pair<char,int>P;
struct lambda{
    bool operator()(P&a, P&b){
        return a.second<b.second;
    }
};
string frequencySort(string s) {
    priority_queue<P,vector<P>, lambda>pq;
    unordered_map<char,int>mp;
    for(char ch:s){
        mp[ch]++;
    }
    for(auto it:mp){
        pq.push({it.first,it.second});
    }
    string result="";
    while(!pq.empty()){
        P temp=pq.top();
        pq.pop();
        result+=string(temp.second,temp.first);
    }
    return result;
}

/*Input: piles = [5,4,9], k = 2
Output: 12
Explanation: Steps of a possible scenario are:
- Apply the operation on pile 2. The resulting piles are [5,4,5].
- Apply the operation on pile 0. The resulting piles are [3,4,5].
The total number of stones in [3,4,5] is 12.*/
int minStoneSum(vector<int>& piles, int k) {
    priority_queue<int>pq;
    for(int pile:piles){
        pq.push(pile);
    }
    while(k--){
        int largest=pq.top();
        pq.pop();
        largest-=largest/2;
        pq.push(largest);
    }
    int sum=0;
    while(!pq.empty()){
        sum+=pq.top();
        pq.pop();
    }
    return sum;
}

//Single Threaded CPU
typedef pair<int,int>P;
vector<int> getOrder(vector<vector<int>>& tasks) {
    int n=tasks.size();
    vector<vector<long long>>sortedArr;
    for(int i=0;i<n;i++){
        sortedArr.push_back({tasks[i][0], tasks[i][1], i});
    }
    sort(sortedArr.begin(), sortedArr.end());
    priority_queue<P,vector<P>, greater<P>>pq;
    vector<int>result;
    long long time=0;
    int idx=0;
    while(idx<n || (!pq.empty())){
        if(pq.empty()){
            time=max(time,sortedArr[idx][0]);
        }
        while(idx<n && sortedArr[idx][0]<=time){
            pq.push({sortedArr[idx][1], sortedArr[idx][2]});
            idx++;
        }
        auto [process,index]=pq.top();
        pq.pop();
        result.push_back(index);
        time+=process;
    }
    return result;
}

int lastStoneWeight(vector<int>& stones) {
    priority_queue<int>pq(stones.begin(), stones.end());
    while(pq.size()>1){
        int y=pq.top();
        pq.pop();
        int x=pq.top();
        pq.pop();
        if(x<y){
            pq.push(y-x);
        } 
    }
    return pq.empty()? 0:pq.top();
}
// If we use max heap-> O(nlogn)
//If we use min heap -> O(nlogk)
//Bucket sort ->O(n)
vector<int> topKFrequent(vector<int>& nums, int k) {
    int n=nums.size();
    unordered_map<int,int>freq;
    for(int n:nums){
        freq[n]++;
    }
    vector<vector<int>>bucket(n+1);
    for(auto it:freq){
        bucket[it.second].push_back(it.first);
    }
    vector<int>ans;
    for(int i=n;i>=0;i--){
        for(int num:bucket[i]){
            ans.push_back(num);
            if(ans.size()==k){
                return ans;
            }
        }
    }
    return ans;
}
//Kth Largest elemnt in a stream
priority_queue<int, vector<int>, greater<int>>pq;
int K;
KthLargest(int k, vector<int>& nums) {
    K=k;
    for(int num:nums){
        pq.push(num);
        if(pq.size()>k){
            pq.pop();
        }
    }
}
int add(int val) {
    pq.push(val);
    if(pq.size()>K){
        pq.pop();
    }
    return pq.top();
}

/*Input: nums1 = [1,7,11], nums2 = [2,4,6], k = 3
Output: [[1,2],[1,4],[1,6]]
Explanation: The first 3 pairs are returned from the sequence: [1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]
*/
typedef pair<int,pair<int,int>>P;
vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
    vector<vector<int>>result;
    priority_queue<P,vector<P>, greater<P>>pq;
    set<pair<int,int>>visited;
    pq.push({nums1[0]+nums2[0],{0,0}});
    visited.insert({0,0});
    while(k-- && !pq.empty()){
        auto curr=pq.top();
        pq.pop();
        int idx1=curr.second.first;
        int idx2=curr.second.second;
        result.push_back({nums1[idx1],nums2[idx2]});
        //push(idx1,idx2+1)
        if(idx1<nums1.size() && idx2+1<nums2.size() && visited.find({idx1,idx2+1})==visited.end()){
            pq.push({nums1[idx1]+nums2[idx2+1],{idx1,idx2+1}});
            visited.insert({idx1,idx2+1});
        }
        //push(idx1+1,idx2)
        if(idx1+1<nums1.size() && idx2<nums2.size() && visited.find({idx1+1,idx2})==visited.end()){
            pq.push({nums1[idx1+1]+nums2[idx2],{idx1+1,idx2}});
            visited.insert({idx1+1,idx2});
        }
    }
    return result;
}
int main(){
    return 0;
}