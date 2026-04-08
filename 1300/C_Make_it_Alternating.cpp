#include <iostream>
using namespace std;

const int mod=  998244353;
int fact(int n){
    long long ans=1;
    for(int i=2; i<=n; i++){
        ans= (ans*i)%mod;
    }
    return ans;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int n= s.length();
        long long ans=1;

        int c=1;
        int num=0;
        for(int i=1; i<n; i++){
            if(s[i]==s[i-1]){
                c++;
                num++;
            }
            else{
                ans= (ans*(c))%mod;
                c=1;
            }
        }
        ans= (ans*(c))%mod;
        ans= (ans* fact(num))%mod;

        cout<<num<<" "<<ans<<endl;
    }
    return 0;
}