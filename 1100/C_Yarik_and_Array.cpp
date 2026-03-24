#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>


using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> v(n);
        for(int i=0; i<n; i++){
            cin>>v[i];
        }

        int ans= INT_MIN;
        int sum= 0;
        for(int i=0; i<n; i++){
            if(i>0 && (v[i]+v[i-1])%2==0){
                sum= 0;
            }
            sum+= v[i];
            ans= max(ans, sum);
            if(sum<0){
                sum= 0;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}