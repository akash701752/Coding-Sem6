#include<iostream>
#include<vector>
using namespace std;
int knapsack(vector<int> &wt,vector<int> &val,int w,int n)
{
    if(n==0 || w==0){
        return 0 ;
    }
    if(wt[n-1]<=w){
        return max(val[n-1]+ knapsack(wt,val,w-wt[n-1],n-1) ,knapsack(wt,val,w,n-1)) ;
    }
    else{
        return knapsack(wt,val,w,n-1) ;
    }
}
int main()
{
    int n , w , i;
    cout<<"Enter N : ";
    cin>>n ;
    vector<int> wt(n) , val(n) ;
    cout<<"Enter Weight Array \n" ;
    for(i=0;i<n;i++){
        cin>>wt[i] ;
    }
    cout<<"Enter Value Array \n" ;
    for(i=0;i<n;i++){
        cin>>val[i] ;
    }
    cout<<"Enter W : ";
    cin>>w ;
    cout<<knapsack(wt,val,w,n)<<endl;
    return 0 ;
}