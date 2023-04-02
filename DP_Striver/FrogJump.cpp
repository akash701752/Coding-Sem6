#include<bits/stdc++.h>
using namespace std ;
// int solve(int ind,vector<int> &v,vector<int> &dp){
//     if(ind==0){
//         return 0 ;
//     }
//     if(dp[ind]!=-1){
//         return dp[ind] ;
//     }
//     int left , right = INT_MAX ;
//     left = solve(ind-1,v,dp) + abs(v[ind]-v[ind-1]) ;
//     if(ind>2){
//         right = solve(ind-2,v,dp) + abs(v[ind]-v[ind-2]);
//     }
    // if(dp[ind-1]!=-1){
    //     left = dp[ind-1] ;
    // }
    // else{
    //     left = solve(ind-1,v,dp) + abs(v[ind]-v[ind-1]);
    // }
    // if(ind>1){
    //     if(dp[ind-2]!=-1){
    //         right =dp[ind-2] ;
    //     }
    //     else{
    //         right = solve(ind-2,v,dp) + abs(v[ind]-v[ind-2]);
    //     }
    // }
    //return dp[ind] = min(left,right) ;
//}
int frogJump(vector<int>&v){
    int i , n = v.size() ;
    vector<int> dp(n,0) ;
    dp[0] = 0 ;
    for(i=1;i<n;i++){
        int fs = dp[i-1] + abs(v[i]-v[i-1]);
        int ss = INT_MAX;
        if(i>1){
            ss = dp[i-2] + abs(v[i]-v[i-2]);
        }
        dp[i] = min(fs,ss) ;
    }
    return dp[n-1] ;
}
int main()
{
    int n , i ;
    cout<<"Enter N "<<endl;
    cin>>n ;
    vector<int> v(n) ;
    for(i=0;i<n;i++){
        cin>>v[i] ;
    }
    cout<<frogJump(v)<<endl;
    return 0 ;
}
// I/P : 10 20 30 10
// O/P : 20
// I/P : 10 50 10
// O/P : 0