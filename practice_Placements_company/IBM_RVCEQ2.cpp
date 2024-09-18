/*
Given a linked list of integers, return a similar linked list with all elements having odd values removed.

For example, your linked list values are 1→2→3 →4. Your new linked list should be 2-4.

Function Description

Complete the function deleteOdd in the editor below. The function must return a reference to the head LinkedListNode of your linked list which has the odd values removed.

deleteOdd has the following parameter(s): listHead: a reference to the head node of a linked list

*/

#include<bits/stdc++.h>  // only for competitive programming not for developing
using namespace std;

class SinglyLinkedListNode {
    public:
    int val;
    SinglyLinkedListNode* next;
};


SinglyLinkedListNode* deleteOdd(SinglyLinkedListNode* head){
    SinglyLinkedListNode* dummy = new SinglyLinkedListNode();
    dummy->next = head;
    SinglyLinkedListNode* prev = dummy;
    SinglyLinkedListNode* curr = head;
    while(curr){
        if(curr->val % 2 != 0){
            prev->next = curr->next;
            delete curr;
            curr = prev->next;
        }else{
            prev = curr;
            curr = curr->next;
        }
    }
    return dummy->next;
}


int main(){

return 0;
}