#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        long long n,x;
        cin>>n>>x;
        vector<int> a(n);
        for(int& i: a) cin>>i;
        sort(a.begin(), a.end());

        long long sum=0;
        long long ans=0;
        for(int i=0; i<n; i++){
            sum+=a[i];
            // long long t= ((x-sum)/(i+1))+1;
            if(sum <= x) ans += ((x-sum)/(i+1))+1;
        }
        cout<<ans<<endl;
    }
    return 0;
}