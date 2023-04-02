#include<iostream>
#include<vector>
#include<stack>
using namespace std;
void solve(stack<int> &st,int k)
{
    if(k==1){
        st.pop() ;
        return ;
    }
    int temp = st.top() ;
    st.pop() ;
    solve(st,k-1) ;
    st.push(temp) ;
}
void removeMiddle(stack<int> &st)
{
    if(st.size()==0){
        return ;
    }
    int k = st.size()/2 +1 ;
    solve(st,k);
}
int main()
{
    int n , i , num ;
    cout<<"Enter Size of Stack : ";
    cin>>n ;
    stack<int> st ;
    cout<<"Enter "<<n <<" Elements in Stack "<<endl ;
    for(i=0;i<n;i++){
        cin>>num ;
        st.push(num) ;
    }
    removeMiddle(st) ;
    while(st.size()>0){
        cout<<st.top() <<" " ;
        st.pop() ;
    }
}