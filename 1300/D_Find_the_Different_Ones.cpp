#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        vector<int> dp(n);
        for(int i=0; i<n; i++){
            cin>>arr[i];

            if(i==0){
                dp[i] = -1;
            }
            else{
                if(arr[i] == arr[i-1]){
                    dp[i] = dp[i-1];
                }
                else{
                    dp[i] = i-1;
                }
            }
        }

        int q;
        cin>>q;
        while(q--){
            int l,r;
            cin>>l>>r;
            l--;r--;

            if(dp[r] < l){
                cout<<"-1 -1\n";
            }
            else{
                cout<<dp[r]+1<<" "<<r+1<<"\n";
            }

        }

    }
    return 0;
}