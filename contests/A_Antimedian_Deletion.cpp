#include <iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        for(int& i: a) cin>>i;

        if(n==1) cout<<1<<endl;
        else{
            for(int i=0; i<n; i++){
                cout<<2<<" ";
            }cout<<endl;
        }
    }
}