#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
using namespace std ;
static int mod = 1003 ;
int solve(string str,int i,int j,bool isTrue,unordered_map<string,long long int> &mp)
{
    if(i>j){
        return 0 ;
    }
    if(i==j){
        if(isTrue){
            return str[i]=='T' ;
        }
        else{
            return str[i] =='F' ;
        }
    }
    string key = to_string(i) ;
    key.push_back(' ');
    key.append(to_string(j));
    key.push_back(' ');
    key.append(to_string(isTrue));
    if(mp.find(key)!=mp.end()){
         return mp[key] ;
    }
    long long int ans = 0 ;
    for(int k=i+1;k<=j-1;k=k+2)
    {
        long long int lT,lF,rT,rF ;
        lT = solve(str,i,k-1,true,mp) % mod ;
        lF = solve(str,i,k-1,false,mp) % mod ;
        rT = solve(str,k+1,j,true,mp) % mod ;
        rF = solve(str,k+1,j,false,mp)% mod ;

        if(str[k]=='&'){
            if(isTrue==true){
                ans = (ans + (lT*rT)%mod)%mod ;
            }
            else{
                ans = (ans+ (lT*rF)%mod + (lF*rT)%mod + (lF*rF)%mod ) %mod ;
            }
        }
        if(str[k]=='|'){
            if(isTrue==true){
                ans = (ans+ (lT*rT)%mod + (lT*rF)%mod + (lF*rT)%mod)%mod ;
            }
            else{
                ans =  (ans+ (lF*rF)%mod)%mod ;
            }
        }
        if(str[k]=='^'){
            if(isTrue==true){
                ans =  (ans+ (lT*rF)%mod + (lF*rT)%mod)%mod ;
            }
            else{
                ans =  (ans+ (lF*rF)%mod + (lT*rT)%mod) ;
            }
        }
    }
    return mp[key]= ans ;
}
int evaluateTrue(string str){
    unordered_map<string,long long int> mp ;
    return solve(str,0,str.length()-1,true,mp);
}
int main()
{
    string str ;
    cout<<"Enter a String : ";
    cin>>str ;
    cout<<evaluateTrue(str);
    cout<<endl ;
    return 0 ;
}
// Symbols
//     'T' --- true 
//     'F' --- false 
// And following operators filled between symbols
// Operators
//     &   ---boolean AND
//     |   --- boolean OR
//     ^   --- boolean XOR 
// Count the number of ways we can parenthesize the expression so that the value of expression evaluates to true.
// Example:
// Input: symbol[]    = {T, F, T}
//        operator[]  = {^, &}
// Output: 2
// The given expression is "T ^ F & T", it evaluates true
// in two ways "((T ^ F) & T)" and "(T ^ (F & T))"