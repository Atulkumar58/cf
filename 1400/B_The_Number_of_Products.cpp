#include <iostream>
#include <vector>
using namespace std;

int main(){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int &i: arr) cin>>i;

        vector<int> dp(n, 0);
        bool pos=1;
        int a=0, b=0;
        for(int i=0; i<n; i++){
            if(pos){
                a++;
                if(arr[i]>0){ 
                    dp[i] =a;
                }else{
                    dp[i]=b;
                    pos=0;
                }
            }else{
                b++;
                if(arr[i] > 0){
                    dp[i]=b;
                }else{
                    dp[i]=a;
                    pos=1;
                }
            }
            // cout<<dp[i]<<" ";
        }
        long long ans=0;
        for(int i: dp){
            ans+= (long long) i;
        }
        long long ax= (long long)n*(n+1)/2;
        cout<<ax-ans<<" "<<ans<<endl;

    
    return 0;
}