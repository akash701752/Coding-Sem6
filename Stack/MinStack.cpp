#include<iostream>
#include<vector>
#include<stack>
using namespace std;
void push(stack<int> &st,stack<int> &st1,int x)
{
    st.push(x);
    if(st1.size()==0 || x<= st1.top()){
        st1.push(x) ;
    }
}
void pop(stack<int> &st,stack<int> &st1){
    if(st.size()==0){
        cout<<"Stack Empty "<<endl;
    }
    int top = st.top() ;
    st.pop() ;
    if(st1.top()==top){
        st1.pop() ;
    }
}
int getMin(stack<int> &st,stack<int> &st1){
    if(st1.size()==0){
        cout<<"Stack Empty"<<endl ;
    }
    return st1.top() ;
}
int main()
{
    int ch , x ;
    stack<int> st , st1 ;
    do{
        cout<<"1.Push 2.Pop 3.Get Min 0.Exit \n";
        cin>>ch ;
        switch(ch){
            case 1 : cin>>x ;
                    push(st,st1,x);
                    break;      
            case 2 : pop(st,st1);
                    break;       
            case 3 : cout<<"Min = "<< getMin(st,st1)<<endl;
                    break;
            case 4 : cout<<"!!! Exiting !!! "<<endl ;
                    break; 
            default : cout<<"Enter Valid Choice"   ;
                    break;   
        }
    }while(ch!=0);
    return 0 ;

}