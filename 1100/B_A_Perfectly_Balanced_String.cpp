#include <iostream>
#include  <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;
    while( t--){
        string s;
        cin>>s;

        vector<int>alp(26,0);
        for(int i=0; i<s.size(); i++){
            alp[s[i]-'a']++;
        }
        int cnt=0;
        for(int i=0; i<26; i++){
            if(alp[i]) cnt++;
        }

        alp= vector<int>(26,0);
        bool flag = 1;
        for(int i=0; i<cnt; i++){
            if(alp[s[i]-'a']){
                flag=0;
                break;
            }
            alp[s[i]-'a']=1;
        }

        int i=cnt;
        while(i<s.size()){
            if(s[i] != s[i-cnt]){
                flag=0;
                break;
            }
           i++;
        }
        if(flag) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}