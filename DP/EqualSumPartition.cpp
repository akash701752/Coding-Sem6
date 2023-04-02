#include<iostream>
#include<vector>
using namespace std;
bool subsetSum(vector<int> &wt,int sum,int n)
{
    bool dp[n+1][sum+1] ;
    int i , j ;
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
    return dp[n][sum] ;
}
bool equalSum(vector<int> &wt,int n)
{
    int sum = 0 , i  ;
    for(i=0;i<n;i++){
        sum+= wt[i] ;
    }
    if(sum%2!=0){
        return false ;
    }
    return subsetSum(wt,sum/2,n) ;
}
int main()
{
    int n , i;
    cout<<"Enter N : ";
    cin>>n ;
    vector<int> wt(n) ;
    cout<<"Enter Weight Array \n" ;
    for(i=0;i<n;i++){
        cin>>wt[i] ;
    }
    if(equalSum(wt,n)){
        cout<<"True"<<endl;
    }
    else{
        cout<<"False"<<endl;
    }
    return 0 ;
}