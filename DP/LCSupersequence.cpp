#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std ;
int LCSuprersequence(string x,string y)
{
    int m = x.length() , n = y.length() ;
    vector<vector<int> > dp(m+1,vector<int>(n+1)) ;
    int i , j ;
    for(i=0;i<m+1;i++)
    {
        for(j=0;j<n+1;j++)
        {
            if(i==0 || j==0){
                dp[i][j] = 0 ;
            }
            else if(x[i-1]==y[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1] ;
            }
            else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]) ;
            }
        }
    }
    string ans = "" ;
    i = m , j = n ;
    while(i>0 && j>0)
    {
        if(x[i-1] == y[j-1]){
            ans.push_back(x[i-1]) ;
            i -- ;
            j -- ;
        }
        else if(dp[i-1][j] > dp[i][j-1]){
            ans.push_back(x[i-1]) ;
            i-- ;
        }
        else{
            ans.push_back(y[j-1]) ;
            j-- ;
        }
    }
    while(i>0){
        ans.push_back(x[i-1]) ;
        i --;
    }
    while(j--){
        ans.push_back(y[j-1]) ;
        j --;
    }
    reverse(ans.begin(),ans.end()) ;
    cout<<ans<<endl;
    return m+n - dp[m][n] ;
}
int main()
{
    string x , y ;
    cout<<"Enter String X : " ;
    cin>>x ;
    cout<<"Enter String Y : " ;
    cin>>y ;
    cout<<LCSuprersequence(x,y) ;
    cout<<endl ;
    return 0 ;
}