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
        int count=0;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(i+j+2 == a[i]*a[j]){
                    count++;
                }
            }
        }
        cout<<count<<endl;

    }
    return 0;
}