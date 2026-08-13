#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

int main(){
    string s;
    cin>>s;

    vector<int> arr;
    int count=0;
    int n=s.length();
    for(int i=0; i<n; i++){
        if(s[i]=='a'){
            count++;
        }
        else if(s[i]== 'b' && count>0){
            arr.push_back(count);
            count=0;
        }
    }
    if(count>0){
        arr.push_back(count);
    }
    int m= arr.size();
    vector<int> dp(m, 0);
    long long last=1;
    for(int i=0; i<m; i++){
        dp[i] = (last*(arr[i]+1)) % MOD;
        last = dp[i];
    }

    cout<<((m > 0) ? dp[m-1]-1 : 0) <<endl;
    return 0;
}