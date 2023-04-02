#include<bits/stdc++.h>
using namespace std;
int solve(int ind,vector<int> &v,vector<int> &dp){
    if(ind>=v.size()){
        return 0 ;
    }
    if(dp[ind]!=-1){
        return dp[ind] ;
    }
    int take = solve(ind+2,v,dp) + v[ind] ;
    int not_take = solve(ind+1,v,dp) + 0;
    return dp[ind] = max(take,not_take);
}
int houseRobber(vector<int> &v)
{
    int n = v.size() ;
    vector<int> dp(n+1,-1);
    return solve(0,v,dp);
}
int main()
{
    int n , i ;
    cout<<"Enter N \n";
    cin>>n;
    vector<int> v(n);
    for(i=0;i<n;i++){
        cin>>v[i] ;
    }
    cout<<houseRobber(v)<<endl;
    return 0 ;
}
// You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

// Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.
// Input: nums = [1,2,3,1]
// Output: 4
// Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
// Total amount you can rob = 1 + 3 = 4.