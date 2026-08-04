#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <climits>

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<long long> b(n);
        vector<long long> a(n);
        unordered_map<long long, int> mp;
        for(long long& i: a) {
            cin>>i;
            mp[i]++;
        }
        b= a;
        sort(a.begin(), a.end());
        unordered_map<long long, long long> mp2;

        
        bool possible = 1;
        long long last = LLONG_MAX;
        long long maxi =0;
        
        for(int i=n-2; i>=0; i--){
            if(a[i] != a[i+1]){
                long long diff= a[i+1]-a[i];
                long long count= mp[a[i]];
                if(diff % count ==0){
                    long long step= diff/count;
                    if(step >= last || step <= 0){
                        possible= 0;
                        break;
                    }
                    last= step;
                    maxi= max(maxi, step);
                    mp2[a[i]] = step;

                }else {
                    possible= 0;
                    break;
                }
            }
        }
        if(a[0] != 0) possible= 0;
        if(mp2.size() == 0 && a.back() != 0) possible =0;

        mp2[a[n-1]] = maxi+1;

        if(possible){
            for(int i=0; i<n; i++){
                cout<<mp2[b[i]]<<" ";
            }cout<<endl;
            
        }else cout<<-1<<endl;
    }
    return 0;
}