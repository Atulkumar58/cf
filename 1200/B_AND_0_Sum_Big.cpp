#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const int mod=1e9+7;

int powMod(int x, int n) {
    long long res = 1;
    while(n--){
        res = (res * x) % mod;
    }
    return res;
}
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        long long n, k;
        cin>>n>>k;

        cout<< (powMod(n, k) )<<"\n";
        
    }
    
    return 0;
}