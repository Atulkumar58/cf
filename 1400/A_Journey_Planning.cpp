#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> b(n);
    for(int& i:b) cin>>i;

    unordered_map<int, long long> m;
    for(int i=0; i<n; i++){
        m[b[i]- i] += b[i];
    }

    long long ans=0;
    for(auto& p: m){
        ans = max(ans, p.second);
    }
    cout<<ans<<endl;
    return 0;
}