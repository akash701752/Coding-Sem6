#include<iostream>
#include<vector>
#include<limits>
using namespace std;
int minSubsetDiff(vector<int> &wt,int n)
{
    int sum = 0 ;
    int i , j ;
    for(i=0;i<n;i++){
        sum += wt[i] ;
    }
    bool dp[n+1][sum+1] ;
    for(i=0;i<n+1;i++)
    {
        for(j=0;j<sum+1;j++)
        {
            //Initialization
            if(i==0 || j==0){
                    if(i==0){
                    dp[i][j] = false ;
                }
                if(j==0){
                    dp[i][j] = true ;
                }
            }
            //Choice Code
            else if(wt[i-1]<=j){
                dp[i][j] = dp[i-1][j-wt[i-1]] ||  dp[i-1][j] ;
            }
            else if(wt[i-1]>j){
                dp[i][j] = dp[i-1][j] ;
            }
        }
    }
    int mn = INT_MAX ;
    for(i=0;i<=sum/2;i++){
        if(dp[n][i]==true){
            mn = min(mn,sum - 2*i) ;
        }
    }
    return mn ;
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
    cout<<minSubsetDiff(wt,n) <<endl ;
    return 0 ;
}
// 1 2 7
// O/P : 4