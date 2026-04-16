#include <iostream>
#include<bits/stdc++.h>
using namespace std;
string s;   
int c;
int dfs(int u, vector<vector<int>>& adj){
    int ans=0;
    for(int v: adj[u]){
        ans+= dfs(v, adj);
    }
    if(s[u]=='W') ans++;
    else ans--;
    if(ans==0) c++;
    // cout<<u<<" "<<ans<<" "<<c<<endl;
    return ans;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n; cin>>n;
        vector<vector<int>> adj(n);
        for(int i=1; i< n; i++){
            int p; cin>>p;
            adj[p-1].push_back(i);
        }
        cin>>s;
        c=0;
        int i= dfs(0, adj);
        cout<<c<<endl;
        
    }
    return 0;
}