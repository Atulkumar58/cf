#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<vector<int>> h(n, vector<int>(2));

    for(int i=0; i<n; i++) cin>> h[i][0];
    for(int i=0; i<n; i++) cin>> h[i][1];
    
    vector<vector<long long>> dp(n, vector<long long>(2));
    dp[0][0] = h[0][0];
    dp[0][1] = h[0][1];
    for(int i=1; i<n; i++){
        dp[i][0] = max(dp[i-1][0], dp[i-1][1] + h[i][0]);
        dp[i][1] = max(dp[i-1][1], dp[i-1][0] + h[i][1]);
    }
    cout<<max(dp[n-1][0], dp[n-1][1])<<endl;
    return 0;
}