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
void inOrder(Node* root){
    stack<Node*> st ;
    //st.push(root) ;
    Node *temp = root ;
    vector<int> v ;
    while(true){
        if(temp!=NULL){
            st.push(temp) ;
            temp = temp->left ;
        }
        else{
            if(st.empty()){
                break ;
            }
            temp = st.top() ;
            st.pop() ;
            v.push_back(temp->val) ;
            temp = temp->right ;
        }
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
    inOrder(root);
    return 0 ;
}