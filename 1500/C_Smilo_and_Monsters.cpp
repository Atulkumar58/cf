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

        int i=0, j=n-1;
        int x=0;
        long long ans=0;
        // cout<<i<<" "<<j<<" "<<ans<<endl;
        while(i < j){
            if(arr[i] + x < arr[j]){
                x+= arr[i];
                ans += arr[i];
                i++;
            }
            else{
                int t= arr[j]-x;
                ans += t+1;
                arr[i] -= t;
                arr[j] =0;
                x=0;
                j--;
            }
            // cout<<i<<" "<<j<<" "<<ans<<endl;
        }
        if(arr[i] > 1)ans+= ((arr[i] -x +1)/2 +1);
        if(arr[i] == 1)ans+=1;
        cout<<ans<<endl;
    }
    return 0;
}