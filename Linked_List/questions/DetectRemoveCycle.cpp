#include<bits/stdc++.h>
using namespace std;
    class Node {
        public :

        int data;
        Node *next;

        Node(int data) {
            this -> data = data;
            this -> next = NULL;
        }
    };

bool isLoop(Node* &head){
    if(head == NULL) return false;

    Node* temp = head;
    Node* prev = NULL;
    unordered_map<Node*, bool> vis;
    while(temp != NULL){
        if(vis[temp] == true){
            return true;
        }
        vis[temp] = true;
        prev = temp;
        temp = temp->next;
    }
    return false;
}
Node *removeLoop(Node* &head, Node* &tail)
{
    tail->next = NULL;
    return head;
}

int main(){
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = head;
    if(isLoop(head)){
        cout << "Loop Found" << endl;
    }
    else{
        cout << "No Loop Found" << endl;
    }
    return 0;
}