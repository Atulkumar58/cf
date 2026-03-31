#include <iostream>
#include <vector>
using namespace std;
vector<int> primes;
void sieve(int n){
    vector<bool> is_prime(n+1, true);
    is_prime[0] = is_prime[1] = false;
    for(long long i=2; i<=n; i++){
        if(is_prime[i]){
            primes.push_back(i);
            for(long long j=i*i; j<=n; j+=i){
                is_prime[j] = false;
            }
        }
    }
}
int main(){
    int t;
    cin>>t;
    sieve(1000);
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int& i: a) cin>>i;

        vector<long long> numofprime(primes.size(), 0);
        int othernum= -1, count=0;
        bool flag = true;
        for(int i=0; i<n; i++){
            int j=0;
            while(j < primes.size()){
                if(a[i] == 1) break;
                while(a[i] % primes[j] == 0){
                    numofprime[j]++;
                    a[i] /= primes[j];
                }
                j++;
            }

            if(a[i] != 1){
                if(othernum == -1) {othernum = a[i]; count=1;}
                else if(othernum != a[i]){
                    flag = false;
                    break;
                }
                else count++;
            }
        } 
        if(count%n != 0) flag = false;
        if(flag)
        for(int i: numofprime){
            if(i % n != 0){
               flag = false;
                break;
            }
        }

        if(flag)cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}