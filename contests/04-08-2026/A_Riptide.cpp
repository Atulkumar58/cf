#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
        vector<int> a(3);
        for(int& i:a) cin>>i;

        sort(a.begin(), a.end());
        int ans= a[1]-a[0];
        ans= min(ans, a[2]-a[1]);
        cout<<ans<<endl;
    }
    return 0;
}