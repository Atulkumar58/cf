#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        vector<int> a(n);   
        for(int i=0; i<n; i++){
            cin>>a[i];
        }

        int ans= INT_MAX;
        for(int i=0; i<n; i++){
            int t= a[i]%k;
            if(t==0){
                ans=0;
                break;
            }
            ans= min(ans, k-t);
        }
        cout<<ans<<endl;
    }
    return 0;
}