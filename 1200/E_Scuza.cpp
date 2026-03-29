#include <iostream>
#include <bits/stdc++.h>
using namespace std;
long long BS(vector<pair<int, long long>> & a, int x){
    int l=0, r= a.size()-1;
    while(l<=r){
        int mid= l+(r-l)/2;

        if(a[mid].first <= x) l= mid+1;
        else r= mid-1;
    }
    return a[r].second;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<pair<int, long long>> a(n+1);
        vector<int> b(m);
        int maxi= 0;
        long long sum=0;
        a[0] = {0, 0};
        for(int i=1; i<=n; i++){
            int t;
            cin>>t;
            sum += (long long)t;
            maxi= max(maxi, t);
            a[i]= {maxi, sum};
        }
        
        for(int i=0; i<m; i++)
            cin>>b[i];
        
        for(int i: b){
            cout<< BS(a, i) <<" ";
        }
        cout<<endl;
        
    }
    return 0;
}