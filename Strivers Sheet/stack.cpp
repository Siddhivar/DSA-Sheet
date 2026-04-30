#include<bits/stdc++.h>
using namespace std;

// class Stack{
// private:
//     int* arr;
//     int capacity;
//     int top;
// public:
//     //constructor
//     Stack(int size=100){
//         capacity=size;
//         arr=new int [capacity];
//         top=-1;
//     }
//     void push(int x){
//         if (top == capacity - 1){
//             cout<<"Stack Overflow\n";
//             return;
//         }
//         arr[++top]=x;
//     }
//     int pop(){
//         if(isEmpty()){
//             cout<<"Stack Underflow\n";
//             return -1;
//         }
//         return arr[top--];
//     }
//     bool isEmpty(){
//         return top==-1;
//     }
//     int topEle(){
//         if(isEmpty()){
//             cout<<"Stack Underflow\n";
//             return -1;
//         }
//         return arr[top];
//     }
//     ~Stack(){
//         delete[] arr;
//     }

// };

// //Implement Stack using TWO queues
// class MyStack {
// private:
//     queue<int>q1,q2;
// public:
    
//     void push(int x) {
//         q2.push(x);
//         while(!q1.empty()){
//             q2.push(q1.front());
//             q1.pop();
//         }
//         swap(q1,q2);
//     }
    
//     int pop() {
//         int val=q1.front();
//         q1.pop();
//         return val;
//     }
    
//     int top() {
//         return q1.front();
//     }
    
//     bool empty() {
//         return q1.empty();
//     }
// };
// //Implement stack using ONE queue
// class MyStack {
// private:
//     queue<int>q;
// public:
//     void push(int x) {
//         q.push(x);
//         int size=q.size();
//         for(int i=0;i<size-1;i++){
//             q.push(q.front());
//             q.pop();
//         }
//     }
    
//     int pop() {
//         int val=q1.front();
//         q1.pop();
//         return val;
//     }
    
//     int top() {
//         return q1.front();
//     }
    
//     bool empty() {
//         return q1.empty();
//     }
// };

//============================Implement Stack Using Linked List========================
class LinkedListStack{
    struct Node{
        int data;
        Node* next;
        Node(int x){
            data=x;
            next=NULL;
        }
    };
    Node* topnode;
    public:
    LinkedListStack(){
        topnode=NULL;
    }
    void push(int x){
        Node* newnode= new Node(x);
        newnode->next=topnode;
        topnode=newnode;
    }
    int pop(){
        if(isEmpty()){
            cout<<"Stack Underflow\n";
            return -1;
        }
        int val= topnode->data;
        Node* temp= topnode;
        topnode=topnode->next;
        delete temp;
        return val;
    }
    int top(){
        if(isEmpty()){
            cout<<"Stack Underflow\n";
            return -1;
        }
        return topnode->data;
    }
    bool isEmpty(){
        return topnode==NULL;
    }
};

// Minimum Stack
class MinStack {
    stack<int>st;
    stack<int>minst;
public:
    MinStack() {
        
    }
    
    void push(int val) {
       st.push(val);
       if(minst.empty() || (val<=minst.top())){
        minst.push(val);
       } 
    }
    
    void pop() {
        if(st.top()==minst.top()){
            minst.pop();
        }
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minst.top();
    }
};
//Array is non-circular
vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    stack<int>st;
    map<int, int>mp;
    for(int num:nums2){
        while(!st.empty()&& st.top()<num){
            mp[st.top()]=num;
            st.pop();
        }
        st.push(num);
    }
    while(!st.empty()){
        mp[st.top()]=-1;
        st.pop();
    }
    vector<int>res;
    for(int num:nums1){
        res.push_back(mp[num]);
    }
    return res;
}

//Array is circular
vector<int> nextGreaterElements(vector<int>& nums) {
    int n=nums.size();
    vector<int>ans(n,-1);
    stack<int>st;
    for(int i=0;i<2*n;i++){
        int num=nums[i%n];
        while(!st.empty() && nums[st.top()]<num){
            ans[st.top()]=num;
            st.pop();
        }
        if(i<n){
            st.push(i);
        }
    }
    return ans;
}

vector<int>nextSmallerElement(vector<int>&nums){
    stack<int>st;
    int n=nums.size();
    vector<int>ans(n,-1);
    for(int i=0;i<nums.size();i++){
        while(!st.empty() && nums[st.top()]>nums[i]){
            ans[st.top()]=nums[i];
            st.pop();
        }
        st.push(i);
    }
    return ans;
}

int sumSubarrayMins(vector<int>& arr) {
    int n=arr.size();
    const int mod=1e9+7;
    vector<int>left(n);
    vector<int>right(n);
    stack<int>st;
    for(int i=0;i<n;i++){
        while(!st.empty() && arr[st.top()]>arr[i]){
            st.pop();
        }
        if(st.empty()){
            left[i]=i+1;
        }else{
            left[i]=i-st.top();
        }
        st.push(i);
    }
    while(!st.empty()){
        st.pop();
    }
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && arr[st.top()]>=arr[i]){
            st.pop();
        }
        if(st.empty()){
            right[i]=n-i;
        }else{
            right[i]=st.top()-i;
        }
        st.push(i);
    }
    long long ans=0;
    for(int i=0;i<n;i++){
        ans=(ans+(long long)arr[i] * left[i] * right[i])%mod;
    }
    return ans;
}
long long sumSubarrayMaxs(vector<int>& arr) {
    int n=arr.size();
    vector<int>left(n);
    vector<int>right(n);
    stack<int>st;
    for(int i=0;i<n;i++){
        while(!st.empty() && arr[st.top()]<arr[i]){
            st.pop();
        }
        if(st.empty()){
            left[i]=i+1;
        }else{
            left[i]=i-st.top();
        }
        st.push(i);
    }
    while(!st.empty()){
        st.pop();
    }
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && arr[st.top()]<=arr[i]){
            st.pop();
        }
        if(st.empty()){
            right[i]=n-i;
        }else{
            right[i]=st.top()-i;
        }
        st.push(i);
    }
    long long ans=0;
    for(int i=0;i<n;i++){
        ans+=(long long)arr[i] * left[i] * right[i];
    }
    return ans;
}
    long long subArrayRanges(vector<int>& nums) {
        return sumSubarrayMaxs(nums)-sumSubarrayMins(nums);
    }   
vector<int> asteroidCollision(vector<int>& asteroids) {
    stack<int>st;
    for(int a:asteroids){
        bool alive=true;
        while(alive && !st.empty() && st.top()>0 && a<0){
            if(abs(a)>st.top()){
                st.pop();
            }else if(abs(a)==st.top()){
                st.pop();
                alive=false;
            }else{
                alive=false;
            }
        }
        if(alive) st.push(a);
    }
    vector<int>ans(st.size());
    for(int i=st.size()-1;i>=0;i--){
        ans[i]=st.top();
        st.pop();
    }
    return ans;
}
int main(){
    // Stack s;

    // s.push(1);
    // s.push(2);
    // s.push(3);
    // s.push(4);

    // cout << s.topEle() << endl;

    // s.pop();

    // cout << s.topEle() << endl;
    // cout << s.isEmpty() << endl;

    // LinkedListStack st;
    // cout<<st.isEmpty()<<endl;
    // st.push(1);
    // st.push(2);
    // st.push(3);
    // st.push(4);
    // cout<<st.top()<<endl;
    // cout<<st.pop()<<endl;
    // cout<<st.top()<<endl;
    // cout<<st.isEmpty()<<endl;

    vector<int>nums={10, 9, 8, 7};
    vector<int>res=nextSmallerElement(nums);
    for(int num:res){
        cout<<num<<" ";
    }cout<<endl;
}