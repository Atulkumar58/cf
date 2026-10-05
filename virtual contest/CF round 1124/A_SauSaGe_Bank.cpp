#include <iostream>
#include <bits/stdc++.h>
using namespace std;


int main(){
    int t;
    cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;

        long long int ans= 2*(k-1) + (1<<(n-k+1));
        cout<<ans<<endl;
    }
    return 0;
}