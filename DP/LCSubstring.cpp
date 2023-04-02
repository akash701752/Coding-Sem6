#include<iostream>
#include<string>
#include<vector>
#include<limits>
using namespace std ;
int LCS(string x,string y,int m,int n)
{
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
                dp[i][j] = 0 ;
            }
        }
    }
    int res = INT_MIN ;
    for(i=0;i<m+1;i++){
        for(j=0;j<n+1;j++){
            if(dp[i][j]>res){
                res = dp[i][j] ;
            }
        }
    }
    return res ;
}
int main()
{
    string x, y ;
    cout<<"Enter X String : ";
    cin>>x ;
    cout<<"Enter Y String : ";
    cin>>y ;
    int m = x.length() , n = y.length() ;
    cout<<LCS(x,y,m,n) <<endl ;
    return 0 ;
}
// Input : X = “GeeksforGeeks”, y = “GeeksQuiz”
// Output : 5