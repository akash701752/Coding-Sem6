#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std ;
vector<int> stockSpan(vector<int> &v){
    int n = v.size() ,i ;
    stack<pair<int,int> > st ;
    vector<int> res;
    for(i=0;i<n;i++){
        if(st.size()==0){
            res.push_back(-1) ;
        }
        else if(st.size()>0 && st.top().first> v[i]){
            res.push_back(st.top().second);
        }
        else if(st.size()>0 && st.top().first<= v[i]){
            while(st.size()>0 && st.top().first<= v[i]){
                st.pop() ;
            }
            if(st.size()==0){
                res.push_back(-1) ;
            }
            else{
                res.push_back(st.top().second);
            }
        } 
        st.push(make_pair(v[i],i));
    }
    for(i=0;i<n;i++){
        res[i] = i- res[i] ;
    }
    return res ;
}
int main()
{
    int n , i ;
    cout<<"Enter N  "<<endl;
    cin>>n ;
    vector<int> v(n) ;
    for(i=0;i<n;i++){
        cin>>v[i] ;
    }
    vector<int> ans = stockSpan(v) ;
    for(i=0;i<n;i++){
        cout<<ans[i] <<" ";
    }
    return 0 ;
}
// Input: N = 7, price[] = [100 80 60 70 60 75 85]
// Output: 1 1 1 2 1 4 6
