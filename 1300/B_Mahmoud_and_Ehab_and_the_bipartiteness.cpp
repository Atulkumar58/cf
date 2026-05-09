#include <iostream>
#include <vector>
using namespace std;
long long a, b;
//a => even depth
//b => odd depth
vector<bool> visited;
void dfs(vector<vector<int>>& g, int u, int depth){
    if(visited[u]) return;
    if(depth%2 == 0) a++;
    else b++;
    visited[u] = true;

    for(int v: g[u]){
        dfs(g, v, depth+1);
    }
}
int main(){
    int n;
    cin>>n;
    vector<vector<int>> g(n+1);
    
    for(int i=0; i<n-1; i++){
        int u, v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    visited = vector<bool> (n+1, false);
    dfs(g, 1, 0);
    cout<<a*b - (n-1)<<endl;
    return 0;
}