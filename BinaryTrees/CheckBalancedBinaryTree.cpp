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
int height(Node* root){
    if(root==NULL){
        return 0 ;
    }
    int lh = height(root->left) ;
    if(lh==-1){
        return -1;
    }
    int rh = height(root->right) ;
    if(rh==-1){
        return -1;
    }
    if(abs(lh-rh)>1){
        return -1 ;
    }
    return 1+ max(lh,rh) ;
}
bool isBalanced(Node* root){
    return height(root)!=-1; 
}
int main()
{
    Node *root = new Node(1) ;
    root->left = new Node(2) ;
    root->right = new Node(3) ;
    root->left->left = new Node(4) ;
    root->left->right = new Node(5) ;
    //inorder(root) ;
    if(isBalanced(root)){
        cout<<"Balanced Binary Tree \n";
    }
    else{
        cout<<"Not a Balanced Binary Tree \n";
    }
    return 0 ;
}