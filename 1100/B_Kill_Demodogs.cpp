#include <iostream>
#include  <bits/stdc++.h>
using namespace std;
const long long mod= 1e9+7;
int main(){
    int t;
    cin>>t;
    while(t--){
        long long n;
        cin>>n;
        long long ans= 1;
        //sigma i2
        long long a=n-1, b=n, c= 2*n-1;

        if(a%3==0) a/=3;
        else if(b%3==0) b/=3;
        else c/=3;

        ans= (ans * a) % mod;
        ans= (ans * b) % mod;
        ans= (ans * c) % mod;
        ans= (ans+ (n*n)) % mod;
        
        ans= (ans + (n* (n-1))/2) % mod;
        ans = (ans*2022) % mod;
        cout<<ans<<endl;
    }
    return 0;
}