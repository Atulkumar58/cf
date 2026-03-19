#include <iostream>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, x;
        cin>>n>>x;
        int arr[n+1];
        arr[0]=0;
        for(int i=1; i<=n; i++) cin>>arr[i];

        int ans=0;
        for(int i=1; i<=n; i++) if(arr[i]- arr[i-1] > ans) ans= arr[i]-arr[i-1];
        ans= max(ans, 2*(x-arr[n]));
        cout<<ans<<endl;
    }
    return 0;
}