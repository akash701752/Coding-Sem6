#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std ;
vector<int> NSL(vector<int> &heights){
    int p = -1 , n = heights.size(), i ;
    stack<pair<int,int> > st ;
    vector<int> l ;
    for(i=0;i<n;i++){
        if(st.size()==0){
            l.push_back(p) ;
        }
        else if(st.size()>0 && st.top().first < heights[i]){
            l.push_back(st.top().second);
        }
        else if(st.size()>0 && st.top().first >= heights[i]){
            while(st.size()>0 && st.top().first >= heights[i]){
                st.pop() ;
            }
            if(st.size()==0){
                l.push_back(p) ;
            }
            else{
                l.push_back(st.top().second) ;
            }
        }
        st.push(make_pair(heights[i],i)) ;
    }
    return l ;
}
vector<int> NSR(vector<int> &heights){
    int p , n = heights.size(), i ;
    p = n;
    stack<pair<int,int> > st ;
    vector<int> r ;
    for(i=n-1;i>=0;i--){
        if(st.size()==0){
            r.push_back(p) ;
        }
        else if(st.size()>0 && st.top().first < heights[i]){
            r.push_back(st.top().second);
        }
        else if(st.size()>0 && st.top().first >= heights[i]){
            while(st.size()>0 && st.top().first >= heights[i]){
                st.pop() ;
            }
            if(st.size()==0){
                r.push_back(p) ;
            }
            else{
                r.push_back(st.top().second) ;
            }
        }
        st.push(make_pair(heights[i],i)) ;
    }
    reverse(r.begin(),r.end());
    return r ;
}
int MAH(vector<int> &heights){
    vector<int> left , right ;
    left = NSL(heights) ;
    right = NSR(heights) ;
    int i , area = -1 , n= heights.size();
    cout<< "right =  "; 
    for(i=0;i<n;i++){
        cout<<right[i] <<" ";
    }
    cout<<endl;
    cout<< "left =  "; 
    for(i=0;i<n;i++){
       cout<< left[i] <<" ";
    }
    cout<<endl;
    vector<int> width(n) ;
    for(i=0;i<n;i++){
        width[i] = right[i] - left[i] -1 ;
        area = max(area,heights[i]*width[i]) ;
    }
    return area ;
    
}
int main()
{
    int n , i ;
    cout<<"Enter N  "<<endl;
    cin>>n ;
    vector<int> heights(n) ;
    for(i=0;i<n;i++){
        cin>>heights[i] ;
    }
    int ans = MAH(heights) ;
    cout<<ans ;
    cout<<endl ;
    return 0 ;
}
// I/P : 6 2 5 4 5 1 6
// O/P : 12
