#include <iostream>
#include <vector>
#include <map>
using namespace std;

long long enc(int a, int b){
    return (1LL * a << 32) | b;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n, x, y;
        cin>>n>>x>>y;

        vector<int> a(n);
        map<long long, int> freq;
        for(int& i: a) cin>>i;

        long long ans=0;
        for(int i: a){
            int mx= i % x;
            int my= i % y;

            ans += freq[enc((x - mx)%x, my)];
            freq[enc(mx, my)]++;
        }
        cout<<ans<<endl;
    }
    return 0;
}