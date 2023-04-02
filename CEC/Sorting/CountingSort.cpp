#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void countingSort(vector<int> &v,int n)
{
    int large = *max_element(v.begin(),v.end()) , i ;
    vector<int> c(large+1,0) ;
    //Frequency Array
    for(i=0;i<n;i++){
        c[v[i]]++ ;
    }
    for(i=1;i<large+1;i++){
        c[i] = c[i-1]+ c[i] ;
    }
    vector<int> b(n) ; 
    for(i=n-1;i>=0;i--){
        int pos = c[v[i]] ;
        b[pos-1] = v[i] ;
        c[v[i]]-- ;
    }
    for(i=0;i<n;i++){
        v[i] = b[i] ;
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
    countingSort(v,n);
    for(i=0;i<n;i++){
        cout<<v[i] <<" ";
    }
    cout<<endl ;
    return 0 ;
}