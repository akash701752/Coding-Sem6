#include<iostream>
#include<vector>
using namespace std;
void merge(vector<int> &v,int l,int mid,int h)
{
    int n = (h-l)+1 ;
    int c[n] , i = l , j = mid+1 , k = 0 ;
    while(i<=mid && j<=h){
        if(v[i]<=v[j]){
            c[k++] = v[i++] ;
        }
        else{
            c[k++] = v[j++] ;
        }
    }
    while(i<=mid){
        c[k++] = v[i++] ;
    }
    while(j<=h){
        c[k++] = v[j++] ;
    }
    for(i=0,j=l;i<n;i++,j++){
        v[j] = c[i] ;
    }
}
void mergeSort(vector<int> &v,int l,int h){
    if(l<h){
        int mid = l + (h-l)/2 ;
        mergeSort(v,l,mid) ;
        mergeSort(v,mid+1,h) ;
        merge(v,l,mid,h);
    }
}
int main()
{
    int n , i ;
    cout<<"Enter N : ";
    cin>>n;
    vector<int> v(n) ;
    for(i=0;i<n;i++){
        cin>>v[i] ;
    }
    mergeSort(v,0,n-1);
    for(i=0;i<n;i++){
        cout<<v[i] <<" ";
    }
    cout<<endl ;
    return 0 ;
}