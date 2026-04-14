
#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n, k, x;
    cin>>n>>k>>x;
    vector<long long> a(n);
    for(long long& i: a){
        cin>>i;
    }
    sort(a.begin(), a.end());
    vector<long long> diff;
    for(int i=1; i<n; i++){
        if(a[i]-a[i-1] > x){
            diff.push_back(a[i]-a[i-1]);
        }
    }

    sort(diff.begin(), diff.end());
    long long ans = diff.size() + 1;
    for(long long i: diff){
        long long need = (i-1)/x;
        if(need <= k){
            k -= need;
            ans--;
        }
        else{
            break;
        }
    }
    cout<<ans<<endl;
    return 0;
}