#include<iostream>
#include<vector>
#include<stack>
using namespace std;
void insert(stack<int> &st,int temp)
{
    if(st.size()==0 || st.top()<=temp){
        st.push(temp) ;
        return ;
    }
    int val = st.top() ;
    st.pop() ;
    insert(st,temp) ;
    st.push(val) ;
}
void sort(stack<int> &st)
{
    if(st.size()==1){
        return ;
    }
    int temp = st.top() ;
    st.pop() ;
    sort(st) ;
    insert(st,temp) ;
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
    sort(st) ;
    while(st.size()>0){
        cout<<st.top() <<" " ;
        st.pop() ;
    }
}