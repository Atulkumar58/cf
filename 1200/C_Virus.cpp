#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<int> a(m);
        for(int i=0; i<m; i++)
            cin>>a[i];
        sort(a.begin(), a.end());

        vector<int> temp;
        for(int i=1; i<m; i++){
            temp.push_back(a[i]-a[i-1] -1);
        }
        temp.push_back(n+a[0] - a[m-1] -1);
        sort(temp.begin(), temp.end(), greater<int>());
        long long ans=0;
        for(int i=0; i<temp.size(); i++){
            int t= temp[i] - (4*i);
            if(t > 1) t--;
            // cout<<t<<" ";
            if(t > 0) ans+= t;
            else break;
        }
        cout<<n-ans<<"\n";
    }
    return 0;
}