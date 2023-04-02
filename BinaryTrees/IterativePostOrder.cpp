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
void postOrder(Node* root){
    stack<Node*> st1 ;
    stack<int> st2 ;
    vector<int> v ;
    st1.push(root);
    while(st1.size()>0){
        Node * temp = st1.top() ;
        st1.pop() ;
        if(temp->left){
            st1.push(temp->left) ;
        }
        if(temp->right){
            st1.push(temp->right) ;
        }
        st2.push(temp->val) ;
    }
    while(st2.size()>0){
        v.push_back(st2.top()) ;
        st2.pop() ;
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
    postOrder(root);
    return 0 ;
}