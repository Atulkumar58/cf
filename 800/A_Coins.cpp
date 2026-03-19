#include <iostream>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        int t= n/k;
        int x= n%k;
        bool flag=0;
        if(x%2==0) flag= 1;
        else if(t>0 && k%2!=0) flag=1;
        
        if(flag) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}