#include <iostream>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        int ans = n/ 15;
        ans*=3;
        int rem = n%15;
        if(rem < 3) ans += rem+1;
        else ans+=3;

        cout<<ans<<endl;

    }
    return 0;
}