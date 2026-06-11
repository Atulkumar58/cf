#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        long long n, x;
        cin>>n>>x;

        vector<int>a(n);
        for(int& i:a) cin>>i;

        int ans=0;
        x*=2;
        long long l=a[0], r=a[0];
        for(int i=0; i<n; i++){
            // cout<<i<<" ";
            if(a[i] > l+x || a[i] < r-x){
                ans++;
                
                l=r=a[i];
            }
            else{
                l= min(l, (long long)a[i]);
                r= max(r, (long long)a[i]);
            }
            // cout<<l<<" "<<r<<endl;
        }
        cout<<ans<<endl;
    }
    return 0;
}