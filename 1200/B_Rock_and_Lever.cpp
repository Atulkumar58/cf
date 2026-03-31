#include <iostream>
#include <vector>
using namespace std;
int findmax(int a){
    int k=0;
    while(a >= (1<<k)) k++;
    return k;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        vector<int> v(32, 0);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<n;i++){
            int k=findmax(a[i]);
            v[k-1]++;
        }
        long long ans=0;
        for(int i: v){
            ans += (1LL*i*(i-1))/2;
        }
        cout<<ans<<endl;    
    }
    return 0;
}