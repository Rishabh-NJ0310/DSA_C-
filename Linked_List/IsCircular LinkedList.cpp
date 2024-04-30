#include <bits/stdc++.h> 
/*************************************************
        Following is the structure of class Node:
**************************************************/
        class Node{
        public:
            int data;
            Node* next;
            
            Node(int data){
                this->data = data;
                this->next = NULL;
            }
            
        };

bool isCircular(Node* head){
    // Write your code here.
    if(head == NULL){
        return true;
    }
    else if(head->next == NULL){
        return false;
    }
    Node* curr = head->next;
    while(curr != head && curr != NULL)
    {
        curr = curr->next;
    }
    if(curr == head){
        return true;
    }
    return false;
}
int main(){
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    // head->next->next->next = head;
    std::cout << isCircular(head) << std::endl;
    return 0;
}