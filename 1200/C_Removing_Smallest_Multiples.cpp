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

        long long ans=0;
        vector<bool> vis(s.length(), false);
        for(int i=0; i<n;i++){
            if(s[i]== '0'){
                for(int j=i; j<n; j+= (i+1)){
                    if(s[j]== '0'){
                       if(!vis[j]) ans+= i+1;
                        vis[j]= true;
                    }
                    else break;
                }

            }
            // cout<<ans<<" ";
        }
        cout<<ans<<endl;
    }
    return 0;
} 