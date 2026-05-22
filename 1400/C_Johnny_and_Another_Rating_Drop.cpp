#include <iostream>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        long long n;
        cin>>n;

        long long ans=0;
        long long mask=1;
        while(n){
            if(n&1){
                ans += mask;
            }
            n >>= 1;
            mask <<= 1;
            mask++;
        }
        cout<<ans<<endl;
    }
    return 0;
}