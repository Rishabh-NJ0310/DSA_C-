#include<bits/stdc++.h>  // only for competitive programming not for developing
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node(int d){
        data = d;
        next = NULL;
    }
    ~Node(){
        int val = this->data;
        if(this->next != NULL){
            delete next;
            this->next = NULL;
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
    cout<<"Address in the last node is "<<&(temp->next)<<endl;
}

void insertAtHead(Node* &head, int data){
    Node* temp = new Node(data);
    temp->next = head;
    head = temp;
}

void insertAtEnd(Node* &tail, int data){
    Node* temp = new Node(data);
    tail->next = temp;
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
    n->next = temp->next;
}


void deleteAtHead(Node* &head, int pos){
    Node* temp = head;
    head = head->next;
    temp->next=NULL;
    delete temp;
}

void deleteAtPos(Node* &head,Node* &tail, int pos){
    if(pos == 1){
        deleteAtHead(head,pos);
        return;
    }else{
        Node* curr = head;
        Node* prev = NULL;
        int cnt = 1;
        while(cnt<pos){
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;

        // managing tail
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
            prev->next = curr->next;
            curr->next = NULL;
            delete curr;
            break;
        }
        prev = curr;
        curr = curr->next;
    }
    // managing tail
        Node* temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        tail = temp;
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
int main(){
    Node* node1 = new Node(1);
    Node* head = node1;
    Node* tail = node1;
    insertAtEnd(tail, 2);
    insertAtEnd(tail, 3);
    insertAtEnd(tail, 4);
    print(head);
    // tail handled successfully but i think it is not a good way to handle tail
    deleteAtPos(head,tail,4);
    print(head);
    deleteAtVal(head, tail,3);
    print(head);
    cout<<"Tail is pointing to "<<tail->data<<endl;
    cout<<"Length of the linked list is "<<Len(head)<<endl;
    print(head);
return 0;
}