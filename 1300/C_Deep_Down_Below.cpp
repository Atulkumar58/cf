#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<vector<int>> a(n);
        for(int i=0; i<n; i++){
            int k;
            cin>>k;
            a[i].resize(k);
            for(int j=0; j<k; j++){
                cin>>a[i][j];
            }
        }

        vector<pair<int, int>> least_power(n);
        for(int i=0; i<n; i++){
            least_power[i].first= a[i][0]+1;
            for(int j=1; j<a[i].size(); j++){
                least_power[i].first= max(least_power[i].first, a[i][j]-j+1);
            }
            least_power[i].second= a[i].size(); 
        }

        sort(least_power.begin(), least_power.end());
        // for(int i=0; i<n; i++){
        //     cout<<least_power[i].first<<" ";
        // }
        int ans=0;
        int sum=0;
        for(int i=0; i<n; i++){
            ans= max(ans, least_power[i].first - sum);
            sum+= least_power[i].second;
        }
        cout<<ans<<endl;
    }
    return 0;
}