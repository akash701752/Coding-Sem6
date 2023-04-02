#include<bits/stdc++.h>
using namespace std ;
typedef struct Node
{
    int val ;
    struct Node *left, *right ;
    Node(int x){
        val = x ;
        left = right = NULL ;
    }
}Node;
bool isLeaf(Node* root){
    if(root->left==NULL && root->left==NULL){
        return true ;
    }
    return false;
}
void addLeftBoundary(Node* root,vector<int> &res){
    Node *cur = root->left ;
    while(cur!=NULL){
        if(isLeaf(cur)==false){
            res.push_back(cur->val) ;
        }
        if(root->left){
            cur = cur->left ;
        }
        else{
            cur = cur->right ;
        }
    }
}
void addRightBoundary(Node* root,vector<int> &res){
    Node *cur = root->right ;
    vector<int> v ;
    while(cur!=NULL){
        if(isLeaf(cur)==false){
            res.push_back(cur->val) ;
        }
        if(root->right){
            cur = cur->right ;
        }
        else{
            cur = cur->left ;
        }
    }
    for(int i=v.size()-1;i>=0;i--){
        res.push_back(v[i]);
    }
}
void addLeaves(Node *root,vector<int> &res){
    if(isLeaf(root)){
        res.push_back(root->val) ;
    }
    if(root->left){
        addLeaves(root->left,res) ;
    }
    if(root->right){
        addLeaves(root->right,res) ;
    }
}
void printBoundary(Node* root){
    if(root==NULL){
        return ;
    }
    vector<int> res ;
    if(isLeaf(root)==false){
        res.push_back(root->val) ;
    }
    addLeftBoundary(root,res) ;
    addLeaves(root,res) ;
    addRightBoundary(root,res) ;
    for(int i=0;i<res.size();i++){
        cout<<res[i] <<" " ;
    }
}
int main()
{
    Node *root = new Node(1) ;
    root->left = new Node(2) ;
    root->right = new Node(3) ;
    root->left->left = new Node(4) ;
    root->left->right = new Node(5) ;
    cout<<"Boundary Traversal : " ;
    printBoundary(root);
    cout<<endl ;
    return 0 ;
}