#include<iostream>
#include<vector>
#include<algorithm>
using namespace std ;
int targetSum(vector<int> &nums,int target)
{
    int tsum = 0 , i , j , n = nums.size();
    for(i=0;i<n;i++){
        tsum += nums[i] ;
    }
    int sum = (tsum+target)/2 ;
    if(sum<0){
        return 0 ;
    }
    int dp[n+1][sum+1] ;
    dp[0][0] = 1 ;
    for(i=1;i<sum+1;i++){
        dp[0][i] = 0 ;
    }
    for(i=1;i<n+1;i++)
    {
        for(j=0;j<sum+1;j++)
        {
            if(nums[i-1]<=j){
                dp[i][j] = dp[i-1][j-nums[i-1]] + dp[i-1][j] ;
            }
            else if(nums[i-1]>j){
                dp[i][j] = dp[i-1][j] ;
            }
        }
    }
    return dp[n][sum] ;
}
int main()
{
    int n , i , target;
    cout<<"Enter N : ";
    cin>>n ;
    vector<int> nums(n) ;
    cout<<"Enter Array "<<endl ;
    for(i=0;i<n;i++){
        cin>>nums[i] ;
    }
    cout<<"Enter Target : ";
    cin>>target ;
    cout<<targetSum(nums,target) ;
    return 0 ;
}
// 1 1 1 1 1
// 3
// O/P : 5