#include<bits/stdc++.h>
using namespace std;
int binarySearch(vector<int> &v,int key){
    int start = 0, n = v.size(), end , res= -1 ;
    end = n-1;
    while(start<=end){
        int mid = start+ (end-start)/2;
        if(v[mid]==key){
            return v[mid] ;
        }
        else if(v[mid]<key){
            start = mid+1 ;
        }
        else {
            res = v[mid] ;
            end = mid-1;
        }
    }
    return res;
}
int main()
{
    int n , i , key;
    cout<<"Enter N "<<endl ;
    cin>>n ;
    vector<int> v(n) ;
    for(i=0;i<n;i++){
        cin>>v[i] ;
    }
    cin>>key ;
    cout<<"Ceil is : "<<binarySearch(v,key) <<endl;
    return 0 ;
}
// I/P : 1 2 3 4 8 10 10 12 19
// key : 5
// O/P : 8