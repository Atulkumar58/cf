#include <iostream>
#include <vector>
#include <climits>

using namespace std;
vector<int> a;
int gcd(int x, int y){
    // if(x == INT_MAX) return y;
    if(y==0) return x;
    return gcd(y, x%y);
}
bool canPartition(int l){
    int g= 0;
    int n= a.size();
    for(int i=l; i< n; i++){
        g = gcd(g, abs(a[i]-a[i-l]));
        // cout<<g<<" ";
        if(g == 1) return false;
    }
    return true;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        a.resize(n);
        for(int& i: a) cin>>i;
        int ans=0;
        // canPartition(2);
        for(int i=1; i*i<=n; i++){
            if(n%i == 0){
                if(canPartition(i)) ans++;
                if(i*i != n && canPartition(n/i)) ans++;
                // cout<<ans<<" ";
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}