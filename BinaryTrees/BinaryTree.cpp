#include<bits/stdc++.h>
using namespace std;
typedef struct Node
{
    int val ;
    struct Node *left, *right ;
    Node(int x){
        val = x ;
        left = right = NULL ;
    }
}Node;
void inorder(Node* root){
    if(root==NULL){
        return ;
    }
    inorder(root->left) ;
    cout<<root->val<<" ";
    inorder(root->right) ;
}
int main()
{
    Node *root = new Node(1) ;
    root->left = new Node(2) ;
    root->right = new Node(3) ;
    inorder(root) ;
    return 0 ;
}