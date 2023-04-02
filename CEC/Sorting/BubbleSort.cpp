#include<iostream>
#include<vector>
using namespace std ;
void bubbleSort(vector<int> &v)
{
    int n = v.size() , i , j ;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(v[j]>v[j+1]){
                swap(v[j],v[j+1]) ;
            }
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
    bubbleSort(v);
    for(i=0;i<n;i++){
        cout<<v[i]<<" ";
    }
    cout<<endl ;
    return 0 ;
}
