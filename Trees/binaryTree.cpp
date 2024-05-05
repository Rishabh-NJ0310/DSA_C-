#include<bits/stdc++.h>  // only for competitive programming not for developing
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;
    // vector<node*> child;   //for n-ary tree
    node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

node* buildTree(node* root){
    cout<<"Enter data: "<<endl;
    int data;
    cin>>data;
    root = new node(data);
    if(data == -1){
        return NULL;
    }
    cout<<"Enter data for inserting in left"<<endl;
    root->left = buildTree(root->left);
    cout<<"Enter data for inserting in right"<<endl;
    root->right = buildTree(root->right);
    return root;
}

void buildTreeLevelOrder(node* root){
    queue<node*> q;
    int data;
    cout<<"Enter data: for root node"<<endl;
    cin>>data;
    while(!q.empty()){
        node* temp = q.front();
        q.pop();
        
        cout<<"Enter data for left child of "<<temp->data<<endl;
        int leftdata;
        cin>>leftdata;
        if(leftdata != -1){
            temp->left = new node(leftdata);
            q.push(temp->left);
        }
        cout<<"Enter data for right child of "<<temp->data<<endl;
        int rightdata;
        cin>>rightdata;
        if(rightdata != -1){
            temp->right = new node(rightdata);
            q.push(temp->right);
        }
    }
}

/*****************************************/
/**         Traversal of Trees         **/


void inOrder(node* root){
    if(root == NULL){
        return;
    }
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

void preOrder(node* root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(node* root){
    if(root == NULL){
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}

void levelOrderTraversal(node *root) { 
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node* temp = q.front();
        q.pop();
        if(temp == NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
        cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right); 
            }
        }
    }
}

void verticalOrderTraversal(node* root){
    map<int, vector<int>> m;
    queue<pair<node*, int>> q;
    q.push({root, 0});
    while(!q.empty()){
        pair<node*, int> temp = q.front();
        q.pop();
        node* curr = temp.first;
        int hd = temp.second;
        m[hd].push_back(curr->data);
        if(curr->left){
            q.push({curr->left, hd-1});
        }
        if(curr->right){
            q.push({curr->right, hd+1});
        }
    }
    for(auto x: m){
        for(auto y: x.second){
            cout<<y<<" ";
        }
        cout<<endl;
    }
}
/**          End of Traversals           **/
/*****************************************/

int main(){
    node* root = NULL;
    root = buildTree(root);
    levelOrderTraversal(root);
return 0;
}