#include<bits/stdc++.h>
using namespace std;
int getNoOfElements(vector<int> &v,int key){
    int n = v.size() , l , r, res ;
    l = 0 , r = n-1 , res = -1 ;
    while(l<=r){
        int mid = l+ (r-l)/2 ;
        if(v[mid]==key){
            res = mid ;
            r = mid-1 ;
        }
        else if(v[mid]>key){
            r = mid-1;
        }
        else{
            l = mid+1;
        }
    }
    int left = res , right ;
    res = -1 , l = 0 ,  r = n- 1 ;
    while(l<=r){
        int mid = l+ (r-l)/2 ;
        if(v[mid]==key){
            res = mid ;
            l = mid+1 ;
        }
        else if(v[mid]>key){
            r = mid-1;
        }
        else{
            l = mid+1;
        }
    }
    right = res ;
    return right-left +1;
}
int main()
{
    int n , i , key ;
    cout<<"Enter N "<<endl;
    cin>>n;
    vector<int> v(n) ;
    for(i=0;i<n;i++){
        cin>>v[i];
    }
    cin>>key; 
    cout<<"No. of Elements : "<<getNoOfElements(v,key)<<endl;
    return 0 ;
}