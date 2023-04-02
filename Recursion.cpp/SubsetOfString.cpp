#include<iostream>
#include<string>
using namespace std ;
void solve(string input,string output)
{
    if(input.length()==0){
        cout<<output <<" ";
        return ;
    }
    string op1 = output ;
    string op2 = output ;
    op2.push_back(input[0]) ;
    // op2 += input[0] ;
    input.erase(input.begin()+0) ; // smaller input
    solve(input,op1) ;
    solve(input,op2) ;
}
int main()
{
    string input ;
    cout<<"Enter String : " ;
    cin>>input;
    string output = "";
    solve(input,output);
    cout<<endl ;
    return 0 ;
}
