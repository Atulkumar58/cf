#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }
        set<long long> s;
        long long sum=0;
        s.insert(sum);
        bool flag = false;
        for(int i=0; i<n; i++){
            if(i%2) sum+=arr[i];
            else sum-=arr[i];

            if(s.find(sum) != s.end()){
                cout<<"YES"<<endl;
                flag = true;
                break;
            }
            s.insert(sum);
        }
        if(!flag){
            cout<<"NO"<<endl;
        }
    }
    return 0;
}