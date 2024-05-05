#include <bits/stdc++.h>

class Node {
public:
    int data;
    Node* next;
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
    ~Node() {
        int val = this->data;
        if (this->next != NULL) {
            delete next;
            this->next = NULL;
        }
        std::cout << "Deleting the node with value " << val << std::endl;
    }
};

Node* findMid(Node* head) {
    if (head == NULL || head->next == NULL) return head;
    Node* slow = head;
    Node* fast = head->next;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node* merge(Node* a, Node* b) {
    if (a == NULL) return b;
    if (b == NULL) return a;

    Node* c = new Node(0);
    Node* temp = c;

    while (a != NULL && b != NULL) {
        if (a->data < b->data) {
            temp->next = a;
            temp = temp->next;
            a = a->next;
        } else {
            temp->next = b;
            temp = temp->next;
            b = b->next;
        }
    }

    if (a != NULL) temp->next = a;
    if (b != NULL) temp->next = b;

    c = c->next;
    return c;
}

Node* mergeSort(Node*& head) {
    if (head == NULL || head->next == NULL) return head;

    Node* mid = findMid(head);
    Node* s = head;
    Node* e = mid->next;
    mid->next = NULL;

    s = mergeSort(s);
    e = mergeSort(e);

    Node* ans = merge(s, e);
    return ans;
}

int main()
{
    
    return 0;
}