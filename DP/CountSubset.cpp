#include<iostream>
#include<vector>
using namespace std;
int subsetSum(vector<int> &wt,int sum,int n)
{
    int dp[n+1][sum+1] ;
    int i , j ;
    for(i=0;i<n+1;i++)
    {
        for(j=0;j<sum+1;j++)
        {
            //Initialization
            if(i==0 || j==0){
                    if(i==0){
                    dp[i][j] = 0 ;
                }
                if(j==0){
                    dp[i][j] = 1 ;
                }
            }
            //Choice Code
            else if(wt[i-1]<=j){
                dp[i][j] = dp[i-1][j-wt[i-1]] +  dp[i-1][j] ;
            }
            else if(wt[i-1]>j){
                dp[i][j] = dp[i-1][j] ;
            }
        }
    }
    return dp[n][sum] ;
}
int main()
{
    int n , sum , i;
    cout<<"Enter N : ";
    cin>>n ;
    vector<int> wt(n) ;
    cout<<"Enter Weight Array \n" ;
    for(i=0;i<n;i++){
        cin>>wt[i] ;
    }
    cout<<"Enter Sum : ";
    cin>>sum ;
    cout<<subsetSum(wt,sum,n) ;
    return 0 ;
}
// 2 3 5 6 8 10
// 10
// O/P : 3