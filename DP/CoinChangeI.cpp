#include<iostream>
#include<vector>
using namespace std ;
int coinChange(vector<int> &coin,int n,int sum)
{
    int dp[n+1][sum+1] ;
    int i, j ;
    for(i=0;i<n+1;i++)
    {
        for(j=0;j<sum+1;j++)
        {
            if(i==0 || j==0){
                if(i==0){
                    dp[i][j] = 0 ;
                }
                if(j==0){
                    dp[i][j] = 1 ;
                }
            }
            else if(coin[i-1]<=j){
                dp[i][j] = dp[i][j-coin[i-1]] + dp[i-1][j] ;
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
// sum : 5 
// O/P : 5