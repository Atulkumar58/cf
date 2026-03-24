#include <iostream>
#include <vector>

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        
        vector<int> index(26, n);
        vector<int> dp(n+1, 0);
        for(int i=n-1; i>=0; i--){
            int c = s[i] - 'a';
            dp[i] = dp[i+1] + index[c]- i;
            index[c] = i;
        }

        cout<<dp[0]<<endl;
    }
    return 0;
}