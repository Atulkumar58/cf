#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, w;
        cin>>n>>w;
        int a[n];
        vector<int> m(32, 0);
        long long sum=0;
        for(int i=0; i<n; i++){
            cin>>a[i]; 
            sum+=a[i];
            int k=0;
            while(a[i] != (1<<k)) k++;
            m[k]++;
        } 
        vector<pair<int, int>> v;
        for(int i=0; i<32; i++){
            if(m[i] > 0) v.push_back({i, m[i]});
        }
        sort(v.begin(), v.end(), greater<pair<int, int>>());
        int ans=0;
        while(sum > 0){
            int rem=w;
            for(int i=0; i<v.size(); i++){
                if(v[i].second > 0 && (1<<v[i].first) <= rem){
                    int k=min(v[i].second, rem/(1<<v[i].first));
                    rem-=k*(1<<v[i].first);
                    v[i].second-=k;
                    sum-=k*(1<<v[i].first);
                }
            }
            ans++;
        }
        cout<<ans<<endl;

    }
    return 0;
}