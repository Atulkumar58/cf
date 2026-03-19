#include <iostream>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, a, b;
        cin>>n>>a>>b;

        if((n> a+b+1) || (n==a && n==b)) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}