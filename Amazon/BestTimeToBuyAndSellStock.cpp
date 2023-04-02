#include<bits/stdc++.h>
using namespace std ;
int maxStock(vector<int>&v){
    int n = v.size(), minPrice = INT_MAX , profit = 0 , i ;
    for(i=0;i<n;i++){
        minPrice = min(minPrice,v[i]);
        profit = max(profit,v[i]-minPrice);
    } 
    return profit ;
}
int main()
{
    int n , i ;
    cout<<"Enter N"<<endl ;
    cin>>n ;
    vector<int> v(n);
    for(i=0;i<n;i++){
        cin>>v[i] ;
    }
    cout<<"Maximum Profit = "<<maxStock(v)<<endl;
    return 0 ;
}
// Input: prices = [7,1,5,3,6,4]
// Output: 5