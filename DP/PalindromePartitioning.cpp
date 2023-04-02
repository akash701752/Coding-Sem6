#include<iostream>
#include<vector>
#include<string>
#include<limits>
using namespace std ;
bool isPalindrome(string s,int i,int j){
    while(i<=j){
        if(s[i]!=s[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;
}
int partitioning(string s,int i,int j,vector<vector<int> > &dp)
{
    if(i>=j){
        return 0 ;
    }
    if(isPalindrome(s,i,j)){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j] ;
    }
    int mn= INT_MAX ;
    for(int k=i;k<=j-1;k++)
    {
        int left , right , temp ;
        if(dp[i][k]!=-1){
            left = dp[i][k] ;
        }
        else{
            left = partitioning(s,i,k,dp) ;
            dp[i][k] = left ;
        }
        if(dp[k+1][j]!=-1){
            right = dp[k+1][j] ;
        }
        else{
            right = partitioning(s,k+1,j,dp) ;
            dp[k+1][j] = right ;
        }
        temp = left + right +1;
        mn = min(mn,temp) ;
    }
    return dp[i][j]=mn ;
}
int main()
{
    string s ;
    cout<<"Enter a String : ";
    cin>>s;
    vector<vector<int> > dp(1001,vector<int>(1001,-1));
    cout<<partitioning(s,0,s.length()-1,dp);
    cout<<endl;
    return 0;
}
// Input: str = "ababbbabbababa"
// Output: 3