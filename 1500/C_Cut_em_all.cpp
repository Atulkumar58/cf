#include <iostream>
#include <vector>

using namespace std;
int ans;
vector<vector<int>> arr;
int dfs(int node, int parent= -1){

    int count=1;
    for(int child: arr[node]){
        if(child!= parent){
            int x= dfs(child, node);
            if(x%2==0){
                ans++;
            }
            count+=x;
        }
    }
    return count;
}
int main(){
    int n;
    cin>>n;
    // vector<vector<int>> arr(n+1);
    arr.clear();
    arr.resize(n+1);
    for(int i=0; i<n-1; i++){
        int a, b;
        cin>>a>>b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }
    ans=0;
    if(n%2==1){
        cout<<-1<<endl;
        return 0;
    }
    dfs(1);
    cout<<ans<<endl;
    return 0;
}