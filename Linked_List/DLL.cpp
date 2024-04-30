#include<bits/stdc++.h>  // only for competitive programming not for developing
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node* prevptr;
    Node(int d){
        data = d;
        next = NULL;
        prevptr = NULL;
    }
    ~Node(){
        int val = this->data;
        if(this->next != NULL && this->prevptr){
            delete next;
            delete prevptr;
            this->next = NULL;
            this->prevptr = NULL;
        }
        cout<<"Deleting the node with value "<<val<<endl;
    }
};

void print(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }cout<<endl;
}

int Len(Node* &head){
    Node* temp = head;
    int length = 0;
    while(temp!= NULL){
        length++;
        temp = temp->next;
    }
    return length;
}

void insertAtHead(Node* &head, int data){
    Node* temp = new Node(data);
    temp->next = head;
    head->prevptr = temp;
    head = temp;
}

void insertAtEnd(Node* &tail, int data){
    Node* temp = new Node(data);
    tail->next = temp;
    temp->prevptr = tail;
    tail = temp;
}

void insertAtMiddle(Node* &head,Node* &tail, int data, int pos){
    if(pos == 1){
        insertAtHead(head, data);
        return;
    }
    Node* temp = head;
    int cnt = 1;
    while(cnt != pos-1){
        temp = temp->next;
        cnt++;
    }
    if(temp->next == NULL){
        insertAtEnd(temp, data);
        return;
    }
    Node* n = new Node(data);
    temp->next = n;
    n->prevptr = temp;
    n->next = temp->next;
    temp->next->prevptr = n;
}

void deleteAtHead(Node* &head){
    Node* temp = head;
    head = head->next;
    head->next->prevptr = NULL;
    temp->next=NULL;
    delete temp;
}

void deleteAtTail(Node* &head, Node* &tail){
    Node* curr = head;
    Node* prev = NULL;
    while(curr != tail || curr->next != NULL){
        prev = curr;
        curr = curr->next;
    }
    prev->next = NULL;
    curr->prevptr = NULL;
    tail = prev;
    delete curr;
}

void deleteAtPos(Node* &head,Node* &tail, int pos){
    if(pos == 1){
        deleteAtHead(head);
        return;
    }else{
        Node* curr = head;
        Node* prev = NULL;
        int cnt = 1;
        while(cnt<pos){
            if(curr->next ==NULL){
                deleteAtTail(head,tail);
                break;
            }
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        prev->next = curr->next;
        prev->next->prevptr = prev;
        curr->next = NULL;
        curr->prevptr = NULL;
        delete curr;
        // managing tail;
        Node* temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        tail = temp;
    }
}


void deleteAtVal(Node* &head,Node* &tail, int value){
    Node* curr = head;
    Node* prev = NULL;
    while(curr != NULL){
        if(curr->data == value){
            if(curr->next == NULL){
                deleteAtTail(head,tail);
                break;
            }
        prev->next = curr->next;
        curr->next->prevptr = prev;
        curr->next = NULL;
        curr->prevptr = NULL;
        delete curr;
            break;
        }
        prev = curr;
        curr = curr->next;
    }
        Node* temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        tail = temp;
}

// may not be the optimised code

int main(){
    Node* node1 = new Node(1);
    Node* head = node1;
    Node* tail = node1;
    insertAtHead(head,11);
    insertAtHead(head,12);
    insertAtHead(head,13);
    insertAtHead(head,14);
    insertAtEnd(tail, 2);
    insertAtEnd(tail, 3);
    insertAtEnd(tail, 4);
    print(head);
    deleteAtPos(head,tail,6);
    print(head);
    deleteAtHead(head);
    print(head);
    deleteAtVal(head,tail,4);
    print(head);
    cout<<"Tail is pointing to "<<tail->data<<endl;
return 0;
}