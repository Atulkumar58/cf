#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        long long n, k;
        cin>>n>>k;
        vector<long long> arr(n);
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }
        if(k > 2){
            cout<< 0 <<endl;
            continue;
        }
        else{
            long long ans= LLONG_MAX;
            for(int i=0; i<n; i++){
                ans = min(ans, arr[i]);
                for(int j=i+1; j<n; j++){
                    ans = min(ans, abs(arr[j] - arr[i]));
                }
            }

            if(k == 1){
                cout<< ans <<endl;
            }
            else{
                sort(arr.begin(), arr.end());
                for(int i= n-1; i>0; i--){
                    
                    int j=0, k= i-1;
                    while(j <= k){
                        ans= min(ans, abs(arr[i] - arr[j] - arr[k]));

                        if(arr[j] + arr[k] >= arr[i]){
                            k--;
                        }
                        else {
                            j++;
                        }
                    }
                }

                cout<< ans <<endl;
            }
        }
            

    }
    return 0;
}