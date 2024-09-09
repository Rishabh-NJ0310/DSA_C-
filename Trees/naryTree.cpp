#include<bits/stdc++.h>  // only for competitive programming not for developing
using namespace std;

class Node{
    public:
    int data;
    vector<Node*> child;

    Node(){
        this->data = 0;
    }

    Node(int data){
        this->data = data;
    }
    Node(int data, vector<Node*> child){
        this->data = data;
        this->child = child;
    }
    ~Node(){
        for(auto i: child){
            delete i;
        }
    }
    void display(){
        cout<<data<<" -> ";
        for(auto i: child){
            cout<<i->data<<", ";
        }
        cout<<endl;
        for(auto i: child){
            i->display();
        }
    }
};

Node* buildTree(){
    cout<<"Enter data: "<<endl;
    int data;
    cin>>data;
    Node* root = new Node(data);
    if(data == -1){
        return NULL;
    }
    cout<<"Enter number of children for "<<data<<endl;
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        Node* child = buildTree();
        root->child.push_back(child);
    }
    return root;
}

/************ Traversal ***********/
void inOrder(Node* root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    for(auto i: root->child){
        inOrder(i);
    }
}

void preOrder(Node* root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    for(auto i: root->child){
        preOrder(i);
    }
}

void postOrder(Node* root){
    if(root == NULL){
        return;
    }
    for(auto i: root->child){
        postOrder(i);
    }
    cout<<root->data<<" ";
}


void levelOrderTraversal(Node* root){
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        cout<<temp->data<<" ";
        for(auto i: temp->child){
            q.push(i);
        }
    }
}

void verticalOrderTraversal(Node* root){
    map<int, vector<int>> m;
    queue<pair<Node*, int>> q;
    q.push({root, 0});
    while(!q.empty()){
        pair<Node*, int> temp = q.front();
        q.pop();
        Node* curr = temp.first;
        int hd = temp.second;
        m[hd].push_back(curr->data);
        for(auto i: curr->child){
            q.push({i, hd+1});
        }
    }
    for(auto i: m){
        cout<<i.first<<" -> ";
        for(auto j: i.second){
            cout<<j<<", ";
        }
        cout<<endl;
    }
}
/************ End of Traversal ***********/

/************ Height of Tree ***********/
int height(Node* root){
    int h = 0;
    for(auto i: root->child){
        h = max(h, height(i));
    }
    return h+1;
}
/************ End of Height of Tree ***********/


void i_o_f(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
int main(){
i_o_f();

return 0;
}