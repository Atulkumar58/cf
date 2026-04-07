#include <iostream>
#include <vector>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        int ans = 0;
        for(int& i: a) {
            cin>>i;
            ans= ans^i;
        }
        cout<<ans<<endl;

    }
    return 0;
}