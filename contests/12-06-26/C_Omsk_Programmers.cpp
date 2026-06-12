#include <iostream>
#include <climits>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int a,b,x;
        cin>>a>>b>>x;

        if(a < b) swap(a, b);

        int count=0;
        while(a/x > b){
            a/=x;
            count++;
        }
        int ans= INT_MAX;
        while(a > 0 || b>0){
            int m= a-b;
            int n= b-(a/x)+1;
            int temp= count + min(m, n);
            ans= min(ans,  temp);
            a/=x;
            b/=x;
            count+=2;
        }
        ans= min(ans, count);
        
        
        cout<<ans<<endl;
    }
    return 0;
}