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
void bfs(Node* root){
    queue<Node*> q ;
    vector<int> ans ;
    q.push(root) ;
    while(q.size()>0){
        int n = q.size() ;
        for(int i=0;i<n;i++){
            Node *temp = q.front() ;
            q.pop() ;
            if(temp->left!=NULL){
                q.push(temp->left) ;
            }
            if(temp->right!=NULL){
                q.push(temp->right) ;
            }
            ans.push_back(temp->val) ;
        }
    }
    for(int i=0;i<ans.size();i++){
        cout<<ans[i] <<" ";
    }
}
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
    root->left->left = new Node(4) ;
    root->left->right = new Node(5) ;
    //inorder(root) ;
    bfs(root);
    return 0 ;
}