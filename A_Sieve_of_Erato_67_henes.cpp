#include <iostream>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        bool  b=0;
        int n;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++) {cin>>arr[i];
            // if(arr[i]==1) a=1;
            if(arr[i]==67) b=1;
        }

        if(b) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}