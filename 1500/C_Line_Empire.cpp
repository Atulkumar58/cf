#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, a, b;
        cin>>n>>a>>b;
        vector<int> arr(n);
        vector<long long> sum(n);
        for(int i=0; i<n; i++){
            cin>>arr[i];
            if(i==0) sum[i]= arr[i];
            else sum[i]= sum[i-1]+arr[i];
        }

        long long ans=LLONG_MAX;
        for(int i=n-1; i>=0; i--){
            long long cost = (long long)(a+b)*(arr[i]);
            long long s= sum.back()-sum[i];
            int count = n-1-i;
            s-= (long long)count*arr[i];
            cost += (long long)b*s;
            ans = min(ans, cost);
        }
        ans= min(ans, (long long)(b)*sum.back());
        cout<<ans<<endl;
    }
    return 0;
}