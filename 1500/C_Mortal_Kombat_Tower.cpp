#include <iostream>
#include <vector>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> arr(n);
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }

        vector<int> dp(n+2, 0);
        vector<int> dpf(n+2, 0);

        for(int i=n-1; i>=0; i--){
            dp[i]= min(dpf[i+1], dpf[i+2]);

            if(arr[i] == 0){
                int t= dp[i+1];
                if(i+1<n && arr[i+1] ==0){
                    t= min(t, dp[i+2]);
                }
                else if(i+1 < n && arr[i+1] == 1){
                    t= min(t, dp[i+2] + 1);
                }
                dpf[i] = t;
            }
            else{
                int t= dp[i+1] + 1;
                if(i+1 < n && arr[i+1] == 0){
                    t= min(t, dp[i+2]+1);
                }
                else if(i+1 < n && arr[i+1] == 1){
                    t= min(t, dp[i+2]+2);
                }
                dpf[i] = t;
            }
        }
        // for(int i=0; i<n; i++){
        //     // cout<<dp[i]<<" "<<dpf[i]<<endl;
        // }
        cout<<dpf[0]<<endl;
    }
    return 0;
}