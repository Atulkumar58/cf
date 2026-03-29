#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> ins(int n){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> a;
        vector<pair<int,int>> v;
        for(int i=0; i<n; i++){
            int t;
            cin>>t;
            if(a.size() <3 ){
                a.push({t,i});
            }else if(a.top().first < t){
                a.pop();
                a.push({t, i});
            }
        }
        while(!a.empty()){
            v.push_back(a.top());
            a.pop();
        }
    return v;
}
int backtrack(vector<vector<pair<int, int>>> & v, vector<int> x, int idx, int sum){
    if(idx >= v.size()) return sum;

    int ans= INT_MIN;
    for(auto i: v[idx]){
        if(find(x.begin(), x.end(), i.second) != x.end()) continue;
        x.push_back(i.second);
        ans= max(ans, backtrack(v, x, idx+1, sum+i.first));
        x.pop_back();
    }
    return ans;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<vector<pair<int, int>>> v(3);
        v[0] = ins(n);
        v[1] = ins(n);
        v[2] = ins(n);
        vector<int>x;
        cout<<backtrack(v, x, 0, 0)<<endl;
    }
}