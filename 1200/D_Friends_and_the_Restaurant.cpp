#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<pair<int, int>> arr(n);
        for(auto& p: arr) cin>>p.first;
        for(auto& p: arr) cin>>p.second;

        vector<int> a;
        vector<int> b;
        for(int i=0; i<n; i++){
            int t= arr[i].second - arr[i].first;
            if(t >= 0) a.push_back(t);
            else b.push_back(t);
        }

        sort(a.begin(), a.end());
        sort(b.begin(), b.end(), greater<int>());

        int i=0, j=0;
        int ans=0;
        while(i < a.size() && j< b.size()){
            if(a[i] + b[j] >= 0){
                ans++;
                i++;
                j++;
            }
            else i++;
        }
        cout<<ans+ (a.size() -ans)/2<<endl;
    }
    return 0;
}