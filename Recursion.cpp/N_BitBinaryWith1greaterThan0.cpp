#include<iostream>
#include<vector>
#include<string>
using namespace std ;
void solve(int one,int zero,int n,string op,vector<string> &res)
{
    if(n==0){
        res.push_back(op) ;
        return ;
    }
    string op1 = op ;
    op1.push_back('1') ;
    solve(one+1,zero,n-1,op1,res) ;
    if(one>zero){
        string op2 = op ;
        op2.push_back('0') ;
        solve(one,zero+1,n-1,op2,res) ;
    }
}
vector<string> nBitValidBinary(int n)
{
    int one = 0 , zero = 0 ;
    vector<string> res ;
    string op =  "" ; // output
    solve(one,zero,n,op,res) ;
    return res ;
}
int main() 
{
    int n  ;
    cout<<"Enter N : ";
    cin>>n ;
    vector<string> ans = nBitValidBinary(n) ;
    for(int i=0;i<ans.size();i++){
        cout<<ans[i] <<" ";
    }
    cout<<endl ;
    return 0 ;
}