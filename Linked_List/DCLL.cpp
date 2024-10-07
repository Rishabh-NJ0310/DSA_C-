#include<bits/stdc++.h>  // only for competitive programming not for developing
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node* prev;
    Node(int d){
        data = d;
        next = NULL;
        prev = NULL;
    }
    ~Node(){
        int val = this->data;
        if(this->next != NULL && this->prev != NULL){
            delete next;
            delete prev;
            this->next = NULL;
            this->prev = NULL;
        }
        cout<<"Deleting the node with value "<<val<<endl;
    }
};
// we don't actually need head pointer in circular linked list 
void insertNode(Node* &tail,int data, int keyElement){
    if(tail == NULL){
        int d;
        cout<<"The Linked List is empty \nEnter the data for the first node: "<<endl;
        cin>>d;
    Node* newNode = new Node(d);
    tail = newNode;
    newNode->next = newNode;
    }
    // unable to run for data which is not available into list 
    else{
        Node* curr = tail;
        while(curr->data != keyElement){
            curr = curr->next;
            if(curr == tail){
                break;
            }
        }
        Node* temp = new Node(data);
        temp->next = curr->next;
        curr->next = temp;
    }
}
// deletion of Node 
void deleteNode(Node* &tail, int value){
    Node* prev = tail;
    Node* curr = prev->next;

    if(tail->next == NULL){
        delete tail;        
    }
    else if(curr == tail){
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
        tail = prev;
        }
    while(curr->data != value){
        prev = curr;
        curr = curr->next;
    }
    prev->next = curr->next;
    curr->next = NULL;
    delete curr;

}
void print(Node* tail){
    Node* temp = tail;
    
    if(tail == NULL){
        cout<<"List is empty"<<endl;
        return;
    }else {do{
        cout<<tail->data<<" ";
        tail = tail->next;
    }while(tail != temp);
    cout<<endl;}
}


int main(){
Node* tail = NULL;
insertNode(tail, 1, 1);
print(tail);
insertNode(tail, 2, 1);
print(tail);
insertNode(tail, 3, 2);
print(tail);
deleteNode(tail,2);
print(tail);
insertNode(tail, 4, 3);
print(tail);
insertNode(tail, 5, 4);
print(tail);
//Entering invalid search value
insertNode(tail, 7, 6);
print(tail);
cout<<"tail data "<<tail->data<<endl;
return 0;
}