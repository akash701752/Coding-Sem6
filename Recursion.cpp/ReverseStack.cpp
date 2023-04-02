#include<iostream>
#include<vector>
#include<stack>
using namespace std;
void insert(stack<int> &st,int ele)
{
    if(st.size()==0){
        st.push(ele) ;
    }
    else{
        int val = st.top() ;
        st.pop() ;
        insert(st,ele) ;
        st.push(val) ;
    }
}
void reverse(stack<int> &st)
{
    if(st.size()==1){
        return ;
    }
    int temp = st.top() ;
    st.pop() ;
    reverse(st) ;
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
    reverse(st) ;
    while(st.size()>0){
        cout<<st.top() <<" " ;
        st.pop() ;
    }
}