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
    op1.push_back('_') ;
    op1.push_back(input[0]) ;
    op2.push_back(input[0]) ;

    input.erase(input.begin()+0) ;
    solve(input,op1) ;
    solve(input,op2) ;
}
int main()
{
    string input , output ;
    cout<<"Enter String : ";
    cin>>input ;
    output = "";
    output.push_back(input[0]) ;
    input.erase(input.begin()+0) ;
    solve(input,output);
    return 0 ;
}