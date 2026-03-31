#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> primes;
void sieve(int n){
    vector<bool> p(n+1,0);

    for(int i=2; i<=n; i++){
        if(p[i] ==0){
            primes.push_back(i);
            for(int j=i*i; j<=n; j+=i){
                p[j] = 1;
            }
        }
    }
}

int main(){
    int t;
    cin>>t;
    sieve(sqrt(1e9));
    while(t--){
        int n;cin>>n;
        
        bool flag= false;
        for(int i: primes){
            if(n % i == 0){
                cout<<n/i <<" "<<n - n/i<<endl;
                flag = true;
                break;
            }
        }
        if(!flag){
            cout<<"1 "<<n-1<<endl;
        }
    }
    return 0;
}