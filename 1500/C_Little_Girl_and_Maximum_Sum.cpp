#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n, q;
    cin>>n>>q;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    vector<int> prefix(n+1, 0);
    for(int i=0; i<q; i++){
        int l, r;
        cin>>l>>r;
        prefix[l-1]++;
        prefix[r]--;
    }

    sort(arr.begin(), arr.end(), greater<int>());
    vector<int> freq;
    int sum=0;
    for(int i=0; i<n; i++){
        sum+= prefix[i];
        freq.push_back(sum);
    }
    sort(freq.begin(), freq.end(), greater<int>());
    long long ans=0;
    for(int i=0; i<n; i++){
        ans += (long long)arr[i]*freq[i];
    }
    cout<<ans<<endl;
    return 0;
}