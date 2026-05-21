#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

Node* InsertAtHead(Node* &head, int data){
    Node* temp = new Node(data);
    temp->next = head;
    head = temp;
    return head;
}

Node* InsertAtTail(Node* &head, int data){
    Node* temp = new Node(data);
    if(head == NULL){
        head = temp;
        return head;
    }
    Node* curr = head;
    while(curr->next != NULL){
        curr = curr->next;
    }

    curr->next = temp;
    return head;
}

Node* InsertAtMiddle(Node* &head, int data, int k){
    if(k == 1)
        return InsertAtHead(head, data);

    Node* temp = new Node(data);
    Node* curr = head;

    int i = 1;
    while(i < k-1 && curr != NULL){
        curr = curr->next;
        i++;
    }

    temp->next = curr->next;
    curr->next = temp;

    return head;
}

Node* DeleteAtHead(Node* &head){
    if(head == NULL) return NULL;

    Node* temp = head;
    head = head->next;
    delete temp;
    return head;
}

Node* DeleteAtTail(Node* &head){
    if(head == NULL) return NULL;

    if(head->next == NULL)
        return DeleteAtHead(head);

    Node* curr = head;
    while(curr->next->next != NULL){
        curr = curr->next;
    }

    Node* lastNode = curr->next;
    curr->next = NULL;
    delete lastNode;

    return head;
}

Node* DeleteAtMiddle(Node* &head, int k){
    if(head == NULL) return NULL;

    if(k == 1)
        return DeleteAtHead(head);

    Node* curr = head;
    int i = 1;

    while(i < k-1 && curr->next != NULL){
        curr = curr->next;
        i++;
    }

    Node* nodeToDelete = curr->next;
    curr->next = nodeToDelete->next;
    delete nodeToDelete;

    return head;
}

int LengthOfLL(Node* &head){
    if(head==NULL) return 0;
    Node* temp=head;
    int length=0;
    while(temp!=NULL){
        temp=temp->next;
        length++;
    }
    return length;
}

bool Search(Node* &head, int target){
    if(head==NULL) return false;
    Node* temp=head;
    while(temp!=NULL){
        if(temp->data==target){
            return true;
        }
        temp=temp->next;
    }
    return false;
}
Node* middleNode(Node* head) {
    Node* slow=head;
    Node* fast=head;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;

    }
    return slow;
}
bool hasCycle(Node *head) {
    Node* slow=head;
    Node* fast=head;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            return true;
        }
    }
    return false;
}
Node *detectCycle(Node *head) {
    if(!head || !head->next){
        return NULL;
    }
    Node* slow=head;
    Node* fast=head;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            break;
        }
    }
    if(fast==NULL || fast->next==NULL){
        return NULL;
    }
    Node* start=head;
    while(slow!=start){
        slow=slow->next;
        start=start->next;
    }
    return start;
}
bool isPalindrome(Node* head) {
    if(!head || !head->next){
        return true;
    }
    Node* slow=head;
    Node* fast= head;
    while(fast->next!=NULL && fast->next->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    Node* sechalf=ReverseList(slow->next);
    Node* firhalf=head;
    Node* temp=sechalf;
    bool ispalin=true;
    while(temp!=NULL){
        if(firhalf->val!=temp->val){
            ispalin=false;
            break;
        }
        temp=temp->next;
        firhalf=firhalf->next;
    }
    return ispalin;
}
Node* oddEvenList(Node* head) {
    while(!head || !head->next){
        return head;
    }
    Node* odd=head;
    Node* even=head->next;
    Node* evenhead=even;
    while(even!=NULL && even->next!=NULL){
        odd->next=even->next;
        odd=odd->next;
        even->next=odd->next;
        even=even->next;
    }
    odd->next=evenhead;
    return head;
}
Node* removeNthFromEnd(Node* head, int n) {
    Node* dummy = new Node(0);
    dummy->next=head;
    Node* slow=dummy;
    Node* fast=dummy;
    for(int i=0;i<=n;i++){
        fast=fast->next;
    }
    while(fast!=NULL){
        slow=slow->next;
        fast=fast->next;
    }
    Node* temp=slow->next;
    slow->next=slow->next->next;
    delete temp;
    Node* newhead=dummy->next;
    delete dummy;
    return newhead;
}
Node* deleteMiddle(Node* head) {
    if(!head || !head->next){
        return nullptr;
    }
    Node* slow=head;
    Node* fast=head;
    Node* prev=nullptr;
    while(fast && fast->next){
        prev=slow;
        slow=slow->next;
        fast=fast->next->next;
    }
    if(prev) prev->next=slow->next;
    delete slow;
    return head;
}
Node *getIntersectionNode(Node *headA, Node *headB) {
    if(headA==NULL || headB==NULL){
        return NULL;
    }
    Node* p1=headA;
    Node* p2=headB;
    while(p1!=p2){
        if(p1==NULL){
            p1=headB;
        }else{
            p1=p1->next;
        }
        if(p2==NULL){
            p2=headA;
        }else{
            p2=p2->next;
        }
    }
    return p1;
}
Node* addTwoNumbers(Node* l1, Node* l2) {
    Node* dummy=new Node(0);
    Node* curr=dummy;
    int carry=0;
    while(l1!=NULL || l2!=NULL || carry!=0 ){
        int sum=0;
        if(l1!=NULL){
            sum+=l1->val;
            l1=l1->next;
        }
        if(l2!=NULL){
            sum+=l2->val;
            l2=l2->next;
        }
        sum+=carry;
        curr->next=new Node(sum%10);
        carry=sum/10;
        curr=curr->next;
    }
    return dummy->next;
}
Node* ReverseList(Node* &head){
    Node* prev=NULL;
    Node* curr=head;
    while(curr){
        Node* nextNode=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nextNode;
    }
    return prev;
}
Node* addOneAtLast(Node* &head){
    head=ReverseList(head);
    int carry=1;
    Node* curr=head;
    while(curr && carry){
        int sum = curr->data+carry;
        curr->data=sum%10;
        carry=sum/10;
        if(carry && curr->next==NULL){
            Node* newNode= new Node(carry);
            curr->next=newNode;
        }
        curr=curr->next;

    }
    head=ReverseList(head);
    return head;
}
Node* DutchFlag(Node* head){
    if(head==NULL || head->next==NULL) return head;
    Node* zerohead= new Node(-1);
    Node* onehead= new Node(-1);
    Node* twohead= new Node(-1);
    Node* zero=zerohead;
    Node* one=onehead;
    Node* two=twohead;
    Node* curr=head;
    while(curr){
        if(curr->data==0){
            zero->next=curr;
            zero=zero->next;
        }else if(curr->data==1){
            one->next=curr;
            one=one->next;
        }else{
            two->next=curr;
            two=two->next;
        }
        curr=curr->next;
    }
    if(onehead->next!=NULL){
        zero->next=onehead->next;
    }else{
        zero->next=twohead->next;
    }
    one->next=twohead->next;
    two->next=NULL;
    Node* newHead=zerohead->next;
    delete zerohead;
    delete onehead;
    delete twohead;
    return zero->next;
}
/*Input
["Solution", "getRandom", "getRandom", "getRandom", "getRandom", "getRandom"]
[[[1, 2, 3]], [], [], [], [], []]
Output
[null, 1, 3, 2, 2, 3]*/
vector<int>arr;
Solution(ListNode* head) {
    ListNode* temp=head;
    while(temp!=NULL){
        arr.push_back(temp->val);
        temp=temp->next;
    }
}  
int getRandom() {
    int n=arr.size();
    int random_idx=rand()%n;
    return arr[random_idx];
}
/*Input: head = [-10,-3,0,5,9]
Output: [0,-3,9,-10,null,5]
Explanation: One possible answer is [0,-3,9,-10,null,5], which represents the shown height balanced BST.*/
TreeNode* sortedListToBST(ListNode* head) {
    if(!head) return NULL;
    if(!head->next) return new TreeNode(head->val);
    ListNode* slow=head;
    ListNode* fast=head;
    ListNode* prev=nullptr;
    while(fast && fast->next){
        prev=slow;
        slow=slow->next;
        fast=fast->next->next;
    }
    TreeNode* root=new TreeNode(slow->val);
    prev->next=NULL;
    root->left=sortedListToBST(head);
    root->right=sortedListToBST(slow->next);
    return root;
}
int main(){
    Node* head = NULL;

    head = InsertAtHead(head,4);
    head = InsertAtHead(head,3);
    head = InsertAtHead(head,2);
    head = InsertAtHead(head,1);

    head = InsertAtTail(head,5);

    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
    cout<<"Length of LL: "<<LengthOfLL(head)<<endl;
    cout<<Search(head,4)<<endl;
}