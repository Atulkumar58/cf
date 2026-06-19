#include <iostream>
#include<vector>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n; cin>>n;
        vector<long long> a(n);
        // long long sum=0;
        for(int i=0; i<n; i++){
            cin>>a[i];
            if(i > 0 && a[i] < a[i-1]){
                a[i] += a[i-1];
            }
        }
        cout<<a[n-1]<<endl;
    }
    return 0;
}