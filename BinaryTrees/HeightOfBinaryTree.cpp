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
    int rh = height(root->right) ;
    return 1+ max(lh,rh) ;
}
int main()
{
    Node *root = new Node(1) ;
    root->left = new Node(2) ;
    root->right = new Node(3) ;
    root->left->left = new Node(4) ;
    root->left->right = new Node(5) ;
    //inorder(root) ;
    cout<<"Height of Tree : "<< height(root) <<endl;
    return 0 ;
}