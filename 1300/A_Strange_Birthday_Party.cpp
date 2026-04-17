#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<int> a(n);
        for(int i=0; i<n; i++){
            cin>>a[i];
        }
        vector<int> c(m);
        for(int i=0; i<m; i++){
            cin>>c[i];
        }
        sort(a.begin(), a.end());
        long long ans=0;
        int j=0;
        for(int i=n-1; i>=0; i--){
            if(c[j] < c[a[i]-1]){
                ans+= c[j];
                j++;
            }else{
                ans+= c[a[i]-1];
            }
            // cout<<ans<<" ";
        }
        cout<<ans<<endl;
    }
    return 0;
}