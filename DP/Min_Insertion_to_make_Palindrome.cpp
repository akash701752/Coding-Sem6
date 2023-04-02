#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std ;
int minDelPalindrome(string a,string b)
{
    int m , n ,i , j ;
    m = n = a.length() ;
    vector<vector<int> > dp(m+1,vector<int>(n+1)) ;
    for(i=0;i<m+1;i++)
    {
        for(j=0;j<n+1;j++)
        {
            if(i==0 || j==0){
                dp[i][j] = 0;
            }
            else if(a[i-1]==b[j-1]){
                dp[i][j] = 1+ dp[i-1][j-1] ;
            }
            else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return m- dp[m][n] ;
}
int main()
{
    string s , a ;
    cout<<"Enter a String : ";
    cin>>s ;
    a = s ;
    reverse(s.begin(),s.end());
    cout<<minDelPalindrome(a,s) ;
    cout<<endl;
    return 0 ;
}
/*
    I/P : aebcbda
    O/P : 2 (insert e and d .'. aedbcbdea)
*/