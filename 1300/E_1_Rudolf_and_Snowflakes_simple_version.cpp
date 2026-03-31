#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        long long n;
        cin>>n;

        long double ans = -1;
        ans += sqrt(1 + 4*(n-1));
        ans /= 2;
        cout<<ans <<" ";
        int t= ans;
        if(ans- t == 0 && ans > 1){
            cout<<"YES"<<"\n";
        }
        else{
            cout<<"NO"<<"\n";
        }
    }
    return 0;
}