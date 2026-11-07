#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<long long> a(n);
        for(int i=0; i<n; i++){
            cin>>a[i];
        }
        sort(a.begin(), a.end());
        vector<long long> diff(n);
        long long max_diff=0;
        for(int i=1; i<n; i+=2){
            max_diff= max(max_diff, a[i]-a[i-1]);
            diff[i]=max_diff;
        }
        if(n%2 == 0){
            cout<<diff.back()<<endl;
            continue;
        }

        long long ans= LLONG_MAX;
        max_diff=1;
        for(int i= n-2; i>=0; i-=2){
            ans= min(ans, max(max_diff, diff[i]));
            max_diff= max(max_diff, a[i+1]-a[i]);
        }
        ans= min(ans, max_diff);
        cout<<ans<<endl;
    }
}