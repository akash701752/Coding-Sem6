#include<iostream>
#include<vector>
using namespace std;
int knapsack(vector<int> &wt,vector<int> &val,int w,int n)
{
    int dp[n+1][w+1] ;
    int i , j ;
    for(i=0;i<n+1;i++)
    {
        for(j=0;j<w+1;j++)
        {
            //Initialization
            if(i==0 || j==0){
                dp[i][j] = 0 ;
            }
            //Choice Code
            else if(wt[i-1]<=j){
                dp[i][j] = max(val[i-1]+dp[i-1][j-wt[i-1]], dp[i-1][j]) ;
            }
            else if(wt[i-1]>j){
                dp[i][j] = dp[i-1][j] ;
            }
        }
    }
    return dp[n][w] ;
}
int main()
{
    int n , w , i;
    cout<<"Enter N : ";
    cin>>n ;
    vector<int> wt(n) , val(n) ;
    cout<<"Enter Weight Array \n" ;
    for(i=0;i<n;i++){
        cin>>wt[i] ;
    }
    cout<<"Enter Value Array \n" ;
    for(i=0;i<n;i++){
        cin>>val[i] ;
    }
    cout<<"Enter W : ";
    cin>>w ;
    cout<<knapsack(wt,val,w,n)<<endl;
    return 0 ;
}