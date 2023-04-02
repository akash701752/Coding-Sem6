#include<iostream>
#include<vector>
using namespace std;
int partition(vector<int> &v,int l,int h){
    int pivot = v[h] , i , j ;
    i = l-1;
    for(j=l;j<h;j++){
        if(v[j]<pivot){
            i++ ;
            swap(v[i],v[j]) ;
        }
    }
    i++ ;
    swap(v[i],pivot) ;
    swap(v[h],pivot) ;
    return i ;
}
void quickSort(vector<int> &v,int l,int h){
    if(l<h){
        int ind = partition(v,l,h) ;
        quickSort(v,l,ind-1) ;
        quickSort(v,ind+1,h) ;
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
    quickSort(v,0,n-1);
    for(i=0;i<n;i++){
        cout<<v[i] <<" ";
    }
    cout<<endl ;
    return 0 ;
}