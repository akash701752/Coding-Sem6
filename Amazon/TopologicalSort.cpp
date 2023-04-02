#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std ;
void findTopoSort(int node,vector<int> &vis,stack<int> &st,vector<vector<int> >&adj )
{
    vis[node] = 1;
    for(int i=0;i<adj[node].size();i++){
        if(vis[adj[node][i]]==0){
            findTopoSort(adj[node][i],vis,st,adj) ;
        }
    }
    st.push(node) ;
}
vector<int> topoSort(int n,vector<vector<int> >&adj){
    stack<int> st ;
    vector<int> vis(n,0);
    for(int i=0;i<n;i++){
        if(vis[i]==0){
            findTopoSort(i,vis,st,adj) ;
        }
    }
    vector<int> v ;
    while(st.size()>0){
        v.push_back(st.top()) ;
        st.pop() ;
    }
    return v;
}
int main() 
{
    int n , i , j , edge ;
    cout<<"Enter Number of Nodes : ";
    cin>>n ;
    vector<vector<int> > adj(n) ;
    for(i=0;i<n;i++){
        cout<<"Enter number of Edges  Node "<<i+1 << " : ";
        cin>>edge; 
        vector<int> v(edge) ;
        for(j=0;j<edge;j++){
            cin>>v[j] ;
        }
        adj[i]=(v) ;
    }
    vector<int> ans = topoSort(n,adj) ;
    for(i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl ;
    return 0 ;
}