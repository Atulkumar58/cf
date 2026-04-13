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
        int count=1;
        bool flag = true;
        for(int i=0;i<n;i++){
            cin>>a[i];
            if(i!=0 && a[i-1] == a[i]){
                count++;
            }
            else{
                count = 1;
            }
            if(count >= m){
                flag = false;
            }
            
        }

        if(!flag){
            cout<<"NO"<<endl;
        }
        else{
            cout<<"YES"<<endl;
        }

    }
    return 0;
}