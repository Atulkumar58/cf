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
        bool same = true;
        int x, y;
        for(int i=0; i<n; i++){
            cin>>a[i];
            if(i > 0 && a[i] != a[i-1]){
                same = false;
                x= i, y = i-1;
            }
        }
        if(same){
            cout<<"NO"<<endl;
        }
        else{
            cout<<"YES"<<endl;
            cout<<y+1<<" "<<x+1<<endl;
            for(int i=0; i<n; i++){
                if(i!= x && i!=y){
                    if(a[i] != a[y]){
                        cout<<y+1<<" "<<i+1<<endl;
                    }
                    else{
                        cout<<x+1<<" "<<i+1<<endl;
                    }
                }
            }

        }
        
    }
    return 0;
}