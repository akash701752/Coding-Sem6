#include<iostream>
#include<vector>
#include<limits>
using namespace std ;
int coinChange(vector<int> &coin,int n,int sum)
{
    int dp[n+1][sum+1] ;
    int i, j ;
    for(i=0;i<sum+1;i++){
        dp[0][i] = INT_MAX -1 ;
    }
    for(i=1;i<n+1;i++){
        dp[i][0] = 0 ;
    }
    // Second Row Initialization
    for(j=1;j<sum+1;j++){
        if(j%coin[0]==0){
            dp[1][j] = j/coin[0] ;
        }
        else{
            dp[1][j] = INT_MAX -1 ;
        }
    }
    for(i=2;i<n+1;i++)
    {
        for(j=1;j<sum+1;j++)
        {
            if(coin[i-1]<=j){
                dp[i][j] = min(dp[i][j-coin[i-1]]+1,  dp[i-1][j]) ;
            }
            else{
                dp[i][j] = dp[i-1][j] ;
            }
        }
    }
    return dp[n][sum] ;
}
int main()
{
    int n , i ,sum;
    cout<<"Enter N : ";
    cin>>n ;
    vector<int> coin(n) ;
    cout<<"Enter Coin Array"<<endl;
    for(i=0;i<n;i++){
        cin>>coin[i] ;
    }
    cout<<"Sum : ";
    cin>>sum ;
    cout<<coinChange(coin,n,sum) <<endl ;
    return 0 ;
}
// coin [] : 1 2 3
// Sum : 5
// O/P : 2