#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,x;
        cin>>n>>x;
        vector<int> a(n);
        for(int& i: a) cin>>i;
        sort(a.begin(), a.end());

        long long sum=0;
        long long ans=0;
        for(int i=0; i<n; i++){
            sum+=a[i];
            int t=((x-sum)/(i+1)) +1;
            if(t>0) ans+= t;
            // cout<<ans<<" ";
        }
        cout<<ans<<endl;
    }
    return 0;
}