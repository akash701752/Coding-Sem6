#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;
void NSL(vector<int> &l,vector<int> &h)
{
    int n = h.size() , i ;
    stack<pair<int,int> > st ;
    for(i=0;i<n;i++)
    {
        if(st.size()==0){
            l.push_back(-1) ;
        }
        else if(st.size()>0 && st.top().first < h[i]){
            l.push_back(st.top().second);
        }
        else if(st.size()>0 && st.top().first >= h[i])
        {
            while(st.size()>0 && st.top().first >= h[i]){
                st.pop() ;
            }
            if(st.size()==0){
                l.push_back(-1);
            }
            else{
                l.push_back(st.top().second);
            }
        }
        st.push(make_pair(h[i],i));
    } 
}
void NSR(vector<int> &r,vector<int> &h)
{
    int n = h.size() , i ;
    stack<pair<int,int> > st ;
    for(i=0;i<n;i++)
    {
        if(st.size()==0){
            r.push_back(n) ;
        }
        else if(st.size()>0 && st.top().first < h[i]){
            r.push_back(st.top().second);
        }
        else if(st.size()>0 && st.top().first >= h[i])
        {
            while(st.size()>0 && st.top().first >= h[i]){
                st.pop() ;
            }
            if(st.size()==0){
                r.push_back(n);
            }
            else{
                r.push_back(st.top().second);
            }
        }
        st.push(make_pair(h[i],i));
    } 
    reverse(r.begin(),r.end()) ;
}

int MAH(vector<int> &h)
{
    vector<int> l , r ;
    NSL(l,h);
    NSR(r,h);
    int i , n = h.size() ;
    vector<int> width(n) ;
    for(i=0;i<n;i++){
        width[i] = r[i] - l[i] -1;
    }
    int area = 0 ;
    for(i=0;i<n;i++){
        area = max(area, width[i]*h[i]) ;
    }
    return area ;
}
int maxArea(vector<vector<int> >&v)
{
    int i , j , n = v.size() ;
    vector<int> h(n) ;
    for(j=0;j<n;j++){
        h[i] = v[0][j] ;
    }
    int area = MAH(h) ;
    for(i=1;i<n;i++)
    {
        for(j=0;j<n;j++){
            if(v[i][j]==1){
                h[j] = h[j]+1;
            }
            else{
                h[j] = 0 ;
            }
        }
        area = max(area,MAH(h)); 
    }
    return area ;
}
int main()
{
    int n , i , j ;
    cout<<"Enter N  "<<endl;
    cin>>n ;
    vector<vector<int> > v(n,vector<int>(n));
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            cin>>v[i][j] ;
        }
    }
    cout<<maxArea(v) ;
    cout<<endl ;
    return 0 ;
}