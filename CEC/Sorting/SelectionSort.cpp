#include<iostream>
#include<vector>
using namespace std ;
void selectionSort(vector<int> &v)
{
    int n = v.size() , i , j ;
    for(i=0;i<n-1;i++)
    {
        int min = i ;
        for(j=i+1;j<n;j++){
            if(v[j]<v[min]){
                min = j ;
            }
        }
        if(min!=i){
            swap(v[i],v[min]) ;
        }
    }
}
int main()
{
    int n , i ;
    cout<<"Enter N"<<endl ;
    cin>>n;
    vector<int> v(n) ;
    for(i=0;i<n;i++){
        cin>>v[i] ;
    }
    selectionSort(v);
    for(i=0;i<n;i++){
        cout<<v[i]<<" ";
    } 
    cout<<endl ;
    return 0 ;
}
