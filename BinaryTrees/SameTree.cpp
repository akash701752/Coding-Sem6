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
bool isSame(Node* p,Node* q){
    if(p==NULL && q==NULL){
        return true;
    }
    if(p==NULL || q==NULL){
        return false ;
    }
    if(p->val==q->val){
        return isSame(p->left,q->left) && isSame(p->right,q->right) ;
    }
    return false;
}
void inorder(Node* root){
    if(root==NULL){
        return ;
    }
    inorder(root->left) ;
    cout<<root->val<<" ";
    inorder(root->right);
}
int main()
{
    Node *root = new Node(1) ;
    root->left = new Node(2) ;
    root->right = new Node(3) ;
    root->left->left = new Node(4) ;
    root->left->right = new Node(5) ;
    //inorder(root) ;
    Node *newTree = new Node(9) ;
    newTree->left = new Node(10) ;
    int ans = 0 ;
    cout<<"1 : ";
    inorder(root);
    cout<<"\n2 : ";
    inorder(newTree);
    cout<<endl;
    if(isSame(root,newTree)==true){
        cout<<"Same Tree \n" ;
    }
    else{
        cout<<"Not Same Tree \n" ;
    }
    return 0 ;
}