#include<iostream>
#include<bits/stdc++.h> 
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,q;
        cin>>n>>q;

        vector<vector<bool>> dp(16, vector<bool>(16, false));
        for(int i=0; i<16; i++){
            for(int j=i+1; j<16; j++){
                for(int k=1; k<=5; k++){
                    if((i^(3*k))%3 == 0 && (j^(3*k))%3 == 0){
                        dp[i][j] = true;
                        dp[j][i] = true;
                    }
                }
            }
        }

        vector<int>arr(n);
        vector<int> temp(16, 0);
        for(int&i: arr){
            cin>>i;

            bool found = false;
            for(int j=0; j<16; j++){
                if(temp[j] && dp[i][j]){
                    temp[j]--;
                    found = true;
                    break;
                }
            }
            if(!found){
                temp[i]++;
            }
        }
        
        cout<<n - accumulate(temp.begin(), temp.end(), 0)<<" ";

        while(q--){
            int x, y;
            cin>>x>>y;
        }

    }
    return 0;
}