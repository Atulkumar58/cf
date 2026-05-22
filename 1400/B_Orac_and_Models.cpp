#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int& i: a){
            cin>>i;
        }
        vector<int> dp(n, 0);
        long long ans = 0;
        for(int i=1; i<=n; i++){
            for(int j=i-1; j<n; j+= i){
                if(a[j] > a[i-1]){
                    dp[j] = max(dp[j], dp[i-1] + 1);
                }
            }
        }
        // for(int i: dp){
        //     cout<<i<<" ";
        // }
        cout<<*max_element(dp.begin(), dp.end()) + 1<<endl;
    }
    return 0;
}