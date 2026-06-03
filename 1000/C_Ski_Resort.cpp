#include <iostream>
#include <vector>
using namespace std;

long long calculate(int n, int k){
    if (n==0) return 0;
    if (n < k) return 0;
    return (long long)(n-k+1) * (n-k+2) / 2;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n, k, q;
        cin>>n>>k>>q;
        // Process the ski resort problem here
        int consecutive= 0;
        long long ans= 0;
        vector<int> slopes(n);
        for(int i=0;i <n; i++){
            cin>>slopes[i];
            if(slopes[i] <= q){
                consecutive++;
            }
            else{
                ans += calculate(consecutive, k);
                consecutive= 0;
            }
        }
        ans += calculate(consecutive, k);
        cout<<ans<<endl;
    }
    return 0;
}