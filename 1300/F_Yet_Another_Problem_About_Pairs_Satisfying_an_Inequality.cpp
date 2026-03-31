#include <iostream>
#include <vector>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }

        vector<bool> type(n, 0);
        vector<long long> count(n, 0);
        long long sum=0;
        long long ans=0;
        for(int i=0; i<n; i++){
            count[i] = sum;
            if(arr[i] < i+1){
                sum++;
                type[i] = 1;
                if(arr[i] > 0){
                    ans += count[arr[i] - 1];
                }
            }
            // cout<<ans<<" ";
        }

        cout<<ans<<"\n";
    }
    return 0;
}