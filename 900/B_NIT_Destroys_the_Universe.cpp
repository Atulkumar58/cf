#include <iostream>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i <n; i++) cin>>a[i];

        int ns=0;
        int e=0;
        for(int i=0; i<n; i++){
            if(a[i]==0){
                if(e>0){
                    ns++; e=0;
                }
            }
            else e++;
        }
        if(e>0) ns++;

        if(ns>=2) cout<<2<<endl;
        else if(ns==1) cout<<1<<endl;
        else cout<<0<<endl;
        
    }
    return 0;
}