#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        vector<int> arr(n);
        for(int& i: arr){
            cin>>i;
        }

        // vector<int> freq(k, 0);
        unordered_map<int, int> freq;
        for(int i: arr){
            freq[i%k]++;
        }
        long long ans = 0;
        for(auto& p: freq){
            if(p.first == 0){
                continue;
            }
            ans = max(ans, ((long long)(p.second-1) * (k)) + (k-p.first+1));
        }
        // for(int i=1; i<k; i++){
        //     ans = max(ans, ((long long)(freq[i]-1) * (k)) + (k-i+1));
        // }
        cout<<ans<<endl;
    }
    return 0;
}