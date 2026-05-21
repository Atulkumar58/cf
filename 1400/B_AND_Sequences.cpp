#include <iostream>
#include<vector>
#include <unordered_map>
#include<climits>
using namespace std;
const int mod= 1e9+7;

int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        unordered_map<int, int> freq;
        int mask= INT_MAX;
        for(int& i: a){
            cin>>i;
            mask= mask&i;
            freq[i]++;
        } 

        int f= freq[mask];
        if(f==0){ cout<<0<<endl; continue; }
        if(f==1 && n==1) {cout<<1<<endl; continue;}
        else if(f==1){ cout<<0<<endl; continue; }

        long long ans=((long long)f*(f-1))%mod;
        for(int i=1; i<=n-2; i++){
            ans= (ans*i)%mod;
        }

        cout<<ans<<endl;

    }
    return 0;
}