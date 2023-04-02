#include<iostream>
#include<string>
#include<vector>
using namespace std ;
int LCS(string x,string y,int m,int n,vector<vector<int> > &dp)
{
    if(m==0 || n==0){
        return 0;
    }
    if(dp[m][n]!=-1){
        return dp[m][n] ;
    }
    if(x[m-1]==y[n-1]){
        return dp[m][n] = 1+ LCS(x,y,m-1,n-1,dp) ;
    }
    else{
        return dp[m][n] = max(LCS(x,y,m-1,n,dp), LCS(x,y,m,n-1,dp)) ;
    }    
}
int main()
{
    string x, y ;
    cout<<"Enter X String : ";
    cin>>x ;
    cout<<"Enter Y String : ";
    cin>>y ;
    int m = x.length() , n = y.length() ;
    vector<vector<int> > dp(m+1,vector<int>(n+1,-1)) ;
    cout<<LCS(x,y,m,n,dp) <<endl ;
    return 0 ;
}
// X : abcdgh
// Y : abedhr
// O/P : 4
