#include<iostream>
#include<string>
#include<vector>
using namespace std ;
void solve(string input,string output,vector<string> &v)
{
    if(input.length()==0){
        v.push_back(output) ;
        return ;
    }
    string op1 = output ;
    string op2 = output ;
    if(isalpha(input[0])){
        op1.push_back(tolower(input[0])) ;
        op2.push_back(toupper(input[0])) ;
        input.erase(input.begin()+0) ;
        solve(input,op1,v) ;
        solve(input,op2,v) ;
    }
    else{
        op1.push_back(input[0]) ;
        input.erase(input.begin()+0) ;
        solve(input,op1,v) ;
    }
}
int main()
{
    string input , output ;
    cout<<"Enter String : ";
    cin>>input ;
    output = "";
    vector<string> v ;
    solve(input,output,v);
    for(int i=0;i<v.size();i++){
        cout<<v[i] << " ";
    }
    cout<<endl ;
    return 0 ;
}