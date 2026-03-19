#include <iostream>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        int count=0;
        for(int i=0; k>0; i++){
            k-= n-(i+1)/2;
            count++;
        }
        cout<<count<<endl;
    }
    return 0;
}