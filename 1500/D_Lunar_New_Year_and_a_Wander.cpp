#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> adj(n+1);
    for(int i=0; i<m; i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> visited(n+1,false);
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(1);
    visited[1] = true;
    while(!pq.empty()){
        int node = pq.top();
        pq.pop();

        cout<<node<<" ";
        for(int neighbor: adj[node]){
            if(!visited[neighbor]){
                visited[neighbor] = true;
                pq.push(neighbor);
            }
        }
    }
    cout<<endl;
    return 0;
}