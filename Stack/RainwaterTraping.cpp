#include<iostream>
#include<vector>
#include<algorithm>
using namespace std ;
int rainWater(vector<int> &h){
    int i , n = h.size() ;
    vector<int> mxl(n) ,mxr(n) ;
    //Maximum Left
    mxl[0]= h[0] ;
    for(i=1;i<n;i++){
        mxl[i] = max(mxl[i-1],h[i]) ;
    }
    //Maximum Right
    mxr[n-1] = h[n-1] ;
    for(i=n-2;i>=0;i--){
        mxr[i] = max(mxr[i+1],h[i]);
    }
    int area = 0 ;
    for(i=0;i<n;i++){
        area += min(mxr[i],mxl[i]) - h[i] ;
    }
    return area ;
}
int main()
{
    int n , i ;
    cout<<"Enter N "<<endl ;
    cin>>n ;
    vector<int> h(n) ;
    for(i=0;i<n;i++){
        cin>>h[i] ;
    }
    cout<<rainWater(h) ;
    cout<<endl;
    return 0 ;
}
