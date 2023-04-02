#include<iostream>
#include<vector>
#include<algorithm>
using namespace std ;
void insert(vector<int> &v,int temp)
{
    if(v.size()==0 || v[v.size()-1]<=temp){
        v.push_back(temp) ;
        return ;
    }
    int val = v[v.size()-1] ;
    v.pop_back() ;
    insert(v,temp) ;
    v.push_back(val) ;
}
void sort(vector<int> &v)
{
    if(v.size()==1){
        return ;
    }
    int temp = v[v.size()-1] ;
    v.pop_back() ;
    sort(v);
    insert(v,temp) ;
}
int main()
{
    int n ,i ; 
    cout<<"Enter N : ";
    cin>>n ;
    vector<int> v(n) ;
    for(i=0;i<n;i++){
        cin>>v[i] ;
    }
    sort(v) ;
    for(i=0;i<n;i++){
        cout<<v[i] <<" ";
    }
    cout<<endl ;
    return 0 ;
}