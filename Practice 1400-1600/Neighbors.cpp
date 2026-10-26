#include <bits/stdc++.h>

using namespace std;
vector<vector<int>>graph;
vector<bool> vis;

bool dfs(int i, int parent){
  if(vis[i]) return false;
  vis[i]=1;
  
  if(graph[i].size() > 2) return false;
  
  for(int x: graph[i]){
    if(x!= parent){
      if(!dfs(x, i)) return false;
    }
  }
  return true;
}

int main(){
  int n, m;
  cin>>n>>m;
  graph.clear();
  graph.resize(n+1);
  vis.resize(n+1, 0);
  while(m--){
    int a,b;
    cin>>a>>b;
    
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  

  bool possible= true;
  for(int i=1; i<=n; i++){
    if(!vis[i] && !dfs(i, -1)){
      possible= false;
    }
  }
  
  
  if(possible) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
  return 0;
}