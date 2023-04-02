#include<iostream>
using namespace std ;
long int fact(int n)
{
    if(n==0 || n==1){
        return 1 ;
    }
    return n* fact(n-1) ;
}
int main()
{
    int n ;
    cout<<"Enter N : " ;
    cin>>n ;
    cout<<"Factorial is : "<<fact(n) <<endl ;
    return 0 ;
}