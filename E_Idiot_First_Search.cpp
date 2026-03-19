#include <iostream>
#include <bits/stdc++.h>
using namespace std;
unordered_map<int, vector<int>> child;
vector<long long> ans;
const int modul = 1000000007;
void dfs(int v){
    // cout<<v<<" ";
    if(ans[v] != -1) return;
    if(v==0) return;
    long long int rv=0;

    for(int i=0; i<child[v].size(); i++){
        if(child[v][i] != 0){
            dfs(child[v][i]);
            rv+= ans[child[v][i]];
            rv+=2;
        }
    }

    ans[v]= rv%modul;
}
void dfs2(vector<int>& p, int v){
    int a=p[v];
    ans[v]+= ans[a]+1;
    ans[v]%=modul;
    for(int i=0; i<child[v].size(); i++){
        dfs2(p, child[v][i]);
    }
}
int main(){
    int t;
    cin>>t;

    while (t--){
        int n;
        cin>>n;
        child.clear();
        int a, b;
        child[0] = {1};
        vector<int> parent(n+1, 0);
        for(int i=1; i<=n; i++){
            cin>>a>>b;
            if(a!= 0) {
                parent[a]=i;
                child[i].push_back(a);
            }
            if(b!=0){
                parent[b] =i;
                child[i].push_back(b);
            }    
        }

        ans.resize(n+1);
        for(int i=0; i<=n; i++) ans[i]=-1;
        ans[0]=0;

        dfs(1);
        ans[0]=0;

        dfs2(parent, 1);
        for(int i=1; i<=n; i++) cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}