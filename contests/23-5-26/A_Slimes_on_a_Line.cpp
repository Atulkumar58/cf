#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int& i: arr) cin>>i;

        sort(arr.begin(), arr.end());
        long long x= ((long long) arr[n-1] - arr[0]);
        cout<<((x&1) ? x/2 +1 : x/2)<<endl;
    }
    return 0;
}