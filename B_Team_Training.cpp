#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,x;
        cin>>n>>x;
        int arr[n];
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }
        sort(arr, arr+n);
        int c=1;
        int ans=0;
        for(int i=n-1; i>=0; i--){
            if(c*arr[i]>=x){
                ans++;
                c=1;
            }
            else{
                c++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}