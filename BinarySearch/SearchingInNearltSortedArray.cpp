#include<bits/stdc++.h>
using namespace std;
int binarySearch(vector<int> &v,int key){
    int start = 0, n = v.size(), end , res= -1 ;
    end = n-1;
    while(start<=end){
        int mid = start+ (end-start)/2;
        if(v[mid]==key){
            res= mid ;
            break ;
        }
        else if(mid-1>=start && v[mid-1]==key){
            res= mid-1 ;
            break ;
        }
        else if(mid+1<=end && v[mid+1]==key){
            res= mid+1 ;
            break ;
        }
        else if(v[mid]>key){
            end = mid-2;
        }
        else{
            start = mid+2;
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
    cout<<"Element Found at : "<<binarySearch(v,key) <<endl;
    return 0 ;
}
// I/P : 5 10 30 20 40
// key : 30
// O/P : 2