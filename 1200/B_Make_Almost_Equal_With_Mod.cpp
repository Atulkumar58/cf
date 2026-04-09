#include<bits/stdc++.h>
using namespace std;

long long min(long long a, long long b){
    return (a < b) ? a : b;
}
const long long INF = 1e18;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<long long> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }

        int k=0;
        while(k < 62){
            bool flag = true;
            for(int i=0;i<n-1;i++){
                if(((a[i] ^ a[i+1]) & (1LL << k))  != 0){
                    flag = false;
                    break;
                }
            }
            k++;
            if(!flag) break;
        }
        cout<< min(INF, (1LL << k)) << endl;
    }
    return 0;
}