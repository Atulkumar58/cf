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
        for(int& i: a){
            cin>>i;
        }
        vector<int> ans(n);
        for(int i=0; i<n; i++){
            int s= 0, e=i;
            while(s<=e){
                int mid= (s+e)/2;
                if(a[mid] >= i-mid+1){
                    e= mid-1;
                }else{
                    s= mid+1;
                }
            }
            ans[i] = i-e;
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}