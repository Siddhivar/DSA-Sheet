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
// class LinkedListStack{
//     struct Node{
//         int data;
//         Node* next;
//         Node(int x){
//             data=x;
//             next=NULL;
//         }
//     };
//     Node* topnode;
//     public:
//     LinkedListStack(){
//         topnode=NULL;
//     }
//     void push(int x){
//         Node* newnode= new Node(x);
//         newnode->next=topnode;
//         topnode=newnode;
//     }
//     int pop(){
//         if(isEmpty()){
//             cout<<"Stack Underflow\n";
//             return -1;
//         }
//         int val= topnode->data;
//         Node* temp= topnode;
//         topnode=topnode->next;
//         delete temp;
//         return val;
//     }
//     int top(){
//         if(isEmpty()){
//             cout<<"Stack Underflow\n";
//             return -1;
//         }
//         return topnode->data;
//     }
//     bool isEmpty(){
//         return topnode==NULL;
//     }
// };

// // Minimum Stack
// class MinStack {
//     stack<int>st;
//     stack<int>minst;
// public:
//     MinStack() {
        
//     }
    
//     void push(int val) {
//        st.push(val);
//        if(minst.empty() || (val<=minst.top())){
//         minst.push(val);
//        } 
//     }
    
//     void pop() {
//         if(st.top()==minst.top()){
//             minst.pop();
//         }
//         st.pop();
//     }
    
//     int top() {
//         return st.top();
//     }
    
//     int getMin() {
//         return minst.top();
//     }
// };
// //Array is non-circular
// vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
//     stack<int>st;
//     map<int, int>mp;
//     for(int num:nums2){
//         while(!st.empty()&& st.top()<num){
//             mp[st.top()]=num;
//             st.pop();
//         }
//         st.push(num);
//     }
//     while(!st.empty()){
//         mp[st.top()]=-1;
//         st.pop();
//     }
//     vector<int>res;
//     for(int num:nums1){
//         res.push_back(mp[num]);
//     }
//     return res;
// }

// //Array is circular
// vector<int> nextGreaterElements(vector<int>& nums) {
//     int n=nums.size();
//     vector<int>ans(n,-1);
//     stack<int>st;
//     for(int i=0;i<2*n;i++){
//         int num=nums[i%n];
//         while(!st.empty() && nums[st.top()]<num){
//             ans[st.top()]=num;
//             st.pop();
//         }
//         if(i<n){
//             st.push(i);
//         }
//     }
//     return ans;
// }

// vector<int>nextSmallerElement(vector<int>&nums){
//     stack<int>st;
//     int n=nums.size();
//     vector<int>ans(n,-1);
//     for(int i=0;i<nums.size();i++){
//         while(!st.empty() && nums[st.top()]>nums[i]){
//             ans[st.top()]=nums[i];
//             st.pop();
//         }
//         st.push(i);
//     }
//     return ans;
// }

// int sumSubarrayMins(vector<int>& arr) {
//     int n=arr.size();
//     const int mod=1e9+7;
//     vector<int>left(n);
//     vector<int>right(n);
//     stack<int>st;
//     for(int i=0;i<n;i++){
//         while(!st.empty() && arr[st.top()]>arr[i]){
//             st.pop();
//         }
//         if(st.empty()){
//             left[i]=i+1;
//         }else{
//             left[i]=i-st.top();
//         }
//         st.push(i);
//     }
//     while(!st.empty()){
//         st.pop();
//     }
//     for(int i=n-1;i>=0;i--){
//         while(!st.empty() && arr[st.top()]>=arr[i]){
//             st.pop();
//         }
//         if(st.empty()){
//             right[i]=n-i;
//         }else{
//             right[i]=st.top()-i;
//         }
//         st.push(i);
//     }
//     long long ans=0;
//     for(int i=0;i<n;i++){
//         ans=(ans+(long long)arr[i] * left[i] * right[i])%mod;
//     }
//     return ans;
// }
// long long sumSubarrayMaxs(vector<int>& arr) {
//     int n=arr.size();
//     vector<int>left(n);
//     vector<int>right(n);
//     stack<int>st;
//     for(int i=0;i<n;i++){
//         while(!st.empty() && arr[st.top()]<arr[i]){
//             st.pop();
//         }
//         if(st.empty()){
//             left[i]=i+1;
//         }else{
//             left[i]=i-st.top();
//         }
//         st.push(i);
//     }
//     while(!st.empty()){
//         st.pop();
//     }
//     for(int i=n-1;i>=0;i--){
//         while(!st.empty() && arr[st.top()]<=arr[i]){
//             st.pop();
//         }
//         if(st.empty()){
//             right[i]=n-i;
//         }else{
//             right[i]=st.top()-i;
//         }
//         st.push(i);
//     }
//     long long ans=0;
//     for(int i=0;i<n;i++){
//         ans+=(long long)arr[i] * left[i] * right[i];
//     }
//     return ans;
// }
//     long long subArrayRanges(vector<int>& nums) {
//         return sumSubarrayMaxs(nums)-sumSubarrayMins(nums);
//     }   
// vector<int> asteroidCollision(vector<int>& asteroids) {
//     stack<int>st;
//     for(int a:asteroids){
//         bool alive=true;
//         while(alive && !st.empty() && st.top()>0 && a<0){
//             if(abs(a)>st.top()){
//                 st.pop();
//             }else if(abs(a)==st.top()){
//                 st.pop();
//                 alive=false;
//             }else{
//                 alive=false;
//             }
//         }
//         if(alive) st.push(a);
//     }
//     vector<int>ans(st.size());
//     for(int i=st.size()-1;i>=0;i--){
//         ans[i]=st.top();
//         st.pop();
//     }
//     return ans;
// }
// /*Input
// ["StockSpanner", "next", "next", "next", "next", "next", "next", "next"]
// [[], [100], [80], [60], [70], [60], [75], [85]]
// Output
// [null, 1, 1, 1, 2, 1, 4, 6]*/
// int next(int price) {
//     int span=1;
//     while(!st.empty() && st.top().first<=price){
//         span+=st.top().second;
//         st.pop();
//     }
//     st.push({price,span});
//     return span;
// }

// /*Input: temperatures = [73,74,75,71,69,72,76,73]
// Output: [1,1,4,2,1,1,0,0]
// */
// vector<int> dailyTemperatures(vector<int>& temperatures) {
//     stack<int>st;
//     int n=temperatures.size();
//     vector<int>ans(n,0);
//     for(int i=0;i<n;i++){
//         while(!st.empty() && temperatures[i]>temperatures[st.top()]){
//             ans[st.top()]=i-st.top();
//             st.pop();
//         }
//         st.push(i);
//     }
//     return ans;
// }
// /*Input: s = "abbaca"
// Output: "ca"*/
// string removeDuplicates(string s) {
//     stack<char>st;
//     string ans="";
//     for(int i=s.length()-1;i>=0;i--){
//         if(!st.empty() && s[i]==st.top()){
//             st.pop();
//         }else st.push(s[i]);
//     }
//     while(!st.empty()){
//         ans+=st.top();
//         st.pop();
//     }
//     return ans;
// }
// /*Input: s = "(1+(4+5+2)-3)+(6+8)"
// Output: 23*/
// int calculate(string s) {
//     stack<long long>st;
//     int n=s.length();
//     long long result=0;
//     long long num=0;
//     long long sign=1;
//     for(int i=0;i<n;i++){
//         if(isdigit(s[i])){
//             num=num*10+(s[i]-'0');
//         }else if(s[i]=='+'){
//             result+=(num*sign);
//             sign=1;
//             num=0;
//         }else if(s[i]=='-'){
//             result+=(num*sign);
//             sign=-1;
//             num=0;
//         }else if(s[i]=='('){
//             st.push(result);
//             st.push(sign);
//             result=0;
//             num=0;
//             sign=1;
//         }else if(s[i]==')'){
//             result+=(num*sign);
//             num=0;
//             long long stack_sign=st.top();
//             st.pop();
//             long long lastelem=st.top();
//             st.pop();
//             result*=stack_sign;
//             result+=lastelem;
//         }
//     }
//     result+=(num*sign);
//     return result;
// }

// /*Input: tokens = ["2","1","+","3","*"]
// Output: 9
// Explanation: ((2 + 1) * 3) = 9 */
// int operation(int a, int b, string sign){
//     if(sign=="+") return (a+b);
//     else if(sign=="-") return (a-b);
//     else if(sign=="*") return (a*b);
//     else return (a/b);
// }
// int evalRPN(vector<string>& tokens) {
//     stack<int>st;
//     for(int i=0;i<tokens.size();i++){
//         string s=tokens[i];
//         if(s=="+"|| s=="-"|| s=="*"||s=="/"){
//             int b=st.top();st.pop();
//             int a=st.top();st.pop();
//             int r=operation(a,b,s);
//             st.push(r);
//         }else{
//             st.push(stoi(s));
//         }
//     }
// return st.top();
// }

/*Input: path = "/home/user/Documents/../Pictures"
Output: "/home/user/Pictures"
*/
string simplifyPath(string path) {
    stack<string>st;
    stringstream ss(path);
    string token="";
    string result="";
    while(getline(ss, token, '/')){
        if(token=="" || token==".")continue;
        else if(token==".."){
            if(!st.empty()) st.pop();
        }else{
            st.push(token);
        }
    }
    if(st.empty()) return "/";
    while(!st.empty()){
        result="/"+st.top()+result;
        st.pop();
    }
    return result;
}

/*Input: pushed = [1,2,3,4,5], popped = [4,5,3,2,1]
Output: true
Explanation: We might do the following sequence:
push(1), push(2), push(3), push(4),
pop() -> 4,
push(5),
pop() -> 5, pop() -> 3, pop() -> 2, pop() -> 1*/
bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
    int j=0;
    stack<int>st;
    for(int i=0;i<pushed.size();i++){
        st.push(pushed[i]);
        while(!st.empty() && st.top()==popped[j]){
            st.pop();
            j++;
        }
    }
    return (st.empty());
}

/*Input: nums = [3,1,4,2]
Output: true
Explanation: There is a 132 pattern in the sequence: [1, 4, 2].*/
bool find132pattern(vector<int>& nums) {
    int n=nums.size();
    stack<int>st;
    int second=INT_MIN;
    for(int i=n-1;i>=0;i--){
        if(nums[i]<second) return true;
        while(!st.empty() && nums[i]>st.top()){
            second=st.top();
            st.pop();
        }
        st.push(nums[i]);
    }
    return false;
}

/*Input: target = [1,3], n = 3
Output: ["Push","Push","Pop","Push"]
Explanation: Initially the stack s is empty. The last element is the top of the stack.
Read 1 from the stream and push it to the stack. s = [1].
Read 2 from the stream and push it to the stack. s = [1,2].
Pop the integer on the top of the stack. s = [1].
Read 3 from the stream and push it to the stack. s = [1,3].*/
vector<string> buildArray(vector<int>& target, int n) {
    vector<string>result;
    int j=0;
    for(int i=1;i<=n;i++){
        if(j==target.size()) break;
        if(target[j]==i){
            result.push_back("Push");
            j++;
        }else{
            result.push_back("Push");
            result.push_back("Pop");
        }
        
    }
    return result;
}

/*Input: s = "lee(t(c)o)de)"
Output: "lee(t(c)o)de"
Explanation: "lee(t(co)de)" , "lee(t(c)ode)" would also be accepted.*/
string minRemoveToMakeValid(string s) {
    stack<int>st;
    string result;
    for(int i=0;i<s.length();i++){
        if(s[i]=='(') st.push(i);
        else if(s[i]==')'){
            if(!st.empty()) st.pop();
            else{
                s[i]='#';
            }
        }
    }
    while(!st.empty()){
        s[st.top()]='#';
        st.pop();
    }
    for(int i=0;i<s.length();i++){
        if(s[i]=='#'){
            continue;
        }
        result+=s[i];
    }
    return result;
}

/*Input: num = "1432219", k = 3
Output: "1219"
Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.*/
string removeKdigits(string num, int k) {
    if(num.size()==k) return "0";
    stack<char>st;
    for(int i=0;i<num.size();i++){
        while(!st.empty() && k>0 && st.top()>num[i]){
            st.pop();
            k--;
        }
        st.push(num[i]);
    }
    while(!st.empty() && k>0){
        st.pop();
        k--;
    }
    string result="";
    while(!st.empty()) {
    result += st.top();
    st.pop();
    }
    reverse(result.begin(), result.end());

    int i=0;
    while(i<result.size() && result[i]=='0') i++;
    result=result.substr(i);

    if(result.empty()) return "0";
    
    return result;
}

/*Input: heights = [2,1,5,6,2,3]
Output: 10
Explanation: The above is a histogram where width of each bar is 1.
The largest rectangle is shown in the red area, which has an area = 10 units.*/
int largestRectangleArea(vector<int>& heights) {
    int n=heights.size();
    stack<int>st;
    int maxi=0;
    for(int i=0;i<=n;i++){
        while(!st.empty() &&(i==n  || heights[st.top()]>=heights[i])){
            int h=heights[st.top()];
            st.pop();
            int right=i;
            int left;
            if(st.empty()) left=-1;
            else left=st.top();
            int width=right-left-1;
            int area=width*h;
            maxi=max(maxi,area);
        }
        st.push(i);
    }
    return maxi;
}

/*Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
Output: 6*/
int maximalRectangle(vector<vector<char>>& matrix) {
    int rows=matrix.size();
    int cols=matrix[0].size();
    int maxi=0;
    vector<int>heights(cols,0);
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            if(matrix[i][j]=='1') heights[j]++;
            else heights[j]=0;
        }
        maxi=max(maxi,largestRectangleArea(heights));
    }
return maxi;
}

/*Input: s = "(u(love)i)"
Output: "iloveu"
Explanation: The substring "love" is reversed first, then the whole string is reversed.
*/
// This would take O(N^2) because we hve to reverse many times.
string reverseParentheses(string s) {
    stack<int> st;
    string result = "";
    for(int i = 0; i < s.length(); i++) {
        if(s[i] == '(') {
            st.push(result.length());
        } else if(s[i] == ')') {
            int len = st.top();
            st.pop();
            reverse(result.begin() + len, result.end());
        } else {
            result += s[i];
        }
    }
    return result;
}
//Wormhole / Teleportation Technique (O(N))
string reverseParentheses(string s) {
    int n=s.length();
    vector<int>pair(n);
    stack<int>st;
    for(int i=0;i<n;i++){
        if(s[i]=='('){
            st.push(i);
        }else if(s[i]==')'){
            int j=st.top();
            st.pop();
            pair[i]=j;
            pair[j]=i;
        }
    }
    int direction=1;
    string result="";
    for(int i=0;i<n;i+=direction){
        if(s[i]=='(' || s[i]==')'){
            i=pair[i];
            direction=-direction;
        }else{
            result+=s[i];
        }
    }
    return result;
}
int main(){
    string path = "/../";
    string result=simplifyPath(path);
    return 0;
}