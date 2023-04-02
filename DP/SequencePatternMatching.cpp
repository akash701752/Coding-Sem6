#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std ;
int LPS(string a,string b)
{
    int m , n ,i , j ;
    m = a.length() ;
    n = b.length() ;
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
    return (dp[m][n]==m) ;
}
int main()
{
    string a , b ;
    cout<<"Enter a String  A : ";
    cin>>a ;
    cout<<"Enter a String  B : ";
    cin>>b ;
    if(LPS(a,b)){
        cout<<"True";
    }
    else{
        cout<<"False" ;
    }
    cout<<endl;
    return 0 ;
}
/*
    I/P  a : axy
         b : adxcpy
    O/P : True
*/