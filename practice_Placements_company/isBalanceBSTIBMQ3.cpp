/*
Given a binary tree, write a function to determine whether it is a binary search tree (BST). 
A binary search tree is defined as a binary tree in which for every node, 
the left subtree contains only nodes with values less than the node's value, 
and the right subtree contains only nodes with values greater than the node's value. Additionally, 
both the left and right subtrees must also be binary search trees. 
How would you implement a solution to check if the given tree is a BST? (DO NOT USE RECURSION)
*/

#include<bits/stdc++.h>  // only for competitive programming not for developing
using namespace std;

int getValue(const string& node) {
    return stoi(node);
}

bool is_valid_bst(vector<string> root) {
    stack<string> st;
    string prev = ""; 
    int prevValue = numeric_limits<int>::min(); 

    for (const auto& node : root) {
        if (st.empty()) {
            st.push(node);
        } else {
            int currentValue = getValue(node);
            if (getValue(st.top()) < currentValue) {
                st.push(node);
            } else {
                while (!st.empty() && getValue(st.top()) > currentValue) {
                    prev = st.top();
                    st.pop();
                }
                prevValue = getValue(prev);
                if (prevValue >= currentValue) {
                    return false;
                }
                st.push(node);
            }
        }
    }
    return true;
}

int main(){

return 0;
}