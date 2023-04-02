#include<bits/stdc++.h>
using namespace std ;
int kTimesSorted(vector<int> &v){
    int n = v.size() , l , r , res = -1;
    l = 0 , r = n-1;
    while(l<=r){
        int mid = l+ (r-l)/2 ;
        int next = (mid+1)%n;
        int prev = (mid+n-1)%n ;
        if(v[mid]<=v[next] && v[mid]<=v[prev]){
            res = mid ;
            break ;
            //return mid;

        }
        else if(v[0]<=v[mid]){
            l = mid+1;
        }
        else{
            r = mid-1;
        }
    }
    return res;
}
int main()
{
    int n , i ;
    cout<<"Enter N "<<endl;
    cin>>n;
    vector<int> v(n);
    for(i=0;i<n;i++){
        cin>>v[i];
    }
    cout<<kTimesSorted(v) <<endl;
    return 0 ;
}
// I/P : 11 12 15 18 2 5 6 8
// O/P : 4
