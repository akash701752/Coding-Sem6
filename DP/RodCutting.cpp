#include<iostream>
#include<vector>
#include<algorithm>
using namespace std ;
int rodCutting(vector<int> &length,vector<int> &price,int len)
{
    int i , j , n= length.size();
    vector<vector<int> >dp(n+1,vector<int>(len+1));
    for(i=0;i<n+1;i++)
    {
        for(j=0;j<len+1;j++)
        {
            if(i==0 || j==0){
                dp[i][j] = 0 ;
            }
            else if(length[i-1]<=j){
                dp[i][j] = max(price[i-1] + dp[i][j-length[i-1]], dp[i-1][j]) ;
            }
            else{
                dp[i][j] = dp[i-1][j] ;
            }
        }
    }
    return dp[n][len] ;
}
int main()
{
    int n , i , len;
    cout<<"Enter N : ";
    cin>>n ;
    cout<<"Enter Length Array "<<endl ;
    vector<int> length(n) , price(n) ;
    for(i=0;i<n;i++){
        cin>>length[i] ;
    }
    cout<<"Enter Price Array "<<endl ;
    for(i=0;i<n;i++){
        cin>>price[i] ;
    }
    cout<<"Enter Length : ";
    cin>>len ;
    cout<<rodCutting(length,price,len);
    return 0 ;
}
// length   | 1   2   3   4   5   6   7   8  
// price    | 1   5   8   9  10  17  17  20
// O/P : 22