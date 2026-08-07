#include <iostream>
#include <vector>
using namespace std;
const int mod = 1e9 + 7;

long long pow(int a, int b){
    if(b == 0) return 1;

    long long res = pow(a, b/2);
    res = (res * res) % mod;
    if(b % 2 == 0){
        return res;
    }else{
        return (res * a) % mod;
    }
}

vector<int> vis;
vector<vector<int>> adj;
int dfs(int node){
    int res=1;
    for(int child: adj[node]){
        if(!vis[child]){
            vis[child] = true;
            res += dfs(child);
        }
    }
    return res;
}
int main(){
    int n, k;
    cin>>n>>k;
    adj.clear();
    adj.resize(n+1);
    for(int i=1; i<n; i++){
        int a, b, c;
        cin>>a>>b>>c;

        if(c == 0){
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
    }
    long long res= pow(n, k);
    vis.resize(n+1, false);
    for(int i=1; i<=n; i++){
        if(!vis[i]){
            vis[i] = true;
            int x= dfs(i);
            long long temp= pow(x, k);
            
            if(res >= temp){
                res -= temp;
            }else{
                res = (res + mod - temp) % mod;
            }
        }
    }
    cout<<res<<endl;
    return 0;
}