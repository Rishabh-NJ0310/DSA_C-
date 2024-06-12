#include<bits/stdc++.h>  // only for competitive programming not for developing
using namespace std;

class trieNode{
    public:
    char data;
    trieNode* children[26];
    bool isTerminal;

    trieNode(char data){
        this->data = data;
        for(int i=0;i<26;i++){
            this->children[i] = NULL;
        }
        this->isTerminal = false;
    }
    ~trieNode(){
        for(int i=0;i<26;i++){
            delete children[i];
        }
    }
};

class Trie{
    public:
    trieNode* root;
    Trie(){
        root = new trieNode('\0');
    } 
    void insertUtil(trieNode* root, string word){
        if(word.size()== 0){
            root->isTerminal = true;
            return;
        }

        int index = word[0] - 'A';
        trieNode* child;

        if(root->children[index] != NULL){
            child = root->children[index];
        }else{
            child = new trieNode(word[0]);
            root->children[index] = child;
        }
        insertUtil(child, word.substr(1));
    }

    void insertWord(string word){
        insertUtil(root, word);
    }
    
    bool searchUtil(trieNode* root, string word){
        if(word.size() == 0){
            return root->isTerminal;
        }

        int index = word[0] - 'A';
        trieNode* child;
        
        if(root->children[index] != NULL){
            child = root->children[index];
        }else{
            return false;
        }
        return searchUtil(child, word.substr(1));
    }

    bool searchWord(string word){
        return searchUtil(root, word);
    }
    // homework Remove function creation  
};

int main(){
    Trie* t = new Trie();
    t->insertWord("HELLO");
return 0;
}