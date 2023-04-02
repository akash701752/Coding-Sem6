#include<iostream>
#include<vector>
#include<limits>
using namespace std;
int solve(vector<int> &v,int i,int j,vector<vector<int> > &dp)
{
    if(i>=j){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j] ;
    }
    int mn = INT_MAX ;
    for(int k=i;k<=j-1;k++){
        int temp_ans = solve(v,i,k,dp) + solve(v,k+1,j,dp) + v[i-1]*v[k]*v[j] ;
        mn = min(mn,temp_ans) ;
    }
    return dp[i][j] = mn ;
}
int MCM(vector<int> &v){
    vector<vector<int> > dp(101,vector<int>(101, -1)) ;
    return solve(v,1,v.size()-1,dp);
}
int main()
{
    int n, i ;
    cout<<"Enter Size : ";
    cin>>n ;
    vector<int> v(n) ;
    for(i=0;i<n;i++){
        cin>>v[i] ;
    }
    cout<<MCM(v);
    cout<<endl;
    return 0 ;
}
// Input: arr[] = {40, 20, 30, 10, 30}
// Output: 26000