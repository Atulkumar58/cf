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
        for(int& i: arr) cin>>i;
        sort(arr.begin(), arr.end());

        vector<pair<int, int>> a;
        pair<int, int> prev= {arr[0], 1};
        for(int i=1; i<n; i++){
            if(arr[i] == prev.first){
                prev.second++;
            }
            else{
                a.push_back(prev);
                prev= {arr[i], 1};
            }
        }
        a.push_back(prev);

        int ans=a[0].second;
        for(int i=1; i<a.size(); i++){
            if(a[i].first== a[i-1].first+1){
                if(a[i].second > a[i-1].second)
                ans+= a[i].second-a[i-1].second;
            }else{
                ans+= a[i].second;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}