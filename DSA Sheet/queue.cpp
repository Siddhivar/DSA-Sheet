#include<bits/stdc++.h>
using namespace std;

// class Queue{
// private:
//     int* arr;
//     int size;
//     int front;
//     int rear;
//     int capacity;
// public:
//     Queue(int cap=100){
//         capacity=cap;
//         arr=new int[capacity];
//         front=0;
//         rear=-1;
//         size=0;
//     }
//     void push(int x){
//         if(size==capacity){
//             cout<<"Queue Overflow\n";
//             return;
//         }
//         rear=(rear+1)%capacity;
//         arr[rear]=x;
//         size++;
//     }
//     int pop(){
//         if(isEmpty()){
//             cout<<"Queue  is Empty\n";
//             return -1;
//         }
//         int val=arr[front];
//         front=(front+1)%capacity;
//         size--;
//         return val;
//     }
//     bool isEmpty(){
//         return size==0;
//     }
//     int peek(){
//         if(isEmpty()){
//             return -1;
//         }
//         return arr[front];
//     }
//     ~Queue(){
//         delete[]arr;
//     }
// };
// //=========Implement queue using TWO Stack===================
// class MyQueue {
// private:
//     stack<int>s1,s2;
// public:
//     void push(int x) {
//         s1.push(x);
//     }
    
//     int pop() {
//         if(s2.empty()){
//             while(!s1.empty()){
//                 s2.push(s1.top());
//                 s1.pop();
//             }
//         }
//         int val=s2.top();
//         s2.pop();
//         return val;
//     }
    
//     int peek() {
//         if(s2.empty()){
//             while(!s1.empty()){
//                 s2.push(s1.top());
//                 s1.pop();
//             }
//         }
//         return s2.top();
//     }
    
//     bool empty() {
//         return s1.empty() && s2.empty();
//     }
// };

//Implement Queue using Linked list====================
class LinkedListQueue{
    struct Node{
        int data;
        Node* next;
        Node(int x){
            data=x;
            next=NULL;
        }
    };
    Node* front;
    Node* rear;
    public:
    LinkedListQueue(){
        front= rear = NULL;
    }
    void push(int x){
        Node* newnode=new Node(x);
        if(rear==NULL){
            front=rear=newnode;
            return;
        }
        rear->next=newnode;
        rear=rear->next;
    }
    int pop(){
        if(isEmpty()){
            cout<<"Queue Underflow\n";
            return -1;
        }
        int val=front->data;
        Node* temp=front;
        front=front->next;
        if(front==NULL){
            rear=NULL;
        }
        delete temp;
        return val;
    }
    int peek(){
        if(isEmpty()){
            cout<<"Queue Underflow\n";
            return -1;
        }
        return front->data;
    }
    bool isEmpty(){
        return front==NULL;
    }
};
int main(){
    LinkedListQueue q;
    cout<<"Is Empty? "<<q.isEmpty()<<endl;
    cout<<q.pop()<<endl;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    cout<<q.peek()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.peek()<<endl;
    cout<<"Is Empty? "<<q.isEmpty()<<endl;
}