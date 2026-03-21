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

        if(k==4 && ans!=0 && n>=2){
            int c=0;
            for(int i=0; i<n; i++){
                if(a[i]%k==2){
                    c++;
                }
            }
            if(c>=2){
                ans=0;
            }else if(c==1){
                ans=1;
            }
            else {
                ans= min(ans, 2);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}