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
        for(int& i: a) cin>>i;

        if(a[n-1] < a[n-2]){
            cout<<-1<<endl;
        }
        else{
            if(a[n-1] >= 0){
                cout<<n-2<<endl;
                for(int i=0; i<n-2; i++){
                    cout<<i+1 <<" "<<n-1<<" "<<n<<endl;
                }
            }
            else{
                bool flag=true;
                for(int i=1; i<n; i++){
                    if(a[i] < a[i-1]){
                        cout<<-1<<endl;
                        flag=false;
                        break;
                    }
                }
                if(flag){
                    cout<<0<<endl;
                }
            }
        }
    }
    return 0;
}