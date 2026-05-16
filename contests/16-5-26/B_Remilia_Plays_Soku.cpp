#include <iostream>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, x1, x2, k;
        cin>>n>>x1>>x2>>k;

        if (n <= 3) {
            cout << 1 << "\n";
            continue;
        }

        int ans= abs(x1- x2);
        if(x2 > x1){
            ans= min(ans, x1+n-x2);
        }else{
            ans= min(ans, x2+n-x1);
        }

        cout<<k+ans<<endl;
    }
    return 0;
}