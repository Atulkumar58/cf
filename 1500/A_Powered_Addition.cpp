#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        int maxi= INT_MIN;
        int mini= INT_MAX;
        int sum=0;
        for(int i=0; i<n; i++){
            cin>>a[i];
            if(a[i] > maxi){
                maxi= a[i];
                mini= a[i];
            }
            mini= min(mini, a[i]);
            sum = max(sum, maxi - mini);
            // cout<<sum<<" ";
        }
        // cout<<sum<<endl;
        int mask= 0;
        int time=0;
        while(mask < sum){
            mask= ((mask << 1) | 1);
            time++;
        }
        cout<<time<<endl;
    }
    return 0;
}