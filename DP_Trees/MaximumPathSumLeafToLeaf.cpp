#include<iostream>
#include<vector>
#include<limits>
using namespace std ;
typedef struct TreeNode
{
    int val ;
    struct TreeNode *left , *right ;
    TreeNode(int x){
        val = x ;
        left = right = NULL ;
    }
}TreeNode;
int diameter(TreeNode *root,int &res)
{
    if(root==NULL){
        return 0 ;
    }
    int l = diameter(root->left,res) ;
    int r = diameter(root->right,res) ;
    int temp = max(l,r) +root->val ;
    if(root->left==NULL && root->right==NULL){
        temp = max(temp,root->val) ;
    }
    int ans = max(temp,l+r+root->val) ;
    res= max(res,ans) ;
    return temp ;
}
void inorder(TreeNode *root){
    if(root==NULL){
        return ;
    }
    inorder(root->left) ;
    cout<<root->val <<" ";
    inorder(root->right) ;
}
/*
                   -10
                   / \
                  9   20
                     / \
                    7  15
                  
    O/P : 42
*/
int main()
{
    TreeNode *root = new TreeNode(-10) ;
    root->left = new TreeNode(9) ;
    root->right = new TreeNode(20) ;
    (root->right)->left = new TreeNode(7) ;
    (root->right)->right = new TreeNode(15) ;

    int res = INT_MIN ;
    inorder(root) ;
    cout<<endl;
    int a = diameter(root,res)  ;
    cout<<"Maximum Path Sum of Binary Tree : "<<res ;
    cout<<endl;
    return 0 ;
}