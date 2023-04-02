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
void allTraversal(Node* root){
    stack<pair<Node*,int> >st;
    vector<int> pre, in, post ;
    st.push(make_pair(root,1));
    while(st.size()>0){
        pair<Node*,int> it = st.top() ;
        st.pop();
        if(it.second==1){
            pre.push_back(it.first->val);
            it.second++ ;
            st.push(it) ;
            if(it.first->left!=NULL){
                st.push(make_pair(it.first->left,1)) ;
            }
        }
        else if(it.second==2){
            in.push_back(it.first->val) ;
            it.second++ ;
            st.push(it) ;
            if(it.first->right!=NULL){
                st.push(make_pair(it.first->right,1)) ;
            }
        }
        else{
            post.push_back(it.first->val) ;
        }
    }
    cout<<"PreOrder : ";
    for(int i=0;i<pre.size();i++){
        cout<<pre[i] <<" ";
    }
    cout<<"\nInOrder : ";
    for(int i=0;i<in.size();i++){
        cout<<in[i] <<" ";
    }
    cout<<"\nPreOrder : ";
    for(int i=0;i<post.size();i++){
        cout<<post[i] <<" ";
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
    allTraversal(root);
    return 0 ;
}