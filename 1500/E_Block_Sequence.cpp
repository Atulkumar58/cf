
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

vector<int> dp;
vector<int> a;

int rec(int i){
    if(i == a.size()) return 0;
    if(i >= a.size()) return a.size();
    if(i == a.size()-1) return 1;

    if(dp[i] != INT_MAX) return dp[i];
    
        dp[i]= min(dp[i], rec(i+ a[i] +1));
        dp[i] = min(dp[i], 1 + rec(i+1));
    
    dp[i] = min(dp[i], int(a.size()) -i);
    // cout<<i<<" "<<dp[i]<<endl;
    return dp[i];  
}
int main(){
    //fast io
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        a.resize(n);
        dp.resize(n);
        fill(dp.begin(), dp.end(), INT_MAX);
        dp[0] = INT_MAX;
        for(int i=0; i<n; i++){
            cin>>a[i];
        }
        
        cout<<rec(0)<<endl;

        
    }
    return 0;
}