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
void preOrder(Node* root){
    stack<Node*> st ;
    st.push(root) ;
    vector<int> v ;
    while(st.size()>0){
        Node *temp = st.top() ;
        st.pop() ;
        if(temp->right!=NULL){
            st.push(temp->right) ;
        }
        if(temp->left!=NULL){
            st.push(temp->left) ;
        }
        v.push_back(temp->val) ;
    }
    for(int i=0;i<v.size();i++){
        cout<<v[i] <<" ";
    }
}
int main()
{
    Node *root = new Node(1) ;
    root->left = new Node(2) ;
    root->right = new Node(3) ;
    root->left->left = new Node(4) ;
    root->left->right = new Node(5) ;
    //inorder(root) ;
    preOrder(root);
    return 0 ;
}