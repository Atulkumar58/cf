#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0; i<n; i++){
            cin>>a[i];
        }

        int ans=1;
        int dir=0;
        for(int i=1; i<n; i++){
            if(a[i] > a[i-1] && dir != 1){
                ans++;
                dir=1;
            }
            else if(a[i] < a[i-1] && dir != -1){
                ans++;
                dir=-1;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}