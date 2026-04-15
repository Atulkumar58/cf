#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int&i : a) cin>>i;
        map<int,int> m;
        for(int i=0; i<n; i++){
            m[a[i]-i]++;
        }
        long long ans = 0;
        for(auto& p : m){
            long long x = p.second;
            ans += x * (x - 1) / 2;
        }
        cout << ans << endl;

    }
    return 0;
}