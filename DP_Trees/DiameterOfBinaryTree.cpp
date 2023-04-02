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
    int temp = 1+ max(l,r) ;
    int ans = max(temp,1+l+r) ;
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
                    8
                   / \
                  6   9
                 / \   \
                4   7   10
                   /
                  5
    O/P : 7
*/
int main()
{
    TreeNode *root = new TreeNode(8) ;
    root->left = new TreeNode(6) ;
    root->right = new TreeNode(9) ;
    (root->left)->left = new TreeNode(4) ;
    (root->left)->right = new TreeNode(7) ;
    (root->right)->right = new TreeNode(10) ;
    ((root->left)->right)->left = new TreeNode(5) ;

    int res = INT_MIN ;
    inorder(root) ;
    cout<<endl;
    int a = diameter(root,res)  ;
    cout<<"Diameter of Binary Tree : "<<res ;
    cout<<endl;
    return 0 ;
}