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
        for(int i=0;i<n;i++){
            cin>>a[i];
        }

        sort(a.begin(), a.end(), greater<int>());
        bool flag = true;
        for(int i=0;i<n-1;i++){
            if(a[i] == a[i+1] ){
                flag = false;
                break;
            }
        }
        if(!flag){
            cout<<-1<<endl;
            continue;
        }
        for(int i: a){
            cout<<i<<" ";
        }cout<<endl;
    }
    return 0;
}