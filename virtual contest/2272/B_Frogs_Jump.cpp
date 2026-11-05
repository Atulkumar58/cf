#include <iostream>
#include <vector>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string a, b;
        cin>>a>>b;
        vector<vector<char>> dp(2, vector<char>(2, 'o'));
        int ans=0;
        for(int i=0; i<n; i++){
            dp[0][0]= dp[0][1];
            dp[1][0]= dp[1][1];

            dp[0][1]= a[i];
            dp[1][1]= b[i];

            if(dp[0][0] == dp[1][0] && dp[0][0]=='f'){
                dp[0][0]=dp[1][0]='o';
            }
            if(dp[0][0] == dp[0][1] && dp[0][0]=='f'){
                dp[0][0]=dp[0][1]='o';
            }
            if(dp[1][0]==dp[1][1] && dp[1][1]=='f'){
                dp[1][0]=dp[1][1]='o';
            }
            if(dp[0][1]==dp[1][0] && dp[1][0]=='f'){
                dp[0][1]=dp[1][0]='o';
            }
            if(dp[0][0]==dp[1][1] && dp[1][1]=='f'){
                dp[0][0]=dp[1][1]='o';
            }
            if(dp[0][1]==dp[1][1] && dp[1][1]=='f'){
                dp[0][1]=dp[1][1]='o';
            }
            if(dp[0][0] =='f' || dp[1][0]=='f'){
                ans++;
            }
        }
        if(dp[0][1] =='f' || dp[1][1]=='f'){
                ans++;
            }
        cout<<ans<<endl;
    }
}