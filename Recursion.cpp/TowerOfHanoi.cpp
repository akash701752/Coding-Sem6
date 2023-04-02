#include<iostream>
using namespace std ;
void TOH(int n,int src,int dest,int help,int &count)
{
    count++ ;
    if(n==1){
        cout<<"Move a "" Disc from "<<src << " to "<<dest <<endl ;
        return ;
    }
    TOH(n-1,src,help,dest,count);
    cout<<"Move a "<<" Disc from "<<src << " to "<<dest <<endl ;
    TOH(n-1,help,dest,src,count) ;
}
int main()
{
    int n , count = 0;
    cout<<"Enter No. of Disc : ";
    cin>>n ;
    TOH(n,1,2,3,count);
    cout<<"No. of Steps are : "<<count <<endl;
    return 0 ;
}