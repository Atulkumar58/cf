#include <iostream>
#include <vector>
using namespace std;
int dfs(int v, int l, vector<vector<pair<int, int>>>& adj){
    int ans=0;
    for(auto i: adj[v]){
        if(i.second == l) continue;
        int t= dfs(i.first, i.second, adj);
        if(i.second < l){
            t++;
        }
        ans= max(ans, t);
    }

    return ans;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n; cin>>n;
        vector<vector<pair<int, int>>> adj(n+1);
        for(int i=1; i<n; i++){
            int a, b;
            cin>>a>>b;
            adj[a].push_back({b, i});
            adj[b].push_back({a, i});
        }
        int t= dfs(1,0,adj);
        cout<<t+1<<endl;
    }
    return 0;
}
