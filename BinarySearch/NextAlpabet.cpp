#include<bits/stdc++.h>
using namespace std ;
char getNext(vector<char> &v,char key)
{
    int l , r , n = v.size() ;
    char res = '#' ;
    l = 0 , r = n-1 ;
    while(l<=r)
    {
        int mid = l+ (r-l)/2 ;
        if(v[mid] == key){
            l = mid+1;
        }
        else if(v[mid]<key){
            l = mid+1;
        }
        else if(v[mid]>key){
            res = v[mid] ;
            r = mid-1;
        }
    }
    return res;
}
int main()
{
    int n , i ;
    char key ;
    cout<<"Enter N "<<endl ;
    cin>>n;
    vector<char> v(n) ;
    for(i=0;i<n;i++){
        cin>>v[i];
    }
    cin>>key ;
    cout<<"Next Alphabet : "<<getNext(v,key) <<endl;
    return 0 ;
}
// I/P : a c f h
// Key : f
// O/P : h