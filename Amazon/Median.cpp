#include<iostream>
#include<vector>
#include<algorithm>
using namespace std ;
float median(vector<int> &v){
    int n = v.size() ;
    sort(v.begin(),v.end());
    if(n%2!=0){
        return v[n/2];
    }
    else{
        int a = v[n/2] ;
        int b = v[(n/2)+1];
        return (a+b)/2.0 ;
    }
}
int main()
{
    int n , ch ; 
    vector<int> v;
    do{
        cout<<"1.Add    2.Median    0.Exit \n";
        cin>>ch ;
        switch (ch)
        {
        case 1 : cin>>n ;
                v.push_back(n) ;
            break;
        case 2 : cout<<median(v) <<endl ;
                break ;
        default: cout<<"Invalid Choice"<<endl ;
            break;
        }
    }while(ch!=0);
    return 0 ;
}