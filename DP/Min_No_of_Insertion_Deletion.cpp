#include<iostream>
#include<string>
#include<vector>
using namespace std ;
void minDeletionInsertion(string &a,string &b)
{
    int m = a.length() , n = b.length() , i , j ;
    vector<vector<int> > dp(m+1,vector<int>(n+1)) ;
    for(i=0;i<m+1;i++)
    {
        for(j=0;j<n+1;j++)
        {
            if(i==0 || j==0){
                dp[i][j] = 0 ;
            }
            else if(a[i-1]==b[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1] ;
            }
            else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]) ;
            }
        }
    }
    cout<<"Minimum Deletion  : "<< m-dp[m][n] <<endl;
    cout<<"Minimum Insertion : "<< n-dp[m][n] <<endl;
}
int main()
{
    string a , b ;
    cout<<"Enter String A : ";
    cin>>a ;
    cout<<"Enter String B : ";
    cin>>b ;
    minDeletionInsertion(a,b) ;
    return 0 ;
}
