#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node* prev;

    Node(int data){
        this->data = data;
        this->next = NULL;
        this->prev=NULL;
    }
};
Node* InsertAtHead(Node* head, int data){
    if(head==NULL){
        return Node* head(data);
    }
    Node* temp=new Node(data);
    head->next=temp;
    temp->next=head;
    head=temp;
    return head;
}
Node* InsertAtTail(Node* head, int data){
    if(head==NULL){
        return InsertAtHead(head, data);
    }
    Node* temp=new Node(data);
    Node* curr=head;
    while(curr!=Null){
        curr=curr->next;
    }
    curr->next=temp;
    temp->next=curr;
    return head;
}
Node* InsertAtMiddle(Node* head, int data, int k){
    if(head==1){
        return InsertAtHead(head, data);
    }
    Node* temp=new Node(data);
    Node* curr=head;
    while(curr!=Null){
        curr=curr->next;
    }
    curr->next=temp;
    temp->next=curr;
    return head;
}
int main(){

}