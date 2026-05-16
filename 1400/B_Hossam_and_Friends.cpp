#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> v(n);
        for(int i=0; i<m; i++){
            int a, b;
            cin>>a>>b;
            v.push_back({min(a, b), max(a,b)});
        }
        sort(v.begin(), v.end());
        
    }
    return 0;
}