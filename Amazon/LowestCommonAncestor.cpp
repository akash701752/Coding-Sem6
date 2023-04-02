#include<bits/stdc++.h>
using namespace std ;
typedef struct TreeNode{
    int val ;
    struct TreeNode *left, *right ;
    TreeNode(int x){
        val = x;
        left = right = NULL ;
    }
}TreeNode ;
/*
                1
               / \
              2   3
             / \ 
            4  5
              / \
             6   7
            
    LCA (4,7) = 2
*/
TreeNode* LCA(TreeNode* root,TreeNode* p,TreeNode* q){
    if(root==NULL || root==p || root==q){
        return root;
    }
    TreeNode *left = LCA(root->left,p,q) ;
    TreeNode *right = LCA(root->right,p,q) ;

    if(left==NULL){
        return right ;
    }
    else if(right==NULL){
        return left;
    }
    else{
        return root;
    }
}
int main()
{
    int n ;
    TreeNode *root = new TreeNode(1) ;
     root->left = new TreeNode(2) ;
    root->right = new TreeNode(3) ;
    TreeNode *p = (root->left)->left = new TreeNode(4) ;
    (root->left)->right = new TreeNode(5) ;
    ((root->left)->right)->left = new TreeNode(6) ;
    TreeNode *q = ((root->left)->right)->right = new TreeNode(7) ;

    TreeNode *ans = LCA(root,p,q);
    cout<<"Lowest Common Ancestor of "<<p->val <<" and "<<q->val <<" is : "<<ans->val <<endl ;
    return 0 ;

}