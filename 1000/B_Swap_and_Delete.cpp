#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int n = s.length();

        int n_z=0, n_o=0;
        for(char c: s){
            if (c=='0') n_z++;
            else n_o++;
        }

        for(int i=0; i<n; i++){
            if (s[i]=='0' && n_o>0){
                // cout<<'1';
                n_o--;
            }
            else if (s[i]=='1' && n_z>0){
                // cout<<'0';
                n_z--;
            }
            else{
                // cout<<s[i];
                break;
            }
        }
        cout<<n_o+n_z<<endl;
    }
    return 0;
}