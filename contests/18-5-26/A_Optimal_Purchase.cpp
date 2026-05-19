#include <iostream>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        long long n, a, b;
        cin>>n>>a>>b;

        if(b >= a*3){
            cout<<n*a<<endl;
        } else {
            long long ans = (n/3)*b;
            int c= (n%3)*a;
            if(c < b){
                ans += c;
            } else {
                ans += b;
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}