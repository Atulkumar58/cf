#include <iostream>
#include <vector>

using namespace std;
void shift(vector<int> &ans, int l, int r){
    for(int i=l; i<r; i++){
        ans[i]= i+2;
    }
    ans[r]= l+1;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        for(int i=0; i<n; i++) cin>>a[i];

        bool flag= 1;
        vector<int> ans(n);
        int l=0;
        for(int i=1; i<n; i++){
            if(a[i] != a[i-1]){
                if(l== i-1){
                    flag= false;
                    break;
                }
                else {
                    shift(ans, l, i-1);
                    l= i;
                }
            }
        }
        if(l == n-1){
            flag= false;
        }
        else {
            shift(ans, l, n-1);
        }
        
        if(flag){
            for(int i=0; i<n; i++){
                cout<<ans[i]<<" ";
            }
            cout<<"\n";
        }
        else {
            cout<<"-1\n";
        }
      
    }
    return 0;
}