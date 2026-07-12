#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> parent;
vector<bool> c;
vector<vector<int>> children;
vector<int> ans;
bool dfs(int node){
    bool res = c[node];
    for(int child:children[node]){
        dfs(child);
        res &= c[child];
    }

    if(res) ans.push_back(node);
    return res;
}
int main(){
    int n;
    cin>>n;
    // vector<int> parent(n+1);
    parent.resize(n+1);
    c.resize(n+1);
    // vector<bool> c(n+1);
    // vector<vector<int>> children(n+1);
    children.resize(n+1);
    int root=0;
    for(int i=1; i<=n; i++){
        cin>>parent[i];
        if(parent[i]==-1) root=i;
        else children[parent[i]]. push_back(i);

        int t;
        cin>>t;
        if(t==1) c[i]=true;
        else c[i]=false;
    }
    dfs(root);
    sort(ans.begin(), ans.end());
    if(ans.empty()) cout<<-1;
    
    for(int i: ans) cout<<i<<" ";
    return 0;
}