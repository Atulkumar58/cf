#include <iostream>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int x,y;
        cin>>x>>y;
        int n= abs(x-y);
        int count=0;
        for(int i=1; i<=n; i++){
            if(n%i==0) count++;
        }
        if(n==0) count=1;
        cout<<count<<endl;
        for(int i=0; i<x; i++) cout<<1<<" ";
        for(int i=0; i<y; i++) cout<<-1<<" ";
        cout<<endl;
    }
    return 0;
}