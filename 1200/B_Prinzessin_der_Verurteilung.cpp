#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        int i=0;
        vector<bool> hash(27*(26*26+2), false);
        while(i < n){
            int t=0;
            for(int j=0; j<3 && i+j<n; j++){
                t*=26;
                t+= (s[i+j] - 'a' + 1);

                hash[t]=true;
            }
            i++;
        }

        for(int i=1; i<26*26*26; i++){
            if(!hash[i]){
                string ans="";
                int t=i;
                while(t > 0){
                    if(t == 26){
                        ans+='z';
                        break;
                    }
                    char c= (t%26) + 'a' - 1;
                    ans+=c;
                    t/=26;
                }
                reverse(ans.begin(), ans.end());
                cout<<ans<<"\n";
                break;
            }
        }
    }
    return 0;
}