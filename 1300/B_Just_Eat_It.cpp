#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        long long sum = 0;
        for(int i=0; i<n; i++){
            cin>>a[i];
            sum += a[i];
        }

        long long ans=INT_MIN;
        long long s=0;
        for(int i=1; i<n; i++){
            s += a[i];
            ans = max(ans, s);
            if(s < 0){
                s=0;
            }
        }
        s=0;
        for(int i=0; i<n-1; i++){
            s += a[i];
            ans = max(ans, s);
            if(s < 0){
                s=0;
            }
        }

        if(ans < sum){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}