#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--)
    {
        int n, k;
        cin>>n>>k;
        vector<int> a(31, 0);
        for(int i=0; i<n; i++){
            int x;
            cin>>x;
            for(int j=0; j<31; j++){
                if(x & (1<<j)){
                    a[j]++;
                }
            }
        }
        int ans=0;
        for(int i=30; i>=0; i--){
            if(n-a[i] <= k){
                ans=  ans|(1<<i);
                k= k-(n-a[i]);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}