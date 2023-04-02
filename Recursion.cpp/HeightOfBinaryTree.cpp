#include<iostream>
using namespace std ;
typedef struct TreeNode
{
    int val ;
    struct TreeNode *left , *right ;
    TreeNode(int n){
        val = n ;
        left = right = NULL ;
    }
}TreeNode ;
int height(TreeNode *root)
{
    if(root==NULL){
        return 0 ;
    }
    int lh = height(root->left) ;
    int rh = height(root->right) ;

    return 1 + max(lh,rh) ;
}
/*
            1
           / \
          2   3
         / \
        4   5
           /
          6
*/
int main()
{
    TreeNode *root = new TreeNode(1) ;
    root->left = new TreeNode(2) ;
    root->right = new TreeNode(3) ;
    (root->left)->left = new TreeNode(4) ;
    (root->left)->right = new TreeNode(5) ;

   ((root->left)->right)->left = new TreeNode(6) ;

    cout<<"Height Of Tree is : "<<height(root) <<endl ;
    return 0 ;
}