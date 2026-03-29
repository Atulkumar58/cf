#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;

        vector<int> v(n*(n-1) /2);
        map<int, int> m;
        for(int& i: v){
            cin>>i;
            m[i]++;
        }  
        vector<int> ans;
        for(auto i: m){
            while(i.second > 0){
                ans.push_back(i.first);
                i.second -= (n-1);
                n--;
            }
        }

        for(int i: ans) cout<<i<<" ";
        cout<<ans.back()<<"\n";
        m.clear();
    }
   return 0;
}