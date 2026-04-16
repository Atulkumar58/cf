#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<int> a(n);
        vector<int> b(m, 0);
        for(int&i : a){
            cin>>i;
            b[i%m]++;
        }

        long long ans = 0;
        if(b[0]>0) ans++;
        int i = 1, j = m-1;
        while(i<=j){
            if(b[i] == 0 && b[j] == 0){
                // do nothing
            }
            else if(abs(b[i]-b[j]) > 1){
                ans+= abs(b[i]-b[j]);
            }
            else {
                ans++;
            }
            i++, j--;
        }
        // if(i == j && b[i]) ans++;
        cout<<ans<<endl;    
    }
    return 0;
}