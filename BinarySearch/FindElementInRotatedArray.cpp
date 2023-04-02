#include<bits/stdc++.h>
using namespace std ;
int getMin(vector<int> &v){
    int n = v.size(), l , r , res =-1 ;
    l = 0 , r = n-1 ;
    while(l<=r){
        int mid = l+ (r-l)/2 ;
        int prev = (mid-1+n)%n;
        int next = (mid+1)%n ;
        if(v[mid]<=v[prev] && v[mid]<=v[next]){
            res = mid;
            break ;
        }
        else if(v[0]<v[mid]){
            l = mid+1;
        }
        else{
            r = mid-1;
        }
    }
    return res;
}
int binarySearch(vector<int> &v,int left,int right, int key){
    int n = v.size(), l , r , res =-1 ;
    l = left , r = right-1 ;
    while(l<=r){
        int mid = l+ (r-l)/2 ;
        if(v[mid]==key){
            res = mid;
            break ;
        }
        else if(v[mid]<key){
            l = mid+1;
        }
        else{
            r = mid-1;
        }
    }
    return res;
}
int findElement(vector<int> &v,int key){
    int minInd = getMin(v);
    if(v[minInd]==key){
        return minInd ;
    }
    int find1 = binarySearch(v,0,minInd,key);
    int find2 = binarySearch(v,minInd+1,v.size(),key);
    if(find1!=-1){
        return find1;
    }
    else{
        return find2;
    }
}
int main()
{
    int i , n , key ;
    cout<<"Enter N "<<endl;
    cin>>n;
    vector<int> v(n);
    for(i=0;i<n;i++){
        cin>>v[i];
    }
    cin>>key ;
    cout<<findElement(v,key)<<endl;
    return 0 ;
}
// I/P : 11 12 15 18 2 5 6 8
// Key : 15
// O/P : 2