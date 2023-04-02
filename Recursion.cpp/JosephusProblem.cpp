#include<iostream>
#include<vector>
using namespace std ;
void solve(vector<int> &v,int k,int ind,int &ans){
    if(v.size()==1){
        ans = v[0] ;
        return ;
    }
    ind = (ind+k)%v.size() ;
    v.erase(v.begin()+ind) ;
    solve(v,k,ind,ans) ;
}
int main()
{
    int n , k , i ;
    cout<<"Enter No. of Peoples and K : ";
    cin>>n>>k;
    vector<int> v(n) ;
    for(i=0;i<n;i++){
        v[i]=i+1 ;
    }
    int ans = -1 , ind = 0  ;
    solve(v,k-1,ind,ans) ;
    cout<<"Alive Person is : "<<ans <<endl;
    return 0;
}
