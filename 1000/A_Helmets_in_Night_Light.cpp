#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, p;
        cin>>n>>p;
        vector<pair<int, int>> v(n);
        for(int i=0; i<n; i++){
            cin>>v[i].second;
        }
        for(int i=0; i<n; i++){
            cin>>v[i].first;
        }
        v.push_back({p, n});
        sort(v.begin(), v.end());

        long long ans= p;
        int left= n-1;
        int i=0;
        while(left > 0){
            if(left > v[i].second){
                ans += (long long)v[i].second * (v[i].first);
                left -= v[i].second;
            }
            else{
                ans += (long long)v[i].first * left;
                break;
            }
            i++;
        }
        cout<<ans<<endl;
    }
    return 0;
}