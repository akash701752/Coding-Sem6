#include<bits/stdc++.h>
using namespace std ;
int binarySearch(vector<int> &v,int low,int high)
{
    int l , r , res = -1 , n = v.size();
    l = low , r = high ;
    while(l<=r){
        int mid = l+ (r-l)/2 ;
        if(v[mid]==1){
            res = mid ;
            r = mid-1;
        }
        else if(v[mid]<1){
            l = mid+1;
        }
        else{
            r = mid-1 ;
        }
    }
    return res ;
}
int getIndex(vector<int> &v)
{
    int low = 0 , high = 1 ;
    while(v[high]<1){
        low = high ;
        high = high*2 ;
    }
    return binarySearch(v,low,high) ;
}
int main()
{
    int n , i ;
    cout<<"Enter N : ";
    cin>>n ;
    vector<int> v(n);
    for(i=0;i<n;i++){
        cin>>v[i] ;
    }
    cout<<getIndex(v) <<endl;
    return 0 ;
}
// I/P : 0 0 0 0 0 1 1 1 1 1 1
// O/P : 5