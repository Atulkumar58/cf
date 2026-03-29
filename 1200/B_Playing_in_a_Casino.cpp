#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>>a(m, vector<int> (n));
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                cin>>a[j][i];
        
        long long ans=0;
        for(int i=0; i<m; i++){
            sort(a[i].begin(), a[i].end());
            long long sum= a[i][0];
            for(int j=1; j<n; j++){
                long long t= ((long long)a[i][j]*j) -sum;
                ans+=t;
                sum+=a[i][j];
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}