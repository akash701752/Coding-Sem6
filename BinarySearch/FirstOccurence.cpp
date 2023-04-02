#include<bits/stdc++.h>
using namespace std;
int binarySearch(vector<int> &v,int key){
    int start = 0, n = v.size(), end , res= -1 ;
    end = n-1;
    while(start<=end){
        int mid = start+ (end-start)/2;
        if(v[mid]==key){
            res= mid ;
            end = mid-1;
        }
        else if(v[mid]>key){
            end = mid-1;
        }
        else{
            start = mid+1;
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
    cout<<"First Occurence : "<<binarySearch(v,key) <<endl;
    return 0 ;
}
// I/P : 2 4 10 10 10 18 20
// key : 10
// O/P : 2