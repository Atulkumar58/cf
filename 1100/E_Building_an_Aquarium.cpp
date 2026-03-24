#include <iostream>
#include <vector>

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        long long x;
        cin>>n>>x;
        vector<int> a(n);
        for(int i=0; i<n; i++){
            cin>>a[i];
        }

        long long i=1, j= 2e9+7;
        while(i<=j){
            long long mid= (i+j)/2;
            long long sum= 0;
            for(int k=0; k<n; k++){
                if(mid > a[k]){
                    sum+= mid-a[k];
                }
                if(sum > x){
                    break;
                }
            }

            if(sum > x){
                j= mid-1;
            }
            else{
                i= mid+1;
            }
        }
        cout<<j<<endl;
    }
    return 0;
}