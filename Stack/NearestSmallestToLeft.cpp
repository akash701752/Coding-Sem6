#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std ;
vector<int> nextSmallest(vector<int> &v)
{
    int n = v.size()  , i ;
    stack<int> st ;
    vector<int> res ;
    for(i=0;i<n;i++)
    {
        if(st.size()==0){
            res.push_back(-1) ;
        }    
        else if(st.size()>0  && st.top()<v[i]) {
            res.push_back(st.top()) ;
        }
        else if(st.size()>0 && st.top()>=v[i]){
            while(st.size()>0 && st.top()>=v[i]){
                st.pop() ;
            }
            if(st.size()==0){
                res.push_back(-1) ;
            }
            else{
                res.push_back(st.top()) ;
            }
        }
        st.push(v[i]);
    }
    return res ;
}
int main()
{
    int n , i ;
    cout<<"Enter N "<<endl;
    cin>>n ;
    vector<int> v(n) ;
    for(i=0;i<n;i++){
        cin>>v[i] ;
    }
    vector<int> ans = nextSmallest(v) ;
    for(i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl ;
    return 0 ;
}
// I/P :   4  5    2  10  8
// O/P :  -1  4   -1  2   2
