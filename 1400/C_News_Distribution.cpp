#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

vector<int> no_news;
unordered_map<int, vector<int>> mp;
// vector<bool> visited;
unordered_map<int, bool> visited;
vector<int> friends;

int dfs(int node){
    if(visited[node]) return 0;
    visited[node] = true;
    if(node>0){
    friends.push_back(node);
    }
    int ans = 1;
    if(node < 0) ans=0;

    for(int friend_node: mp[node]){
        // cout<<node<< ": " << friend_node << endl;
        ans += dfs(friend_node);
    }
    
    return ans;
}
int main(){
    int n, m;
    cin>>n>>m;
    mp.clear();

    for(int i=1; i<=m; i++){
        int size;
        cin>>size;
        while(size--){
            int x;
             cin>>x;
            mp[-1 * i].push_back(x);
            mp[x].push_back(-1 * i);
        }
    }
    
    // for(auto &p: mp){
    //     cout<< p.first << ": ";
    //     for(int friend_node: p.second){
    //         cout<< friend_node << " ";
    //     }
    //     cout<< endl;
    // }
    no_news= vector<int>(n+1, 0);
    visited.clear();
    for(int i=1; i<=n; i++){
        if(!visited[i]){
            friends.clear();
            int x= dfs(i);
            // cout<<x<< endl;
            for(int friend_node: friends){
                no_news[friend_node] = x;
            }
        }
        // cout<<"avs"<< endl;
    }
    for(int i=1; i<=n; i++){
        cout<< no_news[i] << " ";
    }
    return 0;
}