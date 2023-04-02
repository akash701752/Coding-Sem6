#include<iostream>
#include<limits>
#include<vector>
using namespace std ;
int eggDrop(int egg,int floor,vector<vector<int> > &dp)
{
    if(floor==0 || floor==1){
        return floor;
    }
    if(egg==1){
        return floor ;
    }
    if(dp[egg][floor]!=-1){
        return dp[egg][floor] ;
    }
    int mn = INT_MAX ;
    for(int k=1;k<=floor;k++)
    {
        int temp , left , right ;
        if(dp[egg-1][k-1]!=-1){
            left = dp[egg-1][k-1] ;
        }
        else{
            left = eggDrop(egg-1,k-1,dp) ;
        }
        if(dp[egg][floor-k]!=-1){
            right = dp[egg][floor-k] ;
        }
        else{
            right = eggDrop(egg,floor-k,dp) ;
        }
        temp = 1+ max(left,right);
        mn = min(mn,temp);
    }
    return mn ;
}
int main()
{
    int egg , floor ;
    cout<<"Enter Number of Eggs and Floors "<<endl;
    cin>>egg>>floor;
    vector<vector<int> > dp(1001,vector<int>(10001,-1)) ; 
    cout<<eggDrop(egg,floor,dp);
    cout<<endl;
    return 0 ;
}