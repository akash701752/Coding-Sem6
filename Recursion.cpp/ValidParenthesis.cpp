#include<iostream>
#include<vector>
#include<string>
using namespace std ;
void solve(int open,int close,string op,vector<string> &res)
{
    if(open == 0 && close == 0){
        res.push_back(op) ;
        return ;
    }
    if(open!=0){
        string op1 = op ;
        op1.push_back('(') ;
        solve(open-1,close,op1,res) ;
    }
    if(close>open){
        string op2 = op ;
        op2.push_back(')') ;
        solve(open,close-1,op2,res) ;
    }
}
vector<string> validParenthesis(int n)
{
    int open , close ;
    open = close = n ;
    vector<string> res ;
    string op =  "" ; // output
    solve(open,close,op,res) ;
    return res ;
}
int main() 
{
    int n  ;
    cout<<"Enter N : ";
    cin>>n ;
    vector<string> ans = validParenthesis(n) ;
    for(int i=0;i<ans.size();i++){
        cout<<ans[i] <<" ";
    }
    cout<<endl ;
    return 0 ;
}