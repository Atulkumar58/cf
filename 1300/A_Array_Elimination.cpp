#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
    if(b==0) return a;
    return gcd(b, a%b);
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        vector<int> bits(31, 0);
        bool all_zero=true;
        for(int& i: a) {
            cin>>i;
            if(i != 0) all_zero=false;
            int k=0;
            while((1<<k) <= i){
                if(i & (1<<k)){
                    bits[k]++;
                }
                k++;
            }
        }
        if(all_zero){
            for(int i=0; i<n; i++){
                cout<<i+1<<" ";
            }
            cout<<endl;
            continue;
        }
        int ans=0;
        for(int i=0; i<31; i++){
            // if(bits[i] > 0){
                ans= gcd(ans, bits[i]);
            // }
        }
        
        for(int i=1; i<=ans; i++){
            if(ans % i == 0){
                cout<<i<<" ";
            }
        }cout<<endl;

    }
    return 0;
}