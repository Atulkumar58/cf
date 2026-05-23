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
        vector<int> b(n);
        for(int& i: a) cin>>i;
        for(int& i: b) cin>>i;

        long long ans=0;
        int maxi=0;

        for(int i=0; i<n; i++){
            int x= max(a[i], b[i]);
            int y= min(a[i], b[i]);
            ans+= x;
            maxi= max(maxi, y);
        }
        cout<<ans+maxi<<endl;
    }
    return 0;
}