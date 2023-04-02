#include<iostream>
#include<vector>
using namespace std;
void maxHeapify(vector<int> &v,int ind,int n)
{
    int lc , rc , max = ind;
    lc = 2*ind+ 1;
    rc = 2*ind+ 2;
    if(lc<n && v[lc]>v[max]){
        max = lc  ;
    }
    if(rc<n && v[rc]>v[max]){
        max = rc ;
    }
    if(max!=ind){
        swap(v[ind],v[max]) ;
        maxHeapify(v,max,n) ;
    }
}
void heapSort(vector<int> &v,int n)
{
    for(int i=n/2-1;i>=0;i--){
        maxHeapify(v,i,n) ;
    }
    for(int i=n-1;i>0;i--){
        swap(v[0],v[i]) ;
        maxHeapify(v,0,i) ;
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
    heapSort(v,n);
    for(i=0;i<n;i++){
        cout<<v[i] <<" ";
    }
    cout<<endl ;
    return 0 ;
}