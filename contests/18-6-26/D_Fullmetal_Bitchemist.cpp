#include <iostream>
#include <bits/stdc++.h>

using namespace std;
void solve(stack<bool>& s){
    while(!s.empty()){
        bool a= s.top();
        s.pop();
        if(s.empty()){
            s.push(a); return;
        }
        bool b= s.top();
        s.pop();
        if(a == b){
            s.push(!a);
        }
        else{
            s.push(b);
            s.push(a);
            return;
        }
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        stack<bool> st;
        for(char c: s){
            if(c=='0'){
                st.push(0);
            }else{
                st.push(1);
            }
            solve(st);
        }
        
    }
    return 0;
}