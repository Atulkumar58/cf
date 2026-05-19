#include <iostream>
#include <vector>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        vector<long long> a(n);
        for(long long& i: a){
            cin>>i;
        }

        long long last=1;
        long long ans=0;
        for(int i=1; i<n; i++){
            if(a[i] * 2 > a[i-1]){
                last++;
            }
            else{
                if(last > k) ans += (last-k);
                last=1;
            }
        }
        if(last > k) ans += (last-k);
        cout<<ans<<endl;
    }
    return 0;
}