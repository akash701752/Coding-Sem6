#include<iostream>
#include<string>
using namespace std ;
int LCS(string x,string y,int m,int n)
{
    if(m==0 || n==0){
        return 0;
    }
    if(x[m-1]==y[n-1]){
        return 1+ LCS(x,y,m-1,n-1) ;
    }
    else{
        return max(LCS(x,y,m-1,n), LCS(x,y,m,n-1)) ;
    }
}
int main()
{
    string x, y ;
    cout<<"Enter X String : ";
    cin>>x ;
    cout<<"Enter Y String : ";
    cin>>y ;
    int m = x.length() , n = y.length() ;
    cout<<LCS(x,y,m,n) <<endl ;
    return 0 ;
}
// X : abcdgh
// Y : abedhr
// O/P : 4