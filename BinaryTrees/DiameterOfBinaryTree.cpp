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
int height(Node* root,int &ans){
    if(root==NULL){
        return 0 ;
    }
    int lh = height(root->left,ans) ;
    int rh = height(root->right,ans) ;
    ans = max(ans,lh+rh) ;
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
    int ans = 0 ;
    height(root,ans) ;
    cout<<"Diameter of Tree : "<< ans  <<endl;
    return 0 ;
}