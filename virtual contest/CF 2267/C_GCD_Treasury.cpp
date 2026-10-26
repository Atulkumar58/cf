#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--){
        int n, x;
        cin>>n>>x;

        vector<int> a(n);
       
        vector<int> factors;
        for(int i=2; i*i<=x; i++){
            if(x%i==0) factors.push_back(i);
            while(x%i ==0){
                x/=i;
            }
        }
        if(x>1) factors.push_back(x);
        // for(int i: factors) cout<<i<<" ";cout<<endl;
        for(int i=0; i<n; i++){
            cin>>a[i];
        }
        long long ans=0;
        for(auto i: factors){
            long long sum=0;
            for(int j=0; j<n; j++){
                if(a[j]%i==0){
                    sum+= a[j];
                }
            }
            ans= max(ans, sum);
        }
        cout<<ans<<endl;
    }
    return 0;
}