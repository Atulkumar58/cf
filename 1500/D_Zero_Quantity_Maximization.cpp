#include <iostream>
#include <vector>
#include <map>

using namespace std;
int gcd(int a, int b){
    if(b==0) return a;
    return gcd(b, a%b);
}
int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    vector<int> b(n);
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    for(int i=0; i<n; i++){
        cin>>b[i];
    }

    map<long long, int> mp;
    int x=0;
    for(int i=0; i<n; i++){
        if(a[i]==0 && b[i]==0){
            x++;
            continue;
        }
        if(a[i]==0) continue;
        if(b[i]==0){
            mp[0]++;
            continue;
        }
        int g = gcd(abs(a[i]), abs(b[i]));
        a[i]/=g;
        b[i]/=g;

        long long key ;
        if((a[i] >= 0 && b[i] >= 0) || (a[i] <= 0 && b[i] <= 0)) key = (long long)abs(a[i])*(1e9+1) + abs(b[i]);
        else key = -((long long)abs(a[i])*(1e9+1) + abs(b[i]));

        mp[key]++;
    }
    int ans=0;
    for(auto it: mp){
        ans = max(ans, it.second);
    }
    cout<<ans+x<<endl;
    return 0;
}